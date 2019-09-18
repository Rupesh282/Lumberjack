
#include "pch.h"
#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <cstdlib>
#include <array>
#include <algorithm>

using namespace std;

class Tree
{
public:
	int x, y, h, d, c, p;
	int key;
	int price()
	{
		return p*h*d;
	}
	int weight()
	{
		return c*h*d;
	}

};

bool operator==(Tree t1, Tree t2)
{
	if (t1.key == t2.key)
		return true;
	else
		return false;
}

enum class Direction
{
	left,
	right,
	up,
	down
};

const array<Direction, 4> all_directions = { Direction::down, Direction::up, Direction::left, Direction::right};

void chain_maker(vector<Tree>::iterator tree, Direction d, vector<vector<Tree>::iterator>* chain,vector<Tree> *trees)
{
	switch (d)
	{
	case Direction::down:
	{
		int min_dist = INT_MAX;
		vector<Tree>::iterator min_dist_tree;
		bool foundTree(0);
		for(auto it = trees->begin(); it != trees->end(); it++)
		{
			if (it->y < tree->y && it->x == tree->x)
			{
				foundTree = 1;
				int dist = tree->y - it->y;
				if (dist < min_dist)
				{
					min_dist = dist;
					min_dist_tree = it;
				}
			}
		}
		if ((foundTree))
		{
			/*for (auto it : *chain)
			{
				if (it->y - min_dist_tree->y < it->h && it->weight()>min_dist_tree->weight())
				{
					chain->emplace_back(min_dist_tree);
					chain_maker(min_dist_tree, Direction::down, chain, trees);
					break;
				}
			}	*/
			auto it = chain->back();
			if (it->y - min_dist_tree->y < it->h && it->weight()>min_dist_tree->weight())
			{
				chain->emplace_back(min_dist_tree);
				chain_maker(min_dist_tree, Direction::down, chain, trees);
			}
		}
		break;
	}
	case Direction::left:
	{
		int min_dist = INT_MAX;
		vector<Tree>::iterator min_dist_tree;
		bool foundTree(0);
		for (auto it = trees->begin(); it != trees->end(); it++)
		{
			if (it->x < tree->x && it->y == tree->y)
			{
				foundTree = 1;
				int dist = tree->x - it->x;
				if (dist < min_dist)
				{
					min_dist = dist;
					min_dist_tree = it;
				}
			}
		}
		if ((foundTree))
		{
			/*for (auto it : *chain)
			{
				if (it->x - min_dist_tree->x < it->h && it->weight()>min_dist_tree->weight())
				{
					chain->emplace_back(min_dist_tree);
					chain_maker(min_dist_tree, Direction::left, chain, trees);
					break;
				}
			}*/
			auto it = chain->back();
			if (it->x - min_dist_tree->x < it->h && it->weight()>min_dist_tree->weight())
			{
				chain->emplace_back(min_dist_tree);
				chain_maker(min_dist_tree, Direction::left, chain, trees);
			}
		}
		break;
	}
	case Direction::right:
	{
		int min_dist = INT_MAX;
		vector<Tree>::iterator min_dist_tree;
		bool foundTree(0);
		for (auto it = trees->begin(); it != trees->end(); it++)
		{
			if (it->x > tree->x && it->y == tree->y)
			{
				foundTree = 1;
				int dist = it->x - tree->x;
				if (dist < min_dist)
				{
					min_dist = dist;
					min_dist_tree = it;
				}
			}
		}
		if ((foundTree))
		{
			/*for (auto it : *chain)
			{
				if (min_dist_tree->x - it->x < it->h && it->weight()>min_dist_tree->weight())
				{
					chain->emplace_back(min_dist_tree);
					chain_maker(min_dist_tree, Direction::right, chain, trees);
					break;
				}
			}*/
			auto it = chain->back();
			if (min_dist_tree->x - it->x < it->h && it->weight()>min_dist_tree->weight())
			{
				chain->emplace_back(min_dist_tree);
				chain_maker(min_dist_tree, Direction::right, chain, trees);
			}
		}
		break;
	}
	case Direction::up:
	{
		int min_dist = INT_MAX;
		vector<Tree>::iterator min_dist_tree;
		bool foundTree(0);
		for (auto it = trees->begin(); it != trees->end(); it++)
		{
			if (it->y > tree->y && it->x == tree->x)
			{
				foundTree = 1;
				int dist = it->y - tree->y;
				if (dist < min_dist)
				{
					min_dist = dist;
					min_dist_tree = it;
				}
			}
		}
		if ((foundTree))
		{
			/*for (auto it : *chain)
			{
				if (min_dist_tree->y - it->y < it->h && it->weight()>min_dist_tree->weight())
				{
					chain->emplace_back(min_dist_tree);
					chain_maker(min_dist_tree, Direction::up, chain, trees);
					break;
				}
			}*/
			auto it = chain->back();
			if (min_dist_tree->y - it->y < it->h && it->weight()>min_dist_tree->weight())
			{
				chain->emplace_back(min_dist_tree);
				chain_maker(min_dist_tree, Direction::up, chain, trees);
			}
		}
		break;
	}
	}
}

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
		temp.key = i;
		trees->emplace_back(temp);
	}
	//End of input
	pair<int,int> curr_coor(0,0); //first is x, second is y
	while (time > 0 && !trees->empty())
	{
		/*int least_dist = INT_MAX;
		for (auto it = trees->begin(); it != trees->end(); it++)
		{
			int dist = abs(curr_coor.first - it->x) + abs(curr_coor.second - it->y);
			if (dist < least_dist)
			{
				least_dist = dist;
				max_profit_tree = it;
			}
		}*/

		vector<Tree>::iterator max_profit_tree=trees->begin();
		int max_profit(0);
		int temp_time(abs(curr_coor.first - trees->begin()->x) + abs(curr_coor.second - trees->begin()->y) + trees->begin()->d);
		double max_ratio(0);
		bool isChain(0);
		Direction chain_dir = Direction::up;
		vector<vector<Tree>::iterator> chain;
		for (auto it = trees->begin(); it != trees->end(); it++)
		{
			int temp_time_local = abs(curr_coor.first - it->x) + abs(curr_coor.second - it->y) + it->d;
			if (temp_time_local > time)
				continue;
			int profit;
			int chain_max_price(0);
			bool isChainLocal(0);
			Direction chain_dir_local;
			vector<vector<Tree>::iterator> chain_local;
			for (Direction d : all_directions)
			{
				vector<vector<Tree>::iterator> temp_chain;
				temp_chain.emplace_back(it);
				chain_maker(it, d, &temp_chain, trees);
				if (temp_chain.size() > 1)
				{
					isChainLocal = 1;
					int temp_price(0);
					for (auto it : temp_chain)
						temp_price += it->price();
					if (chain_max_price < temp_price)
					{
						chain_max_price = temp_price;
						chain_local = temp_chain;
						chain_dir_local = d;
					}
				}
			}
			if (isChainLocal)
				profit = chain_max_price;
			else
				profit = it->price();
			//temp_time_local+= abs(curr_coor.first - it->x) + abs(curr_coor.second - it->y);
			//temp_time_local += it->d;
			double ratio = static_cast<double>(profit) / temp_time_local;
			if (temp_time_local<=time && ratio > max_ratio)
			{
				max_ratio = ratio;
				max_profit = profit;
				max_profit_tree = it;
				isChain = isChainLocal;
				chain_dir = chain_dir_local;
				chain = chain_local;
				temp_time = temp_time_local;
			}

		}
		/*
		//check for domino effect
		for (Direction d : all_directions)
		{
			vector<vector<Tree>::iterator> temp_chain;
			temp_chain.emplace_back(max_profit_tree);
			chain_maker(max_profit_tree, d, &temp_chain, trees);
			if (temp_chain.size()>1)
			{
				isChain = 1;
				int temp_price(0);
				for (auto it : temp_chain)
					temp_price += it->price();
				if (chain_max_price < temp_price)
				{
					chain_max_price = temp_price;
					chain = temp_chain;
					chain_dir = d;
				}
			}
		}*/
		//Calculate time 
	
		//temp_time += abs(curr_coor.first-max_profit_tree->x)+abs(curr_coor.second-max_profit_tree->y);
		//temp_time += max_profit_tree->d;
		if (temp_time < time)
		{
			//go to the tree
			if (curr_coor.first < max_profit_tree->x)
			{
				for (int i = 0; i < max_profit_tree->x - curr_coor.first; i++)
				{
					cout << "move right\n";
				}
			}
			else
			{
				for (int i = 0; i < curr_coor.first - max_profit_tree->x; i++)
				{
					cout << "move left\n";
				}
			}
			if (curr_coor.second < max_profit_tree->y)
			{
				for (int i = 0; i < max_profit_tree->y - curr_coor.second; i++)
				{
					cout << "move up\n";
				}
			}
			else
			{
				for (int i = 0; i < curr_coor.second - max_profit_tree->y; i++)
				{
					cout << "move down\n";
				}
			}
			//cut the tree
			switch (chain_dir)
			{
			case Direction::up:
				cout << "cut up\n";
				break;
			case Direction::down:
				cout << "cut down\n";
				break;
			case Direction::left:
				cout << "cut left\n";
				break;
			case Direction::right:
				cout << "cut right\n";
				break;
			}
			curr_coor.first = max_profit_tree->x;
			curr_coor.second = max_profit_tree->y;
			//trees->erase(max_profit_trees
			
			if (isChain)
			{
				vector<Tree> trees_chain;
				for (auto it : chain)
				{
					trees_chain.emplace_back(*it);
				}
				for (Tree t : trees_chain)
				{
					trees->erase(remove(trees->begin(), trees->end(), t), trees->end());
				}
			}
			else
				trees->erase(max_profit_tree);
			time -= temp_time;
		}
		else
			return 0;
	}
	return 0;
}


