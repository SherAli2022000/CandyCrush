#ifndef score_H_
#define score_H_
#include<iostream>
using namespace std;

class score{
protected:
int s;

public:
score();
score(int a);
virtual void setscore(int a);
virtual int getscore();
virtual score operator++( );
virtual void increaseScr(int a);
};
#endif

