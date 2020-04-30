/*
    Specification file for Movie class
*/
#include <string> 
#include <vector>

using namespace std;

class Movie {
    public:
        Movie(string movieName, string movieDirectorList, string movieGenre, string movieLength, int movieRottenTomatoesRating, int movieReleaseYear, string moviePlot, string seen, string movieAlias);
        ~Movie(); // movie destructor 
        static vector<Movie*> getListOfMovies(); // gets a list of pointers to movie types
        static Movie* findMovieByName(string movieName); // returns a pointer to a movie type found by name
        static vector<Movie*> getListOfMoviesByGenre(string movieGenre); // gets a list of pointers to movie types by genre
        static void printListOfMovies(); // prints list of movies to console
        static void getAndPrintSpecificMovie(); // prints specific movie 
        static void findAndUpdateHasSeenOnMovie(); // finds and updates hasSeen param on specific movie
        static void findAndPrintMoviesOfSpecificGenre(); // prints movies of a specific passed in genre
        static void findAndPrintRandomMovieOfSpecificGenre(); // prints movies of a specific passed in genre
        static void saveFileAndDeleteMovies(); // saves movies to new file and then deletes each object to free up space
        static void printRandomMovie(); // prints a random movie
        static void openAndReadMovieFile(); // opens movie file, and creates and populates movie object from data in file
        static void printMovieAnalytics(); // prints analytics on movies created
        static float getAverageYearOfMovies(); // caluculates average year of movies
        static float getAverageRatingOfMovies(); // gets the average rating of a movie
        void getInfo(); // prints movie info
        unsigned int getMovieId(); // get the movie id 
        int getReleaseYear(); // gets the movie release year
        string getName(); // returns name of movie
        string getDirectors(); // returns director(s) of movie
        string getGenre(); // gets genre of movie
        string getLength(); // gets the length of the movie
        int getRottenTomatoesScore(); // get the rotten tomatoes score
        string getHasSeenProperty(); // gets the has seen property of a movie
        string getAlias(); // get the alias (some movies are known by multiple titles)
        string getPlot(); // gets the movie plot
        string updateHasSeenProperty(); // updates the has seen property of a movie
    private:
        static unsigned int totalMoviesCreated; // total movies that have been created
        static vector<Movie*>listOfMovies; // list of movies
        static int countOfMovieObjectsCreated; //count of total objects created
        unsigned int id; // movie id
        int releaseYear; // release year of movie
        string name; // name of movie
        string directorList; // directors in movie
        string genre; // genre of movie
        string length; // length of movie
        int rottenTomatoesRating; // rotten tomatoes score of movie
        string hasSeen; // parameter if I have seen the movie
        string plot; // plot of movie
        string alias; // alias of movie (some movies are known by multiple names)

};