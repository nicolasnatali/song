#ifndef SONG_SONG_H
#define SONG_SONG_H

#include <string>
#include <ostream>

class Song {
public:
    Song(std::string title, std::string artist, std::string genre);

    [[nodiscard]] const std::string &getTitle() const;

    void setTitle(const std::string &t);

    [[nodiscard]] const std::string &getArtist() const;

    void setArtist(const std::string &a);

    [[nodiscard]] const std::string &getGenre() const;

    void setGenre(const std::string &g);

    bool operator==(const Song &rhs) const;

    bool operator!=(const Song &rhs) const;

    bool operator<(const Song &rhs) const;

    bool operator>(const Song &rhs) const;

    bool operator<=(const Song &rhs) const;

    bool operator>=(const Song &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Song &song);

private:
    std::string title;
    std::string artist;
    std::string genre;
};

#endif //SONG_SONG_H
