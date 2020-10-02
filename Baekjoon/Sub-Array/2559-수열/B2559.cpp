#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int psum[100010];
int Max = -999999999;

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
	
	for(int i = K; i <= N; i++)
	{
		Max =  max(Max, psum[i] - psum[i-K]);
	}
	
	cout << Max;
	
	return 0;
}
