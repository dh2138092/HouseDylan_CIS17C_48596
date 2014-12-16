#ifndef MOVIE
#define MOVIE

#include <iostream>

class Movie
{
public:
	Movie();
	Movie(char *title, char* genre, int releaseDate, int length, int id, int inCount, int outCount);
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

	// Required to compare two MOVIEs
	friend bool operator<(const Movie &a, const Movie &b); 
	friend bool operator>(const Movie &a, const Movie &b);
	friend bool operator==(const Movie &a, const Movie &b);

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