#include "GraphicsTest.h"
#include "Button.h"
#include "Quad.h"
#include <time.h>
using namespace std;
GLdouble width, height;
int wd;
string str;
Button bt({1.0, 1.0, 0.0}, {250, 250}, 250, 50, "Artist: ");
Quad artist({1.0, 0, 1.0}, {100, 100}, 250, 50);
Quad album({0.0, 1.0, 1.0}, {100, 300}, 250, 50);


void init() {
    width = 500;
    height = 500;
    srand(time(0));
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(1.0f, 1.0f, 0.8f, 0.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE

    // Do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

    // Clear the color buffer with current clearing color
    glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE

    /*
     * Draw here
     */
    bt.draw();

    artist.draw();
    glutKeyboardFunc(kbd);
    glRasterPos2f(0., 0.);
    glColor3f(0, 0, 0);
    glRasterPos2i(100 - (4 * str.length()), 100 + 7);
    for (const char &letter : str) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }



    album.draw();
    glutKeyboardFunc(kbd);
    glRasterPos2f(0., 0.);
    glColor3f(0, 0, 0);
    glRasterPos2i(100 - (4 * str.length()), 300 + 7);
    for (const char &letter : str) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }

    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    if (key == 'a') {
        str += 'a';
    }
    else if (key == 127) {
        str.pop_back();
    }
    else if (key == ',') {
        str += ',';
    }
    else if (key == 'b') {
        str += 'b';
    }
    else if (key == 'c') {
        str += 'c';
    }
    else if (key == 'd') {
        str += 'd';
    }
    else if (key == 'e') {
        str += 'e';
    }
    else if (key == 'f') {
        str += 'f';
    }
    else if (key == 'g') {
        str += 'g';
    }
    else if (key == 'h') {
        str += 'h';
    }
    else if (key == 'i') {
        str += 'i';
    }
    else if (key == 'j') {
        str += 'j';
    }
    else if (key == 'k') {
        str += 'k';
    }
    else if (key == 'l') {
        str += 'l';
    }
    else if (key == 'm') {
        str += 'm';
    }
    else if (key == 'n') {
        str += 'n';
    }
    else if (key == 'o') {
        str += 'o';
    }
    else if (key == 'p') {
        str += 'p';
    }
    else if (key == 'q') {
        str += 'q';
    }
    else if (key == 'r') {
        str += 'r';
    }
    else if (key == 's') {
        str += 's';
    }
    else if (key == 't') {
        str += 't';
    }
    else if (key == 'u') {
        str += 'u';
    }
    else if (key == 'v') {
        str += 'v';
    }
    else if (key == 'w') {
        str += 'w';
    }
    else if (key == 'x') {
        str += 'x';
    }
    else if (key == 'y') {
        str += 'y';
    }
    else if (key == 'z') {
        str += 'z';
    }
    else if (key == 32) {
        str += ' ';
    }
    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT:

            break;
        case GLUT_KEY_RIGHT:

            break;
        case GLUT_KEY_UP:

            break;

    }

    glutPostRedisplay();
}

void cursor(int x, int y) {
    if(bt.isOverlapping(x, y)) {
        bt.hover();
    } else {
        bt.release();
    }
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && bt.isOverlapping(x, y)) {
        bt.pressDown();
    } else {
        bt.release();
    }

    glutPostRedisplay();
}

void timer(int dummy) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100,100); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Graphics Final!" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    glEnd();
    return 0;
}