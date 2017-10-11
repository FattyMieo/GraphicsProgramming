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

	void drawPTriangle(float x, float y, float z, float size, float iteration, float offsetAngle = 0.0f)
	{
		float initialOffsetAngle = 90.0f;
		float diffAngle = 120.0f;

		if (iteration > 1)
		{
			drawPTriangle(x, y, z, size / 2.0f, iteration - 1, offsetAngle + 180.0f);

			//glBegin(GL_TRIANGLES);
			for (int t = 0; t < 3; t++)
			{
				float dx = x + (size / 2.0f * cosf((diffAngle * t + (offsetAngle + initialOffsetAngle)) * PI / 180.0f));
				float dy = x + (size / 2.0f * sinf((diffAngle * t + (offsetAngle + initialOffsetAngle)) * PI / 180.0f));

				//glVertex3f(dx, dy, z);
				drawPTriangle(dx, dy, z, size / 2.0f, iteration - 1, offsetAngle);
			}
			//glEnd();
		}
		else
		{
			drawETriangle(x, y, z, size, offsetAngle);
		}
	}

	void drawETriangle(float x, float y, float z, float size, float offsetAngle = 0.0f)
	{
		float initialOffsetAngle = 90.0f;
		float diffAngle = 120.0f;

		glBegin(GL_TRIANGLES);

		for (int t = 0; t < 3; t++)
		{
			float dx = x + (size * cosf((diffAngle * t + (offsetAngle + initialOffsetAngle)) * PI / 180.0f));
			float dy = x + (size * sinf((diffAngle * t + (offsetAngle + initialOffsetAngle)) * PI / 180.0f));

			glVertex3f(dx, dy, z);
		}

		glEnd();
	}

	void draw(const Matrix& viewMatrix)
	{
		drawAxis(viewMatrix);

		glLoadMatrixf((GLfloat*)viewMatrix.mVal);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Show Wireframes

		float radius = 1.0f;

		drawPTriangle(0, 0, 0, radius, 3);
		/*
		for (int y = -1; y <= 1; y += 2)
		{
			float topVertex = (radius / 2.0f) * y;
			for (int i = -1; i <= 1; i += 2)
			{
				float horizontalVertex = radius / 2.0f * i;

				glVertex3f(0.0f, topVertex, 0.0f);
				glVertex3f(radius / 2.0f, 0.0f, horizontalVertex);
				glVertex3f(-radius / 2.0f, 0.0f, horizontalVertex);

				glVertex3f(0.0f, topVertex, 0.0f);
				glVertex3f(horizontalVertex, 0.0f, radius / 2.0f);
				glVertex3f(horizontalVertex, 0.0f, -radius / 2.0f);
			}
		}
		*/
	}
};

#endif
