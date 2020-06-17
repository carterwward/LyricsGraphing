//
// Created by Cameron Hudson on 4/4/20.
//
#include "PopSong.h"
#include <sstream>
#include <map>
#include <algorithm>

PopSong::PopSong() : Song() {
}

PopSong::PopSong(string name, int index, double length, string lyrics, int popularityScore) : Song(name, index, length, lyrics, popularityScore) {
}

double PopSong::calculateUniqueStat(){
    double PopularityPerSec = ((double)(this->popularity))/(this->songLength);
    return PopularityPerSec;
}





