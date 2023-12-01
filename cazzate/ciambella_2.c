#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

static int slices = 16;
static int stacks = 16;
static float angle = 0.0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
    glRotatef(angle, 1.0, 1.0, 1.0);

    glColor3f(1.0, 0.0, 0.0);
    glutSolidTorus(1.0, 2.0, slices, stacks);

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 1.0, 100.0);
}

void idle() {
    angle += 1.0;
    if (angle > 360.0) {
        angle -= 360.0;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Ciambella Che Gira");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}
