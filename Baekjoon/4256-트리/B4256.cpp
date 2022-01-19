#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int T, N;
int pre[1010];
int in[1010];
int preIdx;
vector<int> result;

void solve(int s, int e)
{
	if(s > e)
	{
		return;
	}
	
	preIdx++;	
		
	for(int i = s; i <= e; i++)
	{
		if(pre[preIdx] == in[i])
		{
			solve(s, i-1);
			solve(i+1, e);
			result.push_back(in[i]);	
			break;
		}
	}
}

int main(void)
{
//	freopen("B4256_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		preIdx = 0;
		result.clear();
		
		cin >> N;	
		
		for(int i = 1; i <= N; i++)
		{
			cin >> pre[i];
		}
		
		for(int i = 1; i <= N; i++)
		{
			cin >> in[i];
		}
		
		solve(1, N);
		
		for(int i = 0; i < result.size(); i++)
		{
			cout << result[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
