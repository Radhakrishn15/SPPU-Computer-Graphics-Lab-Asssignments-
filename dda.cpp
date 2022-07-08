#include <graphics.h>
#include <stdio.h>
#include<iostream>
#include <conio.h>
#include <math.h>
#include<stdlib.h>
using namespace std;

main()
{
    int x1, y1, x2, y2,x3,y3;
    int dx,dy,m,length;
    float xn,yn,x,y;
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "");
    cout<<"Enter coordinates for Triangle:\n"<<endl;
    cout<<"Vertex 1(x1,y1):";
    cin>>x1>>y1;
    cout<<"Vertex 2(x2,y2):";
    cin>>x2>>y2;
    cout<<"Vertex 3(x3,y3):";
    cin>>x3>>y3;
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
         delay(10);
    }

    getch();
}
