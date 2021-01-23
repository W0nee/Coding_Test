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

int row, col;
int R, C, K;
int Map[110][110];
vector<pair<int, int>> num;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if(a.second < b.second)
	{
		return true;
	}
	else if(a.second == b.second)
	{
		if(a.first < b.first)
		{
			return true;
		}
		
		return false;
	}
	else
	{
		return false;
	}
}

void cal_R()
{
	int maxCol = col;
	
	for(int i = 1; i <= row; i++)
	{
		vector<pair<int, int>> num;
		int count[110] = {0};
		
		for(int j = 1; j <= col; j++)
		{
			count[Map[i][j]]++;
		}
		
		for(int j = 1; j <= 100; j++)
		{
			if(count[j] != 0)
			{
				num.push_back({j, count[j]});
			}
		}
		
		// 수의 등장 횟수가 커지는 순으로, 그러한 것이 여러가지면 수가 커지는 순으로 정렬한다. 
		sort(num.begin(), num.end(), cmp);
		
		maxCol = max(maxCol, (int)num.size() * 2);
		
		for(int j = 1, idx = 0; j <= maxCol && j <= 100; j += 2, idx++)
		{
			if(idx >= num.size())
			{
				Map[i][j] = 0;
				Map[i][j+1] = 0;
			}
			else
			{
				Map[i][j] = num[idx].first;
				Map[i][j+1] = num[idx].second;
			}
		}
	}
	
	col = maxCol;
	
	if(col > 100)
	{
		col = 100;
	}
}

void cal_C()
{
	int maxRow = row;
	
	for(int j = 1; j <= col; j++)
	{
		vector<pair<int, int>> num;
		int count[110] = {0};
		
		for(int i = 1; i <= row; i++)
		{
			count[Map[i][j]]++;
		}
		
		for(int i = 1; i <= 100; i++)
		{
			if(count[i] != 0)
			{
				num.push_back({i, count[i]});
			}
		}
		
		// 수의 등장 횟수가 커지는 순으로, 그러한 것이 여러가지면 수가 커지는 순으로 정렬한다. 
		sort(num.begin(), num.end(), cmp);
		
		maxRow = max(maxRow, (int)num.size() * 2);
		
		for(int i = 1, idx = 0; i <= maxRow && i <= 100; i += 2, idx++)
		{
			if(idx >= num.size())
			{
				Map[i][j] = 0;
				Map[i+1][j] = 0;
			}
			else
			{
				Map[i][j] = num[idx].first;
				Map[i+1][j] = num[idx].second;
			}
		}
	}
	
	row = maxRow;
	
	if(row > 100)
	{
		row = 100;
	}
}

void print()
{
	cout << "\n";
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve()
{
	int time = 0;
	
	while(1)
	{
		if(Map[R][C] == K)
		{
			cout << time;
			break;
		}
		else if(time > 100)
		{
			cout << "-1";
			break;
		}
		
		if(row >= col)
		{
			cal_R();
		}
		else
		{
			cal_C();
		}
		
//		cout << row << " " << col << "   time :  " << time;
//		print();
		
		time++;
	}	
}

int main(void)
{
//	freopen("B17140_input.txt", "r", stdin);
	
	cin >> R >> C >> K;
	
	row = 3; col = 3;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	solve();
	
	return 0;
}
