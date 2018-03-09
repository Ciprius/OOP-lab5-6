#pragma once
#include <string.h>
#include "Movie.h"
#include "Repository.h"
#include "Controller.h"
#include "Exceptions.h"

class UI
{
private:
	Controller cont;
	void addUI();
	void displayAllMovies();
	void deleteUI();
	void updateUI();
	void addWatchUI();
	void delWatchUI();

	static void printMenu();
	static void printAdminMenu();
	static void printUserMenu();

public:
	UI(Controller& c) : cont(c)  {}
	void run();


};

class Validator 
{
public:
	Validator(Repository& repo) : repo(repo) {}
	void validaddFunct(const std::string& name);
private:
	Repository repo;
	//UIExceptions exps;
};