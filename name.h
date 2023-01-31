#ifndef NAME_H_
#define NAME_H_


#include <iostream>

using namespace std;

class name
{
char* n;
string fname;
string lname;
int lev;

public:
name();

name(string a,string b);
virtual void setfname(string a);
string getfname();
virtual void setlname(string a);
string getlname();
void captalizeF();
void captalizeL();
void setlevel(int a);
int getlev();
name& operator=(name& other);

name& operator+(const char &str);
char* getptr();
void print();

};
#endif
