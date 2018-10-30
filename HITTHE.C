#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>

void glow_obj(int ,int );
void glow_obj1(int ,int );
void set(int *,double *,int *,int *,int );
void main()
{
	int i, gd, gm, j;
	int b,row, column;  //mouse
	union REGS inreg, outreg;
	int miss=0,life=5,score=0,save=-1; //object will be visible depending on interval
	char miss_n[10], life_n[10];
	double count=1000000/2,interval=1000000/2;
	gd= DETECT;
	initgraph(&gd, &gm, "C:\\Turboc3\\bgi");

	rectangle(10, 10, 620, 455); //1st rectangle
	rectangle(70, 70, 560, 395); //2nd rectangle
	setcolor(6);
	rectangle(74, 74, 556, 391); //3rd rectangle
	rectangle(75, 75, 555, 390); //4th rectangle
	setcolor(15);
	line(10, 10, 70, 70);
	line(620, 455, 560, 395);
	line(620, 10, 560, 70);      //up corner
	line(10, 455, 70, 395);      //low corner
	setfillstyle(1, 8);
	floodfill(11, 250, 15);
	floodfill(619, 400, 15);

	setfillstyle(1, 3);
	circle(150, 150, 20);
	floodfill(150, 150, 15);

	setfillstyle(1, 15);
	circle(250, 150, 20);
	floodfill(250, 150, 15);

	setfillstyle(1, 3);
	circle(380, 150, 20);
	floodfill(380, 150, 15);

	setfillstyle(1, 15);
	circle(480, 150, 20);
	floodfill(480, 150, 15);

	setfillstyle(1, 3);
	circle(150, 300, 20);
	floodfill(150, 300, 15);

	setfillstyle(1, 15);
	circle(250, 300, 20);
	floodfill(250, 300, 15);

	setfillstyle(1, 3);
	circle(380, 300, 20);
	floodfill(380, 300, 15);

	setfillstyle(1, 15);
	circle(480, 300, 20);
	floodfill(480, 300, 15);

       //	settextstyle(int font, int direction, int charsize);
       while(!kbhit())
       {
	setcolor(12);
	settextstyle(TRIPLEX_FONT, 0, 4);
	outtextxy(145, 400, "H I T  T H E  D O T S");
	setcolor(4);
	delay(5);
	settextstyle(TRIPLEX_FONT, 0, 4);
	outtextxy(145, 400, "H I T  T H E  D O T S");
	setcolor(6);
	delay(5);
	settextstyle(TRIPLEX_FONT, 0, 4);
	outtextxy(145, 400, "H I T  T H E  D O T S");
	setcolor(12);
	delay(5);




	setcolor(15);
	settextstyle(TRIPLEX_FONT, 0, 3);
	outtextxy(210, 20, "HIGHSCORE : 9999");
	setcolor(2);
	delay(5);
	settextstyle(TRIPLEX_FONT, 0, 3);
	outtextxy(210, 20, "HIGHSCORE : 9999");
	setcolor(3);
	delay(5);
	settextstyle(TRIPLEX_FONT, 0, 3);
	outtextxy(210, 20, "HIGHSCORE : 9999");
	setcolor(15);
	delay(5);
	settextstyle(TRIPLEX_FONT, 0, 2);
	outtextxy(195, 350, "Press enter to continue");
	}
	getch();

       setfillstyle(1,0);
       floodfill(1,1,1);

	settextstyle(DEFAULT_FONT, 0, 1);

	outtextxy(240, 238, "Loading . . .");
	rectangle(240, 250, 380, 260);
	for(i= 242, j=252; i<379; i++)
	{
		line(i, j, i, j+6);
		delay(15);
	}
	getch();
	while(!kbhit())
	{
		outtextxy(221, 270, "Press enter to continue");

	}
	getch();
	setfillstyle(1,0);
	floodfill(1,1,1);
	inreg.x.ax=0;
	int86(0x33,&inreg,&outreg);


	circle(150, 150, 20);


	circle(250, 150, 20);


	circle(380, 150, 20);


	circle(480, 150, 20);


	circle(150, 300, 20);


	circle(250, 300, 20);


	circle(380, 300, 20);



	circle(480, 300, 20);
	inreg.x.ax=1;
	int86(0x33,&inreg,&outreg);
	inreg.x.ax=3;
	int86(0x33,&inreg,&outreg);
	while(!kbhit() && miss<=life)
	{
	    if (count >= interval)
	    {
		      switch (save) //selects the object which was glowing and stops
		      {
		      case -1:
			break;
		      case 0:
			glow_obj1(150,150);
			break;
		      case 1:
			glow_obj1(250,150);
			break;
		      case 2:
			glow_obj1(380,150);
			break;
		      case 3:
			glow_obj1(480,150);
			break;
		      case 4:
			glow_obj1(150,300);
			break;
		      case 5:
			glow_obj1(250,300);
			break;
		      case 6:
			glow_obj1(380,300);
			break;
		      case 7:
			glow_obj1(480,300);
			break;
		    }
		    ++miss;
		    randomize();
		    i=rand()%8;
		    save=i;
		    count=0;
		    switch (i)   //chooses index for object selection
		    {
		      case 0:
			glow_obj(150,150);
			break;
		      case 1:
			glow_obj(250,150);
			break;
		      case 2:
			glow_obj(380,150);
			break;
		      case 3:
			glow_obj(480,150);
			break;
		      case 4:
			glow_obj(150,300);
			break;
		      case 5:
			glow_obj(250,300);
			break;
		      case 6:
			glow_obj(380,300);
			break;
		      case 7:
			glow_obj(480,300);
			break;
		     }
	    }
	    /* Do any sort of decorations here, like developer(our)'s name...
	       Any thing done here will be keep on going untill the end..
	       Do print miss and lives left.... Using outtextxy...	*/

	sprintf(life_n,"%d",(life-miss));
	outtextxy(60, 70, "LIFE");
	setcolor(11);
	rectangle(50,80, 100,120);
		 //everytime while printing it must repaint
      /*	setcolor(0);
	outtextxy(75, 100,life_n);
	setcolor(11);  */
	outtextxy(75, 100,life_n); // erase previous, write new... otherwise
       /*	setcolor(0);
	outtextxy(75, 100,life_n);
	setcolor(11); */

			   // same for below code for score

	 sprintf(miss_n,"%d",score);
	outtextxy(60, 190, "SCORE");
	setcolor(11);
	rectangle(50,200, 100,240);
	outtextxy(75, 215,miss_n);




	    count=count+(interval/5000);
	    inreg.x.ax=1;
	    int86(0x33,&inreg,&outreg);
	    inreg.x.ax=3;
	    int86(0x33,&inreg,&outreg);
	    b=outreg.x.bx;
	    row=outreg.x.dx;
	    column=outreg.x.cx;
	    if (b==1)//checks if mouse is clicked
	    {
		   setfillstyle(1, 0);
		   floodfill(60, 110, 15);
		   floodfill(60, 210, 15);

		   switch (i)
		   {
		      case 0:
			   if((row>130 && row <170) &&  (column>130 && column<170))
				set(&score,&interval,&save,&miss,i);
			   break;
		      case 1:
			if((row>130 && row <170) &&  (column>230 && column<270))
				set(&score,&interval,&save,&miss,i);
			break;
		      case 2:
			if((row>130 && row <170) &&  (column>360 && column<400))
				set(&score,&interval,&save,&miss,i);
			break;
		      case 3:
			if((row>130 && row <170) &&  (column>460 && column<500))
			      set(&score,&interval,&save,&miss,i);
			break;
		      case 4:
			 if((row>280 && row <320) &&  (column>130 && column<170))
			      set(&score,&interval,&save,&miss,i);
			 break;
		      case 5:
		      if((row>280 && row <320) &&  (column>230 && column<270))
			      set(&score,&interval,&save,&miss,i);
			 break;
		      case 6:
		      if((row>280 && row <320) &&  (column>360 && column<400))
			      set(&score,&interval,&save,&miss,i);
			 break;
		      case 7:
		      if((row>280 && row <320) &&  (column>460 && column<500))
			      set(&score,&interval,&save,&miss,i);
			 break;
		   }

	    count=interval;
	    delay(500);
	    }
	    else
		   {
			setcolor(0);
	outtextxy(75, 100,life_n);
	setcolor(11);
		   }
	}
	setfillstyle(1,0);
	floodfill(1,1,1);
	/* void far settextstyle(int font, int direction, int charsize);*/
	while(!kbhit())
	{

	setcolor(1);
	settextstyle(TRIPLEX_FONT,0,2);
	outtextxy(250,150,"Opppsss!");
	setcolor(13);
	settextstyle(TRIPLEX_FONT,0,2);
	outtextxy(250,150,"Opppsss!");
	setcolor(10);
	settextstyle(TRIPLEX_FONT,0,2);
	outtextxy(250,150,"Opppsss!");

	setcolor(12);
	settextstyle(DEFAULT_FONT,0,1);
	outtextxy(150,200,"You are out of life. Good luck next time.");
	setcolor(15);
	outtextxy(400,400,"Press Enter to exit.");
	setcolor(1);
	}

	getch();

}

void set(int *score,double *interval,int *save,int *miss,int i)
{
   (*score)++;
   (*interval)=(*interval)-1000;
   (*save)=i;
   (*miss)--;
}

void glow_obj(int x,int y)
{
	union REGS inreg, outreg;
	inreg.x.ax=2;
	int86(0x33,&inreg,&outreg);
	setfillstyle(1,3);
	floodfill(x,y,15);
	inreg.x.ax=3;
	int86(0x33,&inreg,&outreg);
}
void glow_obj1(int x,int y)
{
	union REGS inreg, outreg;
	inreg.x.ax=2;
	int86(0x33,&inreg,&outreg);
	setfillstyle(1,0);
	floodfill(x,y,15);
	inreg.x.ax=3;
	int86(0x33,&inreg,&outreg);
}