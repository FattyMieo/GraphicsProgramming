#ifndef _AUDIO_VISUALIZER_H
#define _AUDIO_VISUALIZER_H

#include <vector>
#include <iostream>
#include "demo_base.h"
#include "lodepng.h"
#include <fmod.hpp>
#include <fmod_errors.h>

#define TEXTURE_COUNT 16
#define SPECTRUM_SIZE 512 //Must be power of 2
//const int SPECTRUM_SIZE_SHOWN = SPECTRUM_SIZE / 4;
#define SPECTRUM_START 16
#define SPECTRUM_END 128
const int SPECTRUM_SIZE_SHOWN = SPECTRUM_END - SPECTRUM_START;

//FMOD Error Check
void ERRCHECK(FMOD_RESULT result)
{
	if (result != FMOD_OK)
	{
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
	}
}

//class CustomColor
//{
//public:
//	GLubyte r;
//	GLubyte g;
//	GLubyte b;
//
//	CustomColor()
//	{
//		r = (GLubyte)255;
//		g = (GLubyte)255;
//		b = (GLubyte)255;
//	}
//
//	CustomColor(int r, int g, int b)
//	{
//		this->r = (GLubyte)r;
//		this->g = (GLubyte)g;
//		this->b = (GLubyte)b;
//	}
//};
//
//enum FACE_DIRECTION
//{
//	FACE_DIRECTION_RIGHT = 0,
//	FACE_DIRECTION_LEFT,
//	FACE_DIRECTION_FRONT,
//	FACE_DIRECTION_BACK,
//	FACE_DIRECTION_TOP,
//	FACE_DIRECTION_BOTTOM,
//
//	FACE_DIRECTION_TOTAL
//};
//
//enum FACE_CORNER
//{
//	FACE_CORNER_LEFT_BOTTOM = 0,
//	FACE_CORNER_LEFT_TOP,
//	FACE_CORNER_RIGHT_BOTTOM,
//	FACE_CORNER_RIGHT_TOP,
//
//	FACE_CORNER_TOTAL
//};
//
//class ColorArray
//{
//public:
//	CustomColor colors[FACE_CORNER_TOTAL][FACE_DIRECTION_TOTAL];
//	CustomColor solidColor = CustomColor(255, 0, 0);
//	bool useSolidColor = true;
//
//	void SetColor(FACE_DIRECTION dir, FACE_CORNER corner, CustomColor color)
//	{
//		colors[corner][dir] = CustomColor(color);
//	}
//
//	void SetColor(FACE_DIRECTION dir, FACE_CORNER corner, int r, int g, int b)
//	{
//		SetColor(dir, corner, CustomColor(r, g, b));
//	}
//
//	void GetValue(GLubyte* colorValue, bool useSolidColor = true)
//	{
//		if (useSolidColor)
//		{
//			colorValue = new GLubyte[108]
//			{
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b,
//				solidColor.r, solidColor.g, solidColor.b
//			};
//		}
//		else
//		{
//			colorValue = new GLubyte[108]
//			{
//				colors[0][0].r, colors[0][0].g, colors[0][0].b,
//				colors[1][0].r, colors[1][0].g, colors[1][0].b,
//				colors[2][0].r, colors[2][0].g, colors[2][0].b,
//
//				colors[3][0].r, colors[3][0].g, colors[3][0].b,
//				colors[1][0].r, colors[1][0].g, colors[1][0].b,
//				colors[2][0].r, colors[2][0].g, colors[2][0].b,
//
//				colors[0][1].r, colors[0][1].g, colors[0][1].b,
//				colors[1][1].r, colors[1][1].g, colors[1][1].b,
//				colors[2][1].r, colors[2][1].g, colors[2][1].b,
//
//				colors[3][1].r, colors[3][1].g, colors[3][1].b,
//				colors[1][1].r, colors[1][1].g, colors[1][1].b,
//				colors[2][1].r, colors[2][1].g, colors[2][1].b,
//
//				colors[0][2].r, colors[0][2].g, colors[0][2].b,
//				colors[1][2].r, colors[1][2].g, colors[1][2].b,
//				colors[2][2].r, colors[2][2].g, colors[2][2].b,
//
//				colors[3][2].r, colors[3][2].g, colors[3][2].b,
//				colors[1][2].r, colors[1][2].g, colors[1][2].b,
//				colors[2][2].r, colors[2][2].g, colors[2][2].b,
//
//				colors[0][3].r, colors[0][3].g, colors[0][3].b,
//				colors[1][3].r, colors[1][3].g, colors[1][3].b,
//				colors[2][3].r, colors[2][3].g, colors[2][3].b,
//
//				colors[3][3].r, colors[3][3].g, colors[3][3].b,
//				colors[1][3].r, colors[1][3].g, colors[1][3].b,
//				colors[2][3].r, colors[2][3].g, colors[2][3].b,
//
//				colors[0][4].r, colors[0][4].g, colors[0][4].b,
//				colors[1][4].r, colors[1][4].g, colors[1][4].b,
//				colors[2][4].r, colors[2][4].g, colors[2][4].b,
//
//				colors[3][4].r, colors[3][4].g, colors[3][4].b,
//				colors[1][4].r, colors[1][4].g, colors[1][4].b,
//				colors[2][4].r, colors[2][4].g, colors[2][4].b,
//
//				colors[0][5].r, colors[0][5].g, colors[0][5].b,
//				colors[1][5].r, colors[1][5].g, colors[1][5].b,
//				colors[2][5].r, colors[2][5].g, colors[2][5].b,
//
//				colors[3][5].r, colors[3][5].g, colors[3][5].b,
//				colors[1][5].r, colors[1][5].g, colors[1][5].b,
//				colors[2][5].r, colors[2][5].g, colors[2][5].b
//			};
//		}
//	}
//};

