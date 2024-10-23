#pragma once
#include "MathUtilities.h"

class
Vector2 {
public:
  float x; // Valor en x del vector
  float y; // Valor en y del vector

  /**
    * @brief Constructor por defecto que inicializa los valores "x" y "y" en 0
    */
  Vector2() : x(0), y(0) {};

  /**
    * @brief Constructor con par�metros para los valores "x" y "y"
    */
  Vector2(float xNum, float yNum) : x(xNum), y(yNum) {}

  /**
    * @brief Destructor por defecto
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
     * @brief Sobrecarga del operador +, para sumar un vector a otro vector.
     * @param other El otro vector que se sumar�.
     */
  Vector2
   operator+(const Vector2& other) const {
    float new_xNum = x + other.x;
    float new_yNum = y + other.y;
    return Vector2(new_xNum, new_yNum);
  }

  /**
     * @brief Sobrecarga del operador -, para restar un vector a otro vector.
     * @param other El otro vector que se restar�.
     */
  Vector2
  operator-(const Vector2& other) const {
    float new_xNum = x - other.x;
    float new_yNum = y - other.y;
    return Vector2(new_xNum, new_yNum);
  }

  /**
     * @brief Sobrecarga del operador *, para multiplicar un vector a otro vector.
     * @param scalar El producto escalar por el que se multiplicar�.
     */
  Vector2
  operator*(float scalar) const {
    return Vector2(x * scalar, y * scalar);
  }

  /**
    * @brief Se cacula la magnitud de los valores del vector
    */
  float
  magnitude() {
    return sqrtNewthon(x * x + y * y);
  }

  /**
     * @brief Normalizaci�n del vector que devuelva un vector con la misma direcci�n
     */
  Vector2
  normalize() {
    float mag = magnitude();
    // Si la magnitud es 0, se devuelve un vector con las coordenadas (0,0)
    if (mag == 0) {
      return Vector2(0, 0);
    }
    return Vector2(x / mag, y / mag);
  }

  /**
    * @brief M�todo que devuelve un puntero a los componentes del vector
    */
  float*
  data() {
    return &x;
  }

  /**
    * @brief M�todo constante con un puntero a los componentes del vector sin modificarlos
    */
  const float*
  data() const {
    return &x;
  }

private:

};