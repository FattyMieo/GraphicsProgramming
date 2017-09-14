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
		glColor3f(0.0f, 0.0f, 1.0f);

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
		glColor3f(0.0f, 1.0f, 0.0f);

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
		glColor3f(1.0f, 0.0f, 0.0f);

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
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.5f, -0.5f, 0.5f);					// Top
		glVertex3f(0.5f, -0.5f, -0.5f);					// Bottom Left
		glVertex3f(-0.5f, -0.5f, 0.5f);					// Bottom Right

		glVertex3f(-0.5f, -0.5f, -0.5f);				// Top
		glVertex3f(0.5f, -0.5f, -0.5f);					// Bottom Left
		glVertex3f(-0.5f, -0.5f, 0.5f);					// Bottom Right

		// Red Triangles
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.5f, 0.0f);					// Top Vertex
		glVertex3f(0.5f, -0.5f, -0.5f);					// Bottom Left
		glVertex3f(0.5f, -0.5f, 0.5f);					// Bottom Right

		glVertex3f(0.0f, 0.5f, 0.0f);					// Top Vertex
		glVertex3f(-0.5f, -0.5f, -0.5f);				// Bottom Left
		glVertex3f(-0.5f, -0.5f, 0.5f);					// Bottom Right

		// Blue Triangles
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.5f, 0.0f);					// Top Vertex
		glVertex3f(-0.5f, -0.5f, 0.5f);					// Bottom Left
		glVertex3f(0.5f, -0.5f, 0.5f);					// Bottom Right

		glVertex3f(0.0f, 0.5f, 0.0f);					// Top Vertex
		glVertex3f(-0.5f, -0.5f, -0.5f);				// Bottom Left
		glVertex3f(0.5f, -0.5f, -0.5f);					// Bottom Right

		glEnd();										// Finished Drawing The Triangles
	}

	void draw(const Matrix& viewMatrix)
	{
		drawAxis(viewMatrix);

		glLoadMatrixf((GLfloat*)viewMatrix.mVal);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Show Wireframes

		drawCube();
		drawPyramid();
	}
};

#endif
