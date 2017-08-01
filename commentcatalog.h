#ifndef COMMENTCATALOG_H
#define COMMENTCATALOG_H
#include"comment.h"
#include<vector>
using namespace std;

class CommentCatalog
{
public:
    CommentCatalog();

private:
   vector<Comment> CommentList;
};

#endif // COMMENTCATALOG_H
