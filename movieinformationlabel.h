#ifndef MOVIEINFORMATIONLABEL_H
#define MOVIEINFORMATIONLABEL_H
#include<QLabel>
#include<QListWidgetItem>

class MovieInformationLabel : public QLabel
{
    Q_OBJECT
public:
    MovieInformationLabel(QWidget *parent=0);
public slots:
    void showInfo(QListWidgetItem*);
};

#endif // MOVIEINFOMATIONLABEL_H
