#pragma once

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
