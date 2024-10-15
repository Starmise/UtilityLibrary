#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

int main() {
  Vector4 v1(1.0f, 2.0f, 3.0f, 4.0f);
  Vector4 v2;
  Vector4 v3 = v1 + Vector4(2.0f, 3.0f, 4.0f, 1.0f);
  Vector4 v4 = v1 - Vector4(1.0f, 1.0f, 1.0f, 1.0f);
  Vector4 v5 = v1 * 2.0f;
  float mag = v1.magnitude();
  Vector4 v6 = v1.normalize();
  const float* data = v1.data();
  return 0;
}