enum SEASONS
{
	SEASONS_SPRING = 0,
	SEASONS_SUMMER = 1,
	SEASONS_AUTUMN = 2,
	SEASONS_WINTER = 3,

	SEASONS_UNDECIDED = -1
};

class GeometryShape
{
public:
	Vector position = Vector(0.0f, 0.0f, 0.0f);
	Vector rotation = Vector(0.0f, 0.0f, 0.0f);
	Vector scale = Vector(1.0f, 1.0f, 1.0f);
	GLuint textureID = 0;
	//ColorArray colorArray;

	GeometryShape()
	{
		position = Vector(0.0f, 0.0f, 0.0f);
		rotation = Vector(0.0f, 0.0f, 0.0f);
		scale = Vector(1.0f, 1.0f, 1.0f);
		textureID = 0;
	}

	GeometryShape(GLuint textureID)
	{
		position = Vector(0.0f, 0.0f, 0.0f);
		rotation = Vector(0.0f, 0.0f, 0.0f);
		scale = Vector(1.0f, 1.0f, 1.0f);
		this->textureID = textureID;
	}

	GeometryShape(int textureID) : GeometryShape((GLuint)textureID) { }

	GeometryShape(Vector position, Vector rotation, Vector scale, GLuint textureID)
	{
		this->position = position;
		this->rotation = rotation;
		this->scale = scale;
		this->textureID = textureID;
	}

	GeometryShape(Vector position, Vector rotation, Vector scale, int textureID) : GeometryShape(position, rotation, scale, (GLuint)textureID) { }

	//void SetSolidColor(int r, int g, int b)
	//{
	//	for (int i = 0; i < FACE_DIRECTION_TOTAL; i++)
	//	{
	//		for (int j = 0; j < FACE_CORNER_TOTAL; j++)
	//		{
	//			colorArray.SetColor((FACE_DIRECTION)i, (FACE_CORNER)j, r, g, b);
	//		}
	//	}
	//}

	virtual void Draw(const Matrix& parentMatrix) = 0;
};

