#ifndef location_H_
#define location_H_

#include<iostream>
using namespace std;
class location
{
protected:
	int x;
int y;
public:
location();
location(int a,int b);
void setLoc(int a,int b);
location& getloc();
void setx(int a);
int getx();
void sety(int b);
int gety();
location operator++(int );
void printxandy();
};

#endif
