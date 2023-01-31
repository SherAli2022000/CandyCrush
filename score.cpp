#include<iostream>
#include"score.h"

using namespace std;

score::score()
{
s=0;
}
score::score(int a)
{
s=a;
}
void score::setscore(int a)
{
s=a;
}
int score::getscore()
{
return s;
}
score score::operator++( )
{
this->s=this->s+1;
return *this;
}
void score::increaseScr(int a)
{
s=s+a;
}



