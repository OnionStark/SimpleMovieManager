#ifndef MOVIEINFORMATIONLABEL_H
#define MOVIEINFORMATIONLABEL_H
#include<QLabel>
#include<QListWidgetItem>
#include<MovieCatalog.h>
#include<movie.h>
class MovieInformationLabel : public QLabel
{
    Q_OBJECT
public:
    MovieInformationLabel(QWidget *parent=0);
    MovieCatalog* moviecatalog;
    ~MovieInformationLabel();
public slots:
    void showInfo(QListWidgetItem*);
};

#endif // MOVIEINFOMATIONLABEL_H
