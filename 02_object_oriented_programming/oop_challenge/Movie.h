#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie
{
private:
    std::string name;
    std::string rating;
    int watched;
public:
    //constructor - expects all 3 movie attributes
    Movie(std::string name, std::string rating, int watched);
    
    //copy constructor 
    Movie (const Movie &source);
    
    //destructor
    ~Movie();
    
    //basic getters and setters for private attributes
    //implement these inline and watch your const correcness
    void set_name(std::string name) {this->name = name;}
    std::string get_name()const{return name;}
    
    void set_rating(std::string rating) {this->rating = rating;}
    std::string get_rating(){return rating;}
    
    void set_watched(int watched){this->watched = watched;}
    int get_watched()const{return watched;}
    
    //simply increment the watched attribute by 1
    void increment_watched(){++watched;}
    
    //simply displays the movie information
    void display()const;

};

#endif // MOVIE_H
