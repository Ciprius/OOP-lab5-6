#include "Tests.h"
#include <assert.h>
using namespace std;

void tests()
{
	Repository repot{};

	Movie m1{ "Logan", "Action", "https://www.youtube.com/watch?v=gbug3zTm3Ws", 2017, 1000 };
	Movie m2{ "Star Wars VII", "SF","https://www.youtube.com/watch?v=sGbxmsDFVnE",2016,6053 };
	Movie m3{ "Transformers","SF","https://www.youtube.com/watch?v=dYDGqmxMZFI",2014,7654 };
	Movie m4{ "Deadpool", "Action", "https://www.youtube.com/watch?v=9vN6DHB6bJc",2016,3456 };
	repot.add(m1);
	repot.add(m2);
	repot.add(m3);
	repot.add(m4);

	Controller contt{ repot };

	DynamicVector<Movie> mov = contt.getRepo().getMovies();
	assert(mov.getlength()==4);


	//Add tests
	//-----------------------------------------------------
	int a = 2017,b=1000;
	contt.addController("Logan", "Action", "https://www.youtube.com/watch?v=gbug3zTm3Ws", a, b);
	assert(mov.getlength() == 4);
	a = 2017; b = 9077;
	contt.addController("Fast and Furious 8", "Action", "https://www.youtube.com/watch?v=VVQLn10ZsDg", a, b);
	DynamicVector<Movie> mov1 = contt.getRepo().getMovies();
	assert(mov1.getlength() == 5);
	a = 2016;b = 3532;
	contt.addController("Don't Breathe", "Horror", "https://www.youtube.com/watch?v=76yBTNDB6vU", a, b);
	DynamicVector<Movie> mov2 = contt.getRepo().getMovies();
	assert(mov2.getlength() == 6);
	//-----------------------------------------------------


	//Delete tests
	//-----------------------------------------------------
	std::string name = "Logan";
	contt.deleteController(name);
	DynamicVector<Movie> mov3 = contt.getRepo().getMovies();
	assert(mov3.getlength() == 5);
	std::string name1 = "Deadpool";
	contt.deleteController(name1);
	DynamicVector<Movie> mov4 = contt.getRepo().getMovies();
	assert(mov4.getlength() == 4);
	std::string name2 = "Deadpoolrrff";
	contt.deleteController(name2);
	DynamicVector<Movie> mov5 = contt.getRepo().getMovies();
	assert(mov5.getlength() == 4);
	//-----------------------------------------------------


	//Update tests
	//-----------------------------------------------------
	std::string name7 = "Star Wars VII";
	std::string gender = "Action";
	int year = 2018,likes=3456,c=0;
	contt.updateController(name7,gender,year,likes);
	//repot.updateR(name7,gender,year,likes);
	DynamicVector<Movie> mov6 = contt.getRepo().getMovies();
	Movie* movie = mov6.getAllElems();
	for (int i = 0;i < mov6.getlength();i++)
	{
		Movie m = movie[i];
		if (m.getName() == name7 && m.getGender() == gender && m.getYear() == year && m.getLikes() == likes)
			c = 1;
	}
	assert(c==1);
	//-----------------------------------------------------


	//Instances tests
	//-----------------------------------------------------
	assert(contt.seeCount()==8);
	//-----------------------------------------------------


	//Add Watchlist tests
	//-----------------------------------------------------
	std::string gender1 = "ffgg";
	Movie mov9 = contt.getRepo().findByGender(gender1);
	assert(mov9.getGender()=="");
	std::string gender2 = "Action";
	Movie mov10 = contt.getRepo().findByGender(gender2);
	assert(mov10.getGender() == "Action");
	contt.addWatchController(gender2,0);
	assert(contt.getWatchlist().isEmpty()==0);
	//-----------------------------------------------------


	//Delete Movie from Watchlist tests
	//-----------------------------------------------------
	std::string name10 = "fgfdggf";
	contt.delWatchController(name10,0);
	assert(contt.getWatchlist().isEmpty()==0);
	std::string name11 = "Star Wars VII";
	contt.delWatchController(name11, 0);
	assert(contt.getWatchlist().isEmpty()==0);
	std::string name12 = "Fast and Furious 8";
	contt.delWatchController(name12,0);
	assert(contt.getWatchlist().isEmpty()==1);
	//-----------------------------------------------------
}
