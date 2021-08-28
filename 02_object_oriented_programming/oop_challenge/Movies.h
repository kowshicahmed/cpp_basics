#ifndef MOVIES_H
#define MOVIES_H
#include <vector>
#include <string>
#include "Movie.h"

class Movies
{
private:
    std::vector<Movie> movies;
    
    
public:
    //constructor
    Movies();
    
    //destructor
    ~Movies();
    
    //member methods
    bool add_movie(std::string name,std::string rating,int watched);
    bool increment_watched(std::string name);
    void display () const;

};

#endif // MOVIES_H
