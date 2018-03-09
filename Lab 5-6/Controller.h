#pragma once
#include <string.h>
#include "Movie.h"
#include "Repository.h"
#include "Watchlist.h"

class Controller
{
private:
	Repository repo;
	Watchlist watchlist;
	void printchoises();

public:
	Controller(Repository& r) : repo(r) {}
	Repository getRepo() { return repo; }
	Watchlist getWatchlist() { return watchlist; }

	/*
	This function adds a new movie to the list 
	Input:name, gender, trailer, year, likes- the fields of the movie
	Output:returns 1 if the movie was added, otherwise 0
	*/
	void addController(const std::string& name, const std::string& gender, const std::string& trailer, int& year, int& likes);
	
	/*
	This function deletes a movie from the array
	Input:name-the name of the movie which have to be deleted
	Output:returns 1 if the movie was deleted, otherwise 0
	*/
	void deleteController(std::string& name);

	/*
	This function updates a certain movie
	Input:name, gender, trailer, year, likes- the fields of the movie
	Output:returns 1 if the movie was updated, otherwise 0
	*/
	void updateController(std::string& name,std::string& gender,int& year,int& likes);

	/*
	This function adds a new movie to the watch list
	Input:gender- the gender of the movie

	*/
	void addWatchController(std::string& gender,int cond);

	/*
	This function deletes a movie from the watch list
	Input:name-the name of the movie which have to be deleted
	Output:returns 1 if the movie was deleted, otherwise 0
	*/
	void delWatchController(std::string& name,int cond);

	//start playing the movies
	void startWatchlist();

	//play the next movie
	void nextWatchlist();

	void sortController();

	size_t seeCount();
};
