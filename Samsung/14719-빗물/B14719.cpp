#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int H, W;
int block[510];
vector<int> check;
pair<int, int> value[510];

int main(void)
{
//	freopen("B1062_input.txt", "r", stdin);
	
	cin >> H >> W;
	
	for(int i = 1; i <= W; i++)
	{
		cin >> block[i];
		
		value[i].first = block[i];
	}
	
	for(int i = 1; i <= W; i++)
	{
		int h = block[i];
		value[i].second = h;
		
		for(int j = i-1; j >= 1; j--)
		{
			h = max(h, value[j].first);
			value[j].second = min(h, value[j].second);
		}
		
//		for(int i = 1; i <= W; i++)
//	{
//		cout << value[i].first << " " << value[i].second << endl;
//	}
		
		h = block[i];
		
		for(int j = i; j <= W; j++)
		{
			h = max(h, value[j].first);
			value[j].second = min(h, value[j].second);
		}
		
		
		cout << "\n---------------\n";
		for(int i = 1; i <= W; i++)
		{
			cout << value[i].first << " " << value[i].second << endl;
		}
	}
	
//			for(int i = 1; i <= W; i++)
//	{
//		cout << value[i].first << " " << value[i].second << endl;
//	}
	
	
	return 0;
}
