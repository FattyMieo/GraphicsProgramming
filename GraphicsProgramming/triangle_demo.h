#ifndef _TRIANGLE_DEMO_H
#define _TRIANGLE_DEMO_H

#include <vector>
#include <iostream>
#include "demo_base.h"
#include "lodepng.h"
#include <fmod.hpp>
#include <fmod_errors.h>

#define TEXTURE_COUNT 6

//Must be power of 2
#define SPECTRUM_SIZE 1024

void ERRCHECK(FMOD_RESULT result)
{
	if (result != FMOD_OK)
	{
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
	}
}

const int RECT_VERTEX_ARRAY_SIZE = 0;

float m_spectrumLeft[SPECTRUM_SIZE];
float m_spectrumRight[SPECTRUM_SIZE];

class Wave
{
private: 
	//GLfloat mRectVertices[RECT_VERTEX_ARRAY_SIZE];
	float delta = 0.0f;

	float halfSize = 0.0f;
	float inc = 0.0f;

	int qVertices = 0;		// Vertices per quad (Quad)
	int qxVertices = 0;		// Vertices per row of quads (Row)
	int qxzVertices = 0;	// Vertices per col of row of quads (Plane)

	GLfloat *vertices;
	GLubyte *colors;
	GLfloat *texCoords;

	float getY(float j)
	{
		return amplitude * sinf(delta + (j * frequency));
	}

	float getY(float j, float left, float right)
	{
		return left + right / 2;
	}

public:
	float speed;
	float amplitude;
	float frequency;
	float size;
	int iterationPerUnit;
	GLuint textureID;

	void init(GLuint textureID, float speed, float amplitude, float frequency, float size = 1.0f, int iterationPerMeter = 10)
	{
		this->textureID = textureID;
		this->speed = speed;
		this->amplitude = amplitude;
		this->frequency = frequency;
		this->size = size;
		this->iterationPerUnit = iterationPerMeter;

		//Setup values
		halfSize = size / 2.0f;
		inc = 1.0f / iterationPerMeter;
		qVertices = 18;
		qxVertices = (int)(size * iterationPerUnit * qVertices);
		qxzVertices = (int)(size * iterationPerUnit * qxVertices);

		vertices = new GLfloat[qxzVertices];
		colors = new GLubyte[qxzVertices];
		//texCoords = new GLfloat[qxzVertices / 3 * 2];
		texCoords = new GLfloat[qxzVertices];
	}

	void draw()
	{
		glEnable(GL_TEXTURE_2D); //Enable texturing
		glBindTexture(GL_TEXTURE_2D, textureID);

		for (int i = 0; i < size * iterationPerUnit; i++)
		{
			float z = -halfSize + (inc * i);
			for (int j = 0; j < size * iterationPerUnit; j++)
			{
				float x = -halfSize + (inc * j);

				GLfloat quadVertices[] =
				{
					x		, getY(x)		, z			,
					x		, getY(x)		, z + inc	,
					x + inc	, getY(x + inc)	, z			,

					x + inc	, getY(x + inc)	, z + inc	,
					x + inc	, getY(x + inc)	, z			,
					x		, getY(x)		, z + inc
				};

				GLubyte quadColors[] =
				{
					255, 255, 255,
					255, 0, 0,
					0, 255, 0,

					0, 255, 0,
					255, 0, 0,
					255, 255, 255,

					255, 255, 255,
					255, 0, 0,
					0, 255, 0,

					0, 255, 0,
					255, 0, 0,
					255, 255, 255
				};

				GLfloat quadTexCoords[] =
				{
					1.0f, 1.0f,
					1.0f, 0.0f,
					0.0f, 0.0f,

					0.0f, 0.0f,
					0.0f, 1.0f,
					1.0f, 1.0f,

					1.0f, 1.0f,
					1.0f, 0.0f,
					0.0f, 0.0f,

					0.0f, 0.0f,
					0.0f, 1.0f,
					1.0f, 1.0f
				};

				for (int k = 0; k < 18; k++)
				{
					int l = (i * qxVertices) + (j * qVertices) + k;
					vertices[l] = quadVertices[k];
					colors[l] = quadColors[k];
				}

				for (int k = 0; k < 12; k++)
				{
					int l = (i * qxVertices) + (j * qVertices) + k;
					texCoords[l] = quadTexCoords[k];
				}
			}
		}

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, vertices);
		glColorPointer(3, GL_UNSIGNED_BYTE, 0, colors);
		glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
		glDrawArrays(GL_TRIANGLES, 0, qxzVertices / 3);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);

		glDisable(GL_TEXTURE_2D); //Disable texturing
	}

	void drawAudioVisualizer()
	{
		glEnable(GL_TEXTURE_2D); //Enable texturing
		glBindTexture(GL_TEXTURE_2D, textureID);

		for (int i = 0; i < size * iterationPerUnit; i++)
		{
			float z = -halfSize + (inc * i);
			for (int j = 0; j < size * iterationPerUnit; j++)
			{
				float x = -halfSize + (inc * j);

				GLfloat quadVertices[] =
				{
					x		, getY(x, m_spectrumLeft[j], m_spectrumLeft[j])	, z			,
					x		, getY(x, m_spectrumLeft[j], m_spectrumLeft[j])		, z + inc	,
					x + inc	, getY(x + inc, m_spectrumLeft[j+1], m_spectrumLeft[j+1])	, z			,

					x + inc	, getY(x + inc, m_spectrumLeft[j+1], m_spectrumLeft[j+1])	, z + inc	,
					x + inc	, getY(x + inc, m_spectrumLeft[j+1], m_spectrumLeft[j+1])	, z			,
					x		, getY(x, m_spectrumLeft[j], m_spectrumLeft[j])		, z + inc
				};

				GLubyte quadColors[] =
				{
					255, 255, 255,
					255, 0, 0,
					0, 255, 0,

					0, 255, 0,
					255, 0, 0,
					255, 255, 255,

					255, 255, 255,
					255, 0, 0,
					0, 255, 0,

					0, 255, 0,
					255, 0, 0,
					255, 255, 255
				};

				GLfloat quadTexCoords[] =
				{
					1.0f, 1.0f,
					1.0f, 0.0f,
					0.0f, 0.0f,

					0.0f, 0.0f,
					0.0f, 1.0f,
					1.0f, 1.0f,

					1.0f, 1.0f,
					1.0f, 0.0f,
					0.0f, 0.0f,

					0.0f, 0.0f,
					0.0f, 1.0f,
					1.0f, 1.0f
				};

				for (int k = 0; k < 18; k++)
				{
					int l = (i * qxVertices) + (j * qVertices) + k;
					vertices[l] = quadVertices[k];
					colors[l] = quadColors[k];
				}

				for (int k = 0; k < 12; k++)
				{
					int l = (i * qxVertices) + (j * qVertices) + k;
					texCoords[l] = quadTexCoords[k];
				}
			}
		}

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, vertices);
		glColorPointer(3, GL_UNSIGNED_BYTE, 0, colors);
		glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
		glDrawArrays(GL_TRIANGLES, 0, qxzVertices / 3);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);

		glDisable(GL_TEXTURE_2D); //Disable texturing
	}

	void animate()
	{
		delta += speed;
		if (delta >= 2.0f * PI)
		{
			delta -= 2.0f * PI;
		}
		//std::cout << "Delta = " << delta << std::endl;
		draw();
	}
};

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

	FMOD::System* m_fmodSystem;
	FMOD::Sound* m_music;
	FMOD::Channel* m_musicChannel;

