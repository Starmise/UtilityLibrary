#pragma once
#include "MathUtilities.h"

class Vector4
{
public:
  float x; // Valor en x del vector
  float y; // Valor en y del vector
  float z; // Valor en z del vector
  float w; // Valor en w del vector

  /**
    * @brief Constructor por defecto que inicializa los valores "x", "y", "z", "w" en 0
    */
  Vector4() : x(0), y(0), z(0), w(0) {};
  /**
    * @brief Constructor con parámetros para los valores "x", "y", "z" y "w"
    */
  Vector4(float xNum, float yNum, float zNum, float wNum) :
    x(xNum), y(yNum), z(zNum), w(wNum) {}

  /**
    * @brief Destructor por defecto
    */
  ~Vector4() = default;

  /**
     * @brief Sobrecarga del operador +, para sumar un vector a otro vector.
     * @param other El otro vector que se sumará.
     */
  Vector4
    operator+(const Vector4& other) const {
    return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
  }

  /**
     * @brief Sobrecarga del operador -, para restar un vector a otro vector.
     * @param other El otro vector que se restará.
     */
  Vector4
    operator-(const Vector4& other) const {
    return Vector4(x - other.x, y - other.y, z - other.z, w + other.w);
  }

  /**
     * @brief Sobrecarga del operador *, para multiplicar un vector a otro vector.
     * @param other El otro vector que se multiplicará.
     */
  Vector4
    operator*(float scalar) const {
    return Vector4(x * scalar, y - scalar, z - scalar, w + scalar);
  }

  /**
    * @brief Se cacula la magnitud de los valores del vector
    */
  float
    magnitude() {
    return sqrt(x * x + y * y + z * z + w * w);
  }

  /**
     * @brief Normalización del vector que devuelva un vector con la misma dirección
     */
  Vector4
    normalize() {
    float mag = magnitude();
    if (mag == 0) {
      return Vector4(0, 0, 0, 0);
    }
    return Vector4(x / mag, y / mag, z / mag, w / mag);
  }

  /**
    * @brief Método que devuelve un puntero a los componentes del vector
    */
  float*
    data() {
    return &x;
  }

  /**
    * @brief Método constante con un puntero a los componentes del vector sin modificarlos
    */
  const float*
    data() const {
    return &x;
  }

private:

};
