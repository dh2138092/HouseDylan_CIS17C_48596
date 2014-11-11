#ifndef CUSTOMER
#define CUSTOMER

#include <set>
#include "Movie.h"

class Customer
{
public:
	Customer();
	Customer(char *n, int i);
	~Customer();

	void addMovie(Movie m);
	void removeMovie(Movie m);
	std::set<Movie> getMovies() const;

	char* getName() const;
	int getId() const;

	bool operator<(const Customer &c) const; // Required to compare two CUSTOMERs for std::set

private:
	char *name;
	int id;
	std::set<Movie> movies;
};

#endif