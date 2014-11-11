#include "Movie.h"

Movie::Movie()
{
	title = '\0';
	genre = '\0';
	releaseDate = 0;
	length = 0;
}

Movie::Movie(char *t, char *g, int r, int l, int i, int a, int b)
{	
	title = t;
	genre = g;
	releaseDate = r;
	length = l;
	id = i;
	inCount = a;
	outCount = b;
	setStockCount();
}

Movie::~Movie()
{

}

char* Movie::getTitle() const
{
	return title;
}

char* Movie::getGenre() const
{
	return genre;
}

int Movie::getReleaseDate() const
{
	return releaseDate;
}

int Movie::getLength() const
{
	return length;
}

int Movie::getId() const
{
	return id;
}

int Movie::getStockCount() const
{
	return stockCount;
}

int Movie::getInCount() const
{
	return inCount;
}

int Movie::getOutCount() const
{
	return outCount;
}

void Movie::setInCount(int n)
{
	inCount = n;
	setStockCount();
}

void Movie::setOutCount(int n)
{
	outCount = n;
	setStockCount();
}

void Movie::setStockCount()
{
	stockCount = inCount + outCount;
}

void Movie::printInfo() const
{
	std::cout << "Title:        " << title << '\n'
	     	  << "Genre:        " << genre << '\n'
		      << "Length:       " << length << " minutes\n"
		      << "ID#:          " << id << '\n'
		      << "In Stock:     " << outCount << '\n'
		      << "Total Stock:  " << stockCount << "\n\n"
		      << "--------------\n\n";
}

bool Movie::operator<(const Movie &m) const
{
	return id < m.getId();
}