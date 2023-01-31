#include<iostream>
#include<fstream>
#include"util.h"
#include"score.h"
#include"location.h"
#include"Swaping.h"
#include"GameBoard.h"


using namespace std;


GameBoard::GameBoard()            // default constructor
{
	gems=NULL;
	choice=0;
	GameStart=0;
}

string GameBoard::getFNAME()		// getter first name
{
Name.getfname();
}
string GameBoard::getLNAME()		//getter last name
{
Name.getlname();
}
void GameBoard::setName(string a,string b)	//setter name
{
Name.setfname(a);
Name.setlname(b);
}
void GameBoard::settime(int a)		//setter time
{
time=a;
}
int GameBoard::gettime()		//getter time
{
return time;
}
void GameBoard::setswap1(int a,int b)		//setter swapping
{
swaps.setloc1(a,b);
}
void GameBoard::setswap2(int a,int b)
{
swaps.setloc2(a,b);
}

int GameBoard::returnG1x()
{
return swaps.getg1X();
}
int GameBoard::returnG1y()
{
return swaps.getg1Y();
}
int GameBoard::operator--(int)
{
time=time-1;
}
void GameBoard::setchoice(int a)
{
choice=a;
}
int GameBoard::getchoice()
{
return choice;
}

void GameBoard::setGameStart(int a)
{
GameStart=a;
}
int GameBoard::getGameStart()
{
return GameStart;
}
void GameBoard::setMenuLoc(int x,int y)
{
menuloc.setx(x);
menuloc.sety(y);
}

location GameBoard::getMenuLoc()
{
return menuloc;
}
int GameBoard::getscore()
{
return scr.getscore();
}

void GameBoard::setstop(int a)
{
stop=a;
}
int GameBoard::getstop()
{
return stop;
}

void GameBoard::setlevel(int a)
{
level=a;
}
int GameBoard::getlevel()
{
return level;
}
void GameBoard::setscore(int a)
{
scr.setscore(a);
}

void GameBoard::getGems()
{
	gems=new Gem *[8];
	for(int i=0;i<8;i++)
	{
		gems[i]=new Gem[8];
	}

	Gem a;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			
			gems[i][j]=a.getGem();
			gems[i][j].setx(xArr[i]);
			gems[i][j].sety(yArr[j]);
			
		}
	}

}

Gem** GameBoard::getgem()
{
return gems;
}

int* GameBoard::getxArr()
{
return xArr;
}
int* GameBoard::getyArr()
{
return yArr;
}
	
