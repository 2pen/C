#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h> 
void gotoxy(int x, int y);
void edge(int x,int y);
void start(int x,int y);
void star(int x,int y);
int main()
{
	char input,in;
	int h=-1;
	int x=20;
	int y=20;
	int i,j,k;
	int a,b,c,d;
	srand(time(NULL));
	a=rand()%(x-1)+1;
	b=rand()%(y-1)+1;
	c=rand()%(x-1)+1;
	d=rand()%(y-1)+1;
	int z=0;
	int f=0;
	int e[2][1000];
	e[0][0]=a;
	e[1][0]=b;
	while(1)
	{	//system("cls");
	//	gotoxy(0,0);
		edge(x,y);
		gotoxy(0,0);
		star(c,d);
		gotoxy(0,0);
		start(e[0][z],e[1][z]);
		for(int r=1;r<=f;r++)
		{
		gotoxy(0,0);
		star(e[0][z-r],e[1][z-r]);
		//gotoxy(0,0);
		}
		if((e[0][z]==x-1||e[0][z]==0)||(e[1][z]==0||e[1][z]==y))
			break;
		i=1;
		z++;
		if(h<0)
		{
		in=getch();
		if(in=='a')
			h=1;
		if(in=='d')
			h=2;
		if(in=='w')
			h=3;
		if(in=='s')
			h=4;
		}
		Sleep(100);
		if(kbhit())
		{
		
			input=getch();
			if(input=='a')
			{
				if(h!=2)
				{
				e[0][z]=a;
				e[1][z]=--b;
				h=1;i=0;
				}
			} 
			if(input=='d')
			{
				if(h!=1)
				{
				e[0][z]=a;
				e[1][z]=++b;
				h=2;i=0;
				}
			} 
			if(input=='w')
			{
				if(h!=4)
				{
				e[0][z]=--a;
				e[1][z]=b;
				h=3;i=0;
				}
			} 
			if(input=='s')
			{
				if(h!=3)
				{
				e[0][z]=++a;
				e[1][z]=b;
				h=4;i=0;
				}
			}
		}
		if(i)
		{
			if(h==1)
			{
				e[0][z]=a;
				e[1][z]=--b;
			}
			if(h==2)
			{
				e[0][z]=a;
				e[1][z]=++b;
			}
			if(h==3)
			{
				e[0][z]=--a;
				e[1][z]=b;	
			}
			if(h==4)
			{
				e[0][z]=++a;
				e[1][z]=b;
			}
				
		}
	
	if(e[0][z]==c&&e[1][z]==d)
	{
		f++;
		c=rand()%(x-1)+1;
		d=rand()%(y-1)+1;	
	}
//	star(c,d);
//	printf("%d  %d %d",e[0][z],a,z);
//	getch();
//	start(e[0][z],e[1][z]);
//	getchar();
	gotoxy(0,0);
/*	for(int r=1;r<=f;r++)
	{
		gotoxy(0,0);
		star(e[0][z-r],e[1][z-r]);
		gotoxy(0,0);
	}*/
	}
	gotoxy(0,0);
	printf("\ngame over!\n");
	return 0; 
} 
void gotoxy(int x,int y)    
{
    COORD coord;
    coord.X=x;
    coord.Y=y; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void start(int x,int y)
{
	int i,j;
	for(i=0;i<x;i++)
		printf("\n");
	for(j=0;j<y;j++)
		printf(" ");
	printf("@");
}
void star(int x,int y)
{
	int i,j;
	for(i=0;i<x;i++)
		printf("\n");
	for(j=0;j<y;j++)
		printf(" ");
	printf("*");
}
void edge(int x,int y)
{
	int i,j;
	for(i=0;i<y;i++)
	{	
		if(i==0||i==(y-1))
		for(j=0;j<x;j++)
		{
			printf("#");
		}
		else
		for(j=0;j<x;j++)
		{
			printf(" "); 
		} 
		printf("#\n");
	}
	
}

