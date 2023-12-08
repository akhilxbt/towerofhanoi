#include<stdio.h>  //standard input/output
#include<conio.h>   //console input/output
#include<graphics.h> //graphics library
#include<stdlib.h>   //standard library
#include<dos.h>     //for delay  function

#define MAX	10 //max disks for tower
#define BegPos   105    //position of beg tower
#define AuxPos   305    //position for aux tower
#define EndPos   505    //position for end tower

int width;           //declareing disk structure and functions
typedef struct disc
{
 char val1[MAX];
 char top,pos;
};
void push(disc *tt,int x);
pop(disc *tt);
void tower(int,disc *,disc *,disc *);
void draw_stack(disc *beg,disc *,disc *);
void start();
void algo();
void thank();
void main()
{
int gd=DETECT,gm,choice;        // initialize graphics
initgraph(&gd,&gm,"C://TURBOC3//BGI");
int i,x=2;
disc beg,end,aux;
start();
getch();
setbkcolor(DARKGRAY);
while(1)  //menu page
{
	cleardevice();
	setbkcolor(LIGHTGRAY);
	rectangle(2,2,636,474);
	rectangle(6,6,632,470);
	settextstyle(1,0,4);
	setcolor(BROWN);
	outtextxy(130,30," * * *   MENU   * * * ");
	outtextxy(130,170,"1.ALGORITHM");
	outtextxy(130,220,"2.OPEN TOWER OF HANOI");
	outtextxy(130,270,"3.EXIT");
	outtextxy(50,420," *   *   *   *   *   *   *   *   *");

	gotoxy(20,8);
	scanf("%d",&choice);
switch(choice)   //3 choices in menu
{

	case 1: cleardevice();
		      algo();
		      break;
	case 2:      settextstyle(1,0,3);
	 outtextxy(80,330,"NOW,DISKS TO BE ENTERED (max 10):- ");
    scanf("%d",&x);
    if (x<11)
    {
	width=50/x;
    beg.top=end.top=aux.top=0;
	beg.pos=1;end.pos=3;aux.pos=2;

    for(i=0;i<x;i++)
		push(&beg,(x-i)+1);
		draw_stack(&beg,&end,&aux);
		tower(x,&beg,&end,&aux);
		}
		else {
		setcolor(RED);
	outtextxy(80,360,"ENTER DISKS FROM 1-10!! SELECT AGAIN...");
	delay(2000);
		}
		break;
	case 3:       cleardevice();
		      thank();
		      getch();
		      exit(0);

	default:
       settextstyle(8,0,1);
	setcolor(RED);
	outtextxy(120,360,"WRONG INPUT !! PROGRAM EXIT...");
				delay(2000);
				exit(0);
				}}}
