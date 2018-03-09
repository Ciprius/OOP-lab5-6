#include "Repository.h"
#include <string>
#include <stdexcept>
using namespace std;


int Repository::find(const std::string& name)
{
	Movie* dyn = this->movies.getAllElems();
	if (dyn == NULL)
		return 1;

	for (int i = 0;i < this->movies.getlength();i++)
	{
		Movie m = dyn[i];

		if (m.getName() == name)
		{
			return 0;
		}
	}
	return 1;
}

Movie Repository::findByGender(std::string & gender)
{
	Movie* mov = this->movies.getAllElems();
	if (mov == NULL)
		return Movie{};

	for (int i = 0;i < this->movies.getlength();i++)
	{
		Movie m = mov[i];
		if (m.getGender() == gender)
			return m;
	}

	return Movie{};
}

void Repository::likeMovie(std::string& name, int like)
{
	if (like != -1)
	{
		Movie* movie = this->movies.getAllElems();
		if (movie == NULL)
			return;
		for (int i = 0;i < this->movies.getlength();i++)
		{
			Movie m = movie[i];
			if (m.getName() == name)
			{
				this->movies.upMovie(like,i);
			}
		}
	}
}

void Repository::sortRepo()
{
	DynamicVector<Movie> movieSort{movies};
	this->movies.sort(movieSort);
}

size_t Repository::seeCount()
{
	return this->movies.getCount();
}


void Repository::deleteR(std::string & name)
{
	Movie* mov = this->movies.getAllElems();
	if (mov == NULL)
		return;
	for (int i = 0;i < this->movies.getlength();i++)
	{
		Movie m = mov[i];
		if (m.getName() == name)
		{
			this->movies.delDin(i);
		}
	}
}

void Repository::updateR(std::string & name, std::string & gender, int & year, int & likes)
{
	Movie* mov = this->movies.getAllElems();
	if (mov == NULL)
		return;
	for (int i = 0;i < this->movies.getlength();i++)
	{
		Movie m = mov[i];
		if (m.getName() == name)
		{
			this->movies.upDin(gender,year,likes,i);
		}
	}
}

void Repository::add(Movie &m)
{
	if (find(m.getName()) == 0)
		return;
	this->movies.add(m);

}


