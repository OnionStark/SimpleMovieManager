#include "commentcatalog.h"
#include"comment.h"
CommentCatalog::CommentCatalog()
{
QFile file("comment.dat");
file.open(QIODevice::ReadOnly);
QDataStream in(&file);
if(file.exists()&&!in.atEnd()){
    in>>CommentList;
}
 file.close();
}
CommentCatalog::~CommentCatalog(){
   QFile file("comment.dat") ;
   file.open(QIODevice::WriteOnly|QIODevice::Truncate);
   if(file.exists()){
   QDataStream out(&file);
   out<<this->CommentList;
   cout<<"write comment success"<<endl;

   file.close();
   }
}
QVector<Comment>& CommentCatalog::getCommentList(){
   return CommentList;
}