void GameBoard::SwapProcess(int x1,int y1,int x2,int y2)
{


if( (x1+1==x2 || x1-1==x2) )
{ 
	if( y1==y2 )
	{	
		

	
			if ((gems[x1][y1].getx() < xArr[x2]) && (gems[x2][y2].getx() > xArr[x1]))
			{
			
			gems[x1][y1].setx(gems[x1][y1].getx()+5);
			gems[x2][y2].setx(gems[x2][y2].getx()-5);
				if(gems[x1][y1].getx()==xArr[x2] && gems[x2][y2].getx()==xArr[x1])
				{
				Gem temp=gems[x1][y1];
				gems[x1][y1]=gems[x2][y2];
				gems[x2][y2]=temp;
				swaps.setloc1(0,0);
				swaps.setloc2(0,0);
				}
			
			if(removePossible()==1)
			{
			checkremove();
			}
			glutPostRedisplay();
			}
			if ((gems[x1][y1].getx() > xArr[x2]) && (gems[x2][y2].getx() < xArr[x1]) )
			{
			
			gems[x1][y1].setx(gems[x1][y1].getx()-5);
			gems[x2][y2].setx(gems[x2][y2].getx()+5);
				if(gems[x1][y1].getx()==xArr[x2] && gems[x2][y2].getx()==xArr[x1])
				{
				Gem temp=gems[x1][y1];
				gems[x1][y1]=gems[x2][y2];
				gems[x2][y2]=temp;
				swaps.setloc1(0,0);
				swaps.setloc2(0,0);
				}
			
			if(removePossible()==1)
			{
			checkremove();
			}
			glutPostRedisplay();
			}

			
	
				
	}
}

if( (y1+1==y2 || y1-1==y2))
{
	if( x1==x2)
	{
					
			
			if ((gems[x1][y1].gety() < yArr[y2]) && (gems[x2][y2].gety() > yArr[y1]))
			{
			
			gems[x1][y1].sety(gems[x1][y1].gety()+5);
			gems[x2][y2].sety(gems[x2][y2].gety()-5);
				if(gems[x1][y1].gety()==yArr[y2] && gems[x2][y2].gety()==yArr[y1])
				{
				Gem temp=gems[x1][y1];
				gems[x1][y1]=gems[x2][y2];
				gems[x2][y2]=temp;
				swaps.setloc1(0,0);
				swaps.setloc2(0,0);;
				}
			if(removePossible()==1)
			{
			checkremove();
			}
			
			glutPostRedisplay();
			}
			if ((gems[x1][y1].gety() > yArr[y2]) && (gems[x2][y2].gety() < yArr[y1]))
			{
			
			gems[x1][y1].sety(gems[x1][y1].gety()-5);
			gems[x2][y2].sety(gems[x2][y2].gety()+5);
				if(gems[x1][y1].gety()==yArr[y2] && gems[x2][y2].gety()==yArr[y1])
				{
				Gem temp=gems[x1][y1];
				gems[x1][y1]=gems[x2][y2];
				gems[x2][y2]=temp;
				swaps.setloc1(0,0);
				swaps.setloc2(0,0);
				}
			if(removePossible()==1)
			{
			checkremove();
			}
			glutPostRedisplay();
			}

			
			
	}
	
}
	

}
void GameBoard::Swapcheck()
{
	int xtemp1=-1;
	int ytemp1=-1;
	int xtemp2=-1;
	int ytemp2=-1;
	
location temp1;
	temp1=swaps.getg1();
	location temp2;
	temp2=swaps.getg2();
	

	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			int x=xArr[i];
			int y=yArr[j];
			if(temp1.getx()<= (x+30)+29 && temp1.getx()>=(x+30)-29)
			{
			xtemp1=i;
			}
			if (temp1.gety()<=y+29 && temp1.gety()>=y-29)
			{
			ytemp1=j;
			}
		}
	}

	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			int x=xArr[i];
			int y=yArr[j];
			if(temp2.getx()<=(x+30)+29 && temp2.getx()>=(x+30)-29)
			{
			xtemp2=i;
			}
			if (temp2.gety()<=y+29 && temp2.gety()>=y-29)
			{
			ytemp2=j;
			}
		}
	}

		

	if(xtemp1!=(-1) && ytemp1!=(-1))
	{
	SwapProcess(xtemp1,ytemp1,xtemp2,ytemp2);
	}
	
	


}


void GameBoard::newappear()
{

	for(int i=0;i<8;i++)
		{
		if(gems[i][7].gettype()=="no")
		{
		Gem extra;
		gems[i][7]=extra.getGem();
		gems[i][7].setx(xArr[i]);
		gems[i][7].sety(yArr[7]);
		}
		}
		
	
}

void GameBoard::noMoveUp(int x1,int y1,int x2,int y2)
{
	if ((gems[x1][y1].gety() < yArr[y2]) && (gems[x2][y2].gety() > yArr[y1]))
			{
			
			gems[x1][y1].sety(gems[x1][y1].gety()+5);
			gems[x2][y2].sety(gems[x2][y2].gety()-5);
				if(gems[x1][y1].gety()==yArr[y2] && gems[x2][y2].gety()==yArr[y1])
				{
				Gem temp=gems[x1][y1];
				gems[x1][y1]=gems[x2][y2];
				gems[x2][y2]=temp;
				return;
				}
				if(gems[x1][y1].gety()!=yArr[y2] && gems[x2][y2].gety()!=yArr[y1])
				{
				noMoveUp(x1,y1,x1,y2);
				}
				
			}
	
}

bool GameBoard::removePossible()
{
	for(int i=0;i<8;i++)
	{
	for(int j=0;j<8;j++)
	{
	if(gems[i][j].gettype()=="no")
	{
	return false;
	}
	}
	}
return true;
}


void GameBoard::ifnoExist()
{
int noX=-1;
int noY=-1;
for(int i=0;i<8;i++)
{
	for(int j=0;j<8;j++)
	{
		if(j!=7)
		{
			if(gems[i][j].gettype()=="no" && gems[i][j+1].gettype() !="no")
			{
			noX=i;
			noY=j;
			SwapProcess(noX,noY,noX,noY+1);
			
			}
			

		}
	}
newappear();	
}


}
			


