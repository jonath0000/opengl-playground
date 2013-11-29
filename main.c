#include <GL/glut.h>
#include "utils.h"

const int g_fps = 60;
int g_resetTimer = 1;


void processKeys(unsigned char key, int x, int y) {

}


void update() {
    g_resetTimer = 1;
    glutPostRedisplay();
}


void updateTimer() {
    if (g_resetTimer != 0) {
	glutTimerFunc(1000/g_fps, update, 0); 
	g_resetTimer = 0;
    }
}


void render() {
    updateTimer();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);

    glutCreateWindow("GL");

    glutDisplayFunc(render);
    glutIdleFunc(updateTimer);
    glutTimerFunc(100, update, 0);

    glutKeyboardFunc(processKeys);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();

    return 0;
}
