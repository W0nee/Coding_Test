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

#define INF 987654321;

int N, K;
int psum[100010];
int Max = -INF;

int main(void)
{
//	freopen("B2559_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		
		psum[i] = psum[i-1] + num;
	}
	
	int left = 0;
	int right = K;
	
	while(right <= N)
	{
//		cout << left << " " << right << endl;
		Max = max(Max, psum[right++] - psum[left++]);
	}
	
	cout << Max;
	
	return 0;
}
