/*
    Implementation file for Movie class
*/
#include "movie.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "helper_functions.h"

using namespace std;

/*
    Movie Destructor
*/
Movie::Movie(string movieName, string movieDirectorList, string movieGenre, string movieLength, int movieRottenTomatoesRating, int movieReleaseYear, string moviePlot, string seen, string movieAlias) {
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
    cout << "Rotten Tomatoes Score: " << getRottenTomatoesScore() << "%" << endl;
    cout << "Release Year: " << getReleaseYear() << endl;
    cout << "Has seen: " << getHasSeenProperty() << endl;
    cout << "Plot: " << getPlot() << endl;
    cout << "----------------------------" << endl;
}

void Movie::openAndReadMovieFile() {
    string id;
    string name; 
    string directors; 
    string genre; 
    string length; 
    string rating; 
    string year;
    string alias; 
    string seen; 
    string plot;
    int yearInt;
    int ratingInt;
    
    ifstream badMovieFile("bad_movie_list_tab.tsv"); // open tsv file


    if(!badMovieFile) {
        cerr << "Error: File could not be opened. It is possible it doesn't exist! Please check and try again." << endl; // error if file doesn't exist
        exit(EXIT_FAILURE);
    }
    while (badMovieFile.good()){
        // get values for each line of file: ID,Name,Director(s),Genre,Length,Rating,Year,Alias,Seen,Plot
        getline(badMovieFile, id, '\t');
        getline(badMovieFile, name, '\t');
        getline(badMovieFile, directors, '\t');
        getline(badMovieFile, genre, '\t');
        getline(badMovieFile, length, '\t');
        getline(badMovieFile, rating, '\t');
        getline(badMovieFile, year, '\t');
        getline(badMovieFile, alias, '\t');
        getline(badMovieFile, seen, '\t');
        getline(badMovieFile, plot, '\n');

        // converts string to lower case for easier searching
        convertStringToLowerCase(name);
        convertStringToLowerCase(directors);
        convertStringToLowerCase(genre);
        convertStringToLowerCase(alias);
        // parses year to int type
        yearInt = stoi(year);
        ratingInt = stoi(rating);
        new Movie(name, directors, genre, length, ratingInt, yearInt, plot, seen, alias); 
       
    }
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
int Movie::getRottenTomatoesScore() {
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
        for(size_t i = 0; i < listOfMovies.size() - 1; i++) {
            if(listOfMovies[i]->getName() == movieName) {
                return listOfMovies[i];
            }
        };

    return nullptr;
}
/*
    Prints list of movies
*/
void Movie::printListOfMovies() {
    cout << "Here is a list of movies: " << endl;
    cout << "---------------------------" << endl;
    vector<Movie*> listOfMovies = Movie::getListOfMovies();
    for(size_t i = 0; i < listOfMovies.size() -1; i++) {
        listOfMovies[i]->getInfo();
    }
}

/*
    Retrieves and prints a specific movie
*/
void Movie::getAndPrintSpecificMovie() {
    cin.ignore();
    string movieName;
    cout << "Please enter the name of the movie you would like to find: ";
    getline(cin, movieName);
    convertStringToLowerCase(movieName);
    Movie* foundMovie = Movie::findMovieByName(movieName);
    if(foundMovie) {
    foundMovie->getInfo();
    } else {
        cout << "Sorry, we don't have that movie in our database." << endl;
    }
}
/*
    Finds and Updates the has seen param on a movie
*/
void Movie::findAndUpdateHasSeenOnMovie() {
    cin.ignore();
    string movieName;
    cout << "Which movie would you like to update?" << endl;
    getline(cin, movieName);
    convertStringToLowerCase(movieName);
    Movie* foundMovie = Movie::findMovieByName(movieName);
    foundMovie->updateHasSeenProperty();
    cout << "Updated if you have seen this movie" << endl;
}

/*
    Finds and prints movie data of a specific genre
*/
void Movie::findAndPrintMoviesOfSpecificGenre(){
    cin.ignore();
    string movieGenre;
    cout << "What genre would you like to see?" << endl;
    getline(cin, movieGenre);
    convertStringToLowerCase(movieGenre);
    vector<Movie*> listOfMoviesByGenre = Movie::getListOfMoviesByGenre(movieGenre);
    if(listOfMoviesByGenre.size() > 0) {
    cout << "Here is a list of movies of the genre " << movieGenre << "for you to enjoy." << endl;
        for(size_t i = 0; i < listOfMoviesByGenre.size() -1; i++) {
            listOfMoviesByGenre[i]->getInfo();
        }
    } else {
        cout << "We could not find any movies from that genre. Please try again!" << endl;
    }
}

/*
    Prints a random movie
*/
void Movie::printRandomMovie() {
    cout << "Here is a random movie for you to enjoy." << endl;
    srand (time(NULL));
    int randomIndex = rand() % Movie::getListOfMovies().size();
    Movie* randomMovie = Movie::getListOfMovies()[randomIndex];
    randomMovie->getInfo();
}

/*
    Prints a random movie of a specific genre
*/
void Movie::findAndPrintRandomMovieOfSpecificGenre() {
    cin.ignore();
    string movieGenre;
    cout << "What genre would you like to see for a random movie?" << endl;
    getline(cin, movieGenre);
    convertStringToLowerCase(movieGenre);
    vector<Movie*> listOfMoviesByGenre = Movie::getListOfMoviesByGenre(movieGenre);
    if(listOfMoviesByGenre.size() > 0) {
        srand (time(NULL));
        int randomIndex = rand() % listOfMoviesByGenre.size();
        Movie* randomMovie = listOfMoviesByGenre[randomIndex];
        randomMovie->getInfo();
    } else {
        cout << "We could not find any movies from that genre. Please try again!" << endl;
    }
}

/*
    Saves file and deletes all movies to free up memory
*/
void Movie::saveFileAndDeleteMovies() {
    ofstream newMovieFile("bad_movie_list_tab.tsv", ios::out);
    if(!newMovieFile) {
        cerr << "File could not be created." << endl;
        exit(EXIT_FAILURE);
    }
    // saves new movie file to update any changes
    for(size_t i = 0; i < Movie::getListOfMovies().size() -1; i++) {
        newMovieFile << 
        Movie::getListOfMovies()[i]->getMovieId() << "\t" << 
        Movie::getListOfMovies()[i]->getName() << "\t" << 
        Movie::getListOfMovies()[i]->getDirectors() << "\t" << 
        Movie::getListOfMovies()[i]->getGenre() << "\t" << 
        Movie::getListOfMovies()[i]->getLength() << "\t" << 
        Movie::getListOfMovies()[i]->getRottenTomatoesScore()<<"\t" << 
        Movie::getListOfMovies()[i]->getReleaseYear() << "\t" << 
        Movie::getListOfMovies()[i]->getAlias() << "\t" <<
        Movie::getListOfMovies()[i]->getHasSeenProperty() << "\t" << 
        Movie::getListOfMovies()[i]->getPlot() << endl;

        // delete movie to free up space allocated from using new keyword
        delete Movie::getListOfMovies()[i];
        
    };
}

/*
    returns average year of movie
*/
float Movie::getAverageYearOfMovies() {
    float total;
    vector<Movie*> listOfMovies = Movie::getListOfMovies();
    for(size_t i = 0; i < listOfMovies.size(); i++) {
        total = total + listOfMovies[i]->getReleaseYear();
    }
    return (total / listOfMovies.size());
}
/*
    gets average rating of movie
*/
float Movie::getAverageRatingOfMovies() {
    float total;
    vector<Movie*> listOfMovies = Movie::getListOfMovies();
    for(size_t i = 0; i < listOfMovies.size(); i++) {
        total = total + listOfMovies[i]->getRottenTomatoesScore();
    }
    return (total / listOfMovies.size());
}
/*
    Prints analytics of all movies
*/
void Movie::printMovieAnalytics() {
    vector<Movie*> listOfMovies = Movie::getListOfMovies();
    cout << "Here are certain analyses on the movies from the list:" << endl;
    cout << "Movie Count: " << listOfMovies.size() << endl;
    cout << "Average Movie Release Year: " << Movie::getAverageYearOfMovies() << endl;
    cout << "Average Movie Rating: " << Movie::getAverageRatingOfMovies() << endl;
};

/*
    Returns list of all movies created
*/
vector<Movie*> Movie::getListOfMovies(){
    return listOfMovies;
};

/*
    Returns list of all movies created of a specific genre
*/
vector<Movie*> Movie::getListOfMoviesByGenre(string movieGenre){
    vector<Movie*> genreMovieList = vector<Movie*>();
    for(size_t i = 0; i < listOfMovies.size() - 1; i++) {
            if(listOfMovies[i]->getGenre() == movieGenre) {
                genreMovieList.push_back(listOfMovies[i]);
            }
        };
    return genreMovieList;

}

/*
    Initializes list of movies to a vector of pointers to movie type
*/
vector<Movie*> Movie::listOfMovies = vector<Movie*>();