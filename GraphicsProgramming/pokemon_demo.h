#ifndef _POKEMON_DEMO_H
#define _POKEMON_DEMO_H

#include "demo_base.h"

class PokemonDemo : public DemoBase
{
public:
	void init()
	{
	}

	void deinit()
	{
	}

	void drawAxis(const Matrix& viewMatrix)
	{
		glLoadMatrixf((GLfloat*)viewMatrix.mVal);
		glBegin(GL_LINES);

		glColor3f(1.0f, 0.3f, 0.3f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);

		glColor3f(0.3f, 1.0f, 0.3f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);

		glColor3f(0.3f, 0.3f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 1.0f);

		glEnd();
	}
	//Sphere
	class Vertex
	{
	public:
		float x;
		float y;
		float z;

		Vertex()
		{
			x = 0;
			y = 0;
			z = 0;
		}

		Vertex(float a, float b, float c)
		{
			x = a;
			y = b;
			z = c;
		}
	};


	Vertex SphereFunction(float u, float v, float radius)
	{
		u = u * 3.142f / 180.0f;
		v = v * 3.142f / 180.0f;
		Vertex answer;
		answer.x = cos(u) * sin(v) * radius;
		answer.y = cos(v) * radius;
		answer.z = sin(u) * sin(v) * radius;
		return answer;
	}

