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

int N, M, K;
vector<int> Tree[20][20];
int Energy[20][20];
int Add_Energy[20][20];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool cmp(int a, int b)
{
	if(a < b)
	{
		return true;
	}	
	
	return false;
}

int safe(int x, int y)
{
	if(1 <= x && x <= N && 1 <= y && y <= N)
	{
		return 1;
	}
	
	return 0;
}

void solve()
{
	int time = 0;
	
	while(1)
	{
		// spring & summer
		vector<int> Live_Tree[20][20];
		
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				int Die_Energy = 0;
				sort(Tree[i][j].begin(), Tree[i][j].end(), cmp);
				
				for(int k = 0; k < Tree[i][j].size(); k++)
				{
					int age = Tree[i][j][k];
					
					if(Energy[i][j] >= age)
					{
						Energy[i][j] -= age;
						Live_Tree[i][j].push_back(age + 1);
					}
					else
					{
						Die_Energy += (age / 2);
					}
				}
				
				Energy[i][j] += Die_Energy;
			}
		}
		
		// fall
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{	
				for(int k = 0; k < Live_Tree[i][j].size(); k++)
				{
					int age = Live_Tree[i][j][k];
					
					if(age % 5 == 0)
					{
						for(int a = 0; a < 8; a++)
						{
							int nx = i+dx[a];
							int ny = j+dy[a];
							
							if(safe(nx, ny))
							{
								Live_Tree[nx][ny].push_back(1);
							}
						}	
					}
				}
			}
		}
		
		// winter
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				Energy[i][j] += Add_Energy[i][j];
			}
		}
		
		// result;
		int cnt = 0;
		
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				Tree[i][j] = Live_Tree[i][j];
				
				cnt += Tree[i][j].size();
			}
		}
		
		time++;
		
		if(time == K)
		{
			cout << cnt;
			return;
		}
	}	
}

int main(void)
{
//	freopen("B16235_input.txt", "r", stdin);
	
	cin >> N >> M >> K;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Add_Energy[i][j];
			
			Energy[i][j] = 5;
		}
	}
	
	for(int i = 1; i <= M; i++)
	{
		int x, y, age;
		cin >> x >> y >> age;
		
		Tree[x][y].push_back(age);
	}
	
	solve();
	
	return 0;
}
