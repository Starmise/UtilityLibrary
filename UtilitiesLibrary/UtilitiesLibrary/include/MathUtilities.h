#pragma once

// Constantes 
const float PI = 3.14159265358979323846f;
const float E = 2.71828182845904523536f;

/*
  * @brief Se calcula el valor absoluto
  * @param num Valor del que se calcula el n�mero absoluto
  */
float
abs(float num) {
  if (num < 0) {
    return num * -1;
  }
  return num;
}

/*
  * @brief Se calcula la raiz cuadrada (aproximaci�n) mediante el m�todo de Newthon
  * @param num Valor del que se calcula la raiz cuadrada
  */
float
sqrtNewthon(int num) {
  float errMargin = 0.0001; //Margen permitido de error
  float estimate = 1.0; // Primera estimaci�n
  // Se ir� calculando hasta que la estimaci�n sea cercana a la ra�z cuadrada del n�mero
  while (abs((estimate * estimate) - num) >= errMargin) {
    float quotient = num / estimate; // Cociente entre el n�mero y la estimaci�n actual
    float prom = (quotient + estimate) / 2.0; // C�lculo para el valor de estimaci�n
    estimate = prom;
  }
  return estimate;
}

/*
  * @brief Se calcula la raiz cuadrada mediante el m�todo de Newthon-Raphson
  * @param num Valor del que se calcula la raiz cuadrada
  */
inline float sqrt(float value) {
  // No se permiten valores negativos
  if (value < 0) {
    return 0;
  }
  float x = value;
  float y = 1.0f;
  float epsilon = 0.00001f;
  while (x - y > epsilon) {
    x = (x + y) / 2.0f;
    y = value / x;
  }
  return x;
}

/**
   * Calcula el seno de un �ngulo en radianes mediante serie de Taylor
   * @param angle �ngulo en radianes.
   */
inline float sin(float angle) {
  float result = 0.0f;
  float term = angle;
  float angle_squared = angle * angle;
  int n = 1;
  while (term > 0.000001 || term < -0.000001) {
    result += term;
    term *= -angle_squared / ((2 * n) * (2 * n + 1));
    ++n;
  }
  return result;
}

/**
   * Calcula el coseno de un �ngulo en radianes mediante serie de Taylor.
   * @param angle �ngulo en radianes.
   */
inline float cos(float angle) {
  float result = 1.0f;
  float term = 1.0f; 
  float angle_squared = angle * angle;
  int n = 1;
  while (term > 1e-6f || term < -1e-6f) {
    term *= -angle_squared / ((2 * n - 1) * (2 * n));
    result += term;
    ++n;
  }
  return result;
}

/**
   * Calcula la tangente de un �ngulo en radianes y se comprueba que no se divida
   * entre 0 usando un operador ternario (condicion ? valor_true : valor_false)
   * @param angle �ngulo en radianes.
   */
inline float tan(float angle) {
  float tSin = sin(angle);
  float tCos = cos(angle);
  return tCos != 0.0f ? tSin / tCos : 0.0f;
}