#include "pnt.h"

#include <cmath>
//-----------Vector3--------------

Vector3::Vector3(float x, float y, float z)
	: x(x), y(y), z(z) {

}

Vector3::Vector3()
	:x(0), y(0), z(0) {
}

float dot(const Vector3& u, const Vector3& v) {
	return u.x * v.x + u.y * v.y + u.z * v.z;
}

Vector3 det(const Vector3& u, const Vector3& v) {
	return Vector3(u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x);
}

float det(const Vector3& u, const Vector3& v, const Vector3& w) {
	return 	u.x * (v.y * w.z - v.z * w.y) +
			u.y * (v.z * w.x - v.x * w.z) +
			u.z * (v.x * w.y - v.y * w.x);
}

float dist(const Vector3 &u, const Vector3 &v) {
	return sqrt( (u.x - v.x) * (u.x - v.x) +
				 (u.y - v.y) * (u.y - v.y) +
				 (u.z - v.z) * (u.z - v.z) );
}

Vector3 operator+ (const Vector3& u, const Vector3& v) {
	return Vector3(u.x + v.x, u.y + v.y, u.z + v.z);
}

Vector3 operator- (const Vector3& u, const Vector3& v) {
	return Vector3(u.x - v.x, u.y - v.y, u.z - v.z);
}

Vector3 operator* (const Vector3& u, float x) {
	return Vector3(u.x * x, u.y * x, u.z * x);
}

Vector3& Vector3::operator+= (const Vector3& u) {
	this->x += u.x;
	this->y += u.y;
	this->z += u.z;
	return *this;
}

Vector3& Vector3::operator-= (const Vector3& u) {
	this->x -= u.x;
	this->y -= u.y;
	this->z -= u.z;
	return *this;
}

Vector3& Vector3::normalize() {
	float len = sqrt(dot(*this, *this));

	this->x /= len;
	this->y /= len;
	this->z /= len;

	return *this;
}

//------------Vector2--------------

Vector2::Vector2(float x, float y)
	: x(x), y(y) {

}

Vector2::Vector2()
	: x(0), y(0) {
}

float dot(const Vector2& u, const Vector2& v) {
	return u.x * v.x + u.y * v.y;
}

float det(const Vector2& u, const Vector2& v) {
	return u.x * v.y - u.y * v.x;
}

float dist(const Vector2 &u, const Vector2 &v) {
	return sqrt( (u.x - v.x) * (u.x - v.x) +
				 (u.y - v.y) * (u.y - v.y) );
}

Vector2 operator+ (const Vector2& u, const Vector2& v) {
	return Vector2(u.x + v.x, u.y + v.y);
}

Vector2 operator- (const Vector2& u, const Vector2& v) {
	return Vector2(u.x - v.x, u.y - v.y);
}

Vector2& Vector2::operator+= (const Vector2& u) {
	this->x += u.x;
	this->y += u.y;
	return *this;
}

Vector2& Vector2::operator-= (const Vector2& u) {
	this->x -= u.x;
	this->y -= u.y;
	return *this;
}

Vector2& Vector2::normalize() {
	float len = sqrt(dot(*this, *this));

	this->x /= len;
	this->y /= len;

	return *this;
}

//------------Vector4--------------
Vector4::Vector4(float x, float y, float z, float w) 
	: x(x), y(y), z(z), w(w) {
}

Vector4::Vector4() 
	: x(0), y(0), z(0), w(0) {
}
