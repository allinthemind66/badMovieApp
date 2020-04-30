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
// void convertStringToLowerCase(string &str); // converts string to lower case for easier searching

int main() {
    Movie::openAndReadMovieFile(); // opens movie list file, creates and populates movie objects
    getUserPrompt(); // gets user prompt until user quits program

    return 0; // success
}

void getUserPrompt() {
    string userPrompt;
    cout << "Enter 'l' to see a list of movies. Enter 'f' to find a movie by the movie name. Enter 'u' to update whether you have seen the movie. Enter 'r' to find a random movie. Enter 'g' to see a list of movies of a certain genre. Enter 'q' to quit program." << endl;
    getline(cin, userPrompt);
    while(userPrompt != "q") {
        if(userPrompt.length() > 1) {
            cout << "> Invalid command. Type 'h' for help and options." << endl;
        } else {
            // change first string to char type for switch statment
            switch(userPrompt.c_str()[0]){
                case 'l': { // list movies
                    Movie::printListOfMovies();
                    break;
                }
                case 'f': { // find specific movie
                    Movie::getAndPrintSpecificMovie();
                    break;
                }
                case 'u': { // update whether you have seen movie
                    Movie::findAndUpdateHasSeenOnMovie();
                    break;
                }
                case 'r': { // see a random movie
                    Movie::printRandomMovie();
                    break;
                }
                case 'g': { // find movies from specific genre
                    Movie::findAndPrintMoviesOfSpecificGenre();
                    break;
                }
                case 'j': { // find a random movie from a specific genre
                    Movie::findAndPrintRandomMovieOfSpecificGenre();
                    break;
                }
                case 'a': {
                    Movie::printMovieAnalytics();
                }
                case 'h': { // prints commands
                    cout << "Enter 'l' to see a list of movies. Enter 'f' to find a movie by the movie name. Enter 'u' to update whether you have seen the movie. Enter 'r' to find a random movie. Enter 'q' to quit program." << endl;
                    break;
                }
            }

        }
    cout << "Please enter a command. Enter 'h' for list of options." << endl;
    cin >> userPrompt;
    }
    Movie::saveFileAndDeleteMovies();
}