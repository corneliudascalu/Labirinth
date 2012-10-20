#include<iostream.h>
#include<conio.h>
#include<fstream.h>
void main()
{
clrscr();
char lab[100][100],tezeu,continu,pas;
int m,n,i,j,p,q,score,blocat,nivel,x,quit;
ifstream f("labirint.in");
nivel=1;   score=0;
tezeu='*';
cout<<"Cate nivele vreti sa jucati?(maxim 10)";cin>>x;
do
  {
  f>>m;f>>n;
for(i=0;i<m;i++)
   for(j=0;j<n;j++)
      f>>lab[i][j];
   p=0;q=0;
   continu='0';blocat=0;
do
  {
  for(i=0;i<m;i++)
     {
     for(j=0;j<n;j++)
	cout<<lab[i][j]<<" ";
     cout<<endl;
     }
  cout<<"Unde mergeti?";pas=getch();
       if(pas=='1')
	       {
	       if(lab[p-1][q]=='1')
		 cout<<"Imposibil";
	       else
	       {
	       lab[p-1][q]=tezeu;
	       lab[p][q]='1';
	       p--;
	       }
	       if((lab[p-1][q]==1)&&(lab[p][q+1]==1)&&(lab[p+1][q]==1)&&(lab[p][q-1]==1))
		 blocat=1;
	       }
       if(pas=='2')
	       {
	       if(lab[p][q+1]=='1')
	       cout<<"Imposibil";
	       else
	       {
	       lab[p][q+1]=tezeu;
	       lab[p][q]='1';
	       q++;
	       }
	       if((lab[p-1][q]==1)&&(lab[p][q+1]==1)&&(lab[p+1][q]==1)&&(lab[p][q-1]==1))
		 blocat=1;
		 }
       if(pas=='3')
	       {
	       if(lab[p+1][q]=='1')
	       cout<<"Imposibil";
	       else
	       {
	       lab[p+1][q]=tezeu;
	       lab[p][q]='1';
	       p++;
	       }
	       if((lab[p-1][q]==1)&&(lab[p][q+1]==1)&&(lab[p+1][q]==1)&&(lab[p][q-1]==1))
		 blocat=1;
		 }
       if(pas=='4')
	       {
	       if(lab[p][q-1]=='1')
	       cout<<"Imposibil";
	       else
	       {
	       lab[p][q-1]=tezeu;
	       lab[p][q]='1';
	       q--;
	       }
	       if((lab[p-1][q]==1)&&(lab[p][q+1]==1)&&(lab[p+1][q]==1)&&(lab[p][q-1]==1))
		 blocat=1;
	       }
       if(pas=='5')
	       quit=1;
       else quit=0;
  clrscr();score=score+100;
   }
while((lab[m-1][n-1]!=tezeu)&&(blocat==0)&&(quit==0));
if(quit==0)
{
cout<<"Score: "<<score;
cout<<'\t'<<"Continue?  Press Y or N.";cin>>continu;  nivel++;}
}
while((continu!='n')&&(nivel<=x)&&(quit==0));
if(quit==0)
cout<<"Victory";
else cout<<"I'm ready to begin a new game.You are ready too?";
getch();
}