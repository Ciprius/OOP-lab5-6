#pragma once
#include <iterator>
#include <vector>
using namespace std;

template <typename T>
class  DynamicVector
{
private:
	T* m;
	int length;
	int capacity;
	static size_t count;

	//Resizes the current DynamicVector
	void resize(double factor = 2);

public:
	DynamicVector(int capacity = 100);
	DynamicVector(const DynamicVector& v);
	~DynamicVector();
	DynamicVector& operator=(const DynamicVector& v);
	T& operator[](int pos);
	void add(const T& e);
	int getlength() const;
	void setLength(int s) { size = s; }
	T* getAllElems() const;
	void delDin(int poz);
	void upDin(std::string & gender, int & year, int & likes, int poz);
	void upMovie(int like, int poz);
	void sort(const DynamicVector& arr);
	void delMovie(int poz);
	static size_t getCount() { return count; }
public:
	class iterator : public std::iterator<std::forward_iterator_tag, T, std::ptrdiff_t, T*, T&>
	{
	private:
		T* ptr;
	public:
		iterator(T* p): ptr{ p } { }
		iterator operator++() { this->ptr++; return *this; }
		iterator operator++(int dummy) { iterator i = *this; this->ptr++; return i; }
		T& operator*() { return *this->ptr; }
		T* operator->() { return ths->ptr; }
		bool operator!=(const iterator& it) { return this->ptr != it.ptr; }
	};
	iterator begin()
	{
		return iterator{ this->m };
	}
	iterator end()
	{
		return iterator{ this->m + this->length };
	}
};

template <typename T>
size_t DynamicVector<T>::count = 0;

template <typename T>
void DynamicVector<T>::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);
	T* els = new T[this->capacity];
	for (int i = 0;i < this->length;i++)
		els[i] = this->m[i];

	delete[] this->m;
	this->m = els;
}

template <typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
	this->length = 0;
	this->count = 0;
	this->capacity = capacity;
	this->m = new T[capacity];
	count++;
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector & v)
{
	this->length = v.length;
	this->capacity = v.capacity;
	this->m = new T[this->capacity];
	for (int i = 0;i < this->length;i++)
		this->m[i] = v.m[i];
	count++;
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->m;
	count--;
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T> & v)
{
	if (this == &v)
		return *this;
	this->length = v.length;
	this->capacity = v.capacity;
	delete[] this->m;
	this->m = new T[this->capacity];
	for (int i = 0;i < this->length;i++)
		this->m[i] = v.m[i];

	return *this;
}

template <typename T>
T & DynamicVector<T>::operator[](int pos)
{
	return this->m[pos];
}

template <typename T>
void DynamicVector<T>::add(const T & e)
{
	if (this->length == this->capacity)
		this->resize();
	this->m[this->length] = e;
	this->length++;
}

template <typename T>
int DynamicVector<T>::getlength() const
{
	return this->length;
}

template <typename T>
T * DynamicVector<T>::getAllElems() const
{
	return this->m;
}

template<typename T>
void DynamicVector<T>::delDin(int poz)
{
	for (int i = poz;i < this->length - 1;i++)
		this->m[i] = this->m[i + 1];
	this->length--;
}

template<typename T>
void DynamicVector<T>::upDin(std::string & gender, int & year, int & likes, int poz)
{
	this->m[poz].setGender(gender);
	this->m[poz].setYear(year);
	this->m[poz].setLikes(likes);
}

template<typename T>
void DynamicVector<T>::upMovie(int like, int poz)
{
	this->m[poz].setLikesWithValue(like);
}

template<typename T>
void DynamicVector<T>::sort(const DynamicVector & arr)
{
	T aux;
	for (int i = 0;i<arr.length - 1;i++)
		for (int j = i + 1;j<arr.length;j++)
			if (arr.m[i].getYear() > arr.m[j].getYear())
			{
				aux = arr.m[i];
				arr.m[i] = arr.m[j];
				arr.m[j] = aux;
			}

	for (int i = 0;i < arr.length;i++)
	{
		cout << "Movie:" << arr.m[i].getName() << " Gender:" << arr.m[i].getGender() << " Year:" << arr.m[i].getYear() << " Likes:" << arr.m[i].getLikes() << endl;
	}
}

template<typename T>
void DynamicVector<T>::delMovie(int poz)
{
	for (int i = poz;i < this->length - 1;i++)
		this->m[i] = this->m[i + 1];
	this->length--;
}

