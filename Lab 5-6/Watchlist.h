#pragma once
#include "DynamicVector.h"
#include "Movie.h"

class Watchlist
{
private:
	DynamicVector<Movie> movies;
	int current;

public:
	Watchlist();

	/*
	This function adds a new movie to the watch list
	Input:mo- the movie to be added
	*/
	void addMovie(Movie& mo);

	/*
	This function deletes a movie from the watch list
	Input:mane-the name of the movie
	*/
	int delMovie(std::string& name,int cond);

	/*
	This function returns the current movie form the watch list
	*/
	Movie Watchlist::getCurrentMovie();

	/*
	This function plays the first movie
	*/
	void play();

	/*
	This function play the next movie
	*/
	void next();
	bool isEmpty();
};
