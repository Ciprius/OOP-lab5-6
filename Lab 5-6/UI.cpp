#include "UI.h"
#include <string>
#include <stdexcept>

using namespace std;


void UI::printMenu()
{
	cout << endl;
	cout << "1- Manage the Admin mode." << endl;
	cout << "2- Manage the User mode." << endl;
	cout << "0- Exit." << endl;
}

void UI::printAdminMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add movie." << endl;
	cout << "\t 2 - Display all." << endl;
	cout << "\t 3 - Delete movie"<<endl;
	cout << "\t 4 - Update movie"<< endl;
	cout << "\t 5 - sort by year." << endl;
	cout << "\t 6 - see the total number of instances." << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::printUserMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add movies by gender." << endl;
	cout << "\t 2 - Delete a movie from watchlist."<< endl;
	cout << "\t 3 - Play." << endl;
	cout << "\t 4 - Next." << endl;
	cout << "\t 5 - Sort the list of movie ascendently by the year."<< endl;
	cout << "\t 0 - Back." << endl;
}


void UI::addUI()
{
	cout << "Enter the name: ";
	std::string name;
	getline(cin, name);

	cout << "Enter the gender: ";
	std::string gender;
	getline(cin, gender);

	cout << "Enter the trailer: ";
	std::string trailer;
	getline(cin, trailer);

	int year = 0, likes = 0;
	cout << "Enter the year: ";
	cin >> year;

	cout << "Enter the likes: ";
	cin >> likes;
	try
	{
		//this->val.validaddFunct(name);
		if (this->cont.getRepo().find(name) == 1)
		{
			this->cont.addController(name, gender, trailer, year, likes);
			cout << "The movie added with succes!" << endl;
		}
		else
			throw std::invalid_argument("The name already exists!");
	}
	catch (const std::invalid_argument&)
	{
		cout << "The name already exists!" << endl;
		return;
	}

}

void UI::displayAllMovies()
{
	DynamicVector<Movie> arr1 = this->cont.getRepo().getMovies();
	Movie* movies = arr1.getAllElems();
	if (movies == NULL)
		return;
	if (arr1.getlength() == 0)
	{
		cout << "There are no movies in the repository" << endl;
		return;
	}

	for (int i = 0;i < arr1.getlength();i++)
	{
		Movie m = movies[i];
		cout <<"Movie:"<< m.getName() << " Gender:" << m.getGender() << " Year:" << m.getYear() << " Likes:" << m.getLikes() << endl;
	}
}

void UI::deleteUI()
{
	cout << "Enter the name:";
	std::string name;
	getline(cin, name);
	try
	{
		if (this->cont.getRepo().find(name) == 0)
		{
			this->cont.deleteController(name);
			cout << "The movie deleted with succes!" << endl;
		}
		else
			throw std::invalid_argument("The name does not exists!");
	}
	catch (const std::invalid_argument&)
	{
		cout << "The name does not exists!" << endl;
		return;
	}
	
	
}

void UI::updateUI()
{
	cout << "Enter the name: ";
	std::string name;
	getline(cin, name);

	cout << "Enter the gender: ";
	std::string gender;
	getline(cin, gender);

	int year = 0, likes = 0;
	cout << "Enter the year: ";
	cin >> year;

	cout << "Enter the likes: ";
	cin >> likes;
	try
	{
		if (this->cont.getRepo().find(name) == 0)
		{
			this->cont.updateController(name, gender, year, likes);
			cout << "The movie updated with succes!" << endl;
		}
		else
			throw std::invalid_argument("The name does not exists!");
	}
	catch (const std::invalid_argument&)
	{
		cout << "The name does not exists!" << endl;
		return;
	}
	
} 

void UI::addWatchUI()
{
	cout << "Give the gender: ";
	std::string gender;
	getline(cin,gender);
	Movie mov=this->cont.getRepo().findByGender(gender);
	try
	{
		if (mov.getGender() == "")
		{
			throw std::invalid_argument("There is no song with the given gender!");
		}
		else
			this->cont.addWatchController(gender, 1);
	}
	catch (const std::invalid_argument&)
	{
		cout << "There is no song with the given gender!" << endl;
		return;
	}
}

void UI::delWatchUI()
{
	cout << " Give the name: ";
	std::string name;
	getline(cin,name);
	try
	{
		if (this->cont.getRepo().find(name) == 0)
		{
			this->cont.delWatchController(name, 1);
			cout << "The movie deleted with succes!" << endl;
		}
		else
			throw std::invalid_argument("The name does not exists!");
	}
	catch (const std::invalid_argument&)
	{
		cout << "The name does not exists!" << endl;
		return;
	}
}


void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;
		if (command == 1)
		{
			while (true)
			{
				UI::printAdminMenu();
				int commRepo{ 0 };
				cout << "Input the command: ";
				cin >> commRepo;
				cin.ignore();
				if (commRepo == 0)
					break;
				if (commRepo == 1)
					this->addUI();
				if (commRepo == 2)
					this->displayAllMovies();
				if (commRepo == 3)
					this->deleteUI();
				if (commRepo == 4)
					this->updateUI();
				if (commRepo == 5)
					this->cont.sortController();
				if (commRepo == 6)
					cout << "The total number of instances is:" <<this->cont.seeCount() << endl;
			}
		}
		if (command == 2)
		{
			while (true)
			{
				UI::printUserMenu();
				int commWatch{ 0 };
				cout << "Input the command: ";
				cin >> commWatch;
				cin.ignore();
				if (commWatch == 0)
					break;
				if (commWatch == 1)
					this->addWatchUI();
				if (commWatch == 2)
					this->delWatchUI();
				if (commWatch == 3)
				{
					if (this->cont.getWatchlist().isEmpty() == 1)
						cout << "Nothing to watch, the watchlist is empty." << endl;
					else
					{
						this->cont.startWatchlist();
						Movie m = this->cont.getWatchlist().getCurrentMovie();
						cout << "You watch at: " << m.getName() << " - " << m.getGender() << endl;
					}
				}
				if (commWatch == 4)
				{
					if (this->cont.getWatchlist().isEmpty() == 1)
						cout << "Nothing to watch, the watchlist is empty." << endl;
					else
					{
						this->cont.nextWatchlist();
						Movie m = this->cont.getWatchlist().getCurrentMovie();
						cout << "You watch at: " << m.getName() << " - " << m.getGender() << endl;
					}
				}
				if (commWatch == 5)
				{
					this->cont.sortController();
				}
			}
		}
	}
}
/*
void Validator::validaddFunct(const std::string & name)
{
	if (repo.find(name) == 0)
	{
		UIExceptions x{ "The name already exist!" };
		throw x;
	}

}*/