void GameBoard::inbetween()
{
if(getstop()==0)
{
for(int i=0;i<8;i++)
{
for(int j=0;j<8;j++)
{
gems[i][j].sety(yArr[j]);
gems[i][j].setx(xArr[i]);
}

}
setstop(1);
}
}

void GameBoard::checkremove()
{

int ibegin=-1;
int jbegin=-1;
int iend=-1;
int jend =-1;


 	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
		ibegin=j;
		jbegin=i;	
		iend=j;
		jend=i;
		
		int count1=0;
		int count2=0;
			if(gems[i][j].gettype()!="no")
			{
			int k=j+1;
			if(k<8)
			{
			for(k;k<8;k++)
			{
				if(gems[i][j].gettype() == gems[i][k].gettype())
				{
				iend++;
				count1++;
				}
				

				if ( gems[i][j].gettype() != gems[i][k].gettype() || iend>=7)
				{
				//cout<<iend<<endl;
				if(count1+1>=3)
				{	
					
					for(int a=ibegin;a<=iend;a++)
					{
					gems[i][a].settype("no");
					scr.increaseScr(count1+1);
					}
				}
				
				break;
				}	
			}
			}
			int m=i+1;
			if(m<8)
			{
			for(m;m<8;m++)
			{
				if(gems[i][j].gettype() == gems[m][j].gettype())
				{
				jend++;
				count2++;
				}

				if ( gems[i][j].gettype() != gems[m][j].gettype() || jend>=7)
				{
				if(count2+1>=3)
				{	
					
					for(int b=jbegin;b<=jend;b++)
					{
					gems[b][j].settype("no");
					scr.increaseScr(count2+1);
					}
				}
				break;
				}
			}
			}

			
			}
				
		}
	}
	

}




void GameBoard::checkHighScore(int l)
{
fstream new_file; 
char a;
new_file.open("highscores.txt",ios::out | ios::app | ios::in);  
if(!new_file) 
{

}
else
{
char **p=new char*[10];
for(int i=0;i<10;i++)
{
p[i]=new char[10];
}
int m=0;
int i=0;
while(!new_file.eof())
{
if(m==10)
{
break;
}
	for(i=0;i<10;i++)
	{
	new_file>>a;
	
	if(a!='\n')
	{
	p[m][i]=a;
	}
	else 
	{
	m++;
	i=0;	
	}
	}
	
}
char **ptr=new char*[10];
for(int i=0;i<10;i++)
{
ptr[i]=new char[10];
}

new_file.seekg(0);

for(int c=0;c<10;c++)
{	
	
	if(p[c][0]<l)
	{
		new_file>>l;
		
		i++;
		l=-1;
	}
	if(p[c][0]>l)
	{
		for(int j=0;ptr[c][j]!='\0';j++)
		{
		new_file>>ptr[c][j];
		}
		

	}
	
}
new_file.close(); 
}   
exit(0);
}


