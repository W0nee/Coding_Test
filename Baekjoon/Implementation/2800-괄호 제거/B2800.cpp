#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

string s;
vector<pair<int, int>> List;
vector<pair<int, int>> choice;
vector<string> result;

void check_gwalho()
{
	stack<pair<char, int>> st;
	
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '(')
		{
			st.push({s[i], i});
		}
		else if(s[i] == ')')
		{
			List.push_back({st.top().second, i});
			st.pop();
		}
	}
}

void cal()
{
	string val = "";
	int visited[210] = {0};
	
	for(int i = 0; i < choice.size(); i++)
	{
		visited[choice[i].first] = 1;
		visited[choice[i].second] = 1;
	}
	
	for(int i = 0; i < s.size(); i++)
	{
		if(visited[i] == 0)
		{
			val += s[i];
		}
	}
	
	result.push_back(val);
}

void combination(int idx, int cnt, int K)
{
	if(cnt == K)
	{
		cal();
		
		return;
	}
	
	for(int i = idx; i < List.size(); i++)
	{
		choice.push_back(List[i]);
		combination(i+1, cnt+1, K);
		choice.pop_back();
	}	
}

int main(void)
{
//	freopen("B2800_input.txt", "r", stdin);
	
	cin >> s;
	
	check_gwalho();

	for(int i = 1; i <= List.size(); i++)
	{
		combination(0, 0, i);
	}
	
	sort(result.begin(), result.end());
	
	map<string, int> check;
	
	for(int i = 0; i < result.size(); i++)
	{
		if(check[result[i]] == 0)
		{
			check[result[i]] = 1;
			cout << result[i] << "\n";
		}
	}
	
	return 0;
}
