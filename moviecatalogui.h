#ifndef MOVIECATALOGUI_H
#define MOVIECATALOGUI_H
#include<QListWidget>
#include"MovieCatalog.h"
class MovieCatalogUI : public QListWidget
{
    Q_OBJECT
public:
    MovieCatalogUI(QWidget *parent=0);
    void reset();
    MovieCatalog* catalog;

};

#endif // MOVIECATALOGUI_H
