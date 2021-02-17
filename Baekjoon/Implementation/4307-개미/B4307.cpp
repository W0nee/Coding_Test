#include <stdio.h>
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

int T;
int L, N;
int ant[100010];

int main(void)
{
//	freopen("B5430_input.txt", "r", stdin);

	cin >> T;
	
	while(T--)
	{
		cin >> L >> N;
		
		int Short = 0;
		int Long = 0;
		
		for(int i = 1; i <= N; i++)
		{
			cin >> ant[i];
			
			int antMin = min(ant[i], L - ant[i]);
			int antMax = max(ant[i], L - ant[i]);
			
			Short = max(Short, antMin);
			Long = max(Long, antMax);
		}	
		
		cout << Short << " " << Long << endl;
	}
	
	return 0;
}
