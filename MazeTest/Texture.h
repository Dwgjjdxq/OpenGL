#ifndef TEXTURE_H
#define TEXTURE_H

#include<string.h>
#include<GL\glew.h>
#include<SOIL\SOIL.h>
class Texture
{
public:

	//ͼƬID
	GLuint texture;
	Texture(const GLchar* texturePath,GLuint id);

	//���û��Ʒ�ʽ
	void setWrapping(const GLchar* mays);

	//���ù��˷�ʽ
	void setFiltering(const GLchar* mays);

	//��������
	void getTexture();
	//�����������ͷ�ͼ������
	void releaseTexture();
	~Texture();

private:

	//ͼƬ����ֵ��߶�ֵ
	int width;
	int height;
	//��ȡͼƬ���ݱ���
	unsigned char* image;


};

Texture::Texture(const GLchar* texturePath, GLuint id)
{
	glGenTextures(id, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	image = SOIL_load_image(texturePath, &width, &height, 0, SOIL_LOAD_RGB);
}
void Texture::setWrapping(const GLchar* ways){
	if (ways == "REPET"){
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
	
}
void Texture::setFiltering(const GLchar* ways){
	if (ways == "NEAREST"){
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}

	if (ways == "LINER"){
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

}

void Texture::getTexture(){
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
}
void Texture::releaseTexture(){
	
	SOIL_free_image_data(image);   //�ͷ�ͼ������
	glBindTexture(GL_TEXTURE_2D, 0);	//����������
}

Texture::~Texture()
{
}
#endif