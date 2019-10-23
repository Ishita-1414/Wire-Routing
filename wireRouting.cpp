#include<iostream>
using namespace std;
class Routing
{
    int mesh[10][10];
    int size;
    int count;
    int a[2],b[2];
    public:
    	void input();
	void pathFinding();
	void DistanceLabelling();
	void left(int,int,int);
	void right(int,int,int);
	void up(int,int,int);
	void down(int,int,int);
};
void Routing::input()
{
	cout<<"Enter size of the circuit grid: ";
	cin>>size;
	cout<<"Enter value of Dead Ends as 0 and 1 for available way in the grid"<<endl;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cin>>mesh[i][j];
		}
	}
	count =2;
	cout<<"Enter coordinates of a: ";
	cin>>a[0]>>a[1];
	cout<<"Enter coordinates of b: ";
	cin>>b[0]>>b[1];
	mesh[a[0]][a[1]]=0;
	mesh[b[0]][b[1]]=0;
}
void Routing::left(int i,int j,int cnt)
{
	if(i==b[0]&&(j-1)==b[1])
	{
		return;
	}
	else if(mesh[i][j-1]==1&&j!=0)
	    {
			if(mesh[i][j-1]>cnt||mesh[i][j-1]==1)
			mesh[i][j-1]=cnt;
			left(i,j-1,cnt+1);
			up(i,j,cnt+1);
			//right(i,j-1,cnt+1);
			down(i,j-1,cnt+1);
	    }else
		return;
}
void Routing::right(int i,int j,int cnt)
{
if(i==b[0]&&(j+1)==b[1])
{
return;
}
	if(mesh[i][j+1]==1&&j!=size-1)
	    {
if(mesh[i][j+1]>cnt||mesh[i][j+1]==1)
			mesh[i][j+1]=cnt;
			//left(i,j+1,cnt+1);
			up(i,j+1,cnt+1);
			right(i,j+1,cnt+1);
			down(i,j+1,cnt+1);
	    }else
		return;
}
void Routing::up(int i,int j,int cnt)
{
	if((i-1)==b[0]&&j==b[1])
	{
		return;
	}
	if(mesh[i-1][j]==1&&i!=0)
	{
if(mesh[i-1][j]>cnt||mesh[i-1][j]==1)
		mesh[i-1][j]=cnt;
		left(i-1,j,cnt+1);
		up(i-1,j,cnt+1);
		right(i-1,j,cnt+1);
		//down(i-1,j,cnt+1);
	}else
		return;
}
void Routing::down(int i,int j,int cnt)
{
if((i+1)==b[0]&&j==b[1])
{
return;
}
	if(mesh[i+1][j]==1&&i!=size-1)
	    {
if(mesh[i+1][j]>cnt||mesh[i+1][j]==1)
			mesh[i+1][j]=cnt;
			left(i+1,j,cnt+1);
			//up(i+1,j,cnt+1);
			right(i+1,j,cnt+1);
			down(i+1,j,cnt+1);
	    }else
return;
}
void Routing::DistanceLabelling()
{	
	left(a[0],a[1],2);
	up(a[0],a[1],2);
	right(a[0],a[1],2);
	down(a[0],a[1],2);
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<mesh[i][j]<<"\t";
		}
cout<<endl;
	}
}
//void pathFinding()
//{
//}
int main()
{
	Routing r;
	r.input();
	r.DistanceLabelling();
	return 0;
}
