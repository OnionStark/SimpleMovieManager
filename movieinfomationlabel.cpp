#include "movieinformationlabel.h"

MovieInformationLabel::MovieInformationLabel(QWidget* parent):QLabel(parent)
{

}
void MovieInformationLabel::showInfo(QListWidgetItem* a){
    this->setText(a->text());
}
