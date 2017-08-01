#ifndef ROOTADMINISTRATOR_H
#define ROOTADMINISTRATOR_H


class Administrator
{
public:
    Administrator();
    void setNumber(int a);
    void setPassword(int a);
    int getNumber();
    int getPasswoud();
private:
    int number;
    int password;
};

#endif // ROOTADMINISTRATOR_H
