#ifndef GameBoard_H_
#define GameBoard_H_

#include<iostream>
#include"score.h"
#include"location.h"
#include"name.h"
#include"Swaping.h"

#include "Gem.h"


using namespace std;

class GameBoard
{
protected:

	score scr;
	Gem** gems;
	int xArr[8]={90,150,210,270,330,390,450,510};
	int yArr[8]={185,245,305,365,425,485,545,605};
	int level;
	int choice;
	location menuloc;
	int time;
	int GameStart;
	Swaping swaps;
	int stop;
	name Name;
	

public:
	GameBoard();

void setName(string a, string b);
string getFNAME();
string getLNAME();
void settime(int a);
int gettime();
void setswap1(int a,int b);
void setswap2(int a,int b);
int returnG1x();
int returnG1y();
int operator--(int);
void setchoice(int a);
int getchoice();
void setGameStart(int a);
int getGameStart();
void setMenuLoc(int x,int y);
location getMenuLoc();
virtual int getscore();
void setstop(int a);
int getstop();
void setlevel(int a);
int getlevel();
virtual void setscore(int a);
void getGems();
Gem** getgem();
int* getxArr();
int* getyArr();
void SwapProcess(int x1,int y1,int x2,int y2);
void Swapcheck();
void newappear();
void noMoveUp(int x1,int y1,int x2,int y2);
bool removePossible();
void ifnoExist();		
void inbetween();
void checkremove();
void checkHighScore(int l);
void MenuDisplay();
void PlayerDisplay();
void display();
void gameSelect();
void Pause();
void hint();
void levelDisplay();
};
#endif

