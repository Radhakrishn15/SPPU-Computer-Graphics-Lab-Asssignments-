#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int transformed[10];
double b[3][3]={1,0,0,
				0,1,0,
				0,0,1,
				};
int c[1][1];
float a[1][1];
void matrix(float[]);
void matrix(float p[10])
{
	int i;
	for(i=0;i<9;i=i+2)
        {
            a[0][0]=p[i];
            a[0][1]=p[i+1];
            c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0]+b[2][0];
            c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1]+b[2][1];
            transformed[i]=c[0][0];
            transformed[i+1]=c[0][1];
		}
}
int main()
{
	int n,i,xmax,ymax,xmid,ymid;
	float sx,sy;
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);

	float p[10]={50,50,
                100,50,
                100,100,
                50,100,
                50,50};

    cout<<" Enter Scaling Factors"<<endl;
    cout<<"\nEnter the x scaling\nSx:";
    cin>>sx;
    cout<<"\nEnter y scaling\nSy:";
    cin>>sy;
    b[0][0]=sx;   b[0][1]=0;   b[0][2]=0;
    b[1][0]=0;    b[1][1]=sy;  b[1][2]=0;
    b[2][0]=0;    b[2][1]=0;   b[2][2]=1;



	xmax=getmaxx();
	ymax=getmaxy();
	xmid=xmax/2;
	ymid=ymax/2;
	setcolor(GREEN);
	line(xmid,0,xmid,ymax);
	line(0,ymid,xmax,ymid);
	setcolor(RED);

	for(i=0;i<8;i=i+2){
	line(p[i]+xmid,ymid-p[i+1],xmid+p[i+2],ymid-p[i+3]);
	}

	matrix(p);

	setcolor(WHITE);
	for(i=0;i<8;i=i+2) {
	line(xmid+transformed[i],ymid-transformed[i+1],xmid+transformed[i+2],ymid-transformed[i+3]);
	}
	getch();
	closegraph();
	return 0;
}
