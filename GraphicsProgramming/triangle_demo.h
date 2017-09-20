#ifndef _TRIANGLE_DEMO_H
#define _TRIANGLE_DEMO_H

#include "demo_base.h"

class TriangleDemo : public DemoBase
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
	// ============draw axis.
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
		// ============================
	}

	void drawTriangle()
	{
		glBegin(GL_TRIANGLES);							// Drawing Using Triangles

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);					// Top Left
		glVertex3f(1.0f, -1.0f, 0.0f);					// Bottom Left
		glVertex3f(2.0f, -1.0f, 0.0f);					// Bottom Right

		glEnd();										// Finished Drawing The Triangles
	}

	void drawRectangle()
	{
		glBegin(GL_TRIANGLES);							// Drawing Using Triangles

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);					// Top Left
		glVertex3f(1.0f, -1.0f, 0.0f);					// Bottom Left
		glVertex3f(2.0f, -1.0f, 0.0f);					// Bottom Right

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);					// Top Left
		glVertex3f(2.0f, 1.0f, 0.0f);					// Top Right
		glVertex3f(2.0f, -1.0f, 0.0f);					// Bottom Right

		glEnd();										// Finished Drawing The Triangles
	}

	void drawCube()
	{
		glBegin(GL_TRIANGLES);

		// Blue
		glColor3f(0.25f, 0.25f, 1.0f);

		// Negative Square
		glVertex3f(-0.5f, 0.5f, -0.5f);
		glVertex3f(-0.5f, -0.5f, -0.5f);
		glVertex3f(0.5f, -0.5f, -0.5f);

		glVertex3f(-0.5f, 0.5f, -0.5f);
		glVertex3f(0.5f, 0.5f, -0.5f);
		glVertex3f(0.5f, -0.5f, -0.5f);

		// Positive Square
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glVertex3f(-0.5f, -0.5f, 0.5f);
		glVertex3f(0.5f, -0.5f, 0.5f);

		glVertex3f(-0.5f, 0.5f, 0.5f);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glVertex3f(0.5f, -0.5f, 0.5f);

		// Green
		glColor3f(0.25f, 1.0f, 0.25f);

		// Negative Square
		glVertex3f(0.5f, -0.5f, -0.5f);
		glVertex3f(-0.5f, -0.5f, -0.5f);
		glVertex3f(-0.5f, -0.5f, 0.5f);

		glVertex3f(0.5f, -0.5f, -0.5f);
		glVertex3f(0.5f, -0.5f, 0.5f);
		glVertex3f(-0.5f, -0.5f, 0.5f);

		// Positive Square
		glVertex3f(0.5f, 0.5f, -0.5f);
		glVertex3f(-0.5f, 0.5f, -0.5f);
		glVertex3f(-0.5f, 0.5f, 0.5f);

		glVertex3f(0.5f, 0.5f, -0.5f);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glVertex3f(-0.5f, 0.5f, 0.5f);

		// Red
		glColor3f(1.0f, 0.25f, 0.25f);

		// Negative Square
		glVertex3f(-0.5f, -0.5f, 0.5f);
		glVertex3f(-0.5f, -0.5f, -0.5f);
		glVertex3f(-0.5f, 0.5f, -0.5f);

		glVertex3f(-0.5f, -0.5f, 0.5f);
		glVertex3f(-0.5f, 0.5f, 0.5f);
		glVertex3f(-0.5f, 0.5f, -0.5f);

		// Positive Square
		glVertex3f(0.5f, -0.5f, 0.5f);
		glVertex3f(0.5f, -0.5f, -0.5f);
		glVertex3f(0.5f, 0.5f, -0.5f);

		glVertex3f(0.5f, -0.5f, 0.5f);
		glVertex3f(0.5f, 0.5f, 0.5f);
		glVertex3f(0.5f, 0.5f, -0.5f);

		glEnd();										// Finished Drawing The Triangles
	}

	void drawPyramid()
	{
		glBegin(GL_TRIANGLES);							// Drawing Using Triangles

		// Base
		glColor3f(0.25f, 1.0f, 0.25f);
		glVertex3f(0.5f, -0.5f, 0.5f);					// Top
		glVertex3f(0.5f, -0.5f, -0.5f);					// Bottom Left
		glVertex3f(-0.5f, -0.5f, 0.5f);					// Bottom Right

		glVertex3f(-0.5f, -0.5f, -0.5f);				// Top
		glVertex3f(0.5f, -0.5f, -0.5f);					// Bottom Left
		glVertex3f(-0.5f, -0.5f, 0.5f);					// Bottom Right

		// Red Triangles
		glColor3f(1.0f, 0.25f, 0.25f);
		glVertex3f(0.0f, 0.5f, 0.0f);					// Top Vertex
		glVertex3f(0.5f, -0.5f, -0.5f);					// Bottom Left
		glVertex3f(0.5f, -0.5f, 0.5f);					// Bottom Right

		glVertex3f(0.0f, 0.5f, 0.0f);					// Top Vertex
		glVertex3f(-0.5f, -0.5f, -0.5f);				// Bottom Left
		glVertex3f(-0.5f, -0.5f, 0.5f);					// Bottom Right

		// Blue Triangles
		glColor3f(0.25f, 0.25f, 1.0f);
		glVertex3f(0.0f, 0.5f, 0.0f);					// Top Vertex
		glVertex3f(-0.5f, -0.5f, 0.5f);					// Bottom Left
		glVertex3f(0.5f, -0.5f, 0.5f);					// Bottom Right

		glVertex3f(0.0f, 0.5f, 0.0f);					// Top Vertex
		glVertex3f(-0.5f, -0.5f, -0.5f);				// Bottom Left
		glVertex3f(0.5f, -0.5f, -0.5f);					// Bottom Right

		glEnd();										// Finished Drawing The Triangles
	}

	void drawCylinder(float height, float radius, int iteration = 100)
	{
		//Offset
		float offsetX = 0.0f;
		float offsetY = 0.0f;
		float offsetZ = 0.0f;
		float halfHeight = height / 2.0f;

		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_TRIANGLES);							// Drawing Using Triangles

		float t = 360.0f / iteration;

		for (int i = 0; i < iteration; i++)
		{
			float x1 = radius * cos((i * t) * PI / 180.0);
			float z1 = radius * sin((i * t) * PI / 180.0);

			float x2 = radius * cos(((i + 1) * t) * PI / 180.0);
			float z2 = radius * sin(((i + 1) * t) * PI / 180.0);

			// ---- Upper Circle ----
			glColor3f(1.0f, (i % 2 == 0 ? 0.5f : 1.0f), 0.5f);
			//Center of the circle
			glVertex3f(offsetX, offsetY + halfHeight, offsetZ);

			//First point
			glVertex3f(x1, offsetY + halfHeight, z1);

			//Second point
			glVertex3f(x2, offsetY + halfHeight, z2);

			// ---- Lower Circle ----
			glColor3f(1.0f, (i % 2 == 0 ? 0.5f : 1.0f), 0.5f);
			//Center of the circle
			glVertex3f(offsetX, offsetY - halfHeight, offsetZ);

			//First point
			glVertex3f(x1, offsetY - halfHeight, z1);

			//Second point
			glVertex3f(x2, offsetY - halfHeight, z2);

			// ---- Upper Triangle ----
			glColor3f(0.5f, 1.0f, 0.5f);
			//First point
			glVertex3f(x1, offsetY + halfHeight, z1);

			//Second point
			glVertex3f(x2, offsetY + halfHeight, z2);

			//Third point
			glVertex3f(x1, offsetY - halfHeight, z1);

			// ---- Lower Triangle ----
			glColor3f(0.5f, 0.5f, 1.0f);
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

		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_TRIANGLES);							// Drawing Using Triangles

		float t = 360.0f / iteration;

		for (int i = 0; i < iteration; i++)
		{
			float x1 = radius * cos((i * t) * PI / 180.0);
			float z1 = radius * sin((i * t) * PI / 180.0);

			float x2 = radius * cos(((i + 1) * t) * PI / 180.0);
			float z2 = radius * sin(((i + 1) * t) * PI / 180.0);

			// ---- Circle ----
			glColor3f(1.0f, (i % 2 == 0 ? 0.5f : 1.0f), 0.5f);
			//Center of the circle
			glVertex3f(offsetX, offsetY - halfHeight, offsetZ);

			//First point
			glVertex3f(x1, offsetY - halfHeight, z1);

			//Second point
			glVertex3f(x2, offsetY - halfHeight, z2);

			// ---- Triangle ----
			glColor3f(0.5f, (i % 2 == 0 ? 0.5f : 1.0f), (i % 2 == 0 ? 1.0f : 0.5f));
			//Upper vertex
			glVertex3f(offsetX, offsetY + halfHeight, offsetZ);

			//First point
			glVertex3f(x1, offsetY - halfHeight, z1);

			//Second point
			glVertex3f(x2, offsetY - halfHeight, z2);
		}

		glEnd();										// Finished Drawing The Triangles
	}

	void wavingOrbiter(const Matrix& viewMatrix, float rot1, float rot2, float amplitude, float l1, float l2)
	{
		//Matrix Transformation
		Matrix translate1 = Matrix::makeTranslationMatrix(Vector(0.0f, amplitude * sin(rot1 * PI / 180.0f), 0.0f));
		//Matrix rotate1 = Matrix::makeRotateMatrix(rot2, Vector(0.0f, 1.0f, 0.0f));
		Matrix translate2 = Matrix::makeTranslationMatrix(Vector(l1 * cos(rot2 * PI / 180.0f), 0.0f, l2 * sin(rot2 * PI / 180.0f)));
		//Matrix scale1 = Matrix::makeScaleMatrix(Vector(2.0f, 1.0f, 3.0f));

		// NOTE on OpenGL Matrix model
		// Screen = Proj * View * Model
		// Model = TransformC(3rd) * TransformB(2nd) * TransformA(1st) (Transform could be Rotate, Scale, Translate, etc)

		//Perform Model Transformation
		Matrix modelMatrix = translate1 * translate2;

		Matrix viewSpaceMatrix = viewMatrix * modelMatrix;

		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
	}

	float rot1 = 0.0f;
	float rot2 = 0.0f;

	void draw(const Matrix& viewMatrix)
	{
		drawAxis(viewMatrix);

		glLoadMatrixf((GLfloat*)viewMatrix.mVal);

		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Show Wireframes

		rot1 += 0.01f;
		rot2 += 0.05f;

		wavingOrbiter(viewMatrix, rot2, rot1, 2.0f, 10.0f, 5.0f);

		drawCube();
		//drawPyramid();

		//drawCylinder(2.0f, 1.0f);
		//drawCone(2.0f, 1.0f);
	}
};

#endif
