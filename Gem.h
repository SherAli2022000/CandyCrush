#ifndef Gem_H_
#define Gem_H_

class Gem:public location
{
protected:
string type;

public:
Gem();
Gem(string a,int b,int c);
int getxaxisali();
Gem getGem();
string gettype();
void settype(string a);
};
#endif
