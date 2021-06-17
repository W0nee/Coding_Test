#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int sum, N, M;
vector<int> A;
vector<int> B;
int visitedA[2000010];
int visitedB[2000010];
int ans;

int safe(int a, int b)
{
	if(0 <= a && a < A.size() && 0 <= b && b < B.size())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void solve(int aIdx, int bIdx, int aSum, int bSum)
{
	if(aSum + bSum == sum)
	{
		cout << aSum << " " << bSum << endl;
		ans++;
		return;
	}
	
	if(safe(aIdx, bIdx) == 0)
	{
		return;
	}
	
	if(safe(aIdx-1, bIdx) == 1 && visitedA[aIdx-1] == 0)
	{
		visitedA[aIdx-1] = 1;
		solve(aIdx-1, bIdx, aSum+A[aIdx-1], bSum);
		visitedA[aIdx-1] = 0;
	}
	
	if(safe(aIdx+1, bIdx) == 1 && visitedA[aIdx+1] == 0)
	{
		visitedA[aIdx+1] = 1;
		solve(aIdx+1, bIdx, aSum+A[aIdx+1], bSum);
		visitedA[aIdx+1] = 0;
	}
	
	if(safe(aIdx, bIdx-1) == 1 && visitedB[bIdx-1] == 0)
	{
		visitedB[bIdx-1] = 1;
		solve(aIdx, bIdx-1, aSum, bSum+B[bIdx-1]);
		visitedB[bIdx-1] = 0;
	}
	
	if(safe(aIdx, bIdx+1) == 1 && visitedB[bIdx+1] == 0)
	{
		visitedB[bIdx+1] = 1;
		solve(aIdx, bIdx+1, aSum, bSum+B[bIdx+1]);
		visitedB[bIdx+1] = 0;
	}
}

int main(void)
{
//	freopen("B2632_input.txt", "r", stdin);
	
	cin >> sum >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		int input;
		cin >> input;
		
		A.push_back(input);
	}
	
	for(int i = 1; i <= M; i++)
	{
		int input;
		cin >> input;
		
		B.push_back(input);
	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			solve(i, j, A[i], B[j]);
		}
	}
	
	cout << ans;
	
	return 0;
}
