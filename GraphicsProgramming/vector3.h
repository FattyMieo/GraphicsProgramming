#pragma once
// Include guard
#ifndef _VECTOR3_H_
#define _VECTOR3_H_

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
	Vector3 operator+(const Vector3& v);
	Vector3 operator-(const Vector3& v);
	Vector3 operator*(const float f);
	Vector3 operator/(const float f);
};

Vector3 operator*(const float i, const Vector3& v);
Vector3 operator/(const float i, const Vector3& v);

#endif // _VECTOR3_H_