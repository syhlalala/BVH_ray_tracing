#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "pnt.h"
#include "line.h"
#include "attribute.h"

class Triangle {
public:
	//三角形坐标
	Vector3 a, b, c;
	//贴图坐标
	Vector3 ta, tb, tc;
	//属性
	Attribute attr;
	//重心
	float x, y, z;

	Triangle (const Vector3& a, const Vector3& b, const Vector3& c);
	Triangle (const Vector3& a, const Vector3& b, const Vector3& c, const Vector3& ta, const Vector3& tb, const Vector3& tc);
	Triangle (const Vector3& a, const Vector3& b, const Vector3& c, const Vector3& ta, const Vector3& tb, const Vector3& tc, const Attribute& attr);

	bool intersect(const Line3& line, Vector3& result) const;

	//获得重心坐标
	bool intersect(const Line3& line, Vector4& result) const;
	//通过中心坐标获得交点
	Vector3 get_intersect_point(const Vector4& point) const;
	//通过中心坐标获得贴图坐标
	Vector3 get_texture_point(const Vector4& point) const;
private:
};

#endif //__TRIANGLE_H__
