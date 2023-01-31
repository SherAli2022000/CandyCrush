#include <iostream>
#include<cctype>
#include"name.h"
using namespace std;


name::name()
{
	n=NULL;
	fname="-";
	lname="-";
	lev=0;
}
name::name(string a,string b)
{
	fname=a;
	lname=b;
}
char* name::getptr()
{
return n;
}
void name::setfname(string a)
{
	
	
	toupper(a[0]);
	fname=a;
}
string name::getfname()
{
	return fname;
}
int name::getlev()
{
return lev;
}
void name::setlevel(int a)
{
lev=a;
}
void name::setlname(string a)
{
lname=a;
if(islower(lname[0])==1)
{
toupper(lname[0]);

}
}
string name::getlname()
{
return lname;
}

name& name::operator=(name& other)
{
fname=other.fname;
lname=other.lname;
lev=other.lev;
}
name& name::operator+(const char &str)
{
	char *newptr;
	int len=0;
	for(int i=0;n[i]!='\0';i++)
	{
		len++;
	}

	newptr=new char[len+1];

	for(int i=0;i<len;i++)
	{
		newptr[i]=n[i];
	}
	newptr[len]=str;

	n=newptr;
	return *this;
}

void name::print()
{
	/*for(int i=0;i<4;i++)
	{
		cout<<n[i]<<endl;
	}*/
}


