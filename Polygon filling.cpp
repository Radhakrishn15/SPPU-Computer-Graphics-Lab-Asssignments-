#include<graphics.h>
#include<iostream>
#include<stdlib.h>
#include<dos.h>
using namespace std;
int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
float edge[4][4]={{100,10,200,300},
			{200,300,100,350},
			{100,350,0,300},
			{0,300,100,10}};

int i,m,n,k;
float intr[5];
int c;

 for(i=0;i<4;i++)
   line(edge[i][0],edge[i][1],edge[i][2],edge[i][3]);

 int ymax=edge[0][1];
 int ymin=edge[0][1];
 for(i=0;i<4;i++)
 {
     if(ymax<edge[i][1])
         ymax=edge[i][1];
     if(ymax<edge[i][3])
         ymax=edge[i][1];
     if(ymin>edge[i][1])
         ymin=edge[i][1];
     if(ymin>edge[i][3])
         ymin=edge[i][3];
}

 for(i=0;i<4;i++)
 {
     if(edge[i][1]>edge[i][3])
     {
         float temp1=edge[i][1];
         edge[i][1]=edge[i][3];
         edge[i][3]=temp1;
         float temp2=edge[i][0];
         edge[i][0]=edge[i][2];
         edge[i][2]=temp2;
     }
}

int y;
for(y=ymin;y<=ymax;y++)
{
    c=0;
    for(i=0;i<4;i++)
    {
    if(y>=edge[i][1] && y<edge[i][3])
    {
        float x=((((y-edge[i][3])*(edge[i][0]-edge[i][2])) / (edge[i][1]-edge[i][3]))+ edge[i][2]);
        intr[c]=x;
        c++;
    }
}

for(i=0;i<c-1;i++)
{
    for(int j=0;j<c;j++)
    {
        if(intr[i]>intr[j])
        {
            float temp=intr[i];
            intr[i]=intr[j];
            intr[j]=temp;
        }
    }
}
for(i=0;i<=c;i=i+2)
{
    setcolor(14);
    line(intr[i],y,intr[i+1],y);
}
delay(100);
}
getch();
closegraph();
return 0;
}

