#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int T;
string s;

string solve(string::iterator &it)
{
	char head = *it;
	it++;
	
	if(head == 'b' || head == 'w')
	{
		string result;
		result += head;
		return result;
	}
	
	string upLeft = solve(it);
	string upRight = solve(it);
	string downLeft = solve(it);
	string downRight = solve(it);
	
	return "x" + downLeft + downRight + upLeft + upRight;
}

int main(void)
{
//	freopen("solve_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		cin >> s;
		
		string::iterator it = s.begin();
		
		cout << solve(it) << endl;
	}
	
	return 0;
}
