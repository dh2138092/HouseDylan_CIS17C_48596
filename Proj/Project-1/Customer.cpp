#include "Customer.h"

Customer::Customer()
{
	name = '\0';
	id = 0;
}

Customer::Customer(char *n, int i)
{
	name = n;
	id = i;
}

Customer::~Customer()
{

}

void Customer::addMovie(Movie m)
{
	movies.insert(m);
}

void Customer::removeMovie(Movie m)
{
	movies.erase(movies.find(m));
}

char* Customer::getName() const
{
	return name;
}

int Customer::getId() const
{
	return id;
}

std::set<Movie> Customer::getMovies() const
{
	return movies;
}

bool Customer::operator<(const Customer &c) const
{
	return id < c.getId();
}