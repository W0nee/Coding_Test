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

typedef struct node
{
	int x;
	int y;
	int dir;
	int num;
}node;

int row, col;
int Map[10][10];
int Temp[10][10];
vector<node> cctv;
int Min = 999999999;

void up(int x, int y)
{
	for(int i = x; i >= 1; i--)
	{
		if(1 <= Map[i][y] && Map[i][y] <= 5)
		{
			continue;
		}
		else if(Map[i][y] == 6)
		{
			break;
		}
		
		Map[i][y] = 7;
	}
}

void down(int x, int y)
{
	for(int i = x; i <= row; i++)
	{
		if(1 <= Map[i][y] && Map[i][y] <= 5)
		{
			continue;
		}
		else if(Map[i][y] == 6)
		{
			break;
		}
		
		Map[i][y] = 7;
	}
}

void left(int x, int y)
{
	for(int i = y; i >= 1; i--)
	{
		if(1 <= Map[x][i] && Map[x][i] <= 5)
		{
			continue;
		}
		else if(Map[x][i] == 6)
		{
			break;
		}
		
		Map[x][i] = 7;
	} 
}

void right(int x, int y)
{
	for(int i = y; i <= col; i++)
	{
		if(1 <= Map[x][i] && Map[x][i] <= 5)
		{
			continue;
		}
		else if(Map[x][i] == 6)
		{
			break;
		}
		
		Map[x][i] = 7;
	}
}

void cctv1(int x, int y, int dir)
{
	// ¡æ
	if(dir == 0)
	{
		right(x, y);
	}
	// ¡é 
	else if(dir == 1)
	{
		down(x, y);
	}
	// ¡ç 
	else if(dir == 2)
	{
		left(x, y);
	}
	// ¡è 
	else if(dir == 3)
	{
		up(x, y);
	}	
} 

void cctv2(int x, int y, int dir)
{
	// ¡ç¡æ
	if(dir == 0 || dir == 1)
	{
		left(x, y);
		right(x, y);
	}
	// ¡è¡é 
	else if(dir == 2 || dir == 3)
	{
		up(x, y);
		down(x, y);
	}
}

void cctv3(int x, int y, int dir)
{
	// ¡è¡æ
	if(dir == 0)
	{
		up(x, y);
		right(x, y);
	}
	// ¡æ¡é 
	else if(dir == 1)
	{
		right(x, y);
		down(x, y);
	}
	// ¡ç¡é 
	else if(dir == 2)
	{
		left(x, y);
		down(x, y);
	}
	// ¡ç¡è 
	else if(dir == 3)
	{
		left(x, y);
		up(x, y);
	}	
} 

void cctv4(int x, int y, int dir)
{
	// ¡ç¡è¡æ
	if(dir == 0)
	{
		left(x, y);
		up(x, y);
		right(x, y);
	}
	// ¡æ¡è¡é 
	else if(dir == 1)
	{
		right(x, y);
		up(x, y);
		down(x, y);
	}
	// ¡ç¡é¡æ 
	else if(dir == 2)
	{
		left(x, y);
		down(x, y);
		right(x, y);
	}
	// ¡ç¡è¡é
	else if(dir == 3)
	{
		left(x, y);
		up(x, y);
		down(x, y);
	}	
}

void cctv5(int x, int y, int dir)
{
	// ¡ç¡è¡æ¡é
	left(x, y);
	up(x, y);
	right(x, y);
	down(x, y);
}

void solve()
{
	for(int k = 0; k < cctv.size(); k++)
	{
		int x = cctv[k].x;
		int y = cctv[k].y;
		int dir = cctv[k].dir;
		int num = cctv[k].num;
		
		if(num == 1) cctv1(x, y, dir);
		else if(num == 2) cctv2(x, y, dir);
		else if(num == 3) cctv3(x, y, dir);
		else if(num == 4) cctv4(x, y, dir);
		else if(num == 5) cctv5(x, y, dir);
	}
}

int count()
{
	int cnt = 0;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(Map[i][j] == 0)
			{
				cnt++;
			}
		}	
	}	
	
	return cnt;
}

void copy()
{
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			Map[i][j] = Temp[i][j];
		}	
	}	
}

void print()
{
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cout << Map[i][j] << " ";
		}	
		cout << "\n";
	}	
	cout << "\n";
}

void permutation(int cnt)
{
	if(cnt == cctv.size())
	{
		solve();
		Min = min(Min, count());
//		print();	
		copy();
		
		return;
	}
	
	for(int i = 0; i < 4; i++)
	{
		if(cctv[cnt].num == 5 && i != 0)
		{
			continue;
		}
		
		cctv[cnt].dir = i;
		permutation(cnt+1);
		cctv[cnt].dir = -1;
	}	
}

int main(void)
{
//	freopen("B15683_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
			Temp[i][j] = Map[i][j];
			
			if(1 <= Map[i][j] && Map[i][j] <= 5)
			{
				cctv.push_back({i, j, -1, Map[i][j]});
			}
		}
	}
	
	permutation(0);

	cout << Min;
	
	return 0;
}