void GameBoard::MenuDisplay()
{
if(getchoice()==0)
{
glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	location option=getMenuLoc();
		
	if(option.getx()>300 && option.gety()>300)
	{
	DrawCircle(300,300,280,colors[MAROON]);	
	DrawSquare( 300 , 300 ,-300,colors[BLACK]);
	DrawSquare( 0 , 300 ,300,colors[BLACK]);	
	DrawSquare( 300 , 0 ,300,colors[BLACK]);
	}
	else if(option.getx()>300 && option.gety()<300)
	{
	DrawCircle(300,300,280,colors[MAROON]);	
	DrawSquare( 300 , 300 ,-300,colors[BLACK]);
	DrawSquare( 0 , 300 ,300,colors[BLACK]);	
	DrawSquare( 290 , 290 ,300,colors[BLACK]);
	}
	else if(option.getx()<300 && option.gety()>300)
	{
	DrawCircle(300,300,280,colors[MAROON]);	
	DrawSquare( 300 , 300 ,-300,colors[BLACK]);
	DrawSquare( 300 , 0 ,300,colors[BLACK]);
	DrawSquare( 290 , 290 ,300,colors[BLACK]);
	}
	else if(option.getx()<300 && option.gety()<300)
	{
	DrawCircle(300,300,280,colors[MAROON]);	
	DrawSquare( 0 , 300 ,300,colors[BLACK]);	
	DrawSquare( 300 , 0 ,300,colors[BLACK]);
	DrawSquare( 290 , 290 ,300,colors[BLACK]);
	}
	DrawRectangle(0, 300, 600, 10, colors[WHITE]); // ------ letter M ------
	DrawRectangle(300, 0, 10, 600, colors[WHITE]);
	DrawRectangle(100, 650, 10, 100, colors[WHITE]);
	DrawRectangle(100, 745, 100, 10, colors[WHITE]);
	DrawRectangle(150, 650, 10, 100, colors[WHITE]);
	DrawRectangle(195, 650, 10, 100, colors[WHITE]);

	DrawRectangle(230, 650, 10, 70, colors[WHITE]);	// -----letter i------
	DrawRectangle(230, 730, 10, 20, colors[WHITE]);	

	DrawRectangle(270, 650, 10, 70, colors[WHITE]); // ------letter n ----
	DrawRectangle(305, 650, 10, 70, colors[WHITE]);
	DrawRectangle(265, 715, 50, 10, colors[WHITE]);	

	DrawRectangle(340, 650, 10, 70, colors[WHITE]); // ------letter e ----
	DrawRectangle(340, 650, 50, 10, colors[WHITE]);	
	DrawRectangle(340, 715, 50, 10, colors[WHITE]);	
	DrawRectangle(340, 685, 50, 10, colors[WHITE]);	
	DrawRectangle(380, 685, 10, 35, colors[WHITE]);	
	
	DrawString(430,650, "By  Sher ALi", colors[WHITE]);
	DrawCircle(300,300,50,colors[WHITE]);	
	DrawCircle(300,300,25,colors[RED]);
	
	
	DrawString(400,400, "Start Game", colors[WHITE]);
	DrawString(100,400, "Exit", colors[WHITE]);
	DrawString(100,200, "High Score", colors[WHITE]);
	DrawString(400,200, "Player Profile", colors[WHITE]);
	
	glutSwapBuffers();
	
	
 // do not modify this lin
}
}

void GameBoard::PlayerDisplay()
{
glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	DrawRectangle(100, 650, 10, 100, colors[WHITE]);//-----letter M
	DrawRectangle(100, 745, 100, 10, colors[WHITE]);
	DrawRectangle(150, 650, 10, 100, colors[WHITE]);
	DrawRectangle(195, 650, 10, 100, colors[WHITE]);

	DrawRectangle(230, 650, 10, 70, colors[WHITE]);	// -----letter i------
	DrawRectangle(230, 730, 10, 20, colors[WHITE]);	

	DrawRectangle(270, 650, 10, 70, colors[WHITE]); // ------letter n ----
	DrawRectangle(305, 650, 10, 70, colors[WHITE]);
	DrawRectangle(265, 715, 50, 10, colors[WHITE]);	

	DrawRectangle(340, 650, 10, 70, colors[WHITE]); // ------letter e ----
	DrawRectangle(340, 650, 50, 10, colors[WHITE]);	
	DrawRectangle(340, 715, 50, 10, colors[WHITE]);	
	DrawRectangle(340, 685, 50, 10, colors[WHITE]);	
	DrawRectangle(380, 685, 10, 35, colors[WHITE]);	
	
	DrawString(200,250, "Name : "+Name.getfname() +" " +Name.getlname(), colors[WHITE]);

	DrawString(250,580,"Player Profile",colors[RED]);
	DrawRectangle(250, 570, 140, 5, colors[RED]);	
	
	DrawRectangle(190, 290, 220, 220, colors[GOLD]);
	DrawRectangle(200, 300, 200, 200, colors[SLATE_BM]);
	
	DrawString(430,650, "By  Sher ALi", colors[WHITE]);

	DrawRectangle(40, 30, 120, 52, colors[SLATE_BM]);
	DrawString(85,48,"BACK",colors[RED]);
	 DrawLine(80,30, 80, 80, 3, colors[RED]);
	DrawLine(80,30, 40, 55, 3, colors[RED]);
	DrawLine(40,55, 80, 80, 3, colors[RED]);
	glutSwapBuffers();
}

