#include<iostream>
#include"location.h"
#include"Swaping.h"
using namespace std;


Swaping::Swaping()
{
g1.setx(0);
g1.sety(0);

g2.setx(0);
g2.sety(0);
}

void Swaping::setloc1(int a,int b)
{
g1.setx(a);
g1.sety(b);
}

void Swaping::setloc2(int a,int b)
{
g2.setx(a);
g2.sety(b);
}

location Swaping::getg1()
{
return g1;
}

location Swaping::getg2()
{
return g2;
}

int Swaping::getg1X()
{
return g1.getx();
}
int Swaping::getg1Y()
{
return g1.gety();
}
void Swaping::printloc1()
{
cout<<"x: "<<g1.getx()<< " y : "<<g1.gety()<<endl;
}



