#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
vector<pair<int, int>> list;

void hanoi(int num, int from, int by, int to)
{
	if(num == 1)
	{
		list.push_back({from, to});
		return;
	}
	
	hanoi(num-1, from, to, by);
	list.push_back({from, to});
	hanoi(num-1, by, from, to);
}

int main(void)
{
//	freopen("B11729_input.txt", "r", stdin);
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	
	hanoi(N, 1, 2, 3);
	
	cout << list.size() << "\n";
	
	for(int i = 0; i < list.size(); i++)
	{
		cout << list[i].first << " " << list[i].second << "\n";
	}
	
	return 0;
}