public:
	Wave wave;

	void initFmod()
	{
		FMOD_RESULT result;
		unsigned int version;

		result = FMOD::System_Create(&m_fmodSystem);
		ERRCHECK(result);

		result = m_fmodSystem->getVersion(&version);
		ERRCHECK(result);

		if (version < FMOD_VERSION)
		{
			printf("FMOD Error! You are using an old version of FMOD.", version, FMOD_VERSION);
		}

		//Initialise fmod system
		result = m_fmodSystem->init(32, FMOD_INIT_NORMAL, 0);
		ERRCHECK(result);

		//Load and Set up Music
		result = m_fmodSystem->createStream("../media/bensound-funnysong.mp3", FMOD_SOFTWARE, 0, &m_music);
		ERRCHECK(result);

		//Play the loaded mp3 music
		result = m_fmodSystem->playSound(FMOD_CHANNEL_FREE, m_music, false, &m_musicChannel);
		ERRCHECK(result);
	}

	void updateFmod()
	{
		m_fmodSystem->update();

		//Get spectrum for left and right stereo channels
		m_musicChannel->getSpectrum(m_spectrumLeft, SPECTRUM_SIZE, 0, FMOD_DSP_FFT_WINDOW_RECT);
		m_musicChannel->getSpectrum(m_spectrumRight, SPECTRUM_SIZE, 0, FMOD_DSP_FFT_WINDOW_RECT);

		//Print the first audio spectrum for both left and right channels
		std::cout << m_spectrumLeft[0] << ", " << m_spectrumRight[0] << std::endl;
	}

	void init()
	{
		// To support alpha channel
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_ALPHA_TEST);

		glGenTextures(TEXTURE_COUNT, mTextureID);
		loadPNG("../media/Retina.png", mTextureID[0]);
		loadPNG("../media/IronOre.png", mTextureID[1]);
		
		wave.init(mTextureID[0], 0.01f, 0.05f, 5.0f, 4.0f, 64);
		initFmod();
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

	void drawCubeVertexArray(GLuint textureID, float size = 1.0f)
	{
		glEnable(GL_TEXTURE_2D); //Enable texturing
		glBindTexture(GL_TEXTURE_2D, textureID);

		size /= 2.0f;

		GLfloat vertices[] =
		{
			-size, -size, size,
			size, -size, size,
			size, size, size,

			size, size, size,
			-size, size, size,
			-size, -size, size,

			-size, -size, -size,
			size, -size, -size,
			size, size, -size,

			size, size, -size,
			-size, size, -size,
			-size, -size, -size
		};

		GLfloat texCoordsZ[] =
		{
			1.0f, 1.0f,
			0.0f, 1.0f,
			0.0f, 0.0f,

			0.0f, 0.0f,
			1.0f, 0.0f,
			1.0f, 1.0f,

			1.0f, 1.0f,
			0.0f, 1.0f,
			0.0f, 0.0f,

			0.0f, 0.0f,
			1.0f, 0.0f,
			1.0f, 1.0f
		};

		GLfloat texCoordsY[] =
		{
			0.0f, 0.0f,
			1.0f, 0.0f,
			1.0f, 1.0f,

			1.0f, 1.0f,
			0.0f, 1.0f,
			0.0f, 0.0f,

			0.0f, 0.0f,
			1.0f, 0.0f,
			1.0f, 1.0f,

			1.0f, 1.0f,
			0.0f, 1.0f,
			0.0f, 0.0f
		};

		GLfloat texCoordsX[] =
		{
			1.0f, 1.0f,
			1.0f, 0.0f,
			0.0f, 0.0f,

			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 1.0f,

			1.0f, 1.0f,
			1.0f, 0.0f,
			0.0f, 0.0f,

			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 1.0f
		};

		GLubyte colors[] =
		{
			255, 255, 255,
			255, 0, 0,
			0, 255, 0,

			0, 255, 0,
			255, 0, 0,
			255, 255, 255,

			255, 255, 255,
			255, 0, 0,
			0, 255, 0,

			0, 255, 0,
			255, 0, 0,
			255, 255, 255
		};

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		int c = 0;
		while (c < 3)
		{
			glColorPointer(3, GL_UNSIGNED_BYTE, 0, colors);
			glVertexPointer(3, GL_FLOAT, 0, vertices);
			glTexCoordPointer(2, GL_FLOAT, 0, (c == 0 ? texCoordsZ : (c == 1 ? texCoordsY : texCoordsX)));
			glDrawArrays(GL_TRIANGLES, 0, 12);

			c++;
			if (c >= 3) break;

			float vZero = 0.0f;
			for (int i = 0; i < 6; i++)
			{
				vZero = vertices[0 + 3 * i];
				vertices[0 + 3 * i] = vertices[1 + 3 * i];
				vertices[1 + 3 * i] = vertices[2 + 3 * i];
				vertices[2 + 3 * i] = vZero;

				vZero = vertices[(0 + 3 * i) + 18];
				vertices[(0 + 3 * i) + 18] = vertices[(1 + 3 * i) + 18];
				vertices[(1 + 3 * i) + 18] = vertices[(2 + 3 * i) + 18];
				vertices[(2 + 3 * i) + 18] = vZero;
			}
		}
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
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

		updateFmod();

		//wave.animate();
		wave.drawAudioVisualizer();

		//glDisable(GL_BLEND);
		//glDisable(GL_ALPHA_TEST);

		////Display List Method
		///*
		//glBegin(GL_TRIANGLES);

		//glVertex3f(size, size, size);
		//....

		//glEnd();
		//*/

		////Vertex Array Method (cheaper than Display List Method)
		///*
		//GLfloat vertices[] =
		//{
		//	-1.0f, -1.0f, 1.0f,
		//	1.0f, -1.0f, 1.0f,
		//	1.0f, 1.0f, 1.0f,

		//	1.0f, 1.0f, 1.0f,
		//	-1.0f, 1.0f, 1.0f,
		//	-1.0f, -1.0f, 1.0f
		//};

		//glEnableClientState(GL_VERTEX_ARRAY);
		//glVertexPointer(3, GL_FLOAT, 0, vertices);
		//glDrawArrays(GL_TRIANGLES, 0, 6);
		//*/

		//drawCubeVertexArray(mTextureID[1], 1.0f);

		////  drawCube(mTextureID[1], 50.0f);

		////Matrix forward = Matrix::makeTranslationMatrix(Vector(5.0f, 0.0f, 0.0f));
		////Matrix backward = Matrix::makeTranslationMatrix(Vector(-5.0f, 0.0f, 0.0f));

		////glLoadMatrixf((GLfloat*)(viewMatrix * forward).mVal);
		////drawCube(mTextureID[1], 5.0f);
		////glLoadMatrixf((GLfloat*)(viewMatrix * backward).mVal);
		////drawCube(mTextureID[1], 5.0f);
		////glLoadMatrixf((GLfloat*)(viewMatrix).mVal);

		//glEnable(GL_BLEND);
		//glEnable(GL_ALPHA_TEST);

		////Alpha Blend
		////glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		////Additive Blend
		////glBlendFunc(GL_ONE, GL_ONE);

		////Additive Blend???
		////glBlendFunc(GL_SRC_ALPHA, GL_ONE);

		////Multiply Blend (also is called Modulate) //Needs another opaque object to see
		//glBlendFunc(GL_ZERO, GL_SRC_COLOR);
		////glBlendFunc(GL_DST_COLOR, GL_ZERO);

		//glDepthMask(false); //Ignore the depth mask, for semi-transparent objects

		////  drawCube(mTextureID[0], 3.0f);

		//glDepthMask(true);
	}
};

#endif
