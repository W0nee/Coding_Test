#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
map<int, int> naegodo;
deque<int> belt;

int solve()
{ 
	int stage = 0;	
	vector<int> robot;
	int visited[2*N] = {0};
	
	while(1)
	{
		stage++;
		
		// 1. 벨트가 한 칸 회전한다.
		int temp = belt.back();
		belt.pop_back();
		belt.push_front(temp);
		
		// 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다.
		vector<int> tempRobot;
		for(int i = 0; i < robot.size(); i++)
		{
			int now = robot[i] % (2*N);
			int next = (robot[i] + 1) % (2*N);
			
			// 내려가는 위치
			if(now == belt[N-1])
			{
				visited[now] = 0;
				continue;
			}
			
			if(naegodo[next] >= 1 && visited[next] == 0)
			{
				// 내려가는 위치 
				if(next == belt[N-1])
				{
					naegodo[next]--;
					visited[now] = 0;
				}
				else
				{
					naegodo[next]--;
					visited[now] = 0;
					visited[next] = 1;
					tempRobot.push_back(next);	
				}
			}
			else
			{
				tempRobot.push_back(now);
			}
		}
		robot = tempRobot;
		
		// 3. 올라가는 위치에 로봇이 없다면 로봇을 하나 올린다.
		if(naegodo[belt[0]] >= 1 && visited[belt[0]] == 0)
		{
			naegodo[belt[0]]--;
			visited[belt[0]] = 1;
			robot.push_back(belt[0]);
		}
		
		// 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.	
		int cnt = 0;
		for(int i = 0; i <= 2*N-1; i++)
		{
			if(naegodo[i] == 0)
			{
				cnt++;
			}
		}
		
		if(cnt >= K)
		{
			return stage;
		}
	}
}

int main(void)
{
//	freopen("B20055_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	for(int i = 0; i <= 2*N-1; i++)
	{
		cin >> naegodo[i];
		belt.push_back(i);
	}
	
	cout << solve();
	
	return 0;
}
