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

int M, N;
int larva[1000010];

int main(void)
{
//	freopen("B10836_input.txt", "r", stdin);
	
	cin >> M >> N;
	
	for(int i = 1; i <= N; i++)
	{
		int zero, one, two;
		cin >> zero >> one >> two;
		
		for(int j = zero+1; j <= zero+one; j++)
		{
			larva[j]++;
		}
		
		for(int j = zero+one+1; j <= 2*M-1; j++)
		{
			larva[j] += 2;
		}
	}
	
	for(int i = M; i >= 1; i--)
	{
		cout << 1 + larva[i] << " ";
		
		for(int j = M+1; j <= 2*M-1; j++)
		{
			cout << 1 + larva[j] << " ";
		}
		
		cout << endl;
	}
	
	return 0;
}
