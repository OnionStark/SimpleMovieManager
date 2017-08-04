#ifndef MOVIECATALOGUI_H
#define MOVIECATALOGUI_H
#include<QListWidget>
#include"MovieCatalog.h"
class MovieCatalogUI : public QListWidget
{
    Q_OBJECT
public:
    MovieCatalogUI(QWidget *parent=0);
    ~MovieCatalogUI();
    MovieCatalog* catalog;
public slots:

    void resetMovie();
    void resetMovieSimply();
};

#endif // MOVIECATALOGUI_H
