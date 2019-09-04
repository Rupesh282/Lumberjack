//#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Tree
{
public:
	int x, y, h, d, c, p;
	int time_taken()
	{
		return x+y+d;
	}
};

int main()
{
	//cout<<"Hello\n";
	int time;
	int grid_size;
	int tree_nos;
	int mn;
	Tree trail;
	cin >> time >> grid_size >> tree_nos;
	//cout<<"inp -1\n";
	//Tree ar_tree[tree_nos];
	Tree* ar_tree=new Tree[tree_nos];
	for (int i = 0; i < tree_nos; i++)
	{
		Tree temp;
		cin >> temp.x >> temp.y >> temp.h >> temp.d >> temp.c >> temp.p;
		//cout<<"inp "<<i<<endl;
		ar_tree[i] = temp;
		if(i == 0)
		{
			mn = temp.time_taken();
			trail=ar_tree[i];
		}
		if(mn > ar_tree[i].time_taken())
		{
			mn = ar_tree[i].time_taken();
			trail = ar_tree[i];
		}
	}
	for(int j = 0; j< trail.x; j++)
	{
		cout<<"move right\n";
	}
	for(int s = 0; s< trail.y; s++)
	{
		cout<<"move up\n";
	}
	if(trail.x == grid_size)
		cout<<"cut left\n";
	else if (trail.x == 0)
		cout<<"cut right\n";
	else if (trail.y == 0)
		cout<<"cut up\n";
	else if(trail.y == grid_size)
		cout<<"cut down\n";
	else
		cout<<"cut up\n";
	delete[] ar_tree;
	return 0;
}
