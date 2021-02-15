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

int N, L;
int Map[110][110];
int garo[110];
int sero[110];
int ans;

void solve()
{
	for(int i = 1; i <= N; i++)
	{
		if(garo[i] == 0)
		{
			continue;
		}
		
		int val = Map[i][1];
		bool down = false; // 1
		bool up = false;   // 2
		int cnt = 1;
		
		for(int j = 2; j <= N; j++)
		{
			// down ���� 
			if(val > Map[i][j])
			{
				// down ���θ� �Ϸ����� ���� ���
				if(down)
				{
					break;
				}
				
				down = true;
				cnt = 1;
				val = Map[i][j];
			}
			// up ���� 
			else if(val < Map[i][j])
			{	
				// down ���� ���ʿ� up ���ΰ� ���� ��� 
				if(down)
				{
					break;
				}
						
				if(cnt < L)
				{
					break;
				}
				else if(cnt >= L)
				{
					cnt = 1;
					val = Map[i][j];	
				}
			}
			// flat ���� 
			else
			{
				cnt++;
			}
			
			if(down)
			{
				if(cnt >= L)
				{
					down = false;
					cnt = 0;
				}
			}
			
			if(j == N && down == false)
			{
//				cout << "@ " << down << endl;
//				cout << i << endl;
				ans++;
			} 
		}
	}
	
//	cout << "--------\n";
	
	for(int j = 1; j <= N; j++)
	{
		if(sero[j] == 0)
		{
			continue;
		}
		
		int val = Map[1][j];
		bool down = false; 
		int cnt = 1;
		
		for(int i = 2; i <= N; i++)
		{
			// down ���� 
			if(val > Map[i][j])
			{
				// down ���θ� �Ϸ����� ���� ���
				if(down)
				{
					break;
				}
				 
				down = true;
				cnt = 1;
				val = Map[i][j];
			}
			// up ���� 
			else if(val < Map[i][j])
			{	
				// down ���� ���ʿ� up ���ΰ� ���� ��� 
				if(down)
				{
					break;
				}
						
				if(cnt < L)
				{
					break;
				}
				else if(cnt >= L)
				{
					cnt = 1;
					val = Map[i][j];	
				}
			}
			// flat ���� 
			else
			{
				cnt++;
			}
			
			if(down)
			{
				if(cnt >= L)
				{
					down = false;
					cnt = 0;
				}
			}
			
			if(i == N && down == false)
			{
//				cout << j << endl;
				ans++;
			} 
		}
	}	
}

int main(void)
{
//	freopen("B1062_input.txt", "r", stdin);
	
	cin >> N >> L;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		int diff = 0;
		
		for(int j = 1; j < N; j++)
		{
			diff = max(diff, abs(Map[i][j]-Map[i][j+1]));
		}
		
		if(diff <= 1)
		{
			garo[i] = 1;
		}
	}
	
	for(int j = 1; j <= N; j++)
	{
		int diff = 0;
		
		for(int i = 1; i < N; i++)
		{
			diff = max(diff, abs(Map[i][j]-Map[i+1][j]));
		}
		
		if(diff <= 1)
		{
			sero[j] = 1;
		}
	}
	
	solve();
	
	cout << ans;
	
	return 0;
}
