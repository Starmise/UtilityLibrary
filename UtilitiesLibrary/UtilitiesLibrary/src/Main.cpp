#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Quaternion.h"

int main() {
  Quaternion q1(1.0f, 0.0f, 0.0f, 0.0f);
  Vector3 axis(0.0f, 1.0f, 0.0f);
  float angle = 90.0f;
  Quaternion q2 = Quaternion::fromAxisAngle(axis, angle);
  Quaternion q3 = q1 + q2;
  Quaternion q4 = q1 * q2;
  Quaternion q5 = q2 * 0.5f;
  float mag = q2.magnitude();
  Quaternion q6 = q2.normalize();
  Quaternion qConjug = q2.conjugate();
  Quaternion qInv = q2.inverse();
  Vector3 v(1.0f, 0.0f, 0.f);
  Vector3 vRotated = q2.rotate(v);
  return 0;
}