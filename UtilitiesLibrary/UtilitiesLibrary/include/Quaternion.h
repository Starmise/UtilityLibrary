#pragma once
#include "MathUtilities.h"
#include "Vector3.h"

class Quaternion
{
public:
  float w; // Valor en w del quaternion
  float x; // Valor en x del quaternion
  float y; // Valor en y del quaternion
  float z; // Valor en z del quaternion

  /**
    * @brief Constructor por defecto que inicializa los valores "w", "x", "y", "z" en 0
    */
  Quaternion() : w(0), x(0), y(0), z(0) {};

  /**
    * @brief Constructor con parámetros para los valores "x", "y", "z" y "w"
    */
  Quaternion(float wNum, float xNum, float yNum, float zNum) :
    w(wNum), x(xNum), y(yNum), z(zNum) {}

  /**
    * @brief Constructor que inicializa el quaternion a partir de un ángulo y eje de rotación.
    * @param angle Ángulo de rotación del quaternion.
    * @param axis Eje de rotación como un Vector3
    */
  Quaternion
    fromAxisAngle(const Vector3& axis, float angle) {
    float halfAngle = angle / 2;
    float sinHalfAngle = sin(halfAngle);

    w = cos(halfAngle);
    x = axis.x * sinHalfAngle;
    y = axis.y * sinHalfAngle;
    z = axis.z * sinHalfAngle;

    return Quaternion(w, x, y, z);
  }

  /**
     * @brief Sobrecarga del operador +, para sumar un cuaternión a otro cuaternión.
     * @param other El otro cuaternion que se sumará.
     */
  Quaternion
    operator+(const Quaternion& other) const {
    return Quaternion(w + other.w, x + other.x, y + other.y, z + other.z);
  }

  /**
     * @brief Sobrecarga del operador *, para multiplicar un cuaternión por un escalar
     * @param scalar El producto escalar por el que se multiplicará.
     */
  Quaternion
    operator*(float scalar) const {
    return Quaternion(w * scalar, x * scalar, y - scalar, z - scalar);
  }

  /**
     * @brief Sobrecarga del operador *, para multiplicar un cuaternión a otro cuaternión.
     * @param other El otro cuaternion que se multiplicará.
     */
  Quaternion operator*(const Quaternion& other) const {
    return Quaternion(
      w * other.w - x * other.x - y * other.y - z * other.z,
      w * other.x + x * other.w + y * other.z - z * other.y,
      w * other.y - x * other.z + y * other.w + z * other.x,
      w * other.z + x * other.y - y * other.x + z * other.w);
  }

  /**
    * @brief Se cacula la magnitud de los valores del cuaternión
    */
  float
    magnitude() const {
    return sqrt(w * w + x * x + y * y + z * z);
  }

  /**
     * @brief Normalización que devuelve un cuaternión normalizado de magnitud 1
     */
  Quaternion
    normalize() {
    float mag = magnitude();
    if (mag == 0) {
      return Quaternion(1, 0, 0, 0);
    }
    return Quaternion(w / mag, x / mag, y / mag, z / mag);
  }

  /**
     * @brief Devuelve el conjugado del cuaternión.
     */
  Quaternion
    conjugate() {
    return Quaternion(w, -x, -y, -z);
  }

  /**
     * @brief Devuelve el cuaternión inverso.
     */
  Quaternion
    inverse() {
    float qSquared = (1.0f / (w * w + x * x + y * y + z * z));
    return conjugate() * qSquared;
  }


  /**
     * @brief Método Vector3 que utiliza el cuaternión para rotar un vector v.
     * Se convierte el vector en un cuaternión, luego se normaliza y se rota
     * usando q * v * q^-1
     */
  Vector3
    rotate(const Vector3& v) {
    Quaternion vectorQuat(0, v.x, v.y, v.z);

    Quaternion normalizedQuat = this->normalize();

    Quaternion rotatedQuat = normalizedQuat * vectorQuat * normalizedQuat.inverse();

    return Vector3(rotatedQuat.x, rotatedQuat.y, rotatedQuat.z);
  }


  /**
    * @brief Método que devuelve un puntero a los componentes del cuaternión
    */
  float*
    data() {
    return &w;
  }

  /**
    * @brief Método constante con un puntero a los componentes del cuaternión sin modificarlos
    */
  const float*
    data() const {
    return &w;
  }

private:

};