#include "movieinformationlabel.h"

MovieInformationLabel::MovieInformationLabel(QWidget* parent):QLabel(parent)
{

}
MovieInformationLabel::~MovieInformationLabel(){

}

void MovieInformationLabel::showInfo(QListWidgetItem* a){
   for(int i=0;i<moviecatalog->MovieList.size();i++){
       if(a->text()==moviecatalog->MovieList[i].getName()){
           Movie temp =moviecatalog->MovieList[i];
           this->setText("电影名:"+temp.getName()+"\n导演:"+temp.getDirector()+"\n演员:"+temp.getActor()+"\n时长:"+QString::number(temp.getWhole_time())+"\t票价:"+QString::number(temp.getPrice())+"\n类型:"+temp.getType());
           break;
       }
   }

}
