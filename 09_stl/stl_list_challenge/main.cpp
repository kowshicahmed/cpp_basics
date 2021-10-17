#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <string>

class Song
{
    friend std::ostream& operator<<(std::ostream& os, const Song& s);
    std::string name;
    std::string artist;
    int rating;

public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
        : name { name }
        , artist { artist }
        , rating { rating }
    {
    }
    std::string get_name() const
    {
        return name;
    }
    std::string get_artist()
    {
        return artist;
    }
    int get_rating()
    {
        return rating;
    }
    bool operator<(const Song& rhs) const
    {
        return this->name < rhs.name;
    }

    bool operator==(const Song& rhs) const
    {
        return this->name == rhs.name;
    }
};

std::ostream& operator<<(std::ostream& os, const Song& s)
{
    os << std::setw(20) << std::left << s.name << std::setw(30) << std::left << s.artist << std::setw(2) << std::left
       << s.rating;
    return os;
}

void display_menu()
{
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play  Next Song" << std::endl;
    std::cout << "P - Play Previous Song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L  - List the current playlist" << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << "ENter a selection (Q to quit): ";
}

void play_current_song(const Song& song)
{
    std::cout << "Playing: " << std::endl;
    std::cout << song << std::endl;
}

void display_playlist(const std::list<Song>& playlist, const Song& current_song)
{
    for(const Song& song : playlist) {
        std::cout << song << std::endl;
    }
    std::cout << "Current song:" << std::endl;
    std::cout << current_song << std::endl;
}

int main(int argc, char** argv)
{
    std::list<Song> playlist { { "God's Plan", "Drake", 5 }, { "Never Be The Same", "Camila Cabello", 5 },
        { "Pray For Me", "The Weeknd and K. Lamar", 4 }, { "The Middle", "Zedd,  Maren Morris & Grey", 5 },
        { "Wait", "Maroone 5", 4 }, { "Whatever It Takes", "Imagine Dragons", 3 } };

    char user_input = ' ';
    std::list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist, *current_song);

    while(std::toupper(user_input) != 'Q') {
        display_menu();
        std::cin >> user_input;

        switch(std::toupper(user_input)) {
        case 'F':
        {
            play_current_song(*current_song);
            break;
        }
        case 'N':
        {
            std::advance(current_song, 1);
            if(current_song != playlist.end()) {
                std::cout << "Playing Next song" << std::endl;
                play_current_song(*current_song);
            } else {
                std::cout << "Playing Next song" << std::endl;
                current_song = playlist.begin();
                play_current_song(*current_song);
            }
            break;
        }
        case 'P':
        {
            if(current_song == playlist.begin()) {
                std::cout << "Playing Previous song" << std::endl;
                current_song = playlist.end();
                std::advance(current_song, -1);
                play_current_song(*current_song);
            }

            else {
                std::advance(current_song, -1);
                std::cout << "Playing Previous song" << std::endl;
                play_current_song(*current_song);
            }
            break;
        }
        case 'L':
        {
            display_playlist(playlist, *current_song);
            break;
        }
        case 'A':
        {
            std::string name, artist;
            int rating {};
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout  << "Adding and playing new song" << std::endl;
            std::cout << "Enter song name: ";
            getline(std::cin, name);
            std::cout << "Enter song artist: ";
            getline(std::cin, artist);
            std::cout << "Enter your rating (1-5): ";
            std::cin >> rating;
            playlist.insert(current_song, Song { name, artist, rating });
            current_song--;
            play_current_song(*current_song);
            break;
        }
        default:
            std::cout << "Please Enter a valid choice" << std::endl;
            break;
        }
    }

    return 0;
}
