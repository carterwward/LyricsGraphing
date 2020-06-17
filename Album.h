//
// Created by Brandon Lee
//

#ifndef BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_ALBUM_H
#define BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_ALBUM_H
#include <string>
#include <vector>
#include "Song.h"
#include "RapSong.h"
#include "PopSong.h"
#include <filesystem>
#include <fstream>
#include <memory>
#include <map>
using namespace std;
namespace fs = filesystem;

class Album{
private:
    map<string, unique_ptr<Song>> trackList;
    string name;
    string artist;
    int numSongs;
    bool rap;
public:
    Album();
    Album(string title, string artist, map <string, unique_ptr<Song>>& songMap, bool rap);

    //Setters Here
    void setTrackList(map<string, unique_ptr<Song>>& songMap);
    void setName(string name);
    void setArtist(string artist);
    void setNumSongs(int numSongs);

    // Getters Here
    map<string, unique_ptr<Song>>& getTrackList();
    string getName() const;
    string getArtist() const;
    int getNumSongs() const;
};

// global functions
map<string,unique_ptr<Song>> readFromFolder(string folder, bool rap);

void strReplace(string& word, char old, char newCh);

#endif //BL_CH_CW_JS_FINAL_PROJECT_GRAPHICS_ALBUM_H
