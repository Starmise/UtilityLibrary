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
    * @brief Constructor con par�metros para los valores "x", "y", "z" y "w"
    */
  Quaternion(float wNum, float xNum, float yNum, float zNum) :
    w(wNum), x(xNum), y(yNum), z(zNum) {}

  /**
    * @brief Constructor que inicializa el quaternion a partir de un �ngulo y eje de rotaci�n.
    * @param angle �ngulo de rotaci�n del quaternion.
    * @param axis Eje de rotaci�n como un Vector3
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
     * @brief Sobrecarga del operador +, para sumar un cuaterni�n a otro cuaterni�n.
     * @param other El otro cuaternion que se sumar�.
     */
  Quaternion
    operator+(const Quaternion& other) const {
    return Quaternion(w + other.w, x + other.x, y + other.y, z + other.z);
  }

  /**
     * @brief Sobrecarga del operador *, para multiplicar un cuaterni�n por un escalar
     * @param scalar El producto escalar por el que se multiplicar�.
     */
  Quaternion
    operator*(float scalar) const {
    return Quaternion(w * scalar, x * scalar, y - scalar, z - scalar);
  }

  /**
     * @brief Sobrecarga del operador *, para multiplicar un cuaterni�n a otro cuaterni�n.
     * @param other El otro cuaternion que se multiplicar�.
     */
  Quaternion operator*(const Quaternion& other) const {
    return Quaternion(
      w * other.w - x * other.x - y * other.y - z * other.z,
      w * other.x + x * other.w + y * other.z - z * other.y,
      w * other.y - x * other.z + y * other.w + z * other.x,
      w * other.z + x * other.y - y * other.x + z * other.w);
  }

  /**
    * @brief Se cacula la magnitud de los valores del cuaterni�n
    */
  float
    magnitude() const {
    return sqrt(w * w + x * x + y * y + z * z);
  }

  /**
     * @brief Normalizaci�n que devuelve un cuaterni�n normalizado de magnitud 1
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
     * @brief Devuelve el conjugado del cuaterni�n.
     */
  Quaternion
    conjugate() {
    return Quaternion(w, -x, -y, -z);
  }

  /**
     * @brief Devuelve el cuaterni�n inverso.
     */
  Quaternion
    inverse() {
    float qSquared = (1.0f / (w * w + x * x + y * y + z * z));
    return conjugate() * qSquared;
  }


  /**
     * @brief M�todo Vector3 que utiliza el cuaterni�n para rotar un vector v.
     * Se convierte el vector en un cuaterni�n, luego se normaliza y se rota
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
    * @brief M�todo que devuelve un puntero a los componentes del cuaterni�n
    */
  float*
    data() {
    return &w;
  }

  /**
    * @brief M�todo constante con un puntero a los componentes del cuaterni�n sin modificarlos
    */
  const float*
    data() const {
    return &w;
  }

private:

};