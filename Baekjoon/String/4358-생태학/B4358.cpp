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

map<string, int> visited;
vector<string> v;
int cnt;

int main(void)
{
//	freopen("B4358_input.txt", "r", stdin);

	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	string s;
	
	while(getline(cin, s))
	{
		if(visited[s] == 0)
		{
			visited[s] = 1;
			v.push_back(s);
		}
		else
		{
			visited[s]++;
		}
		
		cnt++;
	}

	sort(v.begin(), v.end());
	
	for(int i = 0; i < v.size(); i++)
	{
		cout << fixed;
		cout.precision(4);
		
		cout << v[i] << " " << (double)(visited[v[i]] * 100) / cnt << "\n";
	}
	
	return 0;
}
