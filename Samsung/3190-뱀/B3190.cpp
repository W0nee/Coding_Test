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
}node;

int N, K, L;
deque<node> snake;
map<pair<int, int>, int> apple;
map<int, char> turn;
int visited[110][110];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int solve()
{
	snake.push_back({1, 1, 0});
	visited[1][1] = 1;
	int time = 0;
	
	while(1)
	{
		time++;
		
		int x = snake[0].x;
		int y = snake[0].y;
		int dir = snake[0].dir;
		
		// ���� ���� �����̸� �÷� �Ӹ��� ����ĭ�� ��ġ��Ų��.
		int nx = x+dx[dir];
		int ny = y+dy[dir];
		
		// �̵� ������ ��� 
		if(1 <= nx && nx <= N && 1 <= ny && ny <= N && visited[nx][ny] == 0)
		{
			// ���� �̵��� ĭ�� ����� �ִٸ�, �� ĭ�� �ִ� ����� �������� ������ �������� �ʴ´�.
			if(apple[{nx, ny}] == 1)
			{
				snake.push_front({nx, ny, dir});	
				visited[nx][ny] = 1;	
				apple[{nx, ny}] = 0;
			}
			else
			{
				snake.push_front({nx, ny, dir});	
				visited[nx][ny] = 1;	
				visited[snake[snake.size()-1].x][snake[snake.size()-1].y] = 0;
				snake.pop_back();
			}
		}
		// �̵� �Ұ����� ��� 
		else
		{
			break;
		}
		
		if(turn[time] == 'L')
		{
			int ndir = dir-1 == -1 ? 3 : (dir-1) % 4;
			snake[0].dir = ndir;
		}
		else if(turn[time] == 'D')
		{
			int ndir = (dir+1) % 4;
			snake[0].dir = ndir;
		}
	}
	
	return time;
}

int main(void)
{
//	freopen("B3190_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	for(int i = 1; i <= K; i++)
	{
		int x, y;	
		cin >> x >> y;
		
		apple[{x, y}] = 1;
	}
	
	cin >> L;
	
	for(int i = 1; i <= L; i++)
	{
		int time; char dir;
		cin >> time >> dir;
		
		turn[time] = dir;
	}
	
	cout << solve();	
	
	return 0;
}
