//
// Created by Cameron Hudson on 4/4/20.
//
#include "RapSong.h"
#include <sstream>
#include <map>
#include <algorithm>

RapSong::RapSong() : Song(){
}

RapSong::RapSong(string name, int index, double length, string lyrics, int popularity) : Song(name, index, length, lyrics, popularity) {
    uniqueWordCounter();
}


void RapSong::uniqueWordCounter() {
    // call split here
    vector<string> lyr = split(this->lyrics, ' ');
    map<string, int> mp;
    for (int i = 0; i < lyr.size(); ++i) {
        if(!mp.count(lyr[i]))
            mp.insert(make_pair(lyr[i], 1));
        else
            mp[lyr[i]]++;
    }
    int uniqueWordCount = 0;
    for (map<string, int> :: iterator p = mp.begin(); p != mp.end(); p++) {
        if (p->second == 1) {
            uniqueWordCount++;
        }
    }
    this->uniqueWords = uniqueWordCount;
}

double RapSong::calculateUniqueStat(){
    double uniqueWordsPerSec = ((double)(this->uniqueWords))/(this->songLength);
    return uniqueWordsPerSec;
}





