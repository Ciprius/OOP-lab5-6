#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "Controller.h"

using namespace std;


void Controller::printchoises()
{
	cout << "1 -To add the movie to the watchlist. " << endl;
	cout << "2 -Don't add the movie to tehe watchlist."<< endl;
	cout << "0 -To exit." << endl;
}

void Controller::addController(const std::string & name, const std::string & gender, const std::string & trailer, int& year, int& likes)
{
	Movie m{ name,gender,trailer,year,likes };
	this->repo.add(m);
}

void Controller::deleteController(std::string & name)
{
	this->repo.deleteR(name);
}

void Controller::updateController(std::string & name, std::string & gender, int & year, int & likes)
{
	this->repo.updateR(name,gender,year,likes);
}

void Controller::addWatchController(std::string & gender,int cond)
{
	if (cond == 1)
	{
		DynamicVector<Movie> arr = this->repo.getMovies();
		Movie* mov = arr.getAllElems();

		for (int i = 0;i < arr.getlength();i++)
		{
			Movie m = mov[i];
			if (m.getGender() == gender)
			{
				cout << "You watch at:" << m.getName() << " - " << m.getGender() << " - " << m.getYear() << " - " << m.getLikes() << endl;
				m.Play();
				this->printchoises();
				int com{ 0 };
				cout << " Give the command: ";
				cin >> com;
				cin.ignore();
				if (com == 1)
					this->watchlist.addMovie(m);
				if (com == 0)
					break;
			}
			if (i == arr.getlength() - 1)
			{
				int com1{ 0 };
				cout << "End of database do you want to watch again(1-to continue/0-to exit): ";
				cin >> com1;
				cin.ignore();
				if (com1 == 1)
					i = -1;
				if (com1 == 0)
					break;
			}
		}
	}
	else
	{
		DynamicVector<Movie> arr1 = this->repo.getMovies();
		Movie* mov1 = arr1.getAllElems();
		for (int i = 0;i < arr1.getlength();i++)
		{
			Movie m1 = mov1[i];
			if (m1.getGender() == gender)
				this->watchlist.addMovie(m1);
		}
	}
}

void Controller::delWatchController(std::string & name,int cond)
{
	this->repo.likeMovie(name,this->watchlist.delMovie(name,cond));
}

void Controller::startWatchlist()
{
	this->watchlist.play();
}

void Controller::nextWatchlist()
{
	this->watchlist.next();
}

void Controller::sortController()
{
	this->repo.sortRepo();
}

size_t Controller::seeCount()
{
	return this->repo.seeCount();
}
