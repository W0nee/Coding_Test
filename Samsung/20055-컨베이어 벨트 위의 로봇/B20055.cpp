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
		
		// 1. ��Ʈ�� �� ĭ ȸ���Ѵ�.
		int temp = belt.back();
		belt.pop_back();
		belt.push_front(temp);
		
		// 2. ���� ���� ��Ʈ�� �ö� �κ�����, ��Ʈ�� ȸ���ϴ� �������� �� ĭ �̵��� �� �ִٸ� �̵��Ѵ�.
		vector<int> tempRobot;
		for(int i = 0; i < robot.size(); i++)
		{
			int now = robot[i] % (2*N);
			int next = (robot[i] + 1) % (2*N);
			
			// �������� ��ġ
			if(now == belt[N-1])
			{
				visited[now] = 0;
				continue;
			}
			
			if(naegodo[next] >= 1 && visited[next] == 0)
			{
				// �������� ��ġ 
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
		
		// 3. �ö󰡴� ��ġ�� �κ��� ���ٸ� �κ��� �ϳ� �ø���.
		if(naegodo[belt[0]] >= 1 && visited[belt[0]] == 0)
		{
			naegodo[belt[0]]--;
			visited[belt[0]] = 1;
			robot.push_back(belt[0]);
		}
		
		// 4. �������� 0�� ĭ�� ������ K�� �̻��̶�� ������ �����Ѵ�. �׷��� �ʴٸ� 1������ ���ư���.	
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
