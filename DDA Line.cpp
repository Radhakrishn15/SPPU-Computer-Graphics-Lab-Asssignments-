#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;
main()
{
    int gd = DETECT ,gm, i;
    float x,y,dx,dy,length;
    int x1,y1, x2,y2,xn,yn;
    initgraph(&gd, &gm,"");
    cout<<"Enter the starting coordinate:";
    cin>>x1>>y1;
    cout<<"Enter the ending coordinate:";
    cin>>x2>>y2;
    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
      length = abs(dx);
    else
      length = abs(dy);

    xn = dx / length;
    yn = dy / length;

    x = x1;
    y = y1;

    putpixel(x1, y1, WHITE);

    for (int i = 0; i< length; i++)
    {

         x = x + xn;
         y = y + yn;
         putpixel(x, y, WHITE);
    }

    getch();
    closegraph();
}
