#include "Sprite.h"

Sprite::Sprite()
{
	xPos = 0;
	yPos = 0;
	zRot = 0;
	scale = 1;
	texture = Texture();
}

Sprite::Sprite(string path)
{
	texture = Texture::Texture(path);
	xPos = 0;
	yPos = 0;
	zRot = 0;
	scale = 1;
}

Sprite::Sprite(string path, float _xPos, float _yPos)
{
	texture = Texture::Texture(path);
	xPos = _xPos;
	yPos = _yPos;
	zRot = 0;
	scale = 1;
}

void Sprite::Update()
{

}

void Sprite::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.GetID());
	glLoadIdentity();

	// translate
	glTranslatef(xPos, yPos, 0);
	// rotate
	//glRotatef(rotation, 0, 0, 1);
	// scale
	glScalef(scale, scale, scale);

	// color
	glColor4f(1, 1, 1, 1);

	glBegin(GL_QUADS);
	// Top left
	glTexCoord2f(0, 0);		glVertex2f(0, 0);
	// Top right
	glTexCoord2f(1, 0);		glVertex2f(texture.GetWidth(), 0);
	// Bottom right
	glTexCoord2f(1, 1);		glVertex2f(texture.GetWidth(), texture.GetHeight());
	// Bottom left
	glTexCoord2f(0, 1);		glVertex2f(0, texture.GetHeight());

	glEnd();

	glDisable(GL_TEXTURE_2D);
}