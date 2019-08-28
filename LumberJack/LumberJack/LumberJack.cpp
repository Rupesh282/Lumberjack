

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Tree
{
public:
	int x, y, h, d, c, p;
};

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
}


