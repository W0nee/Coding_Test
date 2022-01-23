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

#define INF 987654321

int N, K;
int num[200010];
int psum[200010];
map<int, long long> check;

int main(void)
{
//	freopen("B2015_input.txt", "r", stdin);
	
	long long ans = 0;
	
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
		
		psum[i] = psum[i-1] + num[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(psum[i] == K)
		{
			ans++;
		}

		// psum[i] - psum[j] = K
		ans += check[psum[i] - K];
		
		check[psum[i]]++;
	}
	
	cout << ans;
	
	return 0;
}
