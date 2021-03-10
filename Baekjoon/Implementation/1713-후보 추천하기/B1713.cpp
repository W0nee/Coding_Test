#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node
{
	int cnt;
	int order;
	int num;
}node;

int N, M;
int order;
deque<node> frame;
map<int, int> check;
vector<int> result;

bool cmp(node a, node b)
{
	if(a.cnt < b.cnt)
	{
		return true;
	} 
	else if(a.cnt == b.cnt)
	{
		if(a.order < b.order)
		{
			return true;
		}
		
		return false;
	}
	
	return false;
}

int main(void)
{
//	freopen("B1713_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= M; i++)
	{
		int num;
		cin >> num;
		
		// 이미 사진틀에 걸려있는 경우 
		if(check[num] != 0)
		{
			for(int i = 0; i < frame.size(); i++)
			{
				if(frame[i].num == num)
				{
					frame[i].cnt++;
					break;
				}
			}
			
			continue;
		}
		
		// 비어있는 사진틀이 있는 경우
		if(frame.size() < N)
		{
			frame.push_back({++check[num], ++order, num});
		}
		// 비어있는 사진틀이 없는 경우
		else
		{
			sort(frame.begin(), frame.end(), cmp);
			
			check[frame[0].num] = 0;
			frame.pop_front();
			
			frame.push_back({++check[num], ++order, num});
		}
	}
	
	for(int i = 0; i < frame.size(); i++)
	{
		result.push_back(frame[i].num);
	}
	
	sort(result.begin(), result.end());
	
	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	
	return 0;
}
