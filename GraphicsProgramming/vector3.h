#pragma once
// Include guard
#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include <cmath>

class Vector3
{
public:
	//Variables
	float x;
	float y;
	float z;

	//Constructors
	Vector3();
	Vector3(float _x, float _y, float _z);

	//Functions
	static Vector3 Zero();
	Vector3 Add(const Vector3& v);
	Vector3 Multiply(const float f);
	float GetMagnitude();
	Vector3 GetNormalized();
	void Normalize();
	float Dot(const Vector3& v);
	Vector3 Cross(const Vector3& v);

	//Overloadings
	Vector3 operator+(const Vector3& v);
	Vector3 operator-(const Vector3& v);
	Vector3 operator*(const float f);
	Vector3 operator/(const float f);
};

Vector3 operator*(const float i, const Vector3& v);
Vector3 operator/(const float i, const Vector3& v);

Vector3 operator-(const Vector3& v);

#endif // _VECTOR3_H_