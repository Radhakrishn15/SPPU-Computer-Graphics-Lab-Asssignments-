#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
class trans
{
 public:
 float transco[3][3];
// float orico[3][3];
 float scalco[3][3];
 float rotco[3][3];
 void drawtri(float [3][3]);
 void translation(int,int,float [3][3]);
 void scaling(float,float,float [3][3]);
 void rotation(float,float [3][3]);
};
void trans::drawtri(float co[3][3])
{
//clrscr();
line(co[0][0],co[1][0],co[0][1],co[1][1]);
line(co[0][1],co[1][1],co[0][2],co[1][2]);
line(co[0][2],co[1][2],co[0][0],co[1][0]);
}
void trans::translation(int tx,int ty,float orico[3][3])
{
cout<<"\nEnter Translation Factor"<<endl;
cout<<"Tx : ";
cin>>tx;
cout<<"Ty : ";
cin>>ty;
int i,j;
for(i=0;i<3;i++)
{
 transco[0][i]=orico[0][i]+tx;
 transco[1][i]=orico[1][i]+ty;
 transco[2][i]=1;
}
cout<<"\nAfter Translation Matrix:-\n";
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
cout<<"  "<<transco[i][j]<<"\t";
}
cout<<endl;
}
}
void trans::scaling(float sx,float sy,float orico[3][3])
{
cout<<"\nEnter Scaling Factor"<<endl;
cout<<"Sx : ";
cin>>sx;
cout<<"Sy : ";
cin>>sy;
int i,j;
for(i=0;i<3;i++)
{
 scalco[0][i]=orico[0][i]*sx;
 scalco[1][i]=orico[1][i]*sy;
 scalco[2][i]=1;
}
cout<<"\nAfter Scaling Matrix:-\n";
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
cout<<" "<<scalco[i][j]<<"\t";
}
cout<<endl;
}
}
void trans::rotation(float theta,float orico[3][3])
{
cout<<"\nEnter Rotation Angle"<<endl;
cin>>theta;
cout<<theta<<endl;
theta= theta*(3.14/180);
cout<<"theta in radius"<<theta<<endl;
int i,j,refx,refy;
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
rotco[i][j]=0;
}
 }
 for(i=0;i<3;i++)
 {
rotco[0][i]=orico[0][i]*cos(theta)-
orico[1][i]*sin(theta);
rotco[1][i]=orico[0][i]*sin(theta)+orico[1][i]*cos(theta);
 }
}
main()
{
 cleardevice();
 int ch;
 int gd= DETECT, gm;
 initgraph(&gd,&gm,"");
 trans t;
 int tx,ty;
 float sx,sy;
 float theta;
 float orico[3][3] ={{300,250,350},{200,300,300},{1,1,1}};
cout<<"\n         Original 3*3 Matrix:  \n"<<endl;
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{

    cout<<"["<<i<<"]"<<"["<<j<<"]"<<"=> "<<orico[i][j]<<"\t";

}
cout<<endl;
}
 t.drawtri(orico);
 cout<<"\n MENU"<<endl;
 cout<<"1. Translation"<<endl;
 cout<<"2. Scaling"<<endl;
 cout<<"3. Rotation"<<endl;
 cout<<"4. Exit"<<endl;
 cout<<"\nEnter your choice:";
 cin>>ch;
 switch(ch)
 {
    case 1:
        t.translation(tx,ty,orico);
        t.drawtri(t.transco);
        break;
    case 2:
        t.scaling(sx,sy,orico);
        t.drawtri(t.scalco);
        break;
    case 3:
        t.rotation(theta,orico);
        t.drawtri(t.rotco);
        break;

    case 4:
        break;
    default:
        cout<<("Invalid Choice");
 }
 getch();
}
