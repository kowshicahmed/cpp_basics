#include <iostream>
#include "Movies.h"

using namespace std;

//Function prototypes
void increment_watched(Movies &movies, string name);
void add_movie(Movies &movies, string name, string rating, int watched);

int main(int argc, char **argv)
{
	Movies my_movies;
    my_movies.display();
    add_movie(my_movies, "big", "pg-13",2);
    my_movies.display();
    add_movie(my_movies, "star wars", "pg",5);
    add_movie(my_movies, "cinderella", "pg",7);
    my_movies.display();
    add_movie(my_movies, "cinderella", "pg",7);
    my_movies.display();
    increment_watched(my_movies, "cinderella");
    my_movies.display();
	return 0;
}

//Helper function definitions
void increment_watched(Movies &movies, string name)
{
    if (movies.increment_watched(name))
    {
        cout << name << " watch incremented" << endl;
    }
    
    else
    {
        cout << name << " not found" << endl;
    }
}

void add_movie(Movies &movies, string name, string rating, int watched)
{
    if (movies.add_movie(name,rating,watched))
    {
        cout << name << " added" << endl;
    }
    else
    {
        cout << name << " already exists" << endl;
    }
}
