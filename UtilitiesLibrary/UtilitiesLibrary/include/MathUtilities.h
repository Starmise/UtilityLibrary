#pragma once

/*
  * @brief Se calcula el valor absoluto
  * @param num Valor del que se calcula el número absoluto
  */
float
abs(float num) {
  if (num < 0) {
    return num * -1;
  }
  return num;
}

/*
  * @brief Se calcula la raiz cuadrada (aproximación) mediante el método de Newthon
  * @param num Valor del que se calcula la raiz cuadrada
  */
float
sqrtNewthon(int num) {
  float errMargin = 0.0001; //Margen permitido de error
  float estimate = 1.0; // Primera estimación
  // Se irá calculando hasta que la estimación sea cercana a la raíz cuadrada del número
  while (abs((estimate * estimate) - num) >= errMargin) {
    float quotient = num / estimate; // Cociente entre el número y la estimación actual
    float prom = (quotient + estimate) / 2.0; // Cálculo para el valor de estimación
    estimate = prom;
  }
  return estimate;
}

/*
  * @brief Se calcula la raiz cuadrada mediante el método de Newthon-Raphson
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
