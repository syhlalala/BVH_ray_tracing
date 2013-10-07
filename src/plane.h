#ifndef __PLANE_H__
#define __PLANE_H__

#include "pnt.h"
#include "triangle.h"
#include "line.h"


class Plane {
public:
	enum CoordinateType { X, Y, Z };

	Vector3 n;
	float d;

	Plane();
	Plane(const Triangle& triangle);
	Plane(const Vector3& a, const Vector3& b, const Vector3& c);
	Plane(float value, CoordinateType type);

	bool intersect(const Line3& line, Vector3& result) const;
	bool intersect(const Line3& line, float& result) const;

private:
};

#endif //__PLANE_H__
