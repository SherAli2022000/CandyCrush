#ifndef Swaping_H_
#define Swaping_H_

#include<iostream>
#include"location.h"
using namespace std;
class Swaping
{
location g1;
location g2;

public:

Swaping();
void setloc1(int a,int b);
void setloc2(int a,int b);
location getg1();
location getg2();
int getg1X();
int getg1Y();
void printloc1();

};

#endif
