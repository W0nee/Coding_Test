#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
map<string, int> visited;
int cnt;

int main(void)
{
//	freopen("B14425_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		
		visited[s] = 1;
	}
	
	for(int i = 1; i <= M; i++)
	{
		string s;
		cin >> s;
		
		if(visited[s] == 1)
		{
			cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}
