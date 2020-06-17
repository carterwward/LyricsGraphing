
#ifndef BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_BARGRAPH_H
#define BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_BARGRAPH_H

#include <string>
#include <vector>
#include "Graphics.h"


using namespace std;
class BarGraph {
protected:
    int startPixelx;
    int startPixely;
    int numBars;
    double maxHeight;
    int yAxisHeight;
    int xAxisLength;
    string title;
    string yAxisTitle;
    string xAxisTitle;
    vector<double> uniqueStats;

public:
    //Takes in start pixel for x,y (this is where the graph will "start"). THe axis length is also inputted as will as the titles.
    //This also takes in a vector of unique stats. These unique stats are EXPECTED to be in order of tracklist, so that the first element
    //corresponds to the first song
    BarGraph(int startPixelx, int startPixely, int yAxisHeight, int xAxisLength, string title, string yAxisTitle, string xAxisTitle, vector<double> uniqueStats);

    //draws the bar graph with the specified height and length as well as titles and starting position for the inputted data set
    virtual void draw() const;

    //Getters
    int getStartPixelx() const;
    int getStartPixely() const;
    int getNumBars() const;
    double getMaxHeight() const;
    int getYAxisHeight() const;
    int getXAxisLength() const;
    string getTitle() const;
    string getYaAxisTitle() const;
    string getXAxisTitle() const;
    vector<double> getUniqueStats() const;

    //Setters
    void setStartPixelx(int startPixelx);
    void setStartPixely(int startPixely);
    void setNumBars(int numBars);
    void setMaxHeight(double maxHeight);
    void setYAxisHeight(int yAxisHeight);
    void setXAxisLength(int xAxisLength);
    void setTitle(string title);
    void setYaAxisTitle(string yAxisTitle);
    void setXAxisTitle(string xAxisTitle);
    void setUniqueStats(vector<double> uniqueStats);

};


#endif //BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_BARGRAPH_H
