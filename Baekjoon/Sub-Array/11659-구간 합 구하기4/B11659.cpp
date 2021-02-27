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
int pre_sum[100010];
int num[100010];

int main(void)
{
//	freopen("B11659_input.txt", "r", stdin);
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
		
		pre_sum[i] = pre_sum[i-1] + num[i];
	}
	
	for(int i = 1; i <= M; i++)
	{
		int from, to;
		cin >> from >> to;
		
		cout << pre_sum[to] - pre_sum[from-1] << "\n";
	}
	
	return 0;
}
