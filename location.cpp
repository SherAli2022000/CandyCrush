
#include<iostream>
#include"location.h"

using namespace std;

location::location()
{
	x=0;y=0;
}
location::location(int a,int b)
{
	x=a;
	y=b;
}
void location::setLoc(int a,int b)
{
	x=a;
	y=b;

}
location& location::getloc()
{
	return *this;
}
void location::setx(int a)
{
	x=a;
}
int location::getx()
{
	return x;
}
void location::sety(int b)
{
	y=b;
}

int location::gety()
{
	return y;
}

location location::operator++(int )
{
x=x+1;
y=y+1;
return *this;
}
void location::printxandy()
{
	cout<<"X : "<<x<<" Y : "<<y<<endl;
}


