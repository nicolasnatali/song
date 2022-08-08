#include "Song.h"

#include <utility>

Song::Song(std::string title, std::string artist, std::string genre)
        : title{std::move(title)}, artist{std::move(artist)}, genre{std::move(genre)} {}

const std::string &Song::getTitle() const {
    return title;
}

void Song::setTitle(const std::string &t) {
    Song::title = t;
}

const std::string &Song::getArtist() const {
    return artist;
}

void Song::setArtist(const std::string &a) {
    Song::artist = a;
}

const std::string &Song::getGenre() const {
    return genre;
}

void Song::setGenre(const std::string &g) {
    Song::genre = g;
}

bool Song::operator==(const Song &rhs) const {
    return title == rhs.title &&
           artist == rhs.artist &&
           genre == rhs.genre;
}

bool Song::operator!=(const Song &rhs) const {
    return !(rhs == *this);
}

bool Song::operator<(const Song &rhs) const {
    if (artist < rhs.artist)
        return true;
    if (rhs.artist < artist)
        return false;
    if (title < rhs.title)
        return true;
    if (rhs.title < title)
        return false;
    return genre < rhs.genre;
}

bool Song::operator>(const Song &rhs) const {
    return rhs < *this;
}

bool Song::operator<=(const Song &rhs) const {
    return !(rhs < *this);
}

bool Song::operator>=(const Song &rhs) const {
    return !(*this < rhs);
}

std::ostream &operator<<(std::ostream &os, const Song &song) {
    os << "\"" << song.title << "\" by " << song.artist << " (" << song.genre << ")";
    return os;
}
