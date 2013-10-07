#include "line.h"

Line3::Line3() 
	: o(), d() {
}

Line3::Line3(const Vector3& o, const Vector3& d)
	: o(o), d(d) {
	this->d.normalize();
}

Vector3 Line3::get_intersect(float w) const {
	return Vector3(o.x + d.x * w, o.y + d.y * w, o.z + d.z * w);
}
