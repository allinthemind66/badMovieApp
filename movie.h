#include <string> 
#include <vector>

using namespace std;

class Movie {
    public:
        Movie(string movieName, string movieDirectorList, string movieGenre, string movieLength, string movieRottenTomatoesRating, int movieReleaseYear, string moviePlot, string seen, string movieAlias);
        ~Movie();
        void getInfo();
        string getName();
        string getDirectors();
        string getGenre();
        string getLength();
        string getRottenTomatoesScore();
        string getHasSeenProperty();
        string getAlias();
        unsigned int getMovieId();
        int getReleaseYear();
        string getPlot();
        static vector<Movie*> getListOfMovies();
        static Movie* findMovieByName(string movieName);
        string updateHasSeenProperty();
        static unsigned int totalMoviesCreated;
    private:
        static int countOfMovieObjectsCreated;
        unsigned int id;
        string name;
        string directorList;
        string genre;
        string length;
        string rottenTomatoesRating;
        string hasSeen;
        int releaseYear;
        string plot;
        string alias;
        static vector<Movie*>listOfMovies;

};