#ifndef COMMENTCATALOG_H
#define COMMENTCATALOG_H
#include"comment.h"
#include<QVector>
#include<QDataStream>
#include<QFile>
#include<iostream>
using namespace std;

class CommentCatalog
{
public:
    CommentCatalog();
    ~CommentCatalog();
    QVector<Comment>& getCommentList();
private:
   QVector<Comment> CommentList;
};

#endif // COMMENTCATALOG_H
