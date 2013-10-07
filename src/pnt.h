#ifndef __PNT_H__
#define __PNT_H__

class Vector3 {
public:
	float x, y, z;

	Vector3(float x, float y, float z);
	Vector3();

	//点积
	friend float dot(const Vector3& u, const Vector3& v);
	//叉积
	friend Vector3 det(const Vector3& u, const Vector3& v);
	friend float det(const Vector3& u, const Vector3& v, const Vector3& w);
	friend Vector3 operator+ (const Vector3& u, const Vector3& v);
	friend Vector3 operator- (const Vector3& u, const Vector3& v);
	friend Vector3 operator* (const Vector3& u, float x);
	friend float dist(const Vector3 &u, const Vector3 &v);
	Vector3& operator+= (const Vector3& u);
	Vector3& operator-= (const Vector3& u);


	Vector3& normalize();

private:
};

class Vector2 {
public:
	float x, y;
	
	Vector2(float x, float y);
	Vector2();

	//点积
	friend float dot(const Vector2& u, const Vector2& v);
	//叉积
	friend float det(const Vector2& u, const Vector2& v);
	friend Vector2 operator+ (const Vector2& u, const Vector2& v);
	friend Vector2 operator- (const Vector2& u, const Vector2& v);
	friend float dist(const Vector2 &u, const Vector2 &v);
	Vector2& operator+= (const Vector2& u);
	Vector2& operator-= (const Vector2& u);

	Vector2& normalize();

private:
};

class Vector4 {
public:
	float x, y, z, w;

	Vector4(float x, float y, float z, float w);
	Vector4();

private:
};

#endif //__PNT_H__