void GameBoard::display()
{
glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	DrawRectangle(0, 0, 600, 800, colors[RED]);	
	DrawRectangle(10, 0, 580, 780, colors[SALMON]);
	DrawRectangle(75,170,490,485,colors[GOLD]);
	DrawRectangle(80,175,480,475,colors[BLACK]);
	DrawRoundRect(0,-50,600,150,colors[RED],70);
	DrawRoundRect(0,-60,600,150,colors[GOLD],70);	
	DrawCircle(300,100,50,colors[RED]);	
	DrawCircle(300,100,40,colors[GOLD]);
	
	int DispSC=getscore()*10/(getlevel())*100/475;
	string ScrDisp=to_string(DispSC);
	DrawString(70,730, "Score: "+ScrDisp, colors[BLACK]);
	
	string timeDisp=to_string(gettime());
	DrawString(200,730, "time: "+timeDisp, colors[BLACK]);
	string levDisp=to_string(getlevel());
	DrawString(500,730, "Level: "+levDisp, colors[BLACK]);
	DrawRectangle(75, 690, 475, 30, colors[BLACK]);
	if( gettime()<=0)
	{
		int l=getlevel();
		Name.setlevel(l);
		//checkHighScore(l);
		setchoice(0);
		setGameStart(0);
			
	glutPostRedisplay();
		
	}

	if(DispSC*4.75>=475)
	{
	settime(gettime()+(getlevel()*(10/0.5)));
	setlevel(getlevel()+1);
	setscore(0);
	}
	DrawRectangle(75, 690, getscore()*10/getlevel(), 30, colors[YELLOW]);	
	DrawCircle(75,700,20,colors[RED]);
	DrawCircle(550,700,20,colors[RED]);
	DrawRectangle(75, 680, 475, 20, colors[RED]);	
	
	DrawRectangle(280, 70, 10, 60, colors[RED]);
	DrawRectangle(310, 70, 10, 60, colors[RED]);	
	
	DrawRectangle(500, 120, 60, 50, colors[SLATE_BM]);
	DrawString(510,130, "Hint", colors[BLACK]);
	
	Gem **tempgems=getgem();
		int *tempXarr=getxArr();
		int *tempYarr=getyArr();
		
	//ali.print();
	
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				string a;
				
				a=tempgems[i][j].gettype();
				if (a=="Rectangle")
				{
				DrawSquare( tempgems[i][j].getx() , tempgems[i][j].gety() ,40,colors[RED]);
				}
				else if (a=="Circle")
				{
				DrawCircle(tempgems[i][j].getx()+20,tempgems[i][j].gety()+20,20,colors[GOLD]);
				}
				else if(a=="Triangle")
				{
				DrawTriangle( tempgems[i][j].getx(), tempgems[i][j].gety() , tempgems[i][j].getx()+20, tempgems[i][j].gety()+40 , tempgems[i][j].getx()+40 , tempgems[i][j].gety(), colors[BLUE] );
				} 
				else if (a=="Kite")
				{
				DrawTriangle( tempgems[i][j].getx(), tempgems[i][j].gety()+20 , tempgems[i][j].getx()+20, tempgems[i][j].gety()+40 , tempgems[i][j].getx()+40 , tempgems[i][j].gety()+20, colors[GREEN] );
				DrawTriangle( tempgems[i][j].getx(), tempgems[i][j].gety()+20 , tempgems[i][j].getx()+20, tempgems[i][j].gety() , tempgems[i][j].getx()+40 , tempgems[i][j].gety()+20, colors[GREEN] );
				}	
				else if (a=="Diamond")
				{
				DrawTriangle( tempgems[i][j].getx(), tempgems[i][j].gety()+20 , tempgems[i][j].getx()+20, tempgems[i][j].gety() , tempgems[i][j].getx()+40 , tempgems[i][j].gety()+20, colors[PINK] );
				DrawTriangle( tempgems[i][j].getx(), tempgems[i][j].gety()+20 , tempgems[i][j].getx()+10, tempgems[i][j].gety()+40 , tempgems[i][j].getx()+10 , tempgems[i][j].gety()+20, colors[PINK] );
				DrawTriangle( tempgems[i][j].getx()+30, tempgems[i][j].gety()+20 , tempgems[i][j].getx()+30, tempgems[i][j].gety()+40 , tempgems[i][j].getx()+40 , tempgems[i][j].gety()+20, colors[PINK] );
				DrawSquare( tempgems[i][j].getx()+10 , tempgems[i][j].gety()+20 ,22,colors[PINK]);
				}
				else if(a=="no")
				{
			
				}
				else if(a=="Donut")
				{
				DrawCircle(tempgems[i][j].getx()+20,tempgems[i][j].gety()+20,20,colors[AQUA]);
				DrawCircle(tempgems[i][j].getx()+20,tempgems[i][j].gety()+20,10,colors[BLACK]);
				}
				else if(a=="ali")
				{
				DrawSquare( tempgems[i][j].getx() , tempgems[i][j].gety() ,40,colors[VIOLET]);
				DrawSquare( tempgems[i][j].getx()+10 , tempgems[i][j].gety()+10 ,20,colors[BLACK]);
				}
			}
		}
	 	
}

