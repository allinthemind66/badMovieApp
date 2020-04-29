#include <iostream>
#include "movie.h"
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "helper_functions.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

void getUserPrompt(); // gets input from user to make a selection
void convertStringToLowerCase(string &str); // converts string to lower case for easier searching

int main() {
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
        cout << name << endl;

        // converts string to lower case for easier searching
        convertStringToLowerCase(name);
        convertStringToLowerCase(directors);
        convertStringToLowerCase(genre);
        convertStringToLowerCase(alias);
        // parses year to int type
        yearInt = stoi(year);
        new Movie(name, directors, genre, length, rating, yearInt, plot, seen, alias); 
       
    }
    getUserPrompt();

    return 0;
}

void getUserPrompt() {
    char userPrompt;
    cout << "Enter 'l' to see a list of movies. Enter 'f' to find a movie by the movie name. Enter 'u' to update whether you have seen the movie. Enter 'r' to find a random movie. Enter 'q' to quit program." << endl;
    cin >> userPrompt;
    while(userPrompt != 'q') {
        if(userPrompt == 'l') {
            cout << "Here is a list of movies: " << endl;
            cout << "---------------------------" << endl;
            for(size_t i = 0; i < Movie::getListOfMovies().size() -1; i++) {
                Movie::getListOfMovies()[i]->getInfo();
            }
        } 
        if(userPrompt == 'f') {
            cin.ignore();
            string movieName;
            cout << "Please enter the name of the movie you would like to find: ";
            getline(cin, movieName);
            convertStringToLowerCase(movieName);
            Movie* foundMovie = Movie::findMovieByName(movieName);
            foundMovie->getInfo();
        }
        if(userPrompt == 'u') {
            cin.ignore();
            string movieName;
            cout << "Which movie would you like to update?" << endl;
            getline(cin, movieName);
            convertStringToLowerCase(movieName);
            Movie* foundMovie = Movie::findMovieByName(movieName);
            foundMovie->updateHasSeenProperty();
            cout << "Updated if you have seen this movie" << endl;
        }
        if(userPrompt == 'r') {
            cout << "Here is a random movie for you to enjoy." << endl;
            srand (time(NULL));
            int randomIndex = rand() % Movie::getListOfMovies().size();
            Movie* randomMovie = Movie::getListOfMovies()[randomIndex];
            randomMovie->getInfo();
        }
    cout << "Please enter a command..." << endl;
    cin >> userPrompt;
    }
    ofstream newMovieFile("bad_movie_list_tab.tsv", ios::out);
    if(!newMovieFile) {
        cerr << "File could not be created." << endl;
        exit(EXIT_FAILURE);
    }
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