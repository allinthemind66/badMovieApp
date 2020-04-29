#include "movie.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

/*
    Movie Destructor
*/
Movie::Movie(string movieName, string movieDirectorList, string movieGenre, string movieLength, string movieRottenTomatoesRating, int movieReleaseYear, string moviePlot, string seen, string movieAlias) {
    id = Movie::totalMoviesCreated + 1;
    name = movieName;
    directorList = movieDirectorList;
    genre = movieGenre;
    length = movieLength;
    rottenTomatoesRating = movieRottenTomatoesRating;
    releaseYear = movieReleaseYear;
    plot = moviePlot;
    hasSeen = seen;
    alias = movieAlias;

    listOfMovies.push_back(this);
    Movie::totalMoviesCreated++;
}

/*
    Movie Destructor
*/
Movie::~Movie(){
}

/*
    Prints info about a movie object
*/
void Movie::getInfo() {
    cout << "----------------------------" << endl;
    cout << "ID: " << getMovieId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Directors: " << getDirectors() << endl;
    cout << "Genre: " << getGenre() << endl;
    cout << "Runtime: " << getLength() << endl;
    cout << "Rotten Tomatoes Score: " << getRottenTomatoesScore() << endl;
    cout << "Release Year: " << getReleaseYear() << endl;
    cout << "Has seen: " << getHasSeenProperty() << endl;
    cout << "Plot: " << getPlot() << endl;
    cout << "----------------------------" << endl;
}

/*
    Name getter function
*/
string Movie::getName(){
    return name;
}
/*
    Directors getter function
*/
string Movie::getDirectors() {
    return directorList;
}
/*
    Genre getter function
*/
string Movie::getGenre() {
    return genre;
}
/*
    Movie length getter function
*/
string Movie::getLength() {
    return length;
}
/*
    Rotten Tomatoes Score getter function
*/
string Movie::getRottenTomatoesScore() {
    return rottenTomatoesRating;
}
/*
    Release year getter function
*/
int Movie::getReleaseYear() {
    return releaseYear;
}
/*
    Movie plot getter function
*/
string Movie::getPlot() {
    return plot;
}
/*
    Has seen property getter function
*/
string Movie::getHasSeenProperty() {
    return hasSeen;
}
/*
    Movie alias getter function - some low budget
    b movies are known by multiple names
*/
string Movie::getAlias() {
    return alias;
}
/*
    Movie ID getter function
*/
unsigned int Movie::getMovieId() {
    return id;
}
/*
    Initializes the count of movies created
*/
unsigned int Movie::totalMoviesCreated = 0;

/*
    Updates has seen property on object
*/
string Movie::updateHasSeenProperty() {
    if(hasSeen == "FALSE") {
        hasSeen = "TRUE";
    } else {
        hasSeen = "FALSE";
    }
    return hasSeen;
}

/*
    Finds movie by name from vector of pointer to movies
*/
Movie* Movie::findMovieByName(string movieName) {
    for(size_t i = 0; i < Movie::listOfMovies.size(); i++) {
        if(Movie::listOfMovies[i]->getName() == movieName) {
            return Movie::listOfMovies[i];
        }
    };
    return nullptr;
}

/*
    Returns list of all movies created
*/
vector<Movie*> Movie::getListOfMovies(){
    return listOfMovies;
};

/*
    Initializes list of movies to a vector of pointers to movie type
*/
vector<Movie*> Movie::listOfMovies = vector<Movie*>();