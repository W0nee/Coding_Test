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

map<char, pair<int, int>> key;
char l, r;
string s;
int ans;

int main(void)
{
//	freopen("B20436_input.txt", "r", stdin);
	
	key['q'] = {0, 0}, key['w'] = {0, 1}, key['e'] = {0, 2}, key['r'] = {0, 3}, key['t'] = {0, 4}, 
	key['y'] = {0, 5}, key['u'] = {0, 6}, key['i'] = {0, 7}, key['o'] = {0, 8}, key['p'] = {0, 9},
	key['a'] = {1, 0}, key['s'] = {1, 1}, key['d'] = {1, 2}, key['f'] = {1, 3}, key['g'] = {1, 4},
	key['h'] = {1, 5}, key['j'] = {1, 6}, key['k'] = {1, 7}, key['l'] = {1, 8}, 
	key['z'] = {2, 0}, key['x'] = {2, 1}, key['c'] = {2, 2}, key['v'] = {2, 3}, key['b'] = {2, 4},
	key['n'] = {2, 5}, key['m'] = {2, 6};
	
	cin >> l >> r >> s;
	
	for(int i = 0; i < s.size(); i++)
	{
		int x = key[s[i]].first;
		int y = key[s[i]].second;
		
		if((x == 0 && 0 <= y && y <= 4) || (x == 1 && 0 <= y && y <= 4) || (x == 2 && 0 <= y && y <= 3))
		{
			int x1 = key[l].first;
			int y1 = key[l].second;
			
			ans += abs(x-x1) + abs(y-y1) + 1;
			
			l = s[i];
		}
		else
		{
			int x1 = key[r].first;
			int y1 = key[r].second;
			
			ans += abs(x-x1) + abs(y-y1) + 1;
			
			r = s[i];
		}
	}
	
	cout << ans;
	
	return 0;
}
