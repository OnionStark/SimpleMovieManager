#ifndef COMMENT_H
#define COMMENT_H
#include<string>
using namespace std;

class Comment
{
public:
    Comment();
    void setMovie(string a);
    void setUserName(string a);
    void setInformation(string a);
    string getMovie();
    string getUser();
    string getInformation();



private:
   string movie;
   string user_name;
   string information;
};

#endif // COMMENT_H
