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

int T;

int main(void)
{
//	freopen("B9081_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		string s, next;
		
		cin >> s;
		
		next = s;
		
		if(next_permutation(next.begin(), next.end()))
		{
			cout << next << "\n";
		}
		else
		{
			cout << s << "\n";
		}
	}
	
	return 0;
}
