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

int N;
int num[2010];
vector<int> answer;

int main(void)
{
//	freopen("B1253_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	
	sort(num+1, num+N+1);
	
	for(int i = 1; i <= N; i++)
	{
		int left = 1;
		int right = N;
		
		while(left < right)
		{	
			if(num[left] + num[right] < num[i])
			{
				left++;
			}
			else if(num[left] + num[right] > num[i])
			{
				right--;
			}
			else if(num[left] + num[right] == num[i])
			{
				if(left == i)
				{
					left++;
				}
				else if(right == i)
				{
					right--;
				}
				else
				{
					answer.push_back(num[i]);
					break;	
				}
			}	
		}	
	}
	
	cout << (int)answer.size();
	
	return 0;
}
