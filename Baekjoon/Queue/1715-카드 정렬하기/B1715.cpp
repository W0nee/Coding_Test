#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int card[100010];
int ans;

int main(void)
{
//	freopen("B1715_input.txt", "r", stdin);
	
	priority_queue<int, vector<int>, greater<int>> pq;
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> card[i];
		
		pq.push(card[i]);
	}

	while(pq.size() != 1)
	{
		int val1 = pq.top();
		pq.pop();
	
		int val2 = pq.top();
		pq.pop();
		
		int val = val1 + val2;
		pq.push(val);
		
		ans += val;
	}
	
	cout << ans;	
	
	return 0;
}
