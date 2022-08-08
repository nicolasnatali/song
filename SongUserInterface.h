#ifndef SONG_SONGUSERINTERFACE_H
#define SONG_SONGUSERINTERFACE_H

#include "Song.h"
#include <fstream>
#include <iostream>
#include <vector>

class SongUserInterface {
public:
    void run();

private:
    std::vector<Song> songs;

    void addSong();

    static void displaySongs();

    void displaySongsSorted();

    void writeSongsToFile();
};

#endif //SONG_SONGUSERINTERFACE_H
