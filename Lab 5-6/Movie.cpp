#include "Movie.h"
#include <Windows.h>
#include <shellapi.h>

Movie::Movie() : name(""), gender(""), trailer(""), year(0), likes(0) {}


Movie::Movie(const std::string & name, const std::string & gender, const std::string & trailer, int  year, int  likes)
{
	this->name = name;
	this->gender = gender;
	this->trailer = trailer;
	this->year = year;
	this->likes = likes;
}

void Movie::Play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}


