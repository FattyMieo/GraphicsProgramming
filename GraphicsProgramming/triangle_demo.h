#ifndef _TRIANGLE_DEMO_H
#define _TRIANGLE_DEMO_H

#include <vector>
#include <iostream>
#include "demo_base.h"
#include "lodepng.h"

#define TEXTURE_COUNT 5

class TriangleDemo : public DemoBase
{
private:
	GLuint mTextureID[TEXTURE_COUNT];

	void loadPNG(const char* path, GLuint textureID)
	{
		//Load file and decode image
		std::vector<unsigned char> image;
		unsigned width, height;
		unsigned error = lodepng::decode(image, width, height, path);

		//If there's an error, display it
		if (error != 0)
		{
			std::cout << "png load error :" << error << ": " << lodepng_error_text(error) << std::endl;
			return;
		}

		glBindTexture(GL_TEXTURE_2D, textureID);

		//Repeat the texture after exceeding 1.0f
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // apply texture wrapping along horizontal part
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // apply texture wrapping along vertical part

		//Uses last pixel after exceeding 1.0f
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP); // apply texture wrapping along horizontal part
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP); // apply texture wrapping along vertical part

		// bilinear filtering
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // near filtering (For when texture needs to scale...)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // far filtering (For when texture needs to scale...)

		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // near filtering (For when texture needs to scale...)
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // far filtering (For when texture needs to scale...)

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
	}
public:
	void init()
	{
		// To support alpha channel
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_ALPHA_TEST);

		glGenTextures(TEXTURE_COUNT, mTextureID);
		loadPNG("../media/IronOre.png", mTextureID[0]);
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

	void drawTriangle(const Matrix& viewMatrix)
	{
		glLoadMatrixf((GLfloat*)viewMatrix.mVal);
		glBegin(GL_TRIANGLES);							// Drawing Using Triangles

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);					// Top Left
		glVertex3f(1.0f, -1.0f, 0.0f);					// Bottom Left
		glVertex3f(2.0f, -1.0f, 0.0f);					// Bottom Right

		glEnd();										// Finished Drawing The Triangles
	}

	void drawCube(GLuint textureID, float size = 1.0f)
	{
		glEnable(GL_TEXTURE_2D); //Enable texturing
		glBindTexture(GL_TEXTURE_2D, textureID);

		size /= 2.0f;
		glBegin(GL_TRIANGLES);

		// Z

		// Negative Square
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-size, size, -size);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(-size, -size, -size);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(size, -size, -size);

		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-size, size, -size);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(size, size, -size);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(size, -size, -size);

		// Positive Square
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-size, size, size);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(-size, -size, size);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(size, -size, size);

		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-size, size, size);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(size, size, size);
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(size, -size, size);

		// Y

		// Negative Square
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(size, -size, -size);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(-size, -size, -size);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-size, -size, size);

		glTexCoord2f(0.0f, 1.0f);	glVertex3f(size, -size, -size);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(size, -size, size);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-size, -size, size);

		// Positive Square
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(size, size, -size);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(-size, size, -size);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-size, size, size);

		glTexCoord2f(0.0f, 1.0f);	glVertex3f(size, size, -size);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(size, size, size);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-size, size, size);

		// X

		// Negative Square
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(-size, -size, size);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(-size, -size, -size);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-size, size, -size);

		glTexCoord2f(0.0f, 1.0f);	glVertex3f(-size, -size, size);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(-size, size, size);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(-size, size, -size);

		// Positive Square
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(size, -size, size);
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(size, -size, -size);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(size, size, -size);

		glTexCoord2f(0.0f, 1.0f);	glVertex3f(size, -size, size);
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(size, size, size);
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(size, size, -size);

		glEnd();										// Finished Drawing The Triangles
	}

	void drawPyramid(float size = 1.0f)
	{
		size /= 2.0f;
		glBegin(GL_TRIANGLES);							// Drawing Using Triangles

		// Base
		glColor3f(0.25f, 1.0f, 0.25f);
		glVertex3f(size, -size, size);					// Top
		glVertex3f(size, -size, -size);					// Bottom Left
		glVertex3f(-size, -size, size);					// Bottom Right

		glVertex3f(-size, -size, -size);				// Top
		glVertex3f(size, -size, -size);					// Bottom Left
		glVertex3f(-size, -size, size);					// Bottom Right

		// Red Triangles
		glColor3f(1.0f, 0.25f, 0.25f);
		glVertex3f(0.0f, size, 0.0f);					// Top Vertex
		glVertex3f(size, -size, -size);					// Bottom Left
		glVertex3f(size, -size, size);					// Bottom Right

		glVertex3f(0.0f, size, 0.0f);					// Top Vertex
		glVertex3f(-size, -size, -size);				// Bottom Left
		glVertex3f(-size, -size, size);					// Bottom Right

		// Blue Triangles
		glColor3f(0.25f, 0.25f, 1.0f);
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

	void draw(const Matrix& viewMatrix)
	{
		drawAxis(viewMatrix);

		glLoadMatrixf((GLfloat*)viewMatrix.mVal);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Show Wireframes

		drawCube(mTextureID[0], 3.0f);
	}
};

#endif
