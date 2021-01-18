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

int L, C;
vector<string> alphabet;

void solve(int idx, int cnt, int mo, int ja, string word)
{
	if(cnt == L)
	{
		if(mo >= 1 && ja >= 2)
		{
			cout << word << "\n";	
		}
		
		return;
	}
	
	for(int i = idx; i < alphabet.size(); i++)
	{
		if(alphabet[i] == "a" || alphabet[i] == "e" || alphabet[i] == "i" || alphabet[i] == "o" || alphabet[i] == "u")
		{
			solve(i+1, cnt+1, mo+1, ja, word+alphabet[i]);
		}
		else
		{
			solve(i+1, cnt+1, mo, ja+1, word+alphabet[i]);
		}
	}
}

int main(void)
{
//	freopen("B1759_input.txt", "r", stdin);

	cin >> L >> C;
	
	for(int i = 1; i <= C; i++)
	{
		string input;
		cin >> input;
		
		alphabet.push_back(input);
	}
	
	sort(alphabet.begin(), alphabet.end());
	
	solve(0, 0, 0, 0, "");
	
	return 0;
}
