//
// Created by Cameron Hudson on 4/4/20.
//
#include "Song.h"
#include <sstream>
#include <map>
#include <algorithm>

Song::Song() : songName("song"), songLength(60), lyrics(""), totalWordCount(0), albumIndex(0) {
}

Song::Song(string name, int index, double length, string lyrics, int popScore) {
    this->songName = name;
    this->songLength = length;
    this->lyrics = lyrics;
    this->totalWordCount = split(lyrics, ' ').size();
    this->albumIndex = index;
    this->popularity = popScore;
}

string Song::getSongName() const{
    return songName;
}

double Song::getSongLength() const{
    return songLength;
}

string Song::getLyrics() const{
    return lyrics;
}

int Song::getTotalWordCount() const{
    return totalWordCount;
}

int Song::getIndex() const {
    return albumIndex;
}

void Song::setSongName(string songName) {
    this->songName = songName;
}

void Song::setSongLength(int songLength) {
    this->songLength = songLength;
}

void Song::setLyrics(string lyrics) {
    this->lyrics = lyrics;
}

void Song::setTotalWordCount(int totalWordCount) {
    this->totalWordCount = totalWordCount;
}

void Song::setIndex(int index) {
    this->albumIndex = index;
}

int Song::getPopularityScore() const {
    return popularity;
}

void Song::setPopularityScore(int popularityScore) {
    popularity = popularityScore;
}


// make private out of class field
vector<string> split(string str, char space) {
    vector<string> internal;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    str.erase(remove(str.begin(), str.end(), '/'), str.end());
    str.erase(remove(str.begin(), str.end(), '?'), str.end());
    str.erase(remove(str.begin(), str.end(), '!'), str.end());
    str.erase(remove(str.begin(), str.end(), ':'), str.end());
    str.erase(remove(str.begin(), str.end(), ';'), str.end());
    str.erase(remove(str.begin(), str.end(), '\''), str.end());
    
    stringstream ss(str); // Turn the string into a stream.
    string tok;
    while(getline(ss, tok, space)) {
        internal.push_back(tok);
    }
    return internal;
}






