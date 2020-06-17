#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif
#include "BarGraph.h"
#include<iostream>
using namespace std;


BarGraph::BarGraph(int startPixelx, int startPixely, int yAxisHeight, int xAxisLength, string title, string yAxisTitle, string xAxisTitle, vector<double> uniqueStats){
    this->startPixelx = startPixelx;
    this->startPixely = startPixely;
    this->yAxisHeight = yAxisHeight;
    this->xAxisLength = xAxisLength;
    this->title = title;
    this->yAxisTitle = yAxisTitle;
    this->xAxisTitle = xAxisTitle;
    this->uniqueStats = uniqueStats;
    numBars = uniqueStats.size();
    int maxIndex = 0;
    for(int c = 0; c < numBars; ++c){
        if (uniqueStats[c] > uniqueStats[maxIndex]){
            maxIndex = c;
        }
    }
    maxHeight = uniqueStats[maxIndex];
}
void BarGraph::draw() const{
    //cout << this->uniqueStats[0] << endl;
    //Draw x-axis
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(startPixelx, startPixely);
    glVertex2f(startPixelx + xAxisLength,  startPixely);
    glEnd();

    //Draw y-axis
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(startPixelx, startPixely);
    glVertex2f(startPixelx,  startPixely - yAxisHeight);
    glEnd();

    //calculate bar lengths and heights
    int barWidth = (xAxisLength - (2*numBars))/numBars;
    int heightMultiplier = (yAxisHeight)/maxHeight;

    int leftX = startPixelx;
    int bottomY = startPixely;
    // draws the bars of the bar graph
    for(int c = 0; c < numBars; c++){

        leftX = leftX + 2;
        int rightX = leftX + barWidth;
        int topY = bottomY - (this->uniqueStats[c] * heightMultiplier);

        glBegin(GL_QUADS);
        glColor3f(0,0,1);
        // top left
        glVertex2i(leftX, topY);

        // bottom left
        glVertex2i(leftX, bottomY);

        // bottom right
        glVertex2i(rightX, bottomY);

        // top right
        glVertex2i(rightX, topY);

        glEnd();

        leftX = rightX;
    }

    //Draws title
    int xCenterTitle = startPixelx + (xAxisLength/2);
    int yCenterTitle = startPixely - yAxisHeight - 15;
    glColor3f(0, 0, 0);
    glRasterPos2i(xCenterTitle - (4 * title.length()), yCenterTitle - 15);
    for (const char &letter : title) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }

    //Draws x-axis title
    int xCenter = startPixelx + (xAxisLength/2);
    int yCenter = startPixely + 40;
    glColor3f(0, 0, 0);
    glRasterPos2i(xCenter - (4 * xAxisTitle.length()), yCenter + 7);
    for (const char &letter : xAxisTitle) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }

    //Draws y-axis title
    int xCenterYTitle = startPixelx - 5*(yAxisTitle.length()) - 7;
    int yCenterYTitle = startPixely - (yAxisHeight/2);
    glColor3f(0, 0, 0);
    glRasterPos2i(xCenterYTitle - (4 * yAxisTitle.length()), yCenterYTitle);
    for (const char &letter : yAxisTitle) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }
    // Draw max unit
    string maxText = "max value: " + to_string(maxHeight);
    int xMaxTitle = startPixelx - 20;
    int yMaxTitle = startPixely - yAxisHeight;
    glColor3f(0, 0, 0);
    glRasterPos2i(xMaxTitle - 7*size(maxText) - 15, yMaxTitle);
    for (const char &letter : maxText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }

    //draw x-axis units
    int xUnitTitle = startPixelx + (barWidth/2) + 1;
    int yUnitTitle = startPixely + 15;
    for(int c = 0; c < numBars; ++c){
        glColor3f(0, 0, 0);
        glRasterPos2i(xUnitTitle, yUnitTitle);
        string unit = to_string(c+1);
        for (const char &letter : unit) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, letter);
        }
        xUnitTitle = xUnitTitle + 3 + barWidth - unit.length();
    }



    // Don't forget to set the color to the fill field
}


//Getters
int BarGraph::getStartPixelx() const{
    return startPixelx;
}
int BarGraph::getStartPixely() const{
    return startPixely;
}
int BarGraph::getNumBars() const{
    return numBars;
}
double BarGraph::getMaxHeight() const{
    return maxHeight;
}
int BarGraph::getYAxisHeight() const{
    return yAxisHeight;
}
int BarGraph::getXAxisLength() const{
    return xAxisLength;
}
string BarGraph::getTitle() const{
    return title;
}
string BarGraph::getYaAxisTitle() const{
    return yAxisTitle;
}
string BarGraph::getXAxisTitle() const{
    return xAxisTitle;
}
vector<double> BarGraph::getUniqueStats() const{
    return uniqueStats;
}

//Setters
void BarGraph::setStartPixelx(int startPixelx) {
    this->startPixelx=startPixelx;
}
void BarGraph::setStartPixely(int startPixely){
    this->startPixely=startPixely;
}
void BarGraph::setNumBars(int numBars){
    this->numBars=numBars;
}
void BarGraph::setMaxHeight(double maxHeight){
    this->maxHeight=maxHeight;
}
void BarGraph::setYAxisHeight(int yAxisHeight){
    this->yAxisHeight=yAxisHeight;
}
void BarGraph::setXAxisLength(int xAxisLength){
    this->xAxisLength=xAxisLength;
}
void BarGraph::setTitle(string title){
    this->title=title;
}
void BarGraph::setYaAxisTitle(string yAxisTitle){
    this->yAxisTitle=yAxisTitle;
}
void BarGraph::setXAxisTitle(string xAxisTitle){
    this->xAxisTitle=xAxisTitle;
}
void BarGraph::setUniqueStats(vector<double> uniqueStats){
    this->uniqueStats = uniqueStats;
}

//void BarGraph::update(vector<double> nums) {
//    this
//}