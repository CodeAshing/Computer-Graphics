#include<stdlib.h>
#include<dos.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void main()
{

	int i=250,j=250,x=0,y=-1,ch,gd=DETECT, gm;
	initgraph(&gd,&gm, "C:\\TURBOC3\\BGI");
	int color = (rand() % (12 - 2 + 1)) + 2;
	while(1)   //infinite loop
	{
		setfillstyle(SOLID_FILL, color);
		circle(i, j, 30);
		floodfill(i, j, color);
		setcolor(color);

		outtextxy(400,400,"Press Esc to Exit...");
		if(kbhit())  //check if a key is pressed
		{
			ch=getch();
			if(ch==72) //move upward
			{
				x=0;
				y=-1;
			}

			if(ch==75) //move left
			{
				x=-1;
				y=0;

			}

			if(ch==77) //move right
			{
				x=1;
				y=0;
			}

			if(ch==80) //move downward
			{
				x=0;
				y=1;
			}

			if(ch==27) //exit when esc pressed
			{
				exit(0);
			}

		}
		
		if( (j >= getmaxy()-30 && y==1) || (j < 30 && y==-1) ) // check upper and lower boders
		{
			color = (rand() % (12 - 2 + 1)) + 2;
			y=0;
		}

		if( (i >= getmaxx()-30 && x==1) || (i < 30 && x==-1) ) // check left and right boders
		{
			color = (rand() % (12 - 2 + 1)) + 2;
			x=0;
		}

		i=i+x;
		j=j+y;

		delay(5);
		cleardevice();
	}
}