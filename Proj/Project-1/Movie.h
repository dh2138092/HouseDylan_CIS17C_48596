#ifndef MOVIE
#define MOVIE

#include <iostream>

class Movie
{
public:
	Movie();
	Movie(char *t, char* g, int r, int l, int i, int a, int b);
	~Movie();

	char* getTitle() const;
	char* getGenre() const;
	int getReleaseDate() const;
	int getLength() const;
	int getId() const;
	int getStockCount() const;
	int getInCount() const;
	int getOutCount() const;

	void setInCount(int n);
	void setOutCount(int n);
	void setStockCount();

	void printInfo() const;

	bool operator<(const Movie &m) const; // Required to compare two MOVIEs for std::set

private:
	char *title;
	char *genre;
	int releaseDate;
	int length;
	int id;
	int stockCount;
	int inCount;
	int outCount;
};

#endif