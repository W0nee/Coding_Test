#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int num;
int cnt;

int main(void)
{
//	freopen("B17618_input.txt", "r", stdin);
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin >> num;
	
	for(int k = 1; k <= num; k++)
	{
		string tempNum = to_string(k);
		int divide = 0;
		
		for(int i = 0; i < tempNum.size(); i++)
		{
			divide += (tempNum[i] - '0');
		}	
		
		if(k % divide == 0)
		{
			cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}
