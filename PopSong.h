//
// Created by Cameron Hudson on 4/4/20.
//
#ifndef BL_CH_CW_JS_FINAL_PROJECT_Graphics_POPSONG_H
#define BL_CH_CW_JS_FINAL_PROJECT_Graphics_POPSONG_H

#include "Song.h"
#include <string>
#include <vector>

using namespace std;

class PopSong: public Song{
public:
// Constructor
    PopSong();

    explicit PopSong(string name, int index, double length, string lyrics, int popularityScore);


    // Requires: nothing
    // Modifies: nothing
    // Effects: takes popularity and divides it by length of song
    double calculateUniqueStat() override;
};


#endif //BL_CH_CW_JS_FINAL_PROJECT_Graphics_POPSONG_H
