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
int x, y, dir;
int Map[60][60];
bool Flag = false;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int left_dir(int dir)
{
	if(dir == 0) return 3;
	else if(dir == 1) return 0;
	else if(dir == 2) return 1;
	else if(dir == 3) return 2;
}

int back_dir(int dir)
{
	if(dir == 0) return 2;
	else if(dir == 1) return 3;
	else if(dir == 2) return 0;
	else if(dir == 3) return 1;
}

int check(int x, int y)
{
	for(int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		
		if(Map[nx][ny] == 0)
		{
			return 0;
		}
	}
	
	return 1;
}

void solve(int x, int y, int dir, int stage)
{
	if(Flag)
	{
		return;
	}
	
	// 1. ���� ��ġ�� û���Ѵ�.
	if(stage == 1)
	{
		Map[x][y] = 2;	
		stage = 2;
	}
	
	// 2. ���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
	if(stage == 2)
	{
		// d. �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
		if(check(x, y) == 1)
		{
			int ndir = back_dir(dir);
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];
			
			if(Map[nx][ny] == 1)
			{
				Flag = true;
				return;	
			}
		}	
		
		// c. �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
		if(check(x, y) == 1)
		{
			int ndir = back_dir(dir);
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];
			
			if(Map[nx][ny] != 1)
			{
				solve(nx, ny, dir, 2);
				return;	
			}
		}
		
		// a. ���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
		int ndir = left_dir(dir);
		int nx = x + dx[ndir];
		int ny = y + dy[ndir];
		if(Map[nx][ny] == 0)
		{
			solve(nx, ny, ndir, 1);
			return;
		}	
		
		// b. ���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
		if(Map[nx][ny] != 0)
		{
			solve(x, y, ndir, 2);	
		}
	}
}

int main(void)
{
//	freopen("B14503_input.txt", "r", stdin);
	
	cin >> row >> col;
	cin >> x >> y >> dir;
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	solve(x, y, dir, 1);
	
	int cnt = 0;
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(Map[i][j] == 2) cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}
