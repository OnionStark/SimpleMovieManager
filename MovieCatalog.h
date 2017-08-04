#ifndef MOVIECATALOG_H
#define MOVIECATALOG_H
#include"movie.h"
#include"seat.h"
#include"session.h"
#include<QVector>
#include<QDataStream>
#include<QFile>
#include<QString>
#include<iostream>
using namespace std;
class MovieCatalog
{
public:
    MovieCatalog();
    ~MovieCatalog();
    Movie* findMovie(QString name);

   QVector<Movie> MovieList;
};

#endif // INITIALIZE_H
