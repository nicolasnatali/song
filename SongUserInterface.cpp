#include "SongUserInterface.h"

void SongUserInterface::run() {
    int choice;
    do {
        std::cout << "Songs Menu" << std::endl;
        std::cout << "1. Add a song" << std::endl;
        std::cout << "2. Display all songs" << std::endl;
        std::cout << "3. Display all songs sorted by artist" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "> ";
        std::cin >> choice;
        std::cin.ignore();
        std::cout << std::endl;
        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                writeSongsToFile();
                displaySongs();
                break;
            case 3:
                writeSongsToFile();
                displaySongsSorted();
                break;
            case 4:
                return;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
        std::cout << std::endl;
    } while (choice != 4);
}

void SongUserInterface::addSong() {
    std::string title;
    std::string artist;
    std::string genre;
    std::cout << "Enter the title:" << std::endl;
    std::cout << "> ";
    std::getline(std::cin, title);
    std::cout << "Enter the artist:" << std::endl;
    std::cout << "> ";
    std::getline(std::cin, artist);
    std::cout << "Enter the genre:" << std::endl;
    std::cout << "> ";
    std::getline(std::cin, genre);
    songs.emplace_back(title, artist, genre);
}

void SongUserInterface::displaySongs() {
    std::ifstream file("songs.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

void SongUserInterface::displaySongsSorted() {
    std::vector<Song> sortedSongs = songs;
    std::sort(sortedSongs.begin(), sortedSongs.end());
    for (const Song &song: sortedSongs) {
        std::cout << song << std::endl;
    }
}

void SongUserInterface::writeSongsToFile() {
    std::ofstream outFile("songs.txt");
    for (auto &song: songs) {
        outFile << song << std::endl;
    }
    outFile.close();
}
