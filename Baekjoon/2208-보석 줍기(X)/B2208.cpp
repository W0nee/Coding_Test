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

int N, M;

int solve(int )

int main(void)
{
//	freopen("B2208_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	trie *root = new trie();
	
	for(int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		
		root->insert(s, 0);
	}
	
	for(int i = 1; i <= M; i++)
	{
		string check;
		cin >> check;
		
		if(root->find(check, 0))
		{
			cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}
