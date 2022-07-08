#include<iostream>
#include<string.h>
using namespace std;
#define infi -1
#define max 10
#define hash_fun (x) x810

class hash
{
private:
int address, count;
struct tele
{
long int ph_no;
//char name [20];
int link;
}t [10];

public:
hash ()
{
for (int i=0; i<max;i++)
{
t[i].ph_no=-1;
//strcpy (t[i].name, "");
t[i].link infi;
}
}
count=-1;
void chaining ();// Without Replacement
void chaining_with(); // With Replacement
void display();
}h1;

void hash::chaining ()
{
int ph_no;
int i, k, cnt;
char name [20];
cout<<"enter the phone number & name:";
cin>>ph_no; //>>name;
address=hash_fun (ph_no);
if (t [address].ph_no==-1)
{
t[address].ph=ph_no;
//strcpy(t [address].name, name);
}
else
{
//t[address].ph%10!=address
i=address;
count=0;
//find next empty slot.
while (t[i].ph_no! =-1 && count<max)
