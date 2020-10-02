#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node
{
	int num;
	int SorT;
	int d;
}node; 
 
int N, K, M;
vector<int> graphS[100010];
vector<int> graphT[1010];
int visitedS[100010];
int visitedT[1010];
bool Find = false;
int ans;

void BFS()
{
	queue<node> q; // (번호, 역 or 튜브) 
	q.push({1, 0, 1});
	visitedS[1] = 1; 
	
	while(!q.empty())
	{
		int num = q.front().num;
		int SorT = q.front().SorT;
		int d = q.front().d;
		q.pop();
		
		if(num == N && SorT == 0)
		{
			Find = true;
			ans = d;
			return;
		}
		
		// 현재 노드 = 역 
		if(SorT == 0)
		{
			for(int i = 0; i < graphS[num].size(); i++)
			{
				if(visitedT[graphS[num][i]] == 0)
				{
					q.push({graphS[num][i], 1, d+1});
					visitedT[graphS[num][i]] = 1;
				}
			}
		}
		// 현재 노드 = 튜브 
		else
		{
			for(int i = 0; i < graphT[num].size(); i++)
			{
				if(visitedS[graphT[num][i]] == 0)
				{
					q.push({graphT[num][i], 0, d+1});
					visitedS[graphT[num][i]] = 1;
				}
			}
		}
	}
}

int main(void)
{
//	freopen("B5214_input.txt", "r", stdin);
	
	cin >> N >> K >> M;
	
	for(int i = 1; i <= M; i++)
	{
		for(int j = 1; j <= K; j++)
		{
			int val;
			cin >> val;
			
			graphS[val].push_back(i);
			graphT[i].push_back(val);
		}
	}
	
	BFS();
	
	if(Find)
	{
		cout << (ans+1) / 2;
	}
	else
	{
		cout << -1;
	}
	
	return 0;
}