const GLfloat cubeVertices[108] =
{
	//X Axis
	//Positive Face
	1, -1, 1,
	1, 1, 1,
	1, -1, -1,

	1, 1, -1,
	1, 1, 1,
	1, -1, -1,

	//X Axis
	//Negative Face
	-1, -1, -1,
	-1, 1, -1,
	-1, -1, 1,

	-1, 1, 1,
	-1, 1, -1,
	-1, -1, 1,

	//Z Axis
	//Positive Face
	-1, -1, 1,
	-1, 1, 1,
	1, -1, 1,

	1, 1, 1,
	-1, 1, 1,
	1, -1, 1,

	//Z Axis
	//Negative Face
	1, -1, -1,
	1, 1, -1,
	-1, -1, -1,

	-1, 1, -1,
	1, 1, -1,
	-1, -1, -1,

	//Y Axis
	//Positive Face
	-1, 1, 1,
	-1, 1, -1,
	1, 1, 1,

	1, 1, -1,
	-1, 1, -1,
	1, 1, 1,

	//Y Axis
	//Negative Face
	-1, -1, -1,
	-1, -1, 1,
	1, -1, -1,

	1, -1, 1,
	-1, -1, 1,
	1, -1, -1
};

const GLfloat cubeTexCoords[72] =
{
	//X Axis
	//Positive Face
	0, 0,
	0, 1,
	1, 0,

	1, 1,
	0, 1,
	1, 0,

	//X Axis
	//Negative Face
	0, 0,
	0, 1,
	1, 0,

	1, 1,
	0, 1,
	1, 0,

	//Z Axis
	//Positive Face
	0, 0,
	0, 1,
	1, 0,

	1, 1,
	0, 1,
	1, 0,

	//Z Axis
	//Negative Face
	0, 0,
	0, 1,
	1, 0,

	1, 1,
	0, 1,
	1, 0,

	//Y Axis
	//Positive Face
	0, 0,
	0, 1,
	1, 0,

	1, 1,
	0, 1,
	1, 0,

	//Y Axis
	//Negative Face
	0, 0,
	0, 1,
	1, 0,

	1, 1,
	0, 1,
	1, 0
};

class Cube : public GeometryShape
{
public:
	Cube() : GeometryShape() { }
	Cube(GLuint textureID) : GeometryShape(textureID) { }
	Cube(int textureID) : GeometryShape(textureID) { }
	Cube(Vector position, Vector rotation, Vector scale, GLuint textureID) : GeometryShape(position, rotation, scale, textureID) { }
	Cube(Vector position, Vector rotation, Vector scale, int textureID) : GeometryShape(position, rotation, scale, textureID) { }

	void Draw(const Matrix& parentMatrix)
	{
		Matrix translationMatrix = Matrix::makeTranslationMatrix(position);
		Matrix rotationMatrix =
			Matrix::makeRotateMatrix(rotation.mVal[2], Vector(0.0f, 0.0f, 1.0f)) *
			Matrix::makeRotateMatrix(rotation.mVal[1], Vector(0.0f, 1.0f, 0.0f)) *
			Matrix::makeRotateMatrix(rotation.mVal[0], Vector(1.0f, 0.0f, 0.0f));
		Matrix scaleMatrix = Matrix::makeScaleMatrix(scale);

		glLoadMatrixf((GLfloat*)(parentMatrix * translationMatrix * rotationMatrix * scaleMatrix).mVal);

		//Enable Vertex Mode
		glEnableClientState(GL_VERTEX_ARRAY);

		//Enable Texture Mode
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnable(GL_TEXTURE_2D); //Enable texturing
		glBindTexture(GL_TEXTURE_2D, textureID); //Bind Texture

		//Enable Color Mode
		//glEnableClientState(GL_COLOR_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, cubeVertices);
		glTexCoordPointer(2, GL_FLOAT, 0, cubeTexCoords);
		//GLubyte cubeColor[108];
		//colorArray.GetValue(cubeColor);
		//glColorPointer(3, GL_UNSIGNED_BYTE, 0, cubeColor);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Disable Vertex Mode
		glDisableClientState(GL_VERTEX_ARRAY);

		//Disable Texture Mode
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisable(GL_TEXTURE_2D); //Disable texturing

		//Disable Color Mode
		//glDisableClientState(GL_COLOR_ARRAY);

		glLoadMatrixf((GLfloat*)(parentMatrix).mVal);
	}
};

class AudioVisualizer : public DemoBase
{
private:
	GLFWwindow *window;
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
	FMOD::Sound* m_bufferMusic[4];
	FMOD::Sound* m_music[4];
	FMOD::Channel* m_bufferChannel;
	FMOD::Channel* m_musicChannel;

	float m_spectrumLeft[SPECTRUM_SIZE];
	float m_spectrumRight[SPECTRUM_SIZE];

