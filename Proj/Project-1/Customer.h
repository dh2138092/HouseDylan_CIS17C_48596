#ifndef CUSTOMER
#define CUSTOMER

#include <list>
#include "Movie.h"

class Customer
{
public:
	Customer();
	Customer(char *n, int i);
	~Customer();

	void addMovie(Movie *m);
	void removeMovie(Movie *m);
	std::list<Movie *> getMovies() const;

	char* getName() const;
	int getId() const;

	void printInfo() const;

private:
	char *name;
	int id;
	std::list<Movie *> movies;
};

#endif