void GameBoard::gameSelect()
{
glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
glClear (GL_COLOR_BUFFER_BIT); //Update the colors

DrawRectangle(0, 0, 600, 800, colors[RED]);	
DrawRectangle(10, 10, 580, 780, colors[SALMON]);

DrawRectangle(190, 490, 240, 120, colors[GOLD]);
DrawRectangle(200, 500, 220, 100, colors[BLACK]);
DrawString(270,545, "Normal", colors[WHITE]);
DrawRectangle(190, 290, 240, 120, colors[GOLD]);
DrawRectangle(200, 300, 220, 100, colors[BLACK]);
DrawString(270,345, "Endless", colors[WHITE]);

DrawRectangle(40, 30, 120, 52, colors[SLATE_BM]);
DrawString(85,48,"BACK",colors[RED]);
 DrawLine(80,30, 80, 80, 3, colors[RED]);
DrawLine(80,30, 40, 55, 3, colors[RED]);
DrawLine(40,55, 80, 80, 3, colors[RED]);

glutSwapBuffers();
}


void GameBoard::Pause()
{
glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
glClear (GL_COLOR_BUFFER_BIT); //Update the colors

DrawRectangle(0, 0, 600, 800, colors[RED]);	
DrawRectangle(10, 10, 580, 780, colors[SALMON]);

DrawRectangle(190, 490, 240, 120, colors[GOLD]);
DrawRectangle(200, 500, 220, 100, colors[BLACK]);
DrawString(270,545, "Resume", colors[WHITE]);
DrawRectangle(190, 290, 240, 120, colors[GOLD]);
DrawRectangle(200, 300, 220, 100, colors[BLACK]);
DrawString(270,345, "Exit", colors[WHITE]);

glutSwapBuffers();
}

