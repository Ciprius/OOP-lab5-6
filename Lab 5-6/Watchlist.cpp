#include "Watchlist.h"
#include <iostream>
using namespace std;

Watchlist::Watchlist()
{
	this->current=0;
}

void Watchlist::addMovie(Movie & mo)
{
	this->movies.add(mo);
}

int Watchlist::delMovie(std::string& name,int cond)
{
	Movie* mov = this->movies.getAllElems();
	this->current = 0;
	while (this->current!= this->movies.getlength())
	{
		Movie m = mov[this->current];
		if (m.getName() == name)
		{
			this->movies.delMovie(this->current);
			if (cond == 1)
			{
				int com{ 0 };
				cout << "Did you enjoy the movie?(1-to give a like/0-otherwise):";
				cin >> com;
				cin.ignore();
				return com;
			}
			else
				return 0;
		}
		this->current++;
	}
	return -1;
}

Movie Watchlist::getCurrentMovie()
{
	if (this->current == this->movies.getlength())
		this->current = 0;
	Movie* mov = this->movies.getAllElems();
	
	if (mov != NULL)
		return mov[this->current];

	return Movie{};
}

void Watchlist::play()
{
	if (this->movies.getlength() == 0)
		return;
	this->current = 0;
	Movie currmov = this->getCurrentMovie();
	currmov.Play();
}

void Watchlist::next()
{
	if (this->movies.getlength() == 0)
		return;
	this->current++;
	Movie currmov = this->getCurrentMovie();
	currmov.Play();
}

bool Watchlist::isEmpty()
{
	return this->movies.getlength() == 0;
}
