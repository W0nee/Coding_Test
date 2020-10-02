#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node
{
	int from;
	int to;
	int cost;
}node;

int T;
int nodeNum, roadNum, wormNum;
vector<node> graph;
int d[510];

void bellman()
{
//	d[1] = 0;
	for(int k = 1; k <= nodeNum; k++)
	{
		for(int i = 0; i < graph.size(); i++)
		{
			int from = graph[i].from;
			int to = graph[i].to;
			int cost = graph[i].cost;
			
//			if(d[from] == 99999999)
//			{
//				continue;
//			}
			
			if(d[to] > d[from] + cost)
			{
				d[to] = d[from] + cost;
				
				if(k == nodeNum)
				{
					// 음수사이클 
					cout << "YES" << endl;
					return;
				}
			}
		}
	}

	cout << "NO" << endl;
	return;
}

int main(void)
{
//	freopen("B1865_input.txt", "r", stdin);
	
	cin >> T;
		
	while(T--)
	{
		cin >> nodeNum >> roadNum >> wormNum;
		
		for(int i = 1; i <= nodeNum; i++)
		{
			d[i] = 99999999;
		}
		graph.clear();
		
		for(int i = 1; i <= roadNum; i++)
		{
			int from, to, cost;
			cin >> from >>  to >> cost;
			
			graph.push_back({from, to, cost});
			graph.push_back({to, from, cost});
		}
		
		for(int i = 1; i <= wormNum; i++)
		{
			int from, to, cost;
			cin >> from >>  to >> cost;
			
			graph.push_back({from, to, -cost});
		}
		
		bellman();
	}
	
	return 0;
}
