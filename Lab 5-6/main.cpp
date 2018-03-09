#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include "Movie.h"
#include "UI.h"
#include <Windows.h>
#include "Tests.h"



void startapp()
{
	tests();
	
	Repository repo{};
	//Validator val{repo};

	Movie m1{ "Logan", "Action", "https://www.youtube.com/watch?v=gbug3zTm3Ws", 2017, 1000 };
	Movie m2{ "Star Wars VII", "SF","https://www.youtube.com/watch?v=sGbxmsDFVnE",2016,6053 };
	Movie m3{ "Transformers","SF","https://www.youtube.com/watch?v=dYDGqmxMZFI",2014,7654 };
	Movie m4{ "Deadpool", "Action", "https://www.youtube.com/watch?v=9vN6DHB6bJc",2016,3456 };
	Movie m5{ "Justice League", "SF","https://www.youtube.com/watch?v=3cxixDgHUYw",2017,6078};
	Movie m6{ "Dumb and Dumber to", "Comedy","https://www.youtube.com/watch?v=lGXHVlEklgQ",2014,345};
	Movie m7{ "American Sniper", "Documentary","https://www.youtube.com/watch?v=99k3u9ay1gs",2014,3455};
	Movie m8{ "1 The Movie", "Documentary","https://www.youtube.com/watch?v=k59zcs00k0A",2013,2145};
	Movie m9{ "Grave Encounters","Horror","https://www.youtube.com/watch?v=g8FBRATbJoA",2011,100};
	Movie m10{ "Pacific Rim","SF","https://www.youtube.com/watch?v=5guMumPFBag",2013,2214};
	Movie m11{ "Jurassic World","Fantasy","https://www.youtube.com/watch?v=RFinNxS5KN4",2014,7054};
	Movie m12{ "The Avengers:Age of Ultron", "Action","https://www.youtube.com/watch?v=CieuGZ7TthE",2015,6554};
	Movie m13{ "Fist Fight","Comedy","https://www.youtube.com/watch?v=6YVBj2o_3mg",2016,5434};
	Movie m14{ "X-men Apocalypse","Fantasy","https://www.youtube.com/watch?v=Jer8XjMrUB4",2016,5567};
	Movie m15{ "Captain America:Civil War","Fantasy","https://www.youtube.com/watch?v=dKrVegVI0Us",2016,9756};
	Movie m16{ "Ted 2","Comedy","https://www.youtube.com/watch?v=S3AVcCggRnU",2016,3567};
	Movie m17{ "Doctor Strange","Action","https://www.youtube.com/watch?v=HSzx-zryEgM",2016,4536};
	Movie m18{ "Ouja","Horror","https://www.youtube.com/watch?v=_T1Jj1inE8M",2014,123};
	Movie m19{ "Don't Breathe","Horror","https://www.youtube.com/watch?v=76yBTNDB6vU",2016,3532};
	Movie m20{ "Fast and Furious 8","Action","https://www.youtube.com/watch?v=VVQLn10ZsDg",2017,9077};
	repo.add(m1);
	repo.add(m2);
	repo.add(m3);
	repo.add(m4);
	repo.add(m5);
	repo.add(m6);
	repo.add(m7);
	repo.add(m8);
	repo.add(m9);
	repo.add(m10);
	repo.add(m11);
	repo.add(m12);
	repo.add(m13);
	repo.add(m14);
	repo.add(m15);
	repo.add(m16);
	repo.add(m17);
	repo.add(m18);
	repo.add(m19);
	repo.add(m20);


	Controller cont{ repo };
	UI ui{ cont };
	ui.run();

}

int main()
{
	startapp();

	_CrtDumpMemoryLeaks();
	return 0;
}