	float m_bufferSpectrumLeft[SPECTRUM_SIZE];
	float m_bufferSpectrumRight[SPECTRUM_SIZE];

public:
	Cube innerCubes[SPECTRUM_START * 2];
	std::vector<Cube> cubes[SPECTRUM_SIZE_SHOWN * 2];
	float cubeScale = 0.25f;
	float cubeZScale = 0.01f;
	float cubeZOffsetInner = -25.0f;
	float cubeZOffsetOuter = -50.0f;
	float spacing = 0.25f;
	float dropRate = 0.5f;
	float moveRate = 1.0f;
	float amplifyValue = 100.0f;
	int cycles = (int)((cubeZOffsetOuter >= 0 ? cubeZOffsetOuter : -cubeZOffsetOuter) / moveRate);

	//Circle
	float radius = 5.0f;
	float tOuter = 360.0f / (SPECTRUM_SIZE_SHOWN * 2);
	float tInner = 360.0f / (SPECTRUM_START * 2);

	//Sensitivity
	float innerSens = 0.001f;
	float outerSens = 0.025f;

	//Color
	float requiredGrowth = 0.01f * amplifyValue;
	SEASONS season = SEASONS_UNDECIDED;

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
		result = m_fmodSystem->createStream("../media/Vivaldi-Spring.mp3", FMOD_SOFTWARE, 0, &m_bufferMusic[0]);
		ERRCHECK(result);
		result = m_fmodSystem->createStream("../media/Vivaldi-Spring.mp3", FMOD_SOFTWARE, 0, &m_music[0]);
		ERRCHECK(result);
		result = m_fmodSystem->createStream("../media/Vivaldi-Summer.mp3", FMOD_SOFTWARE, 0, &m_bufferMusic[1]);
		ERRCHECK(result);
		result = m_fmodSystem->createStream("../media/Vivaldi-Summer.mp3", FMOD_SOFTWARE, 0, &m_music[1]);
		ERRCHECK(result);
		result = m_fmodSystem->createStream("../media/Vivaldi-Autumn.mp3", FMOD_SOFTWARE, 0, &m_bufferMusic[2]);
		ERRCHECK(result);
		result = m_fmodSystem->createStream("../media/Vivaldi-Autumn.mp3", FMOD_SOFTWARE, 0, &m_music[2]);
		ERRCHECK(result);
		result = m_fmodSystem->createStream("../media/Vivaldi-Winter.mp3", FMOD_SOFTWARE, 0, &m_bufferMusic[3]);
		ERRCHECK(result);
		result = m_fmodSystem->createStream("../media/Vivaldi-Winter.mp3", FMOD_SOFTWARE, 0, &m_music[3]);
		ERRCHECK(result);

