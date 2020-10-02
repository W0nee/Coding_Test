#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

typedef struct node
{
	int left;
	int right;
}node;

int N;
node tree[10010];
vector<pair<int, int>> list; // (num, depth)
vector<int> level[10010];
int maxLevel;
vector<int> result;
int minLevel = -1;
int maxWidth;
int visited[10010];
int root;

void DFS(int num, int level)
{
	if(num == -1)
	{
		return;
	}
	
	DFS(tree[num].left, level+1);
	list.push_back({num, level});
	DFS(tree[num].right, level+1);
}

int main(void)
{
//	freopen("B2250_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		int num, left, right;
		cin >> num >> left >> right;
		
		tree[num].left = left;
		tree[num].right = right;
		
		visited[num]++;
		if(left != -1) visited[left]++;
		if(right != -1) visited[right]++;
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(visited[i] == 1)
		{
			root = i;
		}
	}
	
	DFS(root, 1);
	
	int numOrder = 0;
	for(int i = 0; i < list.size(); i++)
	{
		level[list[i].second].push_back(++numOrder);
		
		maxLevel = max(maxLevel, list[i].second);
	}
	
	for(int i = 1; i <= maxLevel; i++)
	{
		sort(level[i].begin(), level[i].end());
	}
	
	for(int i = 1; i <= maxLevel; i++)
	{
		result.push_back(level[i][level[i].size()-1] - level[i][0] + 1);
	}
	
	for(int i = 0; i < result.size(); i++)
	{
		if(maxWidth < result[i])
		{
			maxWidth = result[i];
			minLevel = i+1;
		}
	}
	
	cout << minLevel << " " << maxWidth;
	
	return 0;
}
