#include <iostream>
#include "Movie.h"

//implementation of the constructor
Movie::Movie(std::string name, std::string rating, int watched)
    :name(name), rating(rating), watched(watched)
{
}

//implementation of the copy constructor
Movie::Movie(const Movie &source)
    :Movie{source.name, source.rating, source.watched}
{
    
}


//implementation of the destructor
Movie::~Movie()
{
}

//implementation of the display method
//should just inset the movie attributes to cout
void Movie::display() const
{
    std::cout << name << "," << rating << "," << watched << std::endl;
}



