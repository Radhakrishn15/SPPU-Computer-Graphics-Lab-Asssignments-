#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

 main()
{
    int gd = DETECT,gm;
	int i,j,k,c,tx,ty;
	int transformed[3][4];
    int T[3][3];
    int  P[3][4];
    int xmax,ymax,xmid,ymid;

    initgraph(&gd,&gm,NULL);

    P[0][0]=50;    P[0][1]=50;    P[0][2]=1;
    P[1][0]=100;   P[1][1]=50;    P[1][2]=1;
    P[2][0]=100;   P[2][1]=100;   P[2][2]=1;
    P[0][3]=50;    P[1][3]=100;   P[2][3]=1;

          tx=-100;
          ty=0;
//    cout<<"\n enter the x translation: ";
//		cin>>tx;
//    cout<<"\n enter the y translation: ";
//		cin>>ty;

    T[0][0]=1;    T[0][1]=0;    T[0][2]=0;
    T[1][0]=0;    T[1][1]=1;    T[1][2]=0;
    T[2][0]=tx;	  T[2][1]=ty;   T[2][2]=1;

    xmax=getmaxx();
	ymax=getmaxy();
	xmid=xmax/2;
	ymid=ymax/2;
	setcolor(GREEN);
	line(xmid,0,xmid,ymax);
	line(0,ymid,xmax,ymid);
	setcolor(RED);

	for(i=0;i<=3;i++)
    {
	   line(+xmid+P[0][i],ymid-P[1][i],xmid+P[0][(i+1)%4],ymid-P[1][(i+1)%4]);
	}


	for(i=0;i<=2;i++)
        {
            for(j=0;j<=3;j++)
            {
                c=0;
                for(k=0;k<=2;k++)
                {
                  c=c+T[i][k]*P[k][j];
                }
            transformed[i][j]=c;
		}


	setcolor(WHITE);
	for(i=0;i<=3;i++)
    {
	    line(xmid+transformed[0][i],ymid-transformed[1][i],xmid+transformed[0][(i+1)%4],ymid-transformed[1][(i+1)%4]);
	}
	getch();
	closegraph();

}
}
