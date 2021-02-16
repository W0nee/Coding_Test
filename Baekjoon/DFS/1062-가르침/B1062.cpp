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

int N, K;
int check[27];
vector<string> word;
int Max;

int can_read()
{
	int cnt = 0;
	
	for(int k = 0; k < word.size(); k++)
	{
		bool Flag = true;
		
		for(int i = 4; i < word[k].size() - 4; i++)
		{
			if(check[word[k][i] - 'a'] == 0)
			{
				Flag = false;
				break;
			}
		}
		
		if(Flag) cnt++;
	}
	
	return cnt;
}

void combination(int idx, int cnt)
{
	if(cnt == K)
	{
		Max = max(Max, can_read());
		return;
	}
	
	for(int i = idx; i < 26; i++)
	{
		if(check[i] == 1)
		{
			continue;
		}
		
		check[i] = 1;
		combination(i+1, cnt+1);
		check[i] = 0;
	}
}

int main(void)
{
//	freopen("B1062_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		
		word.push_back(s);
	}
	
	if(K < 5)
	{
		cout << "0";
	}
	else
	{
		K -= 5;
		check['a'-'a'] = 1;
		check['c'-'a'] = 1;
		check['i'-'a'] = 1;
		check['n'-'a'] = 1;
		check['t'-'a'] = 1;
		
		combination(0, 0);
		
		cout << Max;
	}
	
	return 0;
}
