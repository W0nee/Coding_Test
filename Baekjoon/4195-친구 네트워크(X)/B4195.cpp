#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int T;
int N;
int ans;
int visited[100010];
map<string, int> name;
vector<pair<string, string>> reserve;
vector<int> v[100010];

void DFS(int start)
{
	for(int i = 0; i < v[start].size(); i++)
	{
		if(visited[v[start][i]] == 0)
		{
			ans++;
			visited[v[start][i]] = 1;
			DFS(v[start][i]);
		}
	}
}

int main(void)
{
//	freopen("B4195_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		name.clear();
		reserve.clear();
		for(int i = 0; i < 100010; i++)
		{
			v[i].clear();
		}
		int nameIdx = 1;
		
		cin >> N;
		
		for(int i = 1; i <= N; i++)
		{
			string a, b;
			cin >> a >> b;
			
			if(name.find(a) == name.end())
			{
				name[a] = nameIdx++;
			}
			
			if(name.find(b) == name.end())
			{
				name[b] = nameIdx++;
			}
			
			reserve.push_back({a, b});
		}
		
		for(int i = 0; i < reserve.size(); i++)
		{
			v[name[reserve[i].first]].push_back(name[reserve[i].second]);
			v[name[reserve[i].second]].push_back(name[reserve[i].first]);
			
			ans = 1;	
			for(int j = 0; j < 100010; j++)
			{
				visited[j] = 0;
			}
			
			visited[name[reserve[i].first]] = 1;
			DFS(name[reserve[i].first]);
			
			cout << ans << endl;
		}
	}
	
	return 0;
}
