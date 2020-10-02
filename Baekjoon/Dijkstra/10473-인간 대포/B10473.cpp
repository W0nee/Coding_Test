#include <stdio.h>
#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

double startX, startY;
double arriveX, arriveY;
int N;
vector<pair<double, double>> pos;
double dist[110][110];
double d[110];

void dijkstra()
{
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	pq.push({0, 0});
	d[0] = 0;
	
	while(!pq.empty())
	{
		int now = pq.top().second;
		double nowCost = pq.top().first;
		pq.pop();
		
		if(d[now] < nowCost)
		{
			continue;
		}
		
		for(int i = 1; i <= N+1; i++)
		{
			if(now == i)
			{
				continue;
			}
			
			int next = i;
			double nextCost;
			if(now == 0)
			{
				nextCost = dist[now][next] / 5.0;
			}
			else
			{
				nextCost = min(dist[now][next] / 5.0, abs(dist[now][next]-50.0) / 5.0 + 2.0);
			}
			
			if(d[now] + nextCost < d[next])
			{
				d[next] = d[now] + nextCost;
				if(next != 1)
				{
					pq.push({d[next], next});	
				}
			}	
		}	
	}
}

int main(void)
{
//	freopen("B10473_input.txt", "r", stdin);
	
	cin >> startX >> startY >> arriveX >> arriveY;
	
	cin >> N;
	
	pos.push_back({startX, startY});
	pos.push_back({arriveX, arriveY});
	
	for(int i = 0; i <= N+1; i++)
	{
		d[i] = 999999999;
	}
	
	for(int i = 1; i <= N; i++)
	{
		double x, y;
		cin >> x >> y;
		
		pos.push_back({x, y});
	}
	
	for(int i = 0; i < pos.size(); i++)
	{
		for(int j = 0; j < pos.size(); j++)
		{
			if(i == j)
			{
				continue;
			}
			
			dist[i][j] = sqrt(pow(pos[i].first-pos[j].first, 2.0) + pow(pos[i].second-pos[j].second, 2.0));
		}
	}
	
	dijkstra();
	
	cout << d[1];
	
	return 0;
}
