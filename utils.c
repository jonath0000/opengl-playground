#include <stdio.h>
#include <GL/glut.h>
#include "utils.h"

GLuint loadTexture(const char * filename, int width, int height) {
    GLuint texture;
    unsigned char * data;
    FILE * file;
    
    file = fopen(filename, "rb");
    if (file == NULL) return 0;
    data = (unsigned char *)malloc(width * height * 3);
    fread(data, width * height * 3, 1, file);
    fclose(file);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, 
		 GL_RGB, GL_UNSIGNED_BYTE, data);
    free(data);
    return texture;
}

void freeTexture(GLuint texture) {
  glDeleteTextures(1, &texture);
}
