#include "DynamicArray.h"
#include "Movie.h"
using namespace std;



DynamicArray::DynamicArray(int capacity)
{
	this->length = 0;
	this->capacity = capacity;
	this->m = new TElement[capacity];
}


DynamicArray::DynamicArray(const DynamicArray & arr)
{
	this->length = arr.length;
	this->capacity = arr.capacity;
	this->m = new TElement[this->capacity];
	for (int i = 0;i < this->length;i++)
		this->m[i] = arr.m[i];
}

DynamicArray::~DynamicArray()
{
	delete[] this->m;
}

DynamicArray & DynamicArray::operator=(const DynamicArray & arr)
{
	if (this == &arr)
		return *this;
	this->length = arr.length;
	this->capacity = arr.capacity;
	delete[] this->m;

	this->m = new TElement[this->capacity];
	for (int i = 0;i < this->length;i++)
		this->m[i] = arr.m[i];

	return *this;
}
/*
DynamicArray & DynamicArray::operator+(TElement& m)
{
	this->m[this->length] = this->m[this->length] + m;
	this->length++;
	
	return *this;
}*/


void DynamicArray::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);
	TElement* els = new TElement[this->capacity];
	for (int i = 0;i < this->length;i++)
		this->m[i] = els[i];

	delete[] this->m;
	m = els;
}

void DynamicArray::addDin(TElement& m)
{
	if (this->length == this->capacity)
		this->resize();

	this->m[this->length] = m;
	this->length++;
}

void DynamicArray::delDin(int poz)
{
	for (int i = poz;i < this->length - 1;i++)
		this->m[i] = this->m[i + 1];
	this->length--;
}

void DynamicArray::upDin(std::string & gender, int & year, int & likes,int poz)
{
	this->m[poz].setGender(gender);
	this->m[poz].setYear(year);
	this->m[poz].setLikes(likes);
}

void DynamicArray::upMovie(int like, int poz)
{
	this->m[poz].setLikesWithValue(like);
}

void DynamicArray::delMovie(int poz)
{
	for (int i = poz;i < this->length - 1;i++)
		this->m[i] = this->m[i + 1];
	this->length--;
}

int DynamicArray::getlength() const
{
	return this->length;
}

TElement*  DynamicArray::getAllElems() const
{
	return this->m;
}

void DynamicArray::sort(const DynamicArray& arr)
{
	TElement aux;
	for (int i=0;i<arr.length-1;i++)
		for (int j=i+1;j<arr.length;j++)
			if (arr.m[i].getYear() > arr.m[j].getYear())
			{
				aux =arr.m[i];
				arr.m[i] = arr.m[j];
				arr.m[j] = aux;
			}
	
	for (int i = 0;i < arr.length;i++)
	{
		cout << "Movie:" << arr.m[i].getName() << " Gender:" << arr.m[i].getGender() << " Year:" << arr.m[i].getYear() << " Likes:" << arr.m[i].getLikes() << endl;
	}

}



