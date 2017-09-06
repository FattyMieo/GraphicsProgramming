// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "vector3.h"

using namespace std;

void PrintVector3(Vector3 v)
{
	cout << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

void ScanVector3(Vector3& v)
{
	cin >> v.x >> v.y >> v.z;
}

int main()
{
	Vector3 v1, v2;

	cout << "|===========================|" << endl;
	cout << "| Custom Vector3 Class Demo |" << endl;
	cout << "|===========================|" << endl;
	cout << endl;

	cout << "v1 = ";
	ScanVector3(v1);
	cout << "v2 = ";
	ScanVector3(v2);

	cout << endl;

	cout << "Magnitude of v1 = " << v1.GetMagnitude() << endl;
	cout << "Magnitude of v2 = " << v2.GetMagnitude() << endl;

	cout << endl;

	cout << "Normalized v1 = ";
	PrintVector3(v1.GetNormalized());
	cout << endl;
	cout << "Normalized v2 = ";
	PrintVector3(v2.GetNormalized());
	cout << endl;

	cout << endl;

	cout << "v1 + v2 = ";
	PrintVector3(v1 + v2);
	cout << endl;
	cout << "v1 - v2 = ";
	PrintVector3(v1 - v2);
	cout << endl;
	cout << "v1 * 2 = ";
	PrintVector3(v1 * 2);
	cout << endl;
	cout << "v1 / 2 = ";
	PrintVector3(v1 / 2);
	cout << endl;

	cout << endl;

	cout << "v1 . v2 = " << v1.Dot(v2) << endl;

	cout << endl;

	cout << "v1 x v2 = ";
	PrintVector3(v1.Cross(v2));
	cout << endl;

	cout << endl;

	system("PAUSE");
    return 0;
}

