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

	void draw(const Matrix& viewMatrix)
	{
		drawAxis(viewMatrix);

		glLoadMatrixf((GLfloat*)viewMatrix.mVal);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Show Wireframes

		float radius = 1.0f;

		//drawPTriangle(0, 0, 0, radius, 3);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawSphere(0.0f, 0.0f, 360.0f, 180.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f); //Head

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tCylinderBody = Matrix::makeTranslationMatrix(Vector(0.0f, -2.0f, 0.0f));

		Matrix tUpHsphereBody = Matrix::makeTranslationMatrix(Vector(0.0f, 0.5f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * tUpHsphereBody * tCylinderBody).mVal);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawSphere(0.0f, 0.0f, 360.0f, 90.0f, 1.0f, 25.0f, 25.0f, 1.0f, 1.0f); //Upper Hemisphere Body

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		glLoadMatrixf((GLfloat*)(viewMatrix * tCylinderBody).mVal);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawCylinder(1.0f, 1.0f); //Cylinder Body

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix rInverseX = Matrix::makeRotateMatrix(180.0f, Vector(0.0f, 0.0f, 1.0f));
		Matrix tLowHsphereBody = Matrix::makeTranslationMatrix(Vector(0.0f, -0.5f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * tLowHsphereBody * tCylinderBody * rInverseX).mVal);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawSphere(0.0f, 0.0f, 360.0f, 90.0f, 1.0f, 25.0f, 25.0f, 1.0f, 0.5f); //Lower Hemisphere Body

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tEar = Matrix::makeTranslationMatrix(Vector(0.0f, 1.25f, 0.0f));

		Matrix rLEar = Matrix::makeRotateMatrix(30.0f, Vector(0.0f, 0.0f, 1.0f));
		Matrix tLEar = Matrix::makeTranslationMatrix(Vector(1.0f, 0.0f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * tLEar * tEar * rLEar).mVal);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawSphere(0.0f, 0.0f, 360.0f, 180.0f, 0.25f, 25.0f, 25.0f, 1.0f, 3.0f); //Ear L

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tEarTip = Matrix::makeTranslationMatrix(Vector(0.0f, 0.9f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * tLEar * tEar * rLEar * tEarTip).mVal);

		glColor3f(0.1f, 0.1f, 0.1f);
		drawCone(0.8f, 0.2f); //Ear L Tip

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tREar = Matrix::makeTranslationMatrix(Vector(-1.0f, 0.0f, 0.0f));
		Matrix rREar = Matrix::makeRotateMatrix(-30.0f, Vector(0.0f, 0.0f, 1.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * tREar * tEar * rREar).mVal);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawSphere(0.0f, 0.0f, 360.0f, 180.0f, 0.25f, 25.0f, 25.0f, 1.0f, 3.0f); //Ear R

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		glLoadMatrixf((GLfloat*)(viewMatrix * tREar * tEar * rREar * tEarTip).mVal);

		glColor3f(0.1f, 0.1f, 0.1f);
		drawCone(0.8f, 0.2f); //Ear R Tip

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tHand = Matrix::makeTranslationMatrix(Vector(0.0f, 0.7f, 1.0f));
		Matrix rHand = Matrix::makeRotateMatrix(80.0f, Vector(1.0f, 0.0f, 0.0f));

		Matrix tLHand = Matrix::makeTranslationMatrix(Vector(-0.6f, 0.0f, 0.0f));
		Matrix rLHand = Matrix::makeRotateMatrix(15.0f, Vector(0.0f, 1.0f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * tLHand * tHand * tCylinderBody * rLHand * rHand).mVal);

		glColor3f(1.0f, 0.9f, 0.0f);
		drawCylinder(1.0f, 0.25f); //Hand L

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tRHand = Matrix::makeTranslationMatrix(Vector(0.6f, 0.0f, 0.0f));
		Matrix rRHand = Matrix::makeRotateMatrix(-15.0f, Vector(0.0f, 1.0f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * tRHand * tHand * tCylinderBody * rRHand * rHand).mVal);

		glColor3f(1.0f, 0.9f, 0.0f);
		drawCylinder(1.0f, 0.25f); //Hand R

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tLeg = Matrix::makeTranslationMatrix(Vector(0.0f, -0.5f, 1.0f));
		Matrix rLeg = Matrix::makeRotateMatrix(100.0f, Vector(1.0f, 0.0f, 0.0f));

		Matrix tLLeg = Matrix::makeTranslationMatrix(Vector(-0.6f, 0.0f, 0.0f));
		Matrix rLLeg = Matrix::makeRotateMatrix(15.0f, Vector(0.0f, 1.0f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * tLLeg * tLeg * tCylinderBody * rLLeg * rLeg).mVal);

		glColor3f(1.0f, 0.9f, 0.0f);
		drawCylinder(1.0f, 0.25f); //Leg L

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tRLeg = Matrix::makeTranslationMatrix(Vector(0.6f, 0.0f, 0.0f));
		Matrix rRLeg = Matrix::makeRotateMatrix(-15.0f, Vector(0.0f, 1.0f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * tRLeg * tLeg * tCylinderBody * rRLeg * rLeg).mVal);

		glColor3f(1.0f, 0.9f, 0.0f);
		drawCylinder(1.0f, 0.25f); //Leg R

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tBaseTail = Matrix::makeTranslationMatrix(Vector(0.0f, 0.0f, -1.2f));
		Matrix rBaseTail = Matrix::makeRotateMatrix(65.0f, Vector(1.0f, 0.0f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * tBaseTail * tCylinderBody * rBaseTail).mVal);

		glColor3f(1.0f, 0.5f, 0.0f);
		drawCuboid(0.2f, 0.8f, 0.2f); //Tail Base

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tTail1 = Matrix::makeTranslationMatrix(Vector(0.0f, 0.45f, -0.1f));
		Matrix rTail1 = Matrix::makeRotateMatrix(-85.0f, Vector(1.0f, 0.0f, 0.0f));
		glLoadMatrixf((GLfloat*)(viewMatrix * tTail1 * tBaseTail * tCylinderBody * rTail1 * rBaseTail).mVal);

		glColor3f(1.0f, 0.5f, 0.0f);
		drawCuboid(0.21f, 1.0f, 0.4f); //Tail 1

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		glLoadMatrixf((GLfloat*)(viewMatrix * tTail1 * tTail1 * tBaseTail * tCylinderBody * rBaseTail).mVal);

		glColor3f(1.0f, 0.5f, 0.0f);
		drawCuboid(0.22f, 1.0f, 0.4f); //Tail 2

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		glLoadMatrixf((GLfloat*)(viewMatrix * tTail1 * tTail1 * tTail1 * tBaseTail * tCylinderBody * rTail1 * rBaseTail).mVal);

		glColor3f(1.0f, 0.5f, 0.0f);
		drawCuboid(0.23f, 1.2f, 0.6f); //Tail 3

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		glLoadMatrixf((GLfloat*)(viewMatrix * tTail1 * tTail1 * tTail1 * tTail1 * tBaseTail * tCylinderBody * rBaseTail).mVal);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawCuboid(0.24f, 1.2f, 0.6f); //Tail 4

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		glLoadMatrixf((GLfloat*)(viewMatrix * tTail1 * tTail1 * tTail1 * tTail1 * tTail1 * tBaseTail * tCylinderBody * rTail1 * rBaseTail).mVal);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawCuboid(0.25f, 1.4f, 0.8f); //Tail 5

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		glLoadMatrixf((GLfloat*)(viewMatrix * tTail1 * tTail1 * tTail1 * tTail1 * tTail1 * tTail1 * tBaseTail * tCylinderBody * rBaseTail).mVal);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawCuboid(0.26f, 1.4f, 0.8f); //Tail 6

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tEye = Matrix::makeTranslationMatrix(Vector(0.0f, 0.45f, 0.8f));
		Matrix rEye = Matrix::makeRotateMatrix(120.0f, Vector(1.0f, 0.0f, 0.0f));

		Matrix tLEye = Matrix::makeTranslationMatrix(Vector(-0.2f, 0.0f, 0.08f));
		Matrix rLEye = Matrix::makeRotateMatrix(20.0f, Vector(0.0f, 1.0f, 0.0f));

		glLoadMatrixf((GLfloat*)(viewMatrix * rLEye * tLEye * tEye * rEye).mVal);

		glColor3f(0.0f, 0.0f, 0.0f);
		drawCylinder(0.05f, 0.2f); //Left Eye

		glColor3f(1.0f, 1.0f, 1.0f);
		drawCylinder(0.06f, 0.05f); //Left Eye White

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tREye = Matrix::makeTranslationMatrix(Vector(0.2f, 0.0f, 0.08f));
		Matrix rREye = Matrix::makeRotateMatrix(-20.0f, Vector(0.0f, 1.0f, 0.0f));

		glLoadMatrixf((GLfloat*)(viewMatrix * rREye * tREye * tEye * rEye).mVal);

		glColor3f(0.0f, 0.0f, 0.0f);
		drawCylinder(0.05f, 0.2f); //Right Eye

		glColor3f(1.0f, 1.0f, 1.0f);
		drawCylinder(0.06f, 0.05f); //Right Eye White

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tCheek = Matrix::makeTranslationMatrix(Vector(0.0f, -0.25f, 0.85f));
		Matrix rCheek = Matrix::makeRotateMatrix(80.0f, Vector(1.0f, 0.0f, 0.0f));

		Matrix tLCheek = Matrix::makeTranslationMatrix(Vector(-0.2f, 0.0f, 0.1f));
		Matrix rLCheek = Matrix::makeRotateMatrix(30.0f, Vector(0.0f, 1.0f, 0.0f));

		glLoadMatrixf((GLfloat*)(viewMatrix * rLCheek * tLCheek * tCheek * rCheek).mVal);

		glColor3f(1.0f, 0.0f, 0.0f);
		drawCylinder(0.05f, 0.2f); //Left Cheek

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tRCheek = Matrix::makeTranslationMatrix(Vector(0.2f, 0.0f, 0.1f));
		Matrix rRCheek = Matrix::makeRotateMatrix(-30.0f, Vector(0.0f, 1.0f, 0.0f));

		glLoadMatrixf((GLfloat*)(viewMatrix * rRCheek * tRCheek * tCheek * rCheek).mVal);

		glColor3f(1.0f, 0.0f, 0.0f);
		drawCylinder(0.05f, 0.2f); //Right Cheek

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tNose = Matrix::makeTranslationMatrix(Vector(0.0f, 0.2f, 1.0f));

		glLoadMatrixf((GLfloat*)(viewMatrix * tNose).mVal);

		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, -0.1f, 0.0f);
		glVertex3f(-0.1f, 0.0f, 0.0f);
		glVertex3f(0.1f, 0.0f, 0.0f);
		glEnd();

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		Matrix tMouth = Matrix::makeTranslationMatrix(Vector(0.0f, -0.2f, 1.0f));

		glLoadMatrixf((GLfloat*)(viewMatrix * tMouth).mVal);

		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, 0.1f, 0.0f);
		glVertex3f(-0.2f, 0.0f, 0.0f);
		glVertex3f(0.2f, 0.0f, 0.0f);
		glEnd();

		glLoadMatrixf((GLfloat*)(viewMatrix).mVal);
	}
};

#endif
