#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int L, R;
int Map[55][55];
bool isMove = false;

queue<pair<int, int>> q;
int visited[55][55];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

//int all_visit(int visited[55][55])
//{
//	for(int i = 1; i <= N; i++)
//	{
//		for(int j = 1; j <= N; j++)
//		{
//			if(visited[i][j] == 0)
//			{
//				return 0;
//			}
//		}
//	}
//	
//	return 1;
//}

int safe(int x, int y)
{
	if(1 <= x && x <= N && 1 <= y && y <= N)
	{
		return 1;
	}
	
	return 0;
}

void print()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cout << Map[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n";
}

void BFS(int x, int y, int cnt)
{
	q.push({x, y});
	visited[x][y] = cnt;
	
	int sum = 0;
	vector<pair<int, int>> unite;
		
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		sum += Map[x][y];
		unite.push_back({x, y});
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 1 && visited[nx][ny] == 0)
			{
				int diff = abs(Map[x][y] - Map[nx][ny]);
				
				if(L <= diff && diff <= R)
				{
					q.push({nx, ny});
					visited[nx][ny] = cnt;
				}	
			}
		}	
	}
		
	if(unite.size() >= 2)
	{
		isMove = true;
	}
	
	for(int i = 0; i < unite.size(); i++)
	{
		Map[unite[i].first][unite[i].second] = sum / (int)unite.size();
	}
}

int solve()
{
	int ans = 0;
	
	while(1)
	{
		int cnt = 0;
		isMove = false;
		memset(visited, 0, sizeof(visited));
		
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				if(visited[i][j] == 0)
				{
					BFS(i, j, ++cnt);
				}
			}
		}
		
		if(isMove == false)
		{
			break;
		}
		
		ans++;
	}
	
	return ans;
}

int main(void)
{
//	freopen("B16234_input.txt", "r", stdin);
	
	cin >> N >> L >> R;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	cout << solve();
	
	return 0;
}
