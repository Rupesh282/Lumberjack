

#include "pch.h"
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Tree
{
public:
	int x, y, h, d, c, p;
	int price()
	{
		return p*h*d;
	}
	int weight()
	{
		return c*h*d;
	}
};

/*enum class direction
{
	left,
	right,
	up,
	down
};*/

int main()
{
	//Code for input
	int time;
	int grid_size;
	int tree_nos;
	cin >> time >> grid_size >> tree_nos;
	vector<Tree> *trees = new vector<Tree>;
	for (int i = 0; i < tree_nos; i++)
	{
		Tree temp;
		cin >> temp.x >> temp.y >> temp.h >> temp.d >> temp.c >> temp.p;
		trees->push_back(temp);
	}
	//End of input
	pair<int,int> curr_coor(0,0); //first is x, second is y
	
	
		
}


