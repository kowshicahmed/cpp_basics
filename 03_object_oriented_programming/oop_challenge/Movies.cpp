#include "Movies.h"
#include <iostream>

//constructor
Movies::Movies()
{
}

//copy constructor


//destructor
Movies::~Movies()
{
}

bool Movies::add_movie(std::string name,std::string rating,int watched)
{
    for (const Movie &movie:movies)
    {
        if (movie.get_name() == name)
            return false;
    }
    
    Movie temp {name, rating, watched};
    movies.push_back(temp);
    return true;
    
}

bool Movies::increment_watched(std::string name)
{
    for(auto &obj:movies)
        {
            if (obj.get_name () == name)
            {
                obj.increment_watched ();
                return true;
            }
        }
    return false;
}

void Movies::display () const
{
    if (movies.size() == 0)
    {
        std::cout << "sorry no movies to display" << std::endl;
    }
    
    else
    {
        std::cout << "\n================================" << std::endl;
        for(const auto &obj:movies)
        {
            obj.display();
        }
        std::cout << "\n================================" << std::endl;
    }
    
}

