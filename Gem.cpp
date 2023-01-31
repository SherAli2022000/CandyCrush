#include<iostream>
#include"location.h"
#include"Gem.h"

using namespace std;

Gem::Gem()
{
	type="-";
}
Gem::Gem(string a,int b,int c):type(a)
{
this->setx(b);
this->sety(c);
}

int Gem::getxaxisali()
{
return this->getx();
}

Gem Gem::getGem()
{
int a;
a=rand()%7 +1;
switch (a)
{
case 1:
{
	type="Rectangle";
	x=0;
	y=0;
	break;
}
case 2:
{
	type="Triangle";
	x=0;
				y=0;
	break;
}
case 3:
{
	type="Circle";
	x=0;
				y=0;
	break;
}
case 4:
{
	type="Kite";
	x=0;
				y=0;
	break;
}
case 5:
{
	type="Diamond";
	x=0;
				y=0;
	break;
}
case 6:
{
	type="Donut";
	x=0;
	y=0;
	break;
}
case 7:
{
	type="ali";
	x=0;
	y=0;
	break;
}
}
return *this;
}

string Gem::gettype()
{
	return type;
}
void Gem::settype(string a)
{
type=a;
}



