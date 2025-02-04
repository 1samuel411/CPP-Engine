#include "SpriteRenderer.h"
#include "../../Objects/Object.h"

SpriteRenderer::SpriteRenderer(string path, int _width, int _height)
{
	textures.insert(textures.end(), Texture::Texture(path));
	updateTimer = 0;
	curUpdateTimer = -1;
	width = _width;
	height = _height;
}

SpriteRenderer::SpriteRenderer(string path[], int length, float _updateTime, int _width, int _height)
{
	for (int i = 0; i < length; i++)
	{
		textures.insert(textures.end(), Texture::Texture(path[i]));
	}
	updateTimer = _updateTime;
	curUpdateTimer = Time::GetTimeRunning() + updateTimer;
	width = _width;
	height = _height;
}

void SpriteRenderer::Start()
{
}

void SpriteRenderer::Update()
{
}

void SpriteRenderer::Render()
{
	if (curUpdateTimer - Time::GetTimeRunning() <= 0 && curUpdateTimer != -1)
	{
		index++;
		if (index >= textures.size())
		{
			index = 0;
		}
		curUpdateTimer = Time::GetTimeRunning() + updateTimer;
	}
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, next(textures.begin(), index)->GetID());
	glLoadIdentity();

	// translate
	glTranslatef(object->transform->position.x, object->transform->position.y, 0);
	// rotate
	//glRotatef(rotation, 0, 0, 1);
	// scale
	glScalef(object->transform->scale.x, object->transform->scale.y, 1);

	// color
	glColor4f(1, 1, 1, 1);

	glBegin(GL_QUADS);
	// Top left
	glTexCoord2f(0, 0);		glVertex2f(0, 0);
	// Top right
	glTexCoord2f(1, 0);		glVertex2f(width, 0);
	// Bottom right
	glTexCoord2f(1, 1);		glVertex2f(width, height);
	// Bottom left
	glTexCoord2f(0, 1);		glVertex2f(0, height);

	glEnd();

	glDisable(GL_TEXTURE_2D);
}