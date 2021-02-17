#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N, L, K;
pair<int, int> ant[100010];
int order[100010];

int main(void)
{
//	freopen("B3163_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		cin >> N >> L >> K;	
		
		for(int i = 1; i <= N; i++)
		{
			int d, n;
			cin >> d >> n;
			
			order[i] = n;
			
			ant[i].first = L - d + 1;
			ant[i].second = n;
		}
		
//		sort(ant+1, ant+N+1);
		
//		cout << ant[K].second << endl;
		while(K--)
		{
			if(a
		}

	}
	
	
	
	return 0;
}
