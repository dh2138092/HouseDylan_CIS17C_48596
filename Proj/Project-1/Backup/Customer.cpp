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

void Customer::addMovie(Movie *m)
{
	movies.insert(m);
}

void Customer::removeMovie(Movie *m)
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

std::set<Movie *> Customer::getMovies() const
{
	return movies;
}

void Customer::printInfo() const
{
	std::cout << "Name:  " << name << '\n'
		      << " ID#:  " << id << "\n\n"
		      << "Movies checked-out:\n";

	for (std::set<Movie *>::iterator it = movies.begin(); it != movies.end(); ++it)
		std::cout << "    " << (*it)->getTitle() << '\n';

	std::cout << "--------------\n\n";
}

bool Customer::operator<(const Customer &c) const
{
	return id < c.getId();
}