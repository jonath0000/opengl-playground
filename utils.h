#ifndef UTILS_H
#define UTILS_H

#include <GL/glut.h>

extern GLuint loadTexture(const char * filename, int width, int height);
extern void freeTexture(GLuint texture);

#endif
