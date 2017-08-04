#include "moviecatalogui.h"
#include<QListWidgetItem>
#include"MovieCatalog.h"
#include"movie.h"
#include<QString>
#include<iostream>

using namespace std;
MovieCatalogUI::MovieCatalogUI(QWidget *parent)
{
  }
void MovieCatalogUI::resetMovie(){
    for(int i=this->count()-1;i>=0;i--){
        this->takeItem(i);
    }

    for(int i=0;i<catalog->MovieList.size();i++){
       QString s = catalog->MovieList[i].getName();
       this->setIconSize(QSize(100,100));
       this->setMovement(QListView::Static);
      QString a=catalog->MovieList[i].getUrl();
       QListWidgetItem* temp = new QListWidgetItem(QIcon(a),s);
      QVariant v;
      v.setValue(catalog->MovieList[i].getName());
      temp->setData(Qt::UserRole,v);

        insertItem(i,temp);

}
}
MovieCatalogUI::~MovieCatalogUI(){
}
void MovieCatalogUI::resetMovieSimply(){
    for(int i=this->count()-1;i>=0;i--){
        this->takeItem(i);
    }
    for(int i=0;i<catalog->MovieList.size();i++){
        QListWidgetItem* temp = new QListWidgetItem(catalog->MovieList[i].getName(),this);
        QVariant v;
        v.setValue(catalog->MovieList[i].getName());
        temp->setData(Qt::UserRole,v);
        insertItem(i,temp);
    }
}
