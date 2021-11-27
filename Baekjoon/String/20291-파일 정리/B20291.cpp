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

int N;
map<string, int> dic;
vector<string> list;

int main(void)
{
//	freopen("B20291_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		string file;
		cin >> file;
		
		int dotIdx;
		for(int i = 0; i < file.size(); i++)
		{
			if(file[i] == '.')
			{
				dotIdx = i;
				break;
			}
		}
		
		string ext = file.substr(dotIdx+1);
		
		if(dic[ext] == 0)
		{
			list.push_back(ext);
		}
		dic[ext]++;
	}
	
	sort(list.begin(), list.end());
	
	for(int i = 0; i < list.size(); i++)
	{
		cout << list[i] << " " << dic[list[i]] << "\n";
	}
	
	return 0;
}