	void drawSphere(float startU, float startV, float endU, float endV, float radius, float UResolution, float VResolution, float xFactor, float yFactor)
	{
		float stepU = (endU - startU) / UResolution;
		float stepV = (endV - startV) / VResolution;
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < UResolution; i++)
		{
			for (int j = 0; j < VResolution; j++)
			{
				float u = i*stepU + startU;
				float v = j*stepV + startV;
				float un = (i + 1 == UResolution) ? endU : (i + 1)*stepU + startU;
				float vn = (j + 1 == VResolution) ? endV : (j + 1)*stepV + startV;

				Vertex p0 = SphereFunction(u, v, radius);
				Vertex p1 = SphereFunction(u, vn, radius);
				Vertex p2 = SphereFunction(un, v, radius);
				Vertex p3 = SphereFunction(un, vn, radius);

				glVertex3f(p0.x*xFactor, p0.y*yFactor, p0.z);
				glVertex3f(p2.x*xFactor, p2.y*yFactor, p2.z);
				glVertex3f(p1.x*xFactor, p1.y*yFactor, p1.z);

				glVertex3f(p3.x*xFactor, p3.y*yFactor, p3.z);
				glVertex3f(p1.x*xFactor, p1.y*yFactor, p1.z);
				glVertex3f(p2.x*xFactor, p2.y*yFactor, p2.z);
			}
		}
		glEnd();
	}
	
	//void drawPTriangle(float x, float y, float z, float size, float iteration, float offsetAngle = 0.0f)
	//{
	//	float initialOffsetAngle = 90.0f;
	//	float diffAngle = 120.0f;

	//	if (iteration > 1)
	//	{
	//		drawPTriangle(x, y, z, size / 2.0f, iteration - 1, offsetAngle + 180.0f);

	//		//glBegin(GL_TRIANGLES);
	//		for (int t = 0; t < 3; t++)
	//		{
	//			float dx = x + (size / 2.0f * cosf((diffAngle * t + (offsetAngle + initialOffsetAngle)) * PI / 180.0f));
	//			float dy = x + (size / 2.0f * sinf((diffAngle * t + (offsetAngle + initialOffsetAngle)) * PI / 180.0f));

	//			//glVertex3f(dx, dy, z);
	//			drawPTriangle(dx, dy, z, size / 2.0f, iteration - 1, offsetAngle);
	//		}
	//		//glEnd();
	//	}
	//	else
	//	{
	//		drawETriangle(x, y, z, size, offsetAngle);
	//	}
	//}

	//void drawETriangle(float x, float y, float z, float size, float offsetAngle = 0.0f)
	//{
	//	float initialOffsetAngle = 90.0f;
	//	float diffAngle = 120.0f;

	//	glBegin(GL_TRIANGLES);

	//	for (int t = 0; t < 3; t++)
	//	{
	//		float dx = x + (size * cosf((diffAngle * t + (offsetAngle + initialOffsetAngle)) * PI / 180.0f));
	//		float dy = x + (size * sinf((diffAngle * t + (offsetAngle + initialOffsetAngle)) * PI / 180.0f));

	//		glVertex3f(dx, dy, z);
	//	}

	//	glEnd();
	//}

	void drawCube(float size = 1.0f)
	{
		size /= 2.0f;
		glBegin(GL_TRIANGLES);

		// Negative Square
		glVertex3f(-size, size, -size);
		glVertex3f(-size, -size, -size);
		glVertex3f(size, -size, -size);

		glVertex3f(-size, size, -size);
		glVertex3f(size, size, -size);
		glVertex3f(size, -size, -size);

		// Positive Square
		glVertex3f(-size, size, size);
		glVertex3f(-size, -size, size);
		glVertex3f(size, -size, size);

		glVertex3f(-size, size, size);
		glVertex3f(size, size, size);
		glVertex3f(size, -size, size);

		// Negative Square
		glVertex3f(size, -size, -size);
		glVertex3f(-size, -size, -size);
		glVertex3f(-size, -size, size);

		glVertex3f(size, -size, -size);
		glVertex3f(size, -size, size);
		glVertex3f(-size, -size, size);

		// Positive Square
		glVertex3f(size, size, -size);
		glVertex3f(-size, size, -size);
		glVertex3f(-size, size, size);

		glVertex3f(size, size, -size);
		glVertex3f(size, size, size);
		glVertex3f(-size, size, size);

		// Negative Square
		glVertex3f(-size, -size, size);
		glVertex3f(-size, -size, -size);
		glVertex3f(-size, size, -size);

		glVertex3f(-size, -size, size);
		glVertex3f(-size, size, size);
		glVertex3f(-size, size, -size);

		// Positive Square
		glVertex3f(size, -size, size);
		glVertex3f(size, -size, -size);
		glVertex3f(size, size, -size);

		glVertex3f(size, -size, size);
		glVertex3f(size, size, size);
		glVertex3f(size, size, -size);

		glEnd();										// Finished Drawing The Triangles
	}

	void drawCuboid(float x, float y, float z)
	{
		x /= 2.0f;
		y /= 2.0f;
		z /= 2.0f;
		glBegin(GL_TRIANGLES);

		// Negative Square
		glVertex3f(-x, y, -z);
		glVertex3f(-x, -y, -z);
		glVertex3f(x, -y, -z);

		glVertex3f(-x, y, -z);
		glVertex3f(x, y, -z);
		glVertex3f(x, -y, -z);

		// Positive Square
		glVertex3f(-x, y, z);
		glVertex3f(-x, -y, z);
		glVertex3f(x, -y, z);

		glVertex3f(-x, y, z);
		glVertex3f(x, y, z);
		glVertex3f(x, -y, z);

		// Negative Square
		glVertex3f(x, -y, -z);
		glVertex3f(-x, -y, -z);
		glVertex3f(-x, -y, z);

		glVertex3f(x, -y, -z);
		glVertex3f(x, -y, z);
		glVertex3f(-x, -y, z);

		// Positive Square
		glVertex3f(x, y, -z);
		glVertex3f(-x, y, -z);
		glVertex3f(-x, y, z);

		glVertex3f(x, y, -z);
		glVertex3f(x, y, z);
		glVertex3f(-x, y, z);

		// Negative Square
		glVertex3f(-x, -y, z);
		glVertex3f(-x, -y, -z);
		glVertex3f(-x, y, -z);

		glVertex3f(-x, -y, z);
		glVertex3f(-x, y, z);
		glVertex3f(-x, y, -z);

		// Positive Square
		glVertex3f(x, -y, z);
		glVertex3f(x, -y, -z);
		glVertex3f(x, y, -z);

		glVertex3f(x, -y, z);
		glVertex3f(x, y, z);
		glVertex3f(x, y, -z);

		glEnd();										// Finished Drawing The Triangles
	}

	void drawPyramid(float size = 1.0f)
	{
		size /= 2.0f;
		glBegin(GL_TRIANGLES);							// Drawing Using Triangles

														// Base
		glVertex3f(size, -size, size);					// Top
		glVertex3f(size, -size, -size);					// Bottom Left
		glVertex3f(-size, -size, size);					// Bottom Right

		glVertex3f(-size, -size, -size);				// Top
		glVertex3f(size, -size, -size);					// Bottom Left
		glVertex3f(-size, -size, size);					// Bottom Right

														// Red Triangles
		glVertex3f(0.0f, size, 0.0f);					// Top Vertex
		glVertex3f(size, -size, -size);					// Bottom Left
		glVertex3f(size, -size, size);					// Bottom Right

		glVertex3f(0.0f, size, 0.0f);					// Top Vertex
		glVertex3f(-size, -size, -size);				// Bottom Left
		glVertex3f(-size, -size, size);					// Bottom Right

														// Blue Triangles
		glVertex3f(0.0f, size, 0.0f);					// Top Vertex
		glVertex3f(-size, -size, size);					// Bottom Left
		glVertex3f(size, -size, size);					// Bottom Right

		glVertex3f(0.0f, size, 0.0f);					// Top Vertex
		glVertex3f(-size, -size, -size);				// Bottom Left
		glVertex3f(size, -size, -size);					// Bottom Right

		glEnd();										// Finished Drawing The Triangles
	}

	void drawCylinder(float height, float radius, int iteration = 100) //Change iteration to steps
	{
		//Offset
		float offsetX = 0.0f;
		float offsetY = 0.0f;
		float offsetZ = 0.0f;
		float halfHeight = height / 2.0f;

		glBegin(GL_TRIANGLES);							// Drawing Using Triangles

		float t = 360.0f / iteration;

		for (int i = 0; i < iteration; i++)
		{
			float x1 = radius * cos((i * t) * PI / 180.0);
			float z1 = radius * sin((i * t) * PI / 180.0);

			float x2 = radius * cos(((i + 1) * t) * PI / 180.0);
			float z2 = radius * sin(((i + 1) * t) * PI / 180.0);

			// ---- Upper Circle ----
			//Center of the circle
			glVertex3f(offsetX, offsetY + halfHeight, offsetZ);

			//First point
			glVertex3f(x1, offsetY + halfHeight, z1);

			//Second point
			glVertex3f(x2, offsetY + halfHeight, z2);

			// ---- Lower Circle ----
			//Center of the circle
			glVertex3f(offsetX, offsetY - halfHeight, offsetZ);

			//First point
			glVertex3f(x1, offsetY - halfHeight, z1);

			//Second point
			glVertex3f(x2, offsetY - halfHeight, z2);

			// ---- Upper Triangle ----
			//First point
			glVertex3f(x1, offsetY + halfHeight, z1);

			//Second point
			glVertex3f(x2, offsetY + halfHeight, z2);

			//Third point
			glVertex3f(x1, offsetY - halfHeight, z1);

			// ---- Lower Triangle ----
			//First point
			glVertex3f(x1, offsetY - halfHeight, z1);

			//Second point
			glVertex3f(x2, offsetY - halfHeight, z2);

			//Third point
			glVertex3f(x2, offsetY + halfHeight, z2);
		}

		glEnd();										// Finished Drawing The Triangles
	}

	void drawCone(float height, float radius, int iteration = 100)
	{
		//Offset
		float offsetX = 0.0f;
		float offsetY = 0.0f;
		float offsetZ = 0.0f;
		float halfHeight = height / 2.0f;

		glBegin(GL_TRIANGLES);							// Drawing Using Triangles

		float t = 360.0f / iteration;

		for (int i = 0; i < iteration; i++)
		{
			float x1 = radius * cos((i * t) * PI / 180.0);
			float z1 = radius * sin((i * t) * PI / 180.0);

			float x2 = radius * cos(((i + 1) * t) * PI / 180.0);
			float z2 = radius * sin(((i + 1) * t) * PI / 180.0);

			// ---- Circle ----
			//Center of the circle
			glVertex3f(offsetX, offsetY - halfHeight, offsetZ);

			//First point
			glVertex3f(x1, offsetY - halfHeight, z1);

			//Second point
			glVertex3f(x2, offsetY - halfHeight, z2);

			// ---- Triangle ----
			//Upper vertex
			glVertex3f(offsetX, offsetY + halfHeight, offsetZ);

			//First point
			glVertex3f(x1, offsetY - halfHeight, z1);

			//Second point
			glVertex3f(x2, offsetY - halfHeight, z2);
		}

		glEnd();										// Finished Drawing The Triangles
	}

	Matrix makeTranslationMatrix(float x, float y, float z)
	{
		Matrix tMat = Matrix::makeTranslationMatrix(x, y, -z);

		return tMat;
	}

	Matrix makeEulerRotateMatrix(float x, float y, float z)
	{
		Matrix xMat = Matrix::makeRotateMatrix(x, Vector(1.0f, 0.0f, 0.0f));
		Matrix yMat = Matrix::makeRotateMatrix(y, Vector(0.0f, 1.0f, 0.0f));
		Matrix zMat = Matrix::makeRotateMatrix(z, Vector(0.0f, 0.0f, 1.0f));

		Matrix cMat = yMat * xMat * zMat;
		cMat.mVal[0][2] = -cMat.mVal[0][2];
		cMat.mVal[1][2] = -cMat.mVal[1][2];
		cMat.mVal[2][0] = -cMat.mVal[2][0];
		cMat.mVal[2][1] = -cMat.mVal[2][1];

		return cMat;
	}

	float earAngle = 30.0f;
	bool earDir = true;

	float tailAngle = 0.0f;
	bool tailDir = true;

	float bodyAngle = 0.0f;
	bool bodyDir = true;

	float bodyScale = 1.0f;
	bool bodyScaleDir = true;

	void draw(const Matrix& viewMatrix)
	{
		drawAxis(viewMatrix);

		glLoadMatrixf((GLfloat*)viewMatrix.mVal);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Show Wireframes

		float radius = 1.0f;

		//drawPTriangle(0, 0, 0, radius, 3);

		// New version of Pikachu, bugged
		//Matrix tBody = makeTranslationMatrix(0.0f, -0.75f, 0.0f);
		//Matrix rBody = makeEulerRotateMatrix(0.0f, 30.0f, -10.0f);
		//Matrix sBody = Matrix::makeScaleMatrix(1.0f, 0.25f, 1.0f);
		//Matrix mBody = rBody * sBody * tBody;

		//	Matrix tUpperBody = makeTranslationMatrix(0.0f, 1.0f, 0.0f);
		//	Matrix rUpperBody = makeEulerRotateMatrix(0.0f, 0.0f, 0.0f);
		//	Matrix sUpperBody = Matrix::makeScaleMatrix(1.0f, 4.0f, 1.0f);
		//	Matrix mUpperBody = mBody * rUpperBody * sUpperBody * tUpperBody;

		//		Matrix tHeadJoint = makeTranslationMatrix(0.1f, 0.375f, 0.0f);
		//		Matrix rHeadJoint = makeEulerRotateMatrix(-2.0f, -5.0f, 7.5f);
		//		Matrix sHeadJoint = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
		//		Matrix mHeadJoint = mUpperBody * rHeadJoint * sHeadJoint * tHeadJoint;

		//			Matrix tNeck = makeTranslationMatrix(-0.15f, 0.05f, 0.0f);
		//			Matrix rNeck = makeEulerRotateMatrix(0.0f, 0.0f, -10.0f);
		//			Matrix sNeck = Matrix::makeScaleMatrix(0.75f, 0.2f, 0.8f);
		//			Matrix mNeck = mHeadJoint * rNeck * sNeck * tNeck;

		//			Matrix tHead = makeTranslationMatrix(0.0f, 0.375f+1.0f, 0.0f);
		//			Matrix rHead = makeEulerRotateMatrix(0.0f, 0.0f, 0.0f);
		//			Matrix sHead = Matrix::makeScaleMatrix(1.0f, 0.85f, 1.0f);
		//			Matrix mHead = mHeadJoint * rHead * sHead * tHead;

		//				Matrix tLEarJoint = makeTranslationMatrix(0.0f, 0.3f, -0.25f);
		//				Matrix rLEarJoint = makeEulerRotateMatrix(17.0f, 12.5f, 2.5f);
		//				Matrix sLEarJoint = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
		//				Matrix mLEarJoint = mHead * rLEarJoint * sLEarJoint * tLEarJoint;

		//					Matrix tLEar = makeTranslationMatrix(0.0f, 0.35f+1.0f, -0.2f);
		//					Matrix rLEar = makeEulerRotateMatrix(-30.0f, 15.0f, 0.0f);
		//					Matrix sLEar = Matrix::makeScaleMatrix(0.25f, 1.0f, 0.15f);
		//					Matrix mLEar = mLEarJoint * rLEar * sLEar * tLEar;

		//						Matrix tLEarTip = makeTranslationMatrix(0.05f, 0.25f-1.0f, 0.0f);
		//						Matrix rLEarTip = makeEulerRotateMatrix(0.0f, 0.0f, -10.0f);
		//						Matrix sLEarTip = Matrix::makeScaleMatrix(1.85f-0.85f, 1.0f, 1.85f-0.85f);
		//						Matrix mLEarTip = mLEar * rLEarTip * sLEarTip * tLEarTip;

		//				Matrix tREarJoint = makeTranslationMatrix(0.0f, 0.3f, 0.25f);
		//				Matrix rREarJoint = makeEulerRotateMatrix(-10.0f, 40.5f, 50.0f);
		//				Matrix sREarJoint = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
		//				Matrix mREarJoint = mHead * rREarJoint * sREarJoint * tREarJoint;

		//					Matrix tREar = makeTranslationMatrix(0.0f, 0.35f+1.0f, -0.2f);
		//					Matrix rREar = makeEulerRotateMatrix(30.0f, -15.0f, 0.0f);
		//					Matrix sREar = Matrix::makeScaleMatrix(0.25f, 1.0f, 0.15f);
		//					Matrix mREar = mREarJoint * rREar * sREar * tREar;

		//						Matrix tREarTip = makeTranslationMatrix(0.05f, 0.25f-1.0f, 0.0f);
		//						Matrix rREarTip = makeEulerRotateMatrix(0.0f, 0.0f, -10.0f);
		//						Matrix sREarTip = Matrix::makeScaleMatrix(1.85f-0.85f, 1.0f, 1.85f-0.85f);
		//						Matrix mREarTip = mREar * rREarTip * sREarTip * tREarTip;

		//				Matrix tLEyeJoint = makeTranslationMatrix(0.0f, 0.0f, 0.0f);
		//				Matrix rLEyeJoint = makeEulerRotateMatrix(-10.0f, 25.5f, 25.0f);
		//				Matrix sLEyeJoint = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
		//				Matrix mLEyeJoint = mHead * rLEyeJoint * sLEyeJoint * tLEyeJoint;

		//					Matrix tLEye = makeTranslationMatrix(0.49f, 0.0f, 0.0f);
		//					Matrix rLEye = makeEulerRotateMatrix(0.0f, 0.0f, -90.0f);
		//					Matrix sLEye = Matrix::makeScaleMatrix(0.2f, 0.075f, 0.15f);
		//					Matrix mLEye = mLEyeJoint * rLEye * sLEye * tLEye;

		//					Matrix tLEyeballJoint = makeTranslationMatrix(0.0f, 0.0f, 0.0f);
		//					Matrix rLEyeballJoint = makeEulerRotateMatrix(0.0f, 0.0f, 3.0f);
		//					Matrix sLEyeballJoint = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
		//					Matrix mLEyeballJoint = mLEyeJoint * rLEyeballJoint * sLEyeballJoint * tLEyeballJoint;

		//						Matrix tLEyeball = makeTranslationMatrix(0.525f, 0.0025f, 0.0f);
		//						Matrix rLEyeball = makeEulerRotateMatrix(0.0f, 0.0f, -90.0f);
		//						Matrix sLEyeball = Matrix::makeScaleMatrix(0.075f, 0.025f, 0.05f);
		//						Matrix mLEyeball = mLEyeballJoint * rLEyeball * sLEyeball * tLEyeball;

		//				Matrix tREyeJoint = makeTranslationMatrix(0.0f, 0.0f, 0.0f);
		//				Matrix rREyeJoint = makeEulerRotateMatrix(10.0f, -25.5f, 25.0f);
		//				Matrix sREyeJoint = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
		//				Matrix mREyeJoint = mHead * rREyeJoint * sREyeJoint * tREyeJoint;

		//					Matrix tREye = makeTranslationMatrix(0.49f, 0.0f, 0.0f);
		//					Matrix rREye = makeEulerRotateMatrix(0.0f, 0.0f, -90.0f);
		//					Matrix sREye = Matrix::makeScaleMatrix(0.2f, 0.075f, 0.15f);
		//					Matrix mREye = mREyeJoint * rREye * sREye * tREye;

		//					Matrix tREyeballJoint = makeTranslationMatrix(0.0f, 0.0f, 0.0f);
		//					Matrix rREyeballJoint = makeEulerRotateMatrix(0.0f, 0.0f, 3.0f);
		//					Matrix sREyeballJoint = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
		//					Matrix mREyeballJoint = mREyeJoint * rREyeballJoint * sREyeballJoint * tREyeballJoint;

		//						Matrix tREyeball = makeTranslationMatrix(0.525f, 0.0025f, 0.0f);
		//						Matrix rREyeball = makeEulerRotateMatrix(0.0f, 0.0f, -90.0f);
		//						Matrix sREyeball = Matrix::makeScaleMatrix(0.075f, 0.025f, 0.05f);
		//						Matrix mREyeball = mREyeballJoint * rREyeball * sREyeball * tREyeball;

		//				Matrix tNoseJoint = makeTranslationMatrix(0.0f, 0.0f, 0.0f);
		//				Matrix rNoseJoint = makeEulerRotateMatrix(0.0f, 0.0f, 12.5f);
		//				Matrix sNoseJoint = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
		//				Matrix mNoseJoint = mHead * rNoseJoint * sNoseJoint * tNoseJoint;

		//					Matrix tNose = makeTranslationMatrix(0.499f, 0.0f, 0.0f);
		//					Matrix rNose = makeEulerRotateMatrix(0.0f, 0.0f, -90.0f);
		//					Matrix sNose = Matrix::makeScaleMatrix(0.02353f, 0.02f, 0.02f);
		//					Matrix mNose = mNoseJoint * rNose * sNose * tNose;

		//				Matrix tLCheekJoint = makeTranslationMatrix(0.0f, 0.0f, 0.0f);
		//				Matrix rLCheekJoint = makeEulerRotateMatrix(0.0f, 35.0f, -10.0f);
		//				Matrix sLCheekJoint = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
		//				Matrix mLCheekJoint = mHead * rLCheekJoint * sLCheekJoint * tLCheekJoint;

		//					Matrix tLCheek = makeTranslationMatrix(0.48f, 0.0f, 0.0f);
		//					Matrix rLCheek = makeEulerRotateMatrix(0.0f, 0.0f, -90.0f);
		//					Matrix sLCheek = Matrix::makeScaleMatrix(0.2353f, 0.1f, 0.2f);
		//					Matrix mLCheek = mLCheekJoint * rLCheek * sLCheek * tLCheek;

		//				Matrix tRCheekJoint = makeTranslationMatrix(0.0f, 0.0f, 0.0f);
		//				Matrix rRCheekJoint = makeEulerRotateMatrix(0.0f, -35.0f, -10.0f);
		//				Matrix sRCheekJoint = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
		//				Matrix mRCheekJoint = mHead * rRCheekJoint * sRCheekJoint * tRCheekJoint;

		//					Matrix tRCheek = makeTranslationMatrix(0.48f, 0.0f, 0.0f);
		//					Matrix rRCheek = makeEulerRotateMatrix(0.0f, 0.0f, -90.0f);
		//					Matrix sRCheek = Matrix::makeScaleMatrix(0.2353f, 0.1f, 0.2f);
		//					Matrix mRCheek = mRCheekJoint * rRCheek * sRCheek * tRCheek;

		//				Matrix tMouthJoint = makeTranslationMatrix(0.0f, 0.0f, 0.0f);
		//				Matrix rMouthJoint = makeEulerRotateMatrix(0.0f, 0.0f, -10.0f);
		//				Matrix sMouthJoint = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
		//				Matrix mMouthJoint = mHead * rMouthJoint * sMouthJoint * tMouthJoint;

		//					Matrix tMouth = makeTranslationMatrix(0.48f, 0.15f, 0.0f);
		//					Matrix rMouth = makeEulerRotateMatrix(180.0f, 0.0f, -5.0f);
		//					Matrix sMouth = Matrix::makeScaleMatrix(0.025f, 0.5f, 0.25f);
		//					Matrix mMouth = mMouthJoint * rMouth * sMouth * tMouth;

		//					Matrix tTongueJoint = makeTranslationMatrix(0.0f, 0.0f, 0.0f);
		//					Matrix rTongueJoint = makeEulerRotateMatrix(0.0f, 0.0f, 4.5f);
		//					Matrix sTongueJoint = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
		//					Matrix mTongueJoint = mMouthJoint * rTongueJoint * sTongueJoint * tTongueJoint;

		//						Matrix tTongue = makeTranslationMatrix(0.5f, -0.065f, 0.0f);
		//						Matrix rTongue = makeEulerRotateMatrix(0.0f, 0.0f, -2.5f);
		//						Matrix sTongue = Matrix::makeScaleMatrix(0.025f, 0.15f, 0.15425f);
		//						Matrix mTongue = mTongueJoint * rTongue * sTongue * tTongue;

		//	Matrix tLHandJoint = makeTranslationMatrix(0.065f, 0.2f, -0.4f);
		//	Matrix rLHandJoint = makeEulerRotateMatrix(-25.0f, 30.0f, 20.0f);
		//	Matrix sLHandJoint = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
		//	Matrix mLHandJoint = mUpperBody * rLHandJoint * sLHandJoint * tLHandJoint;

		//		Matrix tLHand = makeTranslationMatrix(0.1f, 0.0f, 0.0f);
		//		Matrix rLHand = makeEulerRotateMatrix(90.0f, 0.0f, 90.0f);
		//		Matrix sLHand = Matrix::makeScaleMatrix(0.25f, 0.2f, 0.25f);
		//		Matrix mLHand = mLHandJoint * rLHand * sLHand * tLHand;

		//			Matrix tLHandPalm = makeTranslationMatrix(0.0f, -1.0f, 0.0f);
		//			Matrix rLHandPalm = makeEulerRotateMatrix(180.0f, 0.0f, 0.0f);
		//			Matrix sLHandPalm = Matrix::makeScaleMatrix(1.0f, 2.0f, 1.0f);
		//			Matrix mLHandPalm = mLHand * rLHandPalm * sLHandPalm * tLHandPalm;

		//				Matrix tLNail1 = makeTranslationMatrix(0.3f, 0.3f, 0.0f);
		//				Matrix rLNail1 = makeEulerRotateMatrix(30.0f, 0.0f, -30.0f);
		//				Matrix sLNail1 = Matrix::makeScaleMatrix(0.5f, 0.5f, 0.5f);
		//				Matrix mLNail1 = mLHandPalm * rLNail1 * sLNail1 * tLNail1;

		//				Matrix tLNail2 = makeTranslationMatrix(-0.3f, 0.3f, 0.0f);
		//				Matrix rLNail2 = makeEulerRotateMatrix(30.0f, 0.0f, 30.0f);
		//				Matrix sLNail2 = Matrix::makeScaleMatrix(0.5f, 0.5f, 0.5f);
		//				Matrix mLNail2 = mLHandPalm * rLNail2 * sLNail2 * tLNail2;

		//				Matrix tLNail3 = makeTranslationMatrix(-0.15f, 0.3f, 0.25f);
		//				Matrix rLNail3 = makeEulerRotateMatrix(60.0f, 0.0f, 15.0f);
		//				Matrix sLNail3 = Matrix::makeScaleMatrix(0.5f, 0.5f, 0.5f);
		//				Matrix mLNail3 = mLHandPalm * rLNail3 * sLNail3 * tLNail3;

		//				Matrix tLNail4 = makeTranslationMatrix(0.15f, 0.3f, 0.25f);
		//				Matrix rLNail4 = makeEulerRotateMatrix(60.0f, 0.0f, -15.0f);
		//				Matrix sLNail4 = Matrix::makeScaleMatrix(0.5f, 0.5f, 0.5f);
		//				Matrix mLNail4 = mLHandPalm * rLNail4 * sLNail4 * tLNail4;

		//	Matrix tRHandJoint = makeTranslationMatrix(0.065f, 0.2f, -0.4f);
		//	Matrix rRHandJoint = makeEulerRotateMatrix(30.0f, -1.5f, 35.0f);
		//	Matrix sRHandJoint = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
		//	Matrix mRHandJoint = mUpperBody * rRHandJoint * sRHandJoint * tRHandJoint;

		//		Matrix tRHand = makeTranslationMatrix(0.1f, 0.0f, 0.0f);
		//		Matrix rRHand = makeEulerRotateMatrix(90.0f, 0.0f, 90.0f);
		//		Matrix sRHand = Matrix::makeScaleMatrix(0.25f, 0.2f, 0.25f);
		//		Matrix mRHand = mRHandJoint * rRHand * sRHand * tRHand;
		//
		//			Matrix tRHandPalm = makeTranslationMatrix(0.0f, -1.0f, 0.0f);
		//			Matrix rRHandPalm = makeEulerRotateMatrix(180.0f, 0.0f, 0.0f);
		//			Matrix sRHandPalm = Matrix::makeScaleMatrix(1.0f, 2.0f, 1.0f);
		//			Matrix mRHandPalm = mRHand * rRHandPalm * sRHandPalm * tRHandPalm;

		//				Matrix tRNail1 = makeTranslationMatrix(0.3f, 0.3f, 0.0f);
		//				Matrix rRNail1 = makeEulerRotateMatrix(30.0f, 0.0f, -30.0f);
		//				Matrix sRNail1 = Matrix::makeScaleMatrix(0.5f, 0.5f, 0.5f);
		//				Matrix mRNail1 = mRHandPalm * rRNail1 * sRNail1 * tRNail1;

		//				Matrix tRNail2 = makeTranslationMatrix(-0.3f, 0.3f, 0.0f);
		//				Matrix rRNail2 = makeEulerRotateMatrix(30.0f, 0.0f, 30.0f);
		//				Matrix sRNail2 = Matrix::makeScaleMatrix(0.5f, 0.5f, 0.5f);
		//				Matrix mRNail2 = mRHandPalm * rRNail2 * sRNail2 * tRNail2;

		//				Matrix tRNail3 = makeTranslationMatrix(-0.15f, 0.3f, 0.25f);
		//				Matrix rRNail3 = makeEulerRotateMatrix(60.0f, 0.0f, 15.0f);
		//				Matrix sRNail3 = Matrix::makeScaleMatrix(0.5f, 0.5f, 0.5f);
		//				Matrix mRNail3 = mRHandPalm * rRNail3 * sRNail3 * tRNail3;

		//				Matrix tRNail4 = makeTranslationMatrix(0.15f, 0.3f, 0.25f);
		//				Matrix rRNail4 = makeEulerRotateMatrix(60.0f, 0.0f, -15.0f);
		//				Matrix sRNail4 = Matrix::makeScaleMatrix(0.5f, 0.5f, 0.5f);
		//				Matrix mRNail4 = mRHandPalm * rRNail4 * sRNail4 * tRNail4;

		//Matrix tLowerBody = makeTranslationMatrix(0.0f, -1.0f, 0.0f);
		//Matrix rLowerBody = makeEulerRotateMatrix(180.0f, 0.0f, 0.0f);
		//Matrix sLowerBody = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
		//Matrix mLowerBody = mBody * rLowerBody * sLowerBody * tLowerBody;

		//	Matrix tLLeg = makeTranslationMatrix(-0.05f, 0.175f, 0.175f);
		//	Matrix rLLeg = makeEulerRotateMatrix(5.0f, 0.0f, 5.0f);
		//	Matrix sLLeg = Matrix::makeScaleMatrix(0.75f, 2.0f, 0.6f);
		//	Matrix mLLeg = mLowerBody * rLLeg * sLLeg * tLLeg;

		//		Matrix tLFootJoint = makeTranslationMatrix(0.125f, 0.35f, 0.0f);
		//		Matrix rLFootJoint = makeEulerRotateMatrix(-6.5f, 6.5f, 45.0f);
		//		Matrix sLFootJoint = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
		//		Matrix mLFootJoint = mLLeg * rLFootJoint * sLFootJoint * tLFootJoint;

		//			Matrix tLFoot = makeTranslationMatrix(0.25f, 0.1f, 0.0f);
		//			Matrix rLFoot = makeEulerRotateMatrix(0.0f, 0.0f, 0.0f);
		//			Matrix sLFoot = Matrix::makeScaleMatrix(1.0f, 0.3f, 0.3f);
		//			Matrix mLFoot = mLFootJoint * rLFoot * sLFoot * tLFoot;

		//	Matrix tRLeg = makeTranslationMatrix(-0.05f, 0.175f, -0.175f);
		//	Matrix rRLeg = makeEulerRotateMatrix(-5.0f, 0.0f, 5.0f);
		//	Matrix sRLeg = Matrix::makeScaleMatrix(0.75f, 2.0f, 0.6f);
		//	Matrix mRLeg = mLowerBody * rRLeg * sRLeg * tRLeg;
		//
		//		Matrix tRFootJoint = makeTranslationMatrix(0.125f, 0.35f, 0.0f);
		//		Matrix rRFootJoint = makeEulerRotateMatrix(-12.5f, 5.0f, 60.0f);
		//		Matrix sRFootJoint = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
		//		Matrix mRFootJoint = mRLeg * rRFootJoint * sRFootJoint * tRFootJoint;

		//			Matrix tRFoot = makeTranslationMatrix(0.25f, 0.1f, 0.0f);
		//			Matrix rRFoot = makeEulerRotateMatrix(0.0f, 0.0f, 0.0f);
		//			Matrix sRFoot = Matrix::makeScaleMatrix(1.0f, 0.3f, 0.3f);
		//			Matrix mRFoot = mRFootJoint * rRFoot * sRFoot * tRFoot;

		//	Matrix tTailJoint = makeTranslationMatrix(-0.375f, 0.0f, 0.0f);
		//	Matrix rTailJoint = makeEulerRotateMatrix(0.0f, -30.0f, -5.0f);
		//	Matrix sTailJoint = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f);
		//	Matrix mTailJoint = mLowerBody * rTailJoint * sTailJoint * tTailJoint;

		//		Matrix tTail1 = makeTranslationMatrix(-0.2f, 0.0f, 0.0f);
		//		Matrix rTail1 = makeEulerRotateMatrix(0.0f, 0.0f, 10.0f);
		//		Matrix sTail1 = Matrix::makeScaleMatrix(0.5f, 1.0f, 0.05f);
		//		Matrix mTail1 = mTailJoint * rTail1 * sTail1 * tTail1;

		//			Matrix tTail2 = makeTranslationMatrix(-0.75f, -0.5f, 0.0f);
		//			Matrix rTail2 = makeEulerRotateMatrix(0.0f, 0.0f, 85.0f);
		//			Matrix sTail2 = Matrix::makeScaleMatrix(2.0f, 0.5f, 1.0f);
		//			Matrix mTail2 = mTail1 * rTail2 * sTail2 * tTail2;

		//				Matrix tTail3 = makeTranslationMatrix(-0.85f, 0.25f, 0.0f);
		//				Matrix rTail3 = makeEulerRotateMatrix(0.0f, 0.0f, -90.0f);
		//				Matrix sTail3 = Matrix::makeScaleMatrix(1.5f, 0.7f, 1.0f);
		//				Matrix mTail3 = mTail2 * rTail3 * sTail3 * tTail3;

		//					Matrix tTail4 = makeTranslationMatrix(-1.0f, -0.5f, 0.0f);
		//					Matrix rTail4 = makeEulerRotateMatrix(0.0f, 0.0f, 90.0f);
		//					Matrix sTail4 = Matrix::makeScaleMatrix(2.0f, 1.0f, 1.0f);
		//					Matrix mTail4 = mTail3 * rTail4 * sTail4 * tTail4;

		//						Matrix tTail5 = makeTranslationMatrix(-0.95f, 1.25f, 0.0f);
		//						Matrix rTail5 = makeEulerRotateMatrix(0.0f, 0.0f, -90.0f);
		//						Matrix sTail5 = Matrix::makeScaleMatrix(3.5f, 0.9f, 1.0f);
		//						Matrix mTail5 = mTail4 * rTail5 * sTail5 * tTail5;

		//glColor3f(1.0f, 1.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mBody).mVal);
		//drawCylinder(3.0f, 1.0f);

		//glColor3f(1.0f, 1.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mUpperBody).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 90.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(1.0f, 1.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mNeck).mVal);
		//drawCylinder(3.0f, 1.0f);

		//glColor3f(1.0f, 1.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mHead).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 180.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(1.0f, 1.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mLEar).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 180.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mLEarTip).mVal);
		//drawCone(3.0f, 1.0f);

		//glColor3f(1.0f, 1.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mREar).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 180.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mREarTip).mVal);
		//drawCone(3.0f, 1.0f);

		//glColor3f(1.0f, 1.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mLEye).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 90.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mLEyeball).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 90.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(1.0f, 1.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mREye).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 90.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mREyeball).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 90.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mNose).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 90.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mLCheek).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 90.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mRCheek).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 90.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mMouth).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 90.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mTongue).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 180.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mLHand).mVal);
		//drawCylinder(3.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mLHandPalm).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 180.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mLNail1).mVal);
		//drawCone(3.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mLNail2).mVal);
		//drawCone(3.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mLNail3).mVal);
		//drawCone(3.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mLNail4).mVal);
		//drawCone(3.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mRHand).mVal);
		//drawCylinder(3.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mRHandPalm).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 180.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mRNail1).mVal);
		//drawCone(3.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mRNail2).mVal);
		//drawCone(3.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mRNail3).mVal);
		//drawCone(3.0f, 1.0f);

		//glColor3f(0.0f, 0.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mRNail4).mVal);
		//drawCone(3.0f, 1.0f);

		//glColor3f(1.0f, 1.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mLowerBody).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 90.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(1.0f, 1.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mLLeg).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 90.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(1.0f, 1.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mLFoot).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 180.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(1.0f, 1.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mRLeg).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 90.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(1.0f, 1.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mRFoot).mVal);
		//drawSphere(0.0f, 0.0f, 360.0f, 180.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f);

		//glColor3f(1.0f, 1.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mTail1).mVal);
		//drawCube();

		//glColor3f(1.0f, 1.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mTail2).mVal);
		//drawCube();

		//glColor3f(1.0f, 1.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mTail3).mVal);
		//drawCube();

		//glColor3f(1.0f, 1.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mTail4).mVal);
		//drawCube();

		//glColor3f(1.0f, 1.0f, 0.0f);
		//glLoadMatrixf((GLfloat*)(viewMatrix * mTail5).mVal);
		//drawCube();

		if (earDir)
		{
			if (earAngle < 40.0f)
			{
				earAngle += 0.1f;
			}
			else
			{
				earDir = false;
			}
		}
		else
		{
			if (earAngle > 20.0f)
			{
				earAngle -= 0.1f;
			}
			else
			{
				earDir = true;
			}
		}

		if (tailDir)
		{
			if (tailAngle < 40.0f)
			{
				tailAngle += 0.1f;
			}
			else
			{
				tailDir = false;
			}
		}
		else
		{
			if (tailAngle > -40.0f)
			{
				tailAngle -= 0.1f;
			}
			else
			{
				tailDir = true;
			}
		}

		if (bodyDir)
		{
			if (bodyAngle < 20.0f)
			{
				bodyAngle += 0.1f;
			}
			else
			{
				bodyDir = false;
			}
		}
		else
		{
			if (bodyAngle > -20.0f)
			{
				bodyAngle -= 0.1f;
			}
			else
			{
				bodyDir = true;
			}
		}

		if (bodyScaleDir)
		{
			if (bodyScale < 1.0f)
			{
				bodyScale += 0.001f;
			}
			else
			{
				bodyScaleDir = false;
			}
		}
		else
		{
			if (bodyScale > 0.8f)
			{
				bodyScale -= 0.001f;
			}
			else
			{
				bodyScaleDir = true;
			}
		}

		Matrix rRotBody = Matrix::makeRotateMatrix(bodyAngle, Vector(0.0f, 0.0f, 1.0f)) * Matrix::makeScaleMatrix(bodyScale, bodyScale, bodyScale);

		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody).mVal);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawSphere(0.0f, 0.0f, 360.0f, 180.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f); //Head

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tCylinderBody = Matrix::makeTranslationMatrix(Vector(0.0f, -2.0f, 0.0f));

		Matrix tUpHsphereBody = Matrix::makeTranslationMatrix(Vector(0.0f, 0.5f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * tUpHsphereBody * tCylinderBody).mVal);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawSphere(0.0f, 0.0f, 360.0f, 90.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f); //Upper Hemisphere Body

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * tCylinderBody).mVal);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawCylinder(1.0f, 1.0f); //Cylinder Body

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix rInverseX = Matrix::makeRotateMatrix(180.0f, Vector(0.0f, 0.0f, 1.0f));
		Matrix tLowHsphereBody = Matrix::makeTranslationMatrix(Vector(0.0f, -0.5f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * tLowHsphereBody * tCylinderBody * rInverseX).mVal);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawSphere(0.0f, 0.0f, 360.0f, 90.0f, 1.0f, 25.0f, 25.0f, 1.0f, 0.5f); //Lower Hemisphere Body

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tEar = Matrix::makeTranslationMatrix(Vector(0.0f, 1.25f, 0.0f));

		Matrix rLEar = Matrix::makeRotateMatrix(earAngle, Vector(0.0f, 0.0f, 1.0f));
		Matrix tLEar = Matrix::makeTranslationMatrix(Vector(1.0f, 0.0f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * tLEar * tEar * rLEar).mVal);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawSphere(0.0f, 0.0f, 360.0f, 180.0f, 0.25f, 25.0f, 25.0f, 1.0f, 3.0f); //Ear L

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tEarTip = Matrix::makeTranslationMatrix(Vector(0.0f, 0.9f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * tLEar * tEar * rLEar * tEarTip).mVal);

		glColor3f(0.1f, 0.1f, 0.1f);
		drawCone(0.8f, 0.2f); //Ear L Tip

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tREar = Matrix::makeTranslationMatrix(Vector(-1.0f, 0.0f, 0.0f));
		Matrix rREar = Matrix::makeRotateMatrix(-earAngle, Vector(0.0f, 0.0f, 1.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * tREar * tEar * rREar).mVal);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawSphere(0.0f, 0.0f, 360.0f, 180.0f, 0.25f, 25.0f, 25.0f, 1.0f, 3.0f); //Ear R

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * tREar * tEar * rREar * tEarTip).mVal);

		glColor3f(0.1f, 0.1f, 0.1f);
		drawCone(0.8f, 0.2f); //Ear R Tip

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tHand = Matrix::makeTranslationMatrix(Vector(0.0f, 0.7f, 1.0f));
		Matrix rHand = Matrix::makeRotateMatrix(80.0f, Vector(1.0f, 0.0f, 0.0f));

		Matrix tLHand = Matrix::makeTranslationMatrix(Vector(-0.6f, 0.0f, 0.0f));
		Matrix rLHand = Matrix::makeRotateMatrix(15.0f, Vector(0.0f, 1.0f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * tLHand * tHand * tCylinderBody * rLHand * rHand).mVal);

		glColor3f(1.0f, 0.9f, 0.0f);
		drawCylinder(1.0f, 0.25f); //Hand L

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tRHand = Matrix::makeTranslationMatrix(Vector(0.6f, 0.0f, 0.0f));
		Matrix rRHand = Matrix::makeRotateMatrix(-15.0f, Vector(0.0f, 1.0f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * tRHand * tHand * tCylinderBody * rRHand * rHand).mVal);

		glColor3f(1.0f, 0.9f, 0.0f);
		drawCylinder(1.0f, 0.25f); //Hand R

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tLeg = Matrix::makeTranslationMatrix(Vector(0.0f, -0.5f, 1.0f));
		Matrix rLeg = Matrix::makeRotateMatrix(100.0f, Vector(1.0f, 0.0f, 0.0f));

		Matrix tLLeg = Matrix::makeTranslationMatrix(Vector(-0.6f, 0.0f, 0.0f));
		Matrix rLLeg = Matrix::makeRotateMatrix(15.0f, Vector(0.0f, 1.0f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * tLLeg * tLeg * tCylinderBody * rLLeg * rLeg).mVal);

		glColor3f(1.0f, 0.9f, 0.0f);
		drawCylinder(1.0f, 0.25f); //Leg L

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tRLeg = Matrix::makeTranslationMatrix(Vector(0.6f, 0.0f, 0.0f));
		Matrix rRLeg = Matrix::makeRotateMatrix(-15.0f, Vector(0.0f, 1.0f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * tRLeg * tLeg * tCylinderBody * rRLeg * rLeg).mVal);

		glColor3f(1.0f, 0.9f, 0.0f);
		drawCylinder(1.0f, 0.25f); //Leg R

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tBaseTail = Matrix::makeTranslationMatrix(Vector(0.0f, 0.0f, -1.2f));
		Matrix rRotTail = Matrix::makeRotateMatrix(tailAngle, Vector(0.0f, 1.0f, 0.0f));
		Matrix rBaseTail = Matrix::makeRotateMatrix(65.0f, Vector(1.0f, 0.0f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * rRotTail * tBaseTail * tCylinderBody * rBaseTail).mVal);

		glColor3f(1.0f, 0.5f, 0.0f);
		drawCuboid(0.2f, 0.8f, 0.2f); //Tail Base

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tTail1 = Matrix::makeTranslationMatrix(Vector(0.0f, 0.45f, -0.1f));
		Matrix rTail1 = Matrix::makeRotateMatrix(-85.0f, Vector(1.0f, 0.0f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * rRotTail * tTail1 * tBaseTail * tCylinderBody * rTail1 * rBaseTail).mVal);

		glColor3f(1.0f, 0.5f, 0.0f);
		drawCuboid(0.21f, 1.0f, 0.4f); //Tail 1

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * rRotTail * tTail1 * tTail1 * tBaseTail * tCylinderBody * rBaseTail).mVal);

		glColor3f(1.0f, 0.5f, 0.0f);
		drawCuboid(0.22f, 1.0f, 0.4f); //Tail 2

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * rRotTail * tTail1 * tTail1 * tTail1 * tBaseTail * tCylinderBody * rTail1 * rBaseTail).mVal);

		glColor3f(1.0f, 0.5f, 0.0f);
		drawCuboid(0.23f, 1.2f, 0.6f); //Tail 3

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * rRotTail * tTail1 * tTail1 * tTail1 * tTail1 * tBaseTail * tCylinderBody * rBaseTail).mVal);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawCuboid(0.24f, 1.2f, 0.6f); //Tail 4

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * rRotTail * tTail1 * tTail1 * tTail1 * tTail1 * tTail1 * tBaseTail * tCylinderBody * rTail1 * rBaseTail).mVal);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawCuboid(0.25f, 1.4f, 0.8f); //Tail 5

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * rRotTail * tTail1 * tTail1 * tTail1 * tTail1 * tTail1 * tTail1 * tBaseTail * tCylinderBody * rBaseTail).mVal);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawCuboid(0.26f, 1.4f, 0.8f); //Tail 6

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tEye = Matrix::makeTranslationMatrix(Vector(0.0f, 0.45f, 0.8f));
		Matrix rEye = Matrix::makeRotateMatrix(120.0f, Vector(1.0f, 0.0f, 0.0f));

		Matrix tLEye = Matrix::makeTranslationMatrix(Vector(-0.2f, 0.0f, 0.08f));
		Matrix rLEye = Matrix::makeRotateMatrix(20.0f, Vector(0.0f, 1.0f, 0.0f));

		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * rLEye * tLEye * tEye * rEye).mVal);

		glColor3f(0.0f, 0.0f, 0.0f);
		drawCylinder(0.05f, 0.2f); //Left Eye

		glColor3f(1.0f, 1.0f, 1.0f);
		drawCylinder(0.06f, 0.05f); //Left Eye White

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tREye = Matrix::makeTranslationMatrix(Vector(0.2f, 0.0f, 0.08f));
		Matrix rREye = Matrix::makeRotateMatrix(-20.0f, Vector(0.0f, 1.0f, 0.0f));

		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * rREye * tREye * tEye * rEye).mVal);

		glColor3f(0.0f, 0.0f, 0.0f);
		drawCylinder(0.05f, 0.2f); //Right Eye

		glColor3f(1.0f, 1.0f, 1.0f);
		drawCylinder(0.06f, 0.05f); //Right Eye White

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tCheek = Matrix::makeTranslationMatrix(Vector(0.0f, -0.25f, 0.85f));
		Matrix rCheek = Matrix::makeRotateMatrix(80.0f, Vector(1.0f, 0.0f, 0.0f));

		Matrix tLCheek = Matrix::makeTranslationMatrix(Vector(-0.2f, 0.0f, 0.1f));
		Matrix rLCheek = Matrix::makeRotateMatrix(30.0f, Vector(0.0f, 1.0f, 0.0f));

		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * rLCheek * tLCheek * tCheek * rCheek).mVal);

		glColor3f(1.0f, 0.0f, 0.0f);
		drawCylinder(0.05f, 0.2f); //Left Cheek

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tRCheek = Matrix::makeTranslationMatrix(Vector(0.2f, 0.0f, 0.1f));
		Matrix rRCheek = Matrix::makeRotateMatrix(-30.0f, Vector(0.0f, 1.0f, 0.0f));

		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * rRCheek * tRCheek * tCheek * rCheek).mVal);

		glColor3f(1.0f, 0.0f, 0.0f);
		drawCylinder(0.05f, 0.2f); //Right Cheek

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tMouth = Matrix::makeTranslationMatrix(Vector(0.0f, 0.0f, 1.0f));
		Matrix rMouth = Matrix::makeRotateMatrix(90.0f, Vector(0.0f, 1.0f, 0.0f));

		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * tMouth * rMouth).mVal);

		glColor3f(1.0f, 0.0f, 0.0f);
		drawSphere(0.0f, 0.0f, 360.0f, 90.0f, 0.25f, 25.0f, 25.0f, 0.1f, -2.0f); //Mouth

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tNose = Matrix::makeTranslationMatrix(Vector(0.0f, 0.2f, 1.0f));

		glLoadMatrixf((GLfloat*)(viewMatrix * rRotBody * tNose).mVal);

		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, -0.1f, 0.0f);
		glVertex3f(-0.1f, 0.0f, 0.0f);
		glVertex3f(0.1f, 0.0f, 0.0f);
		glEnd();

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);
	}
};

#endif
