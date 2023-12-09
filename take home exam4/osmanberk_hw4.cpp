//
//  main.cpp
//  take home exam4
//
//  Created by Osman Berk An on 6.12.2022.
// OSMAN BERK AN 28849

#include <iostream>
#include <string>
#include <vector>
#include "randgen.h"
#include "strutils.h"

using namespace std;



struct Movie{
    string movieName;
    int movieYear;
    string movieGenre;
    
};


void print(vector<Movie> &movies)
{
    for(int i=0; i<movies.size(); i++){
        cout << movies[i].movieName << ";" << movies[i].movieYear << ";" << movies[i].movieGenre;
        if(i != movies.size()-1){
            cout << "|";
        }
    }
}

void insert(vector<Movie> &movies, string name, int year, string genre){
    Movie movie;
    movie.movieName = name;
    movie.movieYear = year;
    movie.movieGenre = genre;
    movies.push_back(movie);
}


void vecproc(string list, vector<Movie> &movies)
{
    
    Movie lastmovie;
    while(list.find("|") != string::npos){
        
        string movieinfs = list.substr(0,list.find("|"));
        list = list.substr(list.find("|")+1);
        
        string name = movieinfs.substr(0,movieinfs.find(";"));
        movieinfs = movieinfs.substr(movieinfs.find(";")+1);
        string year = movieinfs.substr(0,movieinfs.find(";"));
        movieinfs = movieinfs.substr(movieinfs.find(";")+1);
        string genre = movieinfs;
        int yearint = atoi(year);
        insert(movies, name, yearint, genre);

    }
    
    // add last movie to the vector
    
    string lastmovieinfs = list.substr(list.rfind("|")+1);
    string lastmoviename = lastmovieinfs.substr(0,lastmovieinfs.find(";"));
    lastmovieinfs = lastmovieinfs.substr(lastmovieinfs.find(";")+1);
    string lastmovieyear = lastmovieinfs.substr(0,lastmovieinfs.find(";"));
    lastmovieinfs = lastmovieinfs.substr(lastmovieinfs.find(";")+1);
    string lastmoviegenre = lastmovieinfs;
    int lastmovieyearint = atoi(lastmovieyear);
    lastmovie.movieName = lastmoviename;
    lastmovie.movieYear = lastmovieyearint;
    lastmovie.movieGenre = lastmoviegenre;
    
    movies.push_back(lastmovie);
    
}


void sortmovies(vector<Movie> & movies){
    Movie temp;
    for(int i=0; i< movies.size()-1; i++){
        for(int k=i+1; k< movies.size(); k++){
            if(movies[k].movieYear > movies[i].movieYear){
                Movie temp = movies[i];
                movies[i] = movies[k];
                movies[k] = temp;
            }
            else if(movies[k].movieYear == movies[i].movieYear){
                if (movies[k].movieName < movies[i].movieName){
                    Movie temp = movies[i];
                    movies[i] = movies[k];
                    movies[k] = temp;
                }
                
            }
        }
    }
    
    
}
    

string convert(string s){
    for(int i=0; i<s.length(); i++){
        s[i] = tolower(s[i]);
    }
    return s;
}
    
    
int main()
{
    
    RandGen rand;
    vector<Movie> movie_list;
    string select;
    string list,genre;
    
    
    cout << "Welcome to the movie recommender program!" << endl << endl;
    cout << "Please enter the movie, year and genre list:" << endl;
    cin >> list;
    
    
    vecproc(list,movie_list);
    //print(movie_list);
    cout << endl;
    
    sortmovies(movie_list);
    //print(movie_list);
    


    cout << "Please select your action:" << endl;
    cout << "1. Select the genre of the movie that you want to watch" << endl;
    cout << "2. Select the year of the movie that you want to watch" << endl;
    cout << "3. Choose a random movie" << endl;
    cout << "4. Exit program" << endl << endl;
    cout << "Enter your choice: ";
    cin >> select;   
    
    

    while(select != "4"){
        if(select != "1" && select != "2" && select != "3" && select != "4"){
            cout << "Invalid action!" << endl << endl;
            cout << "Enter your choice: ";
            cin >> select;
        }
        else if(select == "1"){
            cout << "Please enter the genre of the movie you want to watch: " ;
            cin >> genre;
            cout << endl;
            if(convert(list).find(convert(genre)) == string::npos){
                cout << "There are no " << genre << " movies!" << endl;
                
            }
            else{
                for(int i=0; i<movie_list.size(); i++){
                    if(i == 0){
                        cout << genre << " movies from newest to oldest:" << endl;
                    }
                    if(convert(movie_list[i].movieGenre) == convert(genre)){
                        cout << "Movie name: " << movie_list[i].movieName << " Release Year: " << movie_list[i].movieYear << endl;
                        
                    }
                
                }
            }
            cout << endl;
            cout << "Enter your choice: ";
            cin >> select;
           
                
        }
        
        
        else if(select == "2"){
            
            string input;           // 1881 or 1881-1883
            
            
            cout << "Please enter the year of the movie you want to watch: ";
            cin >> input;
            
            if(input.find("-") == string::npos){    //  input sadece yil ise
                if(list.find(input) == string::npos){
                    cout << "There are no movies released in " << input << "!" << endl;
                    
                }
                else{
                    for(int i=0; i<movie_list.size(); i++){
                        int yearintt = atoi(input);
                        if(i==0){
                            cout << "Movies released in " << input << " from A to Z:" << endl;
                        }
                        if(movie_list[i].movieYear == yearintt){
                            
                            cout << "Movie name: " << movie_list[i].movieName << " Genre: " << movie_list[i].movieGenre << endl;
                        }
                    }
                }
                
                
            }
            else if(input.find("-") != string::npos){      //  range ise  1881-1893
                string year1 = input.substr(0,input.find("-"));
                string year2 = input.substr(input.find("-")+1);
                int year1int = atoi(year1);
                int year2int = atoi(year2);
                int yearsbetweencount = 0;
            
               
                
                for(int i=0; i< movie_list.size(); i++){
                    
                    if(movie_list[i].movieYear <= year2int && movie_list[i].movieYear >= year1int){
                        yearsbetweencount ++;
                    }
                   
                }
                if(yearsbetweencount ==0){
                    cout << "There are no movies released between " << input << "!" << endl;
                }
                
                else{
                    for(int i=0; i<movie_list.size(); i++){
                        if(i==0){
                            cout << "Movies released between the years " << input << " from A to Z with decreasing year ordering:" << endl;
                        }
                        if(movie_list[i].movieYear <= year2int && movie_list[i].movieYear >= year1int){
                            cout << "Movie name: " << movie_list[i].movieName << " Release Year: " << movie_list[i].movieYear << " Genre: " << movie_list[i].movieGenre << endl;
                        }
                    }
                    
                }
                    
            
                 
                        
                    
                
               
             }
                     
            cout << endl;
            cout << "Enter your choice: ";
            cin >> select;
        }
        
        
        else if(select == "3"){  // random movie
            int random = rand.RandInt(0,movie_list.size()-1);
            cout << "Movie name: " << movie_list[random].movieName << " Release Year: " << movie_list[random].movieYear << " Genre: " << movie_list[random].movieGenre << endl << endl;
            cout << "Enter your choice: ";
            cin >> select;
           
        }

    }
    
    
    if(select == "4"){
        cout << "Thank you..." << endl;
    }
        
    
    
    return 0;
}


