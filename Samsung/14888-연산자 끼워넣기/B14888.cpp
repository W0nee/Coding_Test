#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int oper[4];
vector<int> number;

int Max = -999999999;
int Min = 999999999;

void DFS(int plus, int minus, int multi, int divide, int idx, int sum)
{
	if(idx == N)
	{
		Max = max(Max, sum);
		Min = min(Min, sum);
		
		return;
	}
	
	if(plus > 0)
	{
		DFS(plus-1, minus, multi, divide, idx+1, sum + number[idx]);
	}
	else if(minus > 0)
	{
		DFS(plus, minus-1, multi, divide, idx+1, sum - number[idx]);
	}
	else if(multi > 0)
	{
		DFS(plus, minus, multi-1, divide, idx+1, sum * number[idx]);
	}
	else
	{
		DFS(plus, minus, multi, divide-1, idx+1, sum / number[idx]);
	}
}

int main(void)
{
//	freopen("B14888_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		int input;
		cin >> input;
		
		number.push_back(input);
	}
	
	cin >> oper[0] >> oper[1] >> oper[2] >> oper[3];
	
	DFS(oper[0], oper[1], oper[2], oper[3], 1, number[0]);
	
	cout << Max << "\n";
	cout << Min << "\n";
	
	return 0;
}
