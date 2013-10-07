#include "plane.h"

#include <cmath>
#include "common.h"

Plane::Plane()
	: n(), d(0) {
}

Plane::Plane(const Triangle& t) {
	Vector3 u = t.b - t.a, v = t.c - t.a;
	n = det(u, v).normalize();
	d = -dot(n, t.a);
}

Plane::Plane(const Vector3& a, const Vector3& b, const Vector3& c) {
	Vector3 u = b - a, v = c - a;
	n = det(u, v).normalize();
	d = -dot(n, a);
}

Plane::Plane(float value, CoordinateType type)
	: n(), d(-value) {
	switch (type) {
		case X:
			n.x = 1;
			break;
		case Y:
			n.y = 1;
			break;
		case Z:
			n.z = 1;
			break;
	}
}

bool Plane::intersect(const Line3& line, Vector3& result) const {
	float t = dot(n, line.d);

	if (fabs(t) < EPS) return false;
	t = - (d + dot(n, line.o)) / t;

	if (t <= 0) return false;
	result = line.o + line.d * t;
	return true;
}

bool Plane::intersect(const Line3& line, float& result) const {
	result = dot(n, line.d);

	if (fabs(result) < EPS) return false;
	result = - (d + dot(n, line.o)) / result;

	return result > 0;
}