void start()  //welcome page
{
	setbkcolor(BLACK);
	settextstyle(4,0,8);
	setcolor(GREEN);
	outtextxy(30,20,"~~ Welcome ~~");
	settextstyle(4,0,14);
	outtextxy(30,150,"*");
	outtextxy(550,150,"*");
	settextstyle(1,0,4);
	setcolor(YELLOW);
	rectangle(2,2,636,474);
	rectangle(6,6,632,470);
	line(3,150,636,150);
	line(3,350,636,350);
	outtextxy(180,150,"  MINI-PROJECT ");
	outtextxy(210,200,"--  ON  --");
	outtextxy(180,250,"'TOWER OF HANOI'");
	outtextxy(100,300,"GRAPHICAL REPRESENTATION");
	settextstyle(8,0,1);
	setcolor(12);
	outtextxy(18,380,"By: AKHIL DOGRA
	");
	outtextxy(18,420,"    M.Sc-IT (1 sem)");
	outtextxy(300,380," Submitted to:Prof. Varun Jain");
	outtextxy(300,420," SCD College,Ludhiana");
	}
void algo()  //algorithm  page
{       cleardevice();
	setbkcolor(BLACK);
	rectangle(2,2,636,474);
	rectangle(6,6,632,470);
	settextstyle(7,0,6);
	setcolor(GREEN);
	outtextxy(60,30," # ALGORITHM ~");
	settextstyle(6,0,2);
	setcolor(YELLOW);
	outtextxy(50,100,"  TowerOfHanoi(N,A,B,C) //N is the no. of disks");
	outtextxy(50,140,"//Move the top n disks from tower A to tower B");
	outtextxy(50,180,"  {   if(N>1) then ");
	outtextxy(50,220,"  {  TowerOfHanoi(N-1,A,C,B);");
	outtextxy(50,260," write(\"move top disk from tower \",A \"to top of tower\",B);");
	outtextxy(50,300,"  TowerOfHanoi(N-1,C,B,A);  ");
	outtextxy(50,340,"  } }");
	delay (500);
	setcolor(GREEN);
	outtextxy(40,410,"Press any key to go back...");
	getch();
	main();
	}
void thank() //last page
{
	setbkcolor(BLACK);
	rectangle(2,2,636,474);
	rectangle(6,6,632,470);

	settextstyle(4,0,7);
	setcolor(RED);
	outtextxy(40,50,"~  ~  ~  ~  ~  ~ ");
	outtextxy(40,350,"~  ~  ~  ~  ~  ~ ");
       setcolor(GREEN);
	outtextxy(100,200," Thank You !! ");
       line(120,290,440,290);
       line(120,300,440,300);
       circle(110,295,10);
       circle(450,295,10);

	}

void tower(int n,disc *beg,disc *aux,disc *end) //alogrithm  of toh
{
	if(n>0)
{
    tower(n-1,beg,end,aux);
	push(end,pop(beg));
	draw_stack(beg,end,aux);
	tower(n-1,aux,beg,end);
	getch();
	}}
void push(disc *tt,int x)//inserting disk
{
	tt->val1[tt->top]=x;
	tt->top++;
}
pop(disc *tt)//removing disk
{
	int a;
	tt->top--;
	a=tt->val1[tt->top];
	tt->val1[tt->top]=0;
	return a;
}
void draw_stack(disc *beg,disc *end,disc *aux) //stack structure for n disks
{   delay(10);
	int ypos=295,i,height=10,xpos;
	int ver=0;
	cleardevice();
	setfillstyle(1,2);
	bar(20,300,580,310);
	bar(100,100,110,300);
	bar(300,100,310,300);
	bar(500,100,510,300);
	rectangle(20,300,580,310);
	rectangle(100,100,110,300);
	rectangle(300,100,310,300);
	rectangle(500,100,510,300);
/* END TOWER*/
	ypos=295;
	if(end->pos==1)
	xpos=BegPos;
	else if(end->pos==2)
	xpos=AuxPos;
	else if(end->pos==3)
	xpos=EndPos;
	for(i=0;i<end->top;i++)
	{
	setfillstyle(end->val1[i],end->val1[i]);
	bar(xpos-(end->val1[i]*width),ypos,xpos+(end->val1[i]*width),ypos-height);
	rectangle(xpos-(end->val1[i]*width),ypos,xpos+(end->val1[i]*width),ypos-height);
	ypos-=(height+2);
	}
	ver=end->pos;
/* BEG TOWER*/
	if(beg->pos==1)
	xpos=BegPos;
	else if(beg->pos==2)
	xpos=AuxPos;
	else if(beg->pos==3)
	xpos=EndPos;
	ypos=295;
	for(i=0;i<beg->top;i++)
	{
	setfillstyle(beg->val1[i],beg->val1[i]);
	bar(xpos-(beg->val1[i]*width),ypos,xpos+(beg->val1[i]*width),ypos-height);
	rectangle(xpos-(beg->val1[i]*width),ypos,xpos+(beg->val1[i]*width),ypos-height);
	ypos-=(height+2);
	}
/* AUX TOWER*/
	ver=ver*10+beg->pos;
if(ver<20)
	{
	  if(ver%10==2)
	  xpos=EndPos;
	  else
	  xpos=AuxPos;
	   }
	   else if(ver<30)
	   {
if(ver%10==1)
	xpos=EndPos;
	else
	xpos=BegPos;
	}
	else if(ver<40)
	{
if(ver%10==1)
	xpos=AuxPos;
	else
	xpos=BegPos;
	}
	ypos=295;
	for(i=0;i<aux->top;i++)
	{
	setfillstyle(aux->val1[i],aux->val1[i]);
	bar(xpos-(aux->val1[i]*width),ypos,xpos+(aux->val1[i]*width),ypos-height);
	rectangle(xpos-(aux->val1[i]*width),ypos,xpos+(aux->val1[i]*width),ypos-height);
	ypos-=(height+2);
	}
void   *buffer; //text and progress bar under tower of hanoi
unsigned int size;
setbkcolor(BLACK);
   line(230,330,370,330);
   line(230,350,370,350);
   line(226,335,226,345);
   line(226,335,230,330);
   line(226,345,230,350);
   line(374,335,374,345);
   line(374,335,370,330);
   line(374,345,370,350);
   rectangle(2,2,636,474);
   rectangle(6,6,632,470);
  settextstyle(1,0,4);  //text output on tower page
  outtextxy(100,50,"A");
  outtextxy(300,50,"B");
  outtextxy(500,50,"C");
  outtextxy(90,370,"Moving disks from A to B");
int x=232,y=336,x1=236,y1=344;
 for(int a=1;a<5;a++)
 {
  setfillstyle(1,WHITE);
  bar(x,y,x1,y1);
  x=x1+2;
  x1=x1+6;
   }
  size=imagesize(232,336,256,344);
  buffer=malloc(size);
  getimage(232,336,256,344,buffer);
  x=232;
  int m=0;
  while(!kbhit())
  {
 putimage(x,336,buffer,XOR_PUT);
 x=x+2;
 if(x>=350)
 {
  m++;
  x=232;
  if(m==5)                         // m is no of times bar moves
  return;
}
putimage(x,336,buffer,XOR_PUT);
delay(15);		      // speed of moving bar
}getch();
}

