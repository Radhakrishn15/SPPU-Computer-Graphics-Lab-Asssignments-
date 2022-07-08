#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include<iostream>
using namespace std;

   void EightWaySymmetricPlot(int xc,int yc,int x,int y)
   {
    putpixel(x+xc,y+yc,RED);
    putpixel(x+xc,-y+yc,YELLOW);
    putpixel(-x+xc,-y+yc,GREEN);
    putpixel(-x+xc,y+yc,YELLOW);
    putpixel(y+xc,x+yc,12);
    putpixel(y+xc,-x+yc,14);
    putpixel(-y+xc,-x+yc,15);
    putpixel(-y+xc,x+yc,6);
   }

    void BresenhamCircle(int xc,int yc,int r)
   {
    int x=0,y=r,d=3-(2*r);
    EightWaySymmetricPlot(xc,yc,x,y);

    while(x<=y)
     {
      if(d<=0)
      {
        d=d+(4*x)+6;
      }
      else
      {
        d=d+4*(x-y)+10;
        y=y-1;
      }
       x=x+1;
       EightWaySymmetricPlot(xc,yc,x,y);
      }
    }

int main()
{
    int xc , yc, r ;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    cout<<"Enter the values of xc and yc :";
    cin>>xc>>yc;
    cout<<"Enter the value of radius  :";
    cin>>r;
    BresenhamCircle(xc,yc,r);
     getch();
     closegraph();
     return 0;
    }
