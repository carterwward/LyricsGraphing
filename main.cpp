#include <iostream>
#include <map>
#include <filesystem>
#include "PopSong.h"
#include "RapSong.h"
#include "Album.h"
#include <memory>
using namespace std;
namespace fs = filesystem;
#ifdef _WIN32
const string python = "python";
#else
const string python = "python3";
#endif

void getInput(string artist, string album, map<string, unique_ptr<Song>>& songMap);

int main() {
    RapSong rap;
    // root directory where everything will be stored
    string root = "albums";
    // creates directory if it doesnt exist
    if (!fs::exists(root)) {
        fs::create_directories(root);
    }

    string artist;
    string album;
    map <string, unique_ptr<Song>> songMap;

    getInput(artist, album, songMap);

    // validate that the album exists
    while (songMap.empty()) {
        cout << "It seems the album you typed in doesn't exist or has a typo." << endl;
        getInput(artist, album, songMap);
    }

    for( auto const& [key, val] : songMap)
    {
        cout << "Song name: " << val->getSongName()<< endl;
        cout << "Song length: " << val->getSongLength()<< endl;
        cout << "Song Index: " << val->getIndex()<< endl;
        cout << "Song Popularity: " << val->getPopularityScore()<< endl;
    }
//    fs::remove_all("albums");
    return 0;
}

void getInput(string artist, string album,map <string, unique_ptr<Song>>& songMap){
    string root = "albums";
    cout << "Please enter the name of the album you would like to analyze: ";
    getline(cin, album);
    cout << "Please enter the artist whom the album is by: ";
    getline(cin, artist);
    strReplace(artist, ' ', '-');
    strReplace(album, ' ', '-');

    // run python script
    string command = python + " ../lyrics.py " + artist + " " + album;
    system(command.c_str());
    // get map where keys are song names and values are songs(one full string)
    songMap = readFromFolder(root + "/" + album + "_" + artist, true);
}