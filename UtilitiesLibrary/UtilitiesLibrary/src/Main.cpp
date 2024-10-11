#include "Vector2.h"
#include "Vector3.h"

int main() {
  Vector3 v1(1.0f, 2.0f, 3.0f);
  Vector3 v2;
  Vector3 v3 = v1 + Vector3(2.0f, 3.0f, 4.0f);
  Vector3 v4 = v1 - Vector3(1.0f, 1.0f, 1.0f);
  Vector3 v5 = v1 * 2.0f;
  float mag = v1.magnitude();
  Vector3 v6 = v1.normalize();
  const float* data = v1.data();
  return 0;
}