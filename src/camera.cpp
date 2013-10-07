#include "camera.h"
#include <cstdio>

Camera::Camera(const Vector3 start, const Vector3 directX, const Vector3 directY, const int w, const int h):
	startPoint(start), dX(directX), dY(directY), dZ(0, 0, 0), width(w), height(h)
{
	dX.normalize();
	dY.normalize();
	dZ = det(dX, dY);
	dZ.normalize();
	dX = dX * 0.01;
	dY = dY * 0.01;
	focalLength = 100;
}
Line3 Camera::getSight(int x, int y){
	Vector3 destX = dX * float(x - this->width / 2);
	Vector3 destY = dY * float(y - this->height / 2);
	Vector3 destZ = dZ * focalLength;
	Vector3 to = destX + destY + destZ;
	return Line3(startPoint, to);
	//return Line3(Vector3(float(x - this->width / 2) / 10, float(y - this->height / 2)/ 10, 0) , Vector3(0, 0, 1));
}
void Camera::setFocalLen(float len){
	focalLength = len;
}
