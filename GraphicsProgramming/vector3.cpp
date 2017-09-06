#include "stdafx.h"
#include "vector3.h"

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

//Functions
Vector3 Vector3::Zero()
{
	return Vector3(0, 0, 0);
}

Vector3 Vector3::Add(const Vector3& v)
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::Multiply(const float f)
{
	return Vector3(x * f, y * f, z * f);
}

float Vector3::GetMagnitude()
{
	return sqrt(x*x + y*y + z*z);
}

Vector3 Vector3::GetNormalized()
{
	float m = GetMagnitude();
	if (m <= 1) return Zero();
	return Vector3(x / m, y / m, z / m);
}

void Vector3::Normalize()
{
	float m = GetMagnitude();
	if (m <= 1) return;
	x /= m;
	y /= m;
	z /= m;
}

float Vector3::Dot(const Vector3& v)
{
	return (x * v.x) + (y * v.y) + (z * v.z);
}

Vector3 Vector3::Cross(const Vector3& v)
{
	return Vector3(y * v.z - z *  v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

//Overloadings
Vector3 Vector3::operator+(const Vector3& v)
{
	return Add(v);
}

Vector3 Vector3::operator-(const Vector3& v)
{
	return Add(-v);
}

Vector3 Vector3::operator*(const float f)
{
	return Multiply(f);
}

Vector3 Vector3::operator/(const float f)
{
	return Multiply(1/f);
}

Vector3 operator*(const float i, Vector3& v)
{
	return v.Multiply(i);
}

Vector3 operator/(const float i, Vector3& v)
{
	return v.Multiply(1/i);
}

Vector3 operator-(const Vector3& v)
{
	return Vector3(-v.x, -v.y, -v.z);
}