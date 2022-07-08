#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include<stdlib.h>

void drawline(int x1,int y1,int x2,int y2,int c)
{
  int dx,dy,m,length;
  float xn,yn,x,y;
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

    putpixel(x1, y1, c);

    for (int i = 0; i< length; i++)
    {

         x = x + xn;
         y = y + yn;
         putpixel(x, y, c);
    }

}
 int main()
{

    int gd = DETECT, gm = DETECT, x1, y1, x2, y2;
    system("clear");
    initgraph(&gd, &gm, "");
    drawline(25,25,400,25,4);
    drawline(25,150,400,150,14);
    drawline(25,25,25,150,15);
    drawline(400,25,400,150,2);

    getch();
}