void GameBoard::hint()
{
display();


for(int i=0;i<8;i++)
{
for(int j=0;j<8;j++)
{
	if( i+1!=8 && i+2!=8 && j+1!=8 && j+2!=8 && i-1!=-1 && i-2!=-1 && j-1!=-1 && j-2!=-1 && j-3!=-1 && j+3!=8 && i+3!=8 && i-3!=-1)
	{
	if( (gems[i][j].gettype()==gems[i+1][j+1].gettype()) && (gems[i][j].gettype()==gems[i+2][j+1].gettype()) || 
	(gems[i][j].gettype()==gems[i-1][j+1].gettype()) && (gems[i][j].gettype()==gems[i+1][j+1].gettype()) || 
	(gems[i][j].gettype()==gems[i-1][j+1].gettype()) && (gems[i][j].gettype()==gems[i-2][j+1].gettype()) ||   //  up 
 	(gems[i][j].gettype()==gems[i][j+2].gettype()) && (gems[i][j].gettype()==gems[i][j+3].gettype()))
	{
	DrawRectangle(gems[i][j].getx()+12, gems[i][j].gety()+12,  10, (gems[i][j+1].gety()-gems[i][j].gety()), colors[WHITE]);
	 DrawLine(gems[i][j].getx(),gems[i][j].gety()+60,gems[i][j].getx()+30, gems[i][j].gety()+60, 3, colors[WHITE]);
	DrawLine(gems[i][j].getx(),gems[i][j].gety()+60, gems[i][j].getx()+15, gems[i][j].gety()+90, 3, colors[WHITE]);
	DrawLine(gems[i][j].getx()+30,gems[i][j].gety()+60, gems[i][j].getx()+15, gems[i][j].gety()+90, 3, colors[WHITE]);
	
	break;
	}
	
	if( (gems[i][j].gettype()==gems[i+1][j-1].gettype()) && (gems[i][j].gettype()==gems[i+2][j-1].gettype()) ||
	(gems[i][j].gettype()==gems[i-1][j-1].gettype()) && (gems[i][j].gettype()==gems[i-2][j-1].gettype()) || 
	(gems[i][j].gettype()==gems[i-1][j-1].gettype()) && (gems[i][j].gettype()==gems[i+1][j-1].gettype()) ||
 	(gems[i][j].gettype()==gems[i][j-2].gettype()) && (gems[i][j].gettype()==gems[i][j-3].gettype()))// 	down
	{
	DrawRectangle(gems[i][j].getx()+12, gems[i][j].gety()+42,  10, (gems[i][j].gety()-gems[i][j+1].gety())-12, colors[WHITE]);
	DrawLine(gems[i][j-1].getx(),gems[i][j-1].gety()+30,gems[i][j-1].getx()+30, gems[i][j-1].gety()+30, 3, colors[WHITE]);
	DrawLine(gems[i][j-1].getx(),gems[i][j-1].gety()+30, gems[i][j-1].getx()+15, gems[i][j-1].gety(), 3, colors[WHITE]);
	DrawLine(gems[i][j-1].getx()+15,gems[i][j-1].gety(), gems[i][j-1].getx()+30, gems[i][j-1].gety()+30, 3, colors[WHITE]);
	break;
	}
	
	if( (gems[i][j].gettype()==gems[i+1][j+1].gettype() && gems[i][j].gettype()==gems[i+1][j-1].gettype()) ||
	(gems[i][j].gettype()==gems[i+1][j+1].gettype() && gems[i][j].gettype()==gems[i+1][j+2].gettype()) ||
	(gems[i][j].gettype()==gems[i+1][j-1].gettype() && gems[i][j].gettype()==gems[i+1][j-2].gettype())  || 	//   right
	(gems[i][j].gettype()==gems[i+2][j].gettype() && gems[i][j].gettype()==gems[i+3][j].gettype()))
	{
	DrawRectangle(gems[i][j].getx()+12, gems[i][j].gety()+15,  50, 10, colors[WHITE]);
	DrawLine(gems[i][j].getx()+62,gems[i][j].gety()+5,gems[i][j].getx()+62, gems[i][j].gety()+35, 3, colors[WHITE]);
	DrawLine(gems[i][j].getx()+62,gems[i][j].gety()+5,gems[i][j].getx()+77, gems[i][j].gety()+20, 3, colors[WHITE]);
	DrawLine(gems[i][j].getx()+62,gems[i][j].gety()+35,gems[i][j].getx()+77, gems[i][j].gety()+20, 3, colors[WHITE]);
	break;
	}
	if( (gems[i][j].gettype()==gems[i-1][j+1].gettype() && gems[i][j].gettype()==gems[i-1][j-1].gettype()) ||
	(gems[i][j].gettype()==gems[i-1][j+1].gettype() && gems[i][j].gettype()==gems[i-1][j+2].gettype()) ||
	(gems[i][j].gettype()==gems[i-1][j-1].gettype() && gems[i][j].gettype()==gems[i-1][j-2].gettype())  ||   // left
	(gems[i][j].gettype()==gems[i-2][j].gettype() && gems[i][j].gettype()==gems[i-3][j].gettype()))
	{
	DrawRectangle(gems[i-1][j].getx()+12, gems[i][j].gety()+15,  50, 10, colors[WHITE]);
	DrawLine(gems[i-1][j].getx()+62,gems[i-1][j].gety()+5,gems[i-1][j].getx()+62, gems[i-1][j].gety()+35, 3, colors[WHITE]);
	DrawLine(gems[i-1][j].getx()+62,gems[i-1][j].gety()+5,gems[i-1][j].getx()+77, gems[i-1][j].gety()+20, 3, colors[WHITE]);
	DrawLine(gems[i-1][j].getx()+62,gems[i-1][j].gety()+35,gems[i-1][j].getx()+77, gems[i-1][j].gety()+20, 3, colors[WHITE]);
	break;
	}
	}

}
}
} 

void GameBoard::levelDisplay()
{
glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
glClear (GL_COLOR_BUFFER_BIT); //Update the colors

DrawRectangle(0, 0, 600, 800, colors[RED]);	
DrawRectangle(10, 10, 580, 780, colors[SALMON]);

ifstream a1;
a1.open("levels.txt",ios::binary);
char a;
int num=0;
while(!a1.eof() )
{
cin.get(a);
num++;
cout<<a<<" num "<<num<<endl;
}
string n1,n2,n3,n4,n5;
n1=to_string(num);
DrawString(270,345, " "+n1, colors[WHITE]);
glutSwapBuffers();
}


