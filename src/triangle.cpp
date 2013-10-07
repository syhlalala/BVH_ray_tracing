#include "triangle.h"

#include <cmath>
#include "common.h"

Triangle::Triangle (const Vector3& a, const Vector3& b, const Vector3& c)
	: a(a), b(b), c(c), ta(), tb(), tc(), attr() {
	x = (a.x + b.x + c.x) / 3;
	y = (a.y + b.y + c.y) / 3;
	z = (a.z + b.z + c.z) / 3;
}

Triangle::Triangle (const Vector3& a, const Vector3& b, const Vector3& c, const Vector3& ta, const Vector3& tb, const Vector3& tc)
	: a(a), b(b), c(c), ta(ta), tb(tb), tc(tc), attr() {
	x = (a.x + b.x + c.x) / 3;
	y = (a.y + b.y + c.y) / 3;
	z = (a.z + b.z + c.z) / 3;
}

Triangle::Triangle (const Vector3& a, const Vector3& b, const Vector3& c, const Vector3& ta, const Vector3& tb, const Vector3& tc, const Attribute& attr)
	: a(a), b(b), c(c), ta(ta), tb(tb), tc(tc), attr(attr) {
	x = (a.x + b.x + c.x) / 3;
	y = (a.y + b.y + c.y) / 3;
	z = (a.z + b.z + c.z) / 3;
}

bool Triangle::intersect(const Line3& line, Vector3& result) const {
	Vector3 e1 = a - b, e2 = a - c, s = a - line.o;
	float t = det(line.d, e1, e2);
	if (fabs(t) < EPS) return false;

	float beta = det(line.d, s, e2) / t;
	if (beta < 0 || beta > 1) return false;
	float gamma = det(line.d, e1, s) / t;
	if (gamma < 0 || gamma > 1 || beta + gamma > 1) return false;
	if (det(s, e1, e2) / t <= 0) return false;

	result = a * (1 - beta - gamma) + b * beta + c * gamma;

	return true;
}


bool Triangle::intersect(const Line3& line, Vector4& result) const {
	Vector3 e1 = a - b, e2 = a - c, s = a - line.o;
	result.w = det(line.d, e1, e2);
	if (fabs(result.w) < EPS) return false;

	result.y = det(line.d, s, e2) / result.w;
	if (result.y < 0 || result.y > 1) return false;

	result.z = det(line.d, e1, s) / result.w;
	if (result.z < 0 || result.z > 1 || result.y + result.z > 1) return false;

	result.w = det(s, e1, e2) / result.w;
	if (result.w <= 0) return false;

	result.x = 1 - result.y - result.z;

	return true;
}

Vector3 Triangle::get_intersect_point(const Vector4& p) const {
	return a * p.x + b * p.y + c * p.z;
}

Vector3 Triangle::get_texture_point(const Vector4& p) const {
	return ta * p.x + tb * p.y + tc * p.z;
}
