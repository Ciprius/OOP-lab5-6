#pragma once
#include <string>
#include "Movie.h"
#define CAPACITY 10


typedef Movie TElement;

class DynamicArray
{
public:
	//default constructor
	DynamicArray(int capacity = 100);

	//copy constructor for dynamic array
	DynamicArray(const DynamicArray& arr);
	~DynamicArray();


	/*
	This function adds a new movie to the array
	Input:m-the movie to add
	*/
	void addDin(TElement& m);


	/*
	This function deletes a movie from the array
	Input:poz-the position on which the movie is
	*/
	void delDin(int poz);


	/*
	This function updates a movie 
	Input:gender-the new gender,year-the new year,likes-the new number of likes,poz-the position on which the movie is
	*/
	void upDin(std::string & gender, int & year, int & likes,int poz);


	/*
	This function updates the number of likes for a certain movie
	*/
	void upMovie(int like,int poz);


	/*	
	This function deletes a movie from the Watch list
	Input:poz-the position on which the movie is
	*/
	void delMovie(int poz);

	DynamicArray& operator=(const DynamicArray& arr);
	//DynamicArray& operator+(TElement& m);


	//Retuns the length of the array
	int getlength() const;


	//Returns all the elements of the array
	TElement* getAllElems() const;

	void sort(const DynamicArray& arr);

private:
	int length;
	int capacity;
	TElement* m;
	void resize(double factor = 2);
};