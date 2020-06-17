#include "Graphics.h"
#include "Quad.h"
#include "SubmitButton.h"
#include "BooleanButton.h"
#include "BarGraph.h"
#include "Album.h"
#include "Song.h"
#include "RapSong.h"
#include "PopSong.h"
#include <time.h>
#include <sstream>
#include <iostream>
#ifdef _WIN32
const string python = "python";
#else
const string python = "python3";
#endif
using namespace std;
GLdouble width, height;
int wd;
string str;
string artist;
string album;
string prompt = "Enter album, artist";
string genre = "Genre: Rap";
vector<double> heights;
bool rap = true;

SubmitButton s({1.0, 1.0, 0.0}, {250, 250}, 250, 50, "Submit");
BooleanButton b({1.0, 1.0, 0.0}, {250, 310}, 250, 50, "Change Genre");
//SubmitButton s({1.0, 1.0, 0.0}, {250, 250}, 250, 50, "test");
Quad input({0.0, 1.0, 1.0}, {250, 500}, 250, 50);
Quad promptBox({1.0, 1.0, 1.0}, {250, 450}, 250, 50);
Quad genreBox({1.0, 1.0, 1.0}, {250, 370}, 250, 50);
vector<double> testVector = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
BarGraph test(700, 500, 300, 300, "Song Analysis", "", "Tracks in order of 1 to n", testVector);

void init() {
    width = 1200;
    height = 750;
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
//    glRasterPos2i(250 - (4 * str.length()), 250 + 7);
    s.draw();
    b.draw();
    test.draw();
    input.draw();
    promptBox.draw();
    genreBox.draw();
    glutKeyboardFunc(kbd);

    glRasterPos2f(0., 0.);
    glColor3f(0, 0, 0);
    glRasterPos2i(250 - (4 * str.length()), 500 + 7);
    for (const char &letter : str) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }

    glRasterPos2f(0., 0.);
    glColor3f(0, 0, 0);
    glRasterPos2i(250 - (4 * prompt.length()), 450 + 7);
    for (const char &letter : prompt) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }

    if (rap) {
        genre = "Genre: Rap";
    } else {
        genre = "Genre: Pop";
    }
    glRasterPos2f(0., 0.);
    glColor3f(0, 0, 0);
    glRasterPos2i(250 - (4 * genre.length()), 370 + 7);
    for (const char &letter : genre) {
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
    else if ((key == 127 or key == 8) and !str.empty()) {
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
    if(s.isOverlapping(x, y)) {
        s.hover();
    } else {
        s.release();
    }
    if(b.isOverlapping(x, y)) {
        b.hover();
    } else {
        b.release();
    }
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && s.isOverlapping(x, y) && state == GLUT_DOWN) {
        s.pressDown();
    } else {
        s.release();
    }
    if(button == GLUT_LEFT_BUTTON && b.isOverlapping(x, y) && state == GLUT_DOWN) {
        b.pressDown();
    } else {
        b.release();
    }
    glutPostRedisplay();
}

void timer(int dummy) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

// first index is artist, second index is album
void artistAlbum() {
    // root directory where everything will be stored
    string root = "albums";
    // creates directory if it doesnt exist
    if (!fs::exists(root)) {
        fs::create_directories(root);
    }
    std::vector<std::string> data;
    std::stringstream ss(str);
    while(ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        data.push_back(substr);
    }
    album = data[0];
    artist = data[1];
    strReplace(album, ' ', '-');
    strReplace(artist, ' ', '-');
    // run python script
    string command = python + " ../lyrics.py " + artist + " " + album;
    system(command.c_str());
    map<string, unique_ptr<Song>> songMap = readFromFolder("albums" + std::string("/") +album + '_' + artist.erase(0, 1), rap);
    heights.clear();
    heights.resize(size(songMap));
    double max = 0.0;
    for (auto const& [key, val] : songMap)
    {
        double stat = val->calculateUniqueStat();
        heights[val->getIndex() - 1] = (stat);
        if (stat > max) {
            max = stat;
        }
    }
    if (rap) {
        test.setYaAxisTitle("Unique words/Sec  ");
    } else {
        test.setYaAxisTitle("Popularity Score/Length");
    }
    test.setNumBars(size(heights));
    test.setMaxHeight(max);
    test.setUniqueStats(heights);
}

void typeMusic() {
    bool change = !rap;
    rap = change;
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