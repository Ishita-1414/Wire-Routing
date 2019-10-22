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
	void left(int,int);
	void right(int,int);
	void up(int,int);
	void down(int,int);
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
}
void Routing::left(int i,int j)
{
	if(i==b[0]&&j==b[1])
	{
		return;
	}
	else if(mesh[i][j-1]==1)
	    {
			mesh[i][j-1]=count;
			left(i,j-1);
			up(i,j-1);
			right(i,j-1);
			down(i,j-1);
	    }else
		return;
}
void Routing::right(int i,int j)
{
if(i==b[0]&&j==b[1])
{
return;
}
	if(mesh[i][j+1]==1)
	    {
			mesh[i][j+1]=count;
			left(i,j+1);
			up(i,j+1);
			right(i,j+1);
			down(i,j+1);
	    }else
		return;
}
void Routing::up(int i,int j)
{
	if(i==b[0]&&j==b[1])
	{
		return;
	}
	if(mesh[i-1][j]==1)
	    {
			mesh[i-1][j-1]=count;
			left(i-1,j);
			up(i-1,j);
			right(i-1,j);
			down(i-1,j);
	    }else
return;
}
void Routing::down(int i,int j)
{
if(i==b[0]&&j==b[1])
{
return;
}
	if(mesh[i+1][j]==1)
	    {
			mesh[i+1][j]=count;
			left(i+1,j);
			up(i+1,j);
			right(i+1,j);
			down(i+1,j);
	    }else
return;
}
void Routing::DistanceLabelling()
{
	for(int i=a[0];i<size;i++)
	{
		for(int j=a[1];j<size;j++)
		{
			while(i!=b[0]&&j!=b[1])
			{
				left(i+1,j);
				up(i+1,j);
				right(i+1,j);
				down(i+1,j);
			}
			count++;
		}
	}
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<mesh[i][j];
		}
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