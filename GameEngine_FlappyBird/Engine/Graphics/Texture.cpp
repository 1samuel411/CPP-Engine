#include "Texture.h"

Texture::Texture()
{
	id = -1;
	width = 0;
	height = 0;
}

Texture::Texture(int id)
{
	Texture::id = id;

	if (GetTextureParams() == false)
	{
		cout << "Error loading image with id: " << id << endl;
	}

	width = 0;
	height = 0;
}

Texture::Texture(string path)
{
	width = 0;
	height = 0;
	id = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y);
	if (GetTextureParams() == false)
	{
		cout << "Error loading image from: " << path << endl;
	}
}

int Texture::GetID()
{
	return id;
}

int Texture::GetWidth()
{
	return width;
}

int Texture::GetHeight()
{
	return height;
}

bool Texture::GetTextureParams()
{
	if (id > 0)
	{
		int miplevel = 0;
		glBindTexture(GL_TEXTURE_2D, id);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_WIDTH, &width);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_HEIGHT, &height);

		return true;
	}

	return false;
}