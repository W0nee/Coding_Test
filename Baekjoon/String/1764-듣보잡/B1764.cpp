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
map<string, int> dic;
vector<string> list;

int main(void)
{
//	freopen("B1764_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		string name;
		cin >> name;
		
		dic[name] = 1;
	}
	
	for(int i = 1; i <= M; i++)
	{
		string name;
		cin >> name;
		
		if(dic[name])
		{
			list.push_back(name);
		}
	}
	
	cout << list.size() << endl;
	
	sort(list.begin(), list.end());
	
	for(int i = 0; i < list.size(); i++)
	{
		cout << list[i] << endl;
	}
	
	return 0;
}
