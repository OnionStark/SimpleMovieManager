#include "moviecatalogui.h"
#include<QListWidgetItem>
#include"MovieCatalog.h"
#include"movie.h"
#include<QString>
using namespace std;
MovieCatalogUI::MovieCatalogUI(QWidget *parent)
{
   catalog= new MovieCatalog();
   for(int i=0;i<catalog->MovieList.size();i++){
       string s = catalog->MovieList[i].getName()+"\n"+catalog->MovieList[i].getDirector()+"\n"+to_string(catalog->MovieList[i].getPrice())+"元 "+to_string(catalog->MovieList[i].getWhole_time())+"分钟\n"+catalog->MovieList[i].getIntrotuce();
     QString a = QString::fromStdString(s);
       QListWidgetItem* temp = new QListWidgetItem(a,this);

       QVariant v;
       v.setValue(QString::fromStdString(catalog->MovieList[i].getName()));
      temp->setData(Qt::UserRole,v);

        insertItem(i,temp);

   }
}
void MovieCatalogUI::reset(){
    for(int i=this->count()-1;i>=0;i--){
        this->takeItem(i);
    }

    for(int i=0;i<catalog->MovieList.size();i++){
       string s = catalog->MovieList[i].getName()+"\n"+catalog->MovieList[i].getDirector()+"\n"+to_string(catalog->MovieList[i].getPrice())+"元 "+to_string(catalog->MovieList[i].getWhole_time())+"分钟\n"+catalog->MovieList[i].getIntrotuce();
     QString a = QString::fromStdString(s);
       QListWidgetItem* temp = new QListWidgetItem(a,this);
      QVariant v;
      v.setValue(QString::fromStdString(catalog->MovieList[i].getName()));
      temp->setData(Qt::UserRole,v);

        insertItem(i,temp);

}
}
