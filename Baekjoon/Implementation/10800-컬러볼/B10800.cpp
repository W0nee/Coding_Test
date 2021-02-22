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

typedef struct node
{
	int n;
	int color;
	int size;
}node;

int N;
node ball[200010];
int color_sum[200010];
int size_sum[200010];
int result[200010];
int sum;

bool cmp(node a, node b)
{
	if(a.size < b.size)
	{
		return true;
	}
	else if(a.size == b.size)
	{
		if(a.color < b.color)
		{
			return true;
		}
		
		return false;
	}
	
	return false;
}

int main(void)
{
//	freopen("B10800_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		ball[i].n = i;
		
		cin >> ball[i].color >> ball[i].size;
	}
		
	sort(ball+1, ball+N+1, cmp);
	
	for(int i = 1; i <= N; i++)
	{
		// 총합 
		sum += ball[i].size;
		
		// 같은사이즈 
		size_sum[ball[i].size] += ball[i].size;	
		// 같은색깔 
		color_sum[ball[i].color] += ball[i].size;	
		
		result[ball[i].n] = sum -  size_sum[ball[i].size] - color_sum[ball[i].color] + ball[i].size;
		if(ball[i-1].size == ball[i].size && ball[i-1].color == ball[i].color)
		{
			result[ball[i].n] = result[ball[i-1].n];
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		cout << result[i] << "\n";
	}	
	
	return 0;
}