		//loadMusicOnChannel();
	}

	void loadMusicOnChannel()
	{
		FMOD_RESULT result;

		//Setup the buffered mp3 music
		result = m_fmodSystem->playSound(FMOD_CHANNEL_REUSE, m_bufferMusic[season], false, &m_bufferChannel);
		ERRCHECK(result);

		//Set buffer channel volume to zero
		result = m_bufferChannel->setVolume(0.0f);
		ERRCHECK(result);

		//Setup the loaded mp3 music
		result = m_fmodSystem->playSound(FMOD_CHANNEL_REUSE, m_music[season], false, &m_musicChannel);
		ERRCHECK(result);

		//Pause the loaded mp3 music first
		result = m_musicChannel->setPaused(true);
		ERRCHECK(result);

		hasStarted = false;
	}

	void init()
	{
		// To support alpha channel
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_ALPHA_TEST);

		glGenTextures(TEXTURE_COUNT, mTextureID);
		loadPNG("../media/Textures/LighterBlend-Spring.png", mTextureID[0]);
		loadPNG("../media/Textures/Blend-Spring.png", mTextureID[1]);
		loadPNG("../media/Textures/Explosion-Spring.png", mTextureID[2]);
		loadPNG("../media/Textures/Normal-Spring.png", mTextureID[3]);
		loadPNG("../media/Textures/LighterBlend-Summer.png", mTextureID[4]);
		loadPNG("../media/Textures/Blend-Summer.png", mTextureID[5]);
		loadPNG("../media/Textures/Explosion-Summer.png", mTextureID[6]);
		loadPNG("../media/Textures/Normal-Summer.png", mTextureID[7]);
		loadPNG("../media/Textures/LighterBlend-Autumn.png", mTextureID[8]);
		loadPNG("../media/Textures/Blend-Autumn.png", mTextureID[9]);
		loadPNG("../media/Textures/Explosion-Autumn.png", mTextureID[10]);
		loadPNG("../media/Textures/Normal-Autumn.png", mTextureID[11]);
		loadPNG("../media/Textures/LighterBlend-Winter.png", mTextureID[12]);
		loadPNG("../media/Textures/Blend-Winter.png", mTextureID[13]);
		loadPNG("../media/Textures/Explosion-Winter.png", mTextureID[14]);
		loadPNG("../media/Textures/Normal-Winter.png", mTextureID[15]);

		initFmod();

		for (int i = 0; i < SPECTRUM_START * 2; i++)
		{
			float x1 = (radius/1.0f) * cos((i * tInner) * PI / 180.0);
			float y1 = (radius/1.0f) * sin((i * tInner) * PI / 180.0);

			innerCubes[i].scale.mVal[0] = cubeScale;
			innerCubes[i].scale.mVal[1] = cubeScale;
			innerCubes[i].scale.mVal[2] = cubeZScale;
			innerCubes[i].position.mVal[0] = x1;
			innerCubes[i].position.mVal[1] = y1;
			innerCubes[i].position.mVal[2] = cubeZScale + cubeZOffsetInner;
		}

		std::cout << std::endl << std::endl;
		std::cout << "\t" << "              ================================" << std::endl;
		std::cout << "\t" << "              ||   Vivaldi - Four Seasons   ||" << std::endl;
		std::cout << "\t" << "              ================================" << std::endl;
		std::cout << std::endl;
		std::cout << "\t" << "-------------------------------------------------------------" << std::endl;
		std::cout << "\t" << "  Select masterpiece by pressing a key in the OpenGL window" << std::endl;
		std::cout << "\t" << "-------------------------------------------------------------" << std::endl;
		std::cout << "\t" << "                       Key 1: Spring" << std::endl;
		std::cout << "\t" << "                       Key 2: Summer" << std::endl;
		std::cout << "\t" << "                       Key 3: Autumn" << std::endl;
		std::cout << "\t" << "                       Key 4: Winter" << std::endl;
	}

	void setWindow(GLFWwindow* window)
	{
		this->window = window;
	}

	void deinit() { }

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

	bool hasStarted = false;

	void updateFmod()
	{
		m_fmodSystem->update();

		//Get spectrum for left and right stereo channels
		m_musicChannel->getSpectrum(m_spectrumLeft, SPECTRUM_SIZE, 0, FMOD_DSP_FFT_WINDOW_RECT);
		m_musicChannel->getSpectrum(m_spectrumRight, SPECTRUM_SIZE, 1, FMOD_DSP_FFT_WINDOW_RECT);
		m_bufferChannel->getSpectrum(m_bufferSpectrumLeft, SPECTRUM_SIZE, 0, FMOD_DSP_FFT_WINDOW_RECT);
		m_bufferChannel->getSpectrum(m_bufferSpectrumRight, SPECTRUM_SIZE, 1, FMOD_DSP_FFT_WINDOW_RECT);

		if (!hasStarted)
		{
			unsigned int time;
			m_bufferChannel->getPosition(&time, FMOD_TIMEUNIT_MS);
			//std::cout << "(" << time << "/" << cycles << ")" << std::endl;
			if (time >= cycles)
			{
				m_musicChannel->setPaused(false);
				hasStarted = true;
			}
		}

		//Print the first audio spectrum for both left and right channels
		//std::cout << m_spectrumLeft[0] << ", " << m_spectrumRight[0] << std::endl;
	}

	int oldState[4] = { GLFW_RELEASE };

	void updateKeys()
	{
		int newState[4] = { GLFW_RELEASE };
		newState[0] = glfwGetKey(window, '1');
		newState[1] = glfwGetKey(window, '2');
		newState[2] = glfwGetKey(window, '3');
		newState[3] = glfwGetKey(window, '4');

		for (int i = 0; i < 4; i++)
		{
			if (newState[i] == GLFW_PRESS && oldState[i] == GLFW_RELEASE)
			{
				// Load new season
				season = (SEASONS)i;
				switch (season)
				{
					case 0:
						system("color A0");
						break;
					case 1:
						system("color E0");
						break;
					case 2:
						system("color 4F");
						break;
					case 3:
						system("color 1F");
						break;
				}
				loadMusicOnChannel();
			}

			oldState[i] = newState[i];
		}
	}

	int colorSwitch = 0;

	void draw(const Matrix& viewMatrix)
	{
		updateKeys();

		drawAxis(viewMatrix);

		glLoadMatrixf((GLfloat*)viewMatrix.mVal);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Show Wireframes

		if (season == SEASONS_UNDECIDED)
		{
			if(colorSwitch == 0)
				system("color 0F");
			else if (colorSwitch == 10)
				system("color 8F");

			colorSwitch = (colorSwitch + 1) % 20;
			return;
		}

		updateFmod();

		//Inner Cubes
		for (int i = 0; i < SPECTRUM_START; i++)
		{
			float newSpectrumL = cubeZScale + cubeZOffsetInner + (m_spectrumLeft[i] * amplifyValue);

			innerCubes[(i * 2)].scale.mVal[0] = (m_spectrumLeft[i] * 10.0f + 1.0f) * cubeScale;
			innerCubes[(i * 2)].scale.mVal[1] = (m_spectrumLeft[i] * 10.0f + 1.0f) * cubeScale;

			if (innerCubes[(i * 2)].position.mVal[2] > cubeZScale + cubeZOffsetInner)
				innerCubes[(i * 2)].position.mVal[2] -= dropRate;
			if (innerCubes[(i * 2)].position.mVal[2] < cubeZScale + cubeZOffsetInner)
				innerCubes[(i * 2)].position.mVal[2] = cubeZScale + cubeZOffsetInner;
			if (innerCubes[(i * 2)].position.mVal[2] < newSpectrumL && m_spectrumLeft[i] >= innerSens)
			{
				if (innerCubes[(i * 2)].position.mVal[2] + requiredGrowth < newSpectrumL)
					innerCubes[(i * 2)].textureID = mTextureID[(season * 4) + 3];

				innerCubes[(i * 2)].position.mVal[2] = newSpectrumL;
			}
			else if (m_spectrumLeft[i] >= innerSens * 32.0f)
				innerCubes[(i * 2)].textureID = mTextureID[(season * 4) + 0];
			else if (m_spectrumLeft[i] >= innerSens * 16.0f)
				innerCubes[(i * 2)].textureID = mTextureID[(season * 4) + 2];
			else if (m_spectrumLeft[i] >= innerSens * 8.0f)
				innerCubes[(i * 2)].textureID = mTextureID[(season * 4) + 3];
			else
				innerCubes[(i * 2)].textureID = mTextureID[(season * 4) + 1];
			innerCubes[(i * 2)].Draw(viewMatrix);

			float newSpectrumR = cubeZScale + cubeZOffsetInner + (m_spectrumRight[i] * amplifyValue);

			innerCubes[(i * 2) + 1].scale.mVal[0] = (m_spectrumRight[i] * 10.0f + 1.0f) * cubeScale;
			innerCubes[(i * 2) + 1].scale.mVal[1] = (m_spectrumRight[i] * 10.0f + 1.0f) * cubeScale;

			if (innerCubes[(i * 2) + 1].position.mVal[2] > cubeZScale + cubeZOffsetInner)
				innerCubes[(i * 2) + 1].position.mVal[2] -= dropRate;
			if (innerCubes[(i * 2) + 1].position.mVal[2] < cubeZScale + cubeZOffsetInner)
				innerCubes[(i * 2) + 1].position.mVal[2] = cubeZScale + cubeZOffsetInner;
			if (innerCubes[(i * 2) + 1].position.mVal[2] < newSpectrumR && m_spectrumRight[i] >= innerSens)
			{
				if (innerCubes[(i * 2) + 1].position.mVal[2] + requiredGrowth < newSpectrumR)
					innerCubes[(i * 2) + 1].textureID = mTextureID[(season * 4) + 3];

				innerCubes[(i * 2) + 1].position.mVal[2] = newSpectrumR;
			}
			else if (m_spectrumRight[i] >= innerSens * 32.0f)
				innerCubes[(i * 2) + 1].textureID = mTextureID[(season * 4) + 0];
			else if (m_spectrumRight[i] >= innerSens * 16.0f)
				innerCubes[(i * 2) + 1].textureID = mTextureID[(season * 4) + 2];
			else if (m_spectrumRight[i] >= innerSens * 8.0f)
				innerCubes[(i * 2) + 1].textureID = mTextureID[(season * 4) + 3];
			else
				innerCubes[(i * 2) + 1].textureID = mTextureID[(season * 4) + 1];
			innerCubes[(i * 2) + 1].Draw(viewMatrix);
		}
		
		//Outer Cubes
		for (int i = 0; i < SPECTRUM_SIZE_SHOWN; i++)
		{
			if (m_bufferSpectrumLeft[SPECTRUM_START + i] >= outerSens)
			{
				Cube newCube;
				newCube.scale.mVal[0] = cubeScale;
				newCube.scale.mVal[1] = cubeScale;
				newCube.scale.mVal[2] = cubeZScale;
				newCube.position.mVal[0] = radius * cos(((i * 2) * tOuter) * PI / 180.0);
				newCube.position.mVal[1] = radius * sin(((i * 2) * tOuter) * PI / 180.0);
				newCube.position.mVal[2] = cubeZScale + cubeZOffsetOuter;

				cubes[(i * 2)].push_back(newCube);
			}

			if (m_bufferSpectrumRight[SPECTRUM_START + i] >= outerSens)
			{
				Cube newCube;
				newCube.scale.mVal[0] = cubeScale;
				newCube.scale.mVal[1] = cubeScale;
				newCube.scale.mVal[2] = cubeZScale;
				newCube.position.mVal[0] = radius * cos((((i * 2) + 1) * tOuter) * PI / 180.0);
				newCube.position.mVal[1] = radius * sin((((i * 2) + 1) * tOuter) * PI / 180.0);
				newCube.position.mVal[2] = cubeZScale + cubeZOffsetOuter;

				cubes[(i * 2) + 1].push_back(newCube);
			}
		}

		for (int i = 0; i < SPECTRUM_SIZE_SHOWN * 2; i++)
		{
			if (!cubes[i].empty())
			{
				for(std::vector<Cube>::iterator itr = cubes[i].begin(); itr != cubes[i].end();)
				{
					itr->position.mVal[2] += moveRate;
					if (itr->position.mVal[2] >= 10.0f)
					{
						itr = cubes[i].erase(itr);
						continue;
					}
					else if (itr->position.mVal[2] >= -2.5f)
					{
						itr->textureID = mTextureID[(season * 4) + 3];
						// I give up, my CustomColor class doesn't work
						// I don't want to assign a hard-coded 108 GLubyte in an array every time to change the color
						// So I use a 1x1 texture with a solid color to do it...
						itr->scale.mVal[0] = cubeScale * 0.5f;
						itr->scale.mVal[1] = cubeScale * 0.5f;
					}
					else if (itr->position.mVal[2] >= -5.0f)
					{
						itr->textureID = mTextureID[(season * 4) + 2];
						itr->scale.mVal[0] = cubeScale * 2.0f;
						itr->scale.mVal[1] = cubeScale * 2.0f;
					}
					else if (itr->position.mVal[2] >= -10.0f)
					{
						itr->textureID = mTextureID[(season * 4) + 0];
						itr->scale.mVal[0] = cubeScale * 1.5f;
						itr->scale.mVal[1] = cubeScale * 1.5f;
					}
					else if (itr->position.mVal[2] >= -25.0f)
					{
						itr->textureID = mTextureID[(season * 4) + 1];
						itr->scale.mVal[0] = cubeScale;
						itr->scale.mVal[1] = cubeScale;
					}
					else
					{
						itr->textureID = mTextureID[(season * 4) + 3];
						itr->scale.mVal[0] = cubeScale;
						itr->scale.mVal[1] = cubeScale;
					}
					itr->Draw(viewMatrix);
					itr++;
				}
			}
		}
	}
};

#endif
