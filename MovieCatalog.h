#ifndef MOVIECATALOG_H
#define MOVIECATALOG_H
#include"movie.h"
#include"seat.h"
#include"session.h"
#include<vector>
using namespace std;
class MovieCatalog
{
public:
    MovieCatalog();
   vector<Movie> MovieList;
};

#endif // INITIALIZE_H
