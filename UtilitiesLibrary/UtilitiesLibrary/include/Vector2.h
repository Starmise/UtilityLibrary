#pragma once
#include "MathUtilities.h"

class
Vector2 {
public:
  float x; // X value of the vector
  float y; // Y value of the vector

  /**
    * @brief Default constructor that initializes "x" and "y" to 0
    */
  Vector2() : x(0), y(0) {};

  /**
    * @brief Constructor with parameters for "x" and "y" values
    */
  Vector2(float xNum, float yNum) : x(xNum), y(yNum) {}

  /**
    * @brief Default destructor
    */
  ~Vector2() = default;

  /**
    * Respecto a la sobrecarga del operadores, operator se usa para definir
    * el operador que se va a sobrecargar. Los operandos son, primero el objeto
    * que invoca al m�todo y el segundo el que se pasa por el par�metro. El segundo
    * operando llamado other en este caso, es pasado por referencia para evitar
    * problemas. Como la operaci�n no modifica el valor del argumento, se usa const
    * dentro del paso por referenciaantes y como el m�todo tampoco modifica el valor,
    * se usa un segundo const luego del par�metro. Se usa debido a que de otra forma no
    * es posible sumar dos clases como tal.
   */

   /**
     * @brief  Overload of the + operator, to add one vector to another vector.
     * @param other The other vector to add.
     */
  Vector2
  operator+(const Vector2& other) const {
    float new_xNum = x + other.x;
    float new_yNum = y + other.y;
    return Vector2(new_xNum, new_yNum);
  }

  /**
     * @brief Overload of the - operator, to subtract one vector from another vector.
     * @param other The other vector to add.
     */
  Vector2
  operator-(const Vector2& other) const {
    float new_xNum = x - other.x;
    float new_yNum = y - other.y;
    return Vector2(new_xNum, new_yNum);
  }

  /**
     * @brief Overload of the * operator, to multiply a vector by a scalar.
     * @param scalar The scalar by which to multiply.
     */
  Vector2
  operator*(float scalar) const {
    return Vector2(x * scalar, y * scalar);
  }

  /**
    * @brief Calculates the magnitude of the vector values
    */
  float
  magnitude() {
    return sqrtNewthon(x * x + y * y);
  }

  /**
     * @brief Normalizes the vector, returning a vector with the same direction
     */
  Vector2
  normalize() {
    float mag = magnitude();
    // If the magnitude is 0, a vector with the coordinates (0,0) is returned
    if (mag == 0) {
      return Vector2(0, 0);
    }
    return Vector2(x / mag, y / mag);
  }

  /**
    * @brief Method that returns a pointer to the vector components
    */
  float*
  data() {
    return &x;
  }

  /**
    * @brief Constant method that returns a pointer to the vector components without modifying them
    */
  const float*
  data() const {
    return &x;
  }

private:

};