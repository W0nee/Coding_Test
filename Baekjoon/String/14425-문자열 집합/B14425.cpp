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
int cnt;

class trie
{
	public: 
		trie *child[26];
		bool finish;
		
	public:
		trie()
		{
			for(int i = 0; i < 26; i++)
			{
				child[i] = NULL;
			}	
			finish = false;
		}	
		
		void insert(string &word, int idx)
		{
			if(idx == word.size())
			{
				finish = true;
				return;
			}
			
			int now = word[idx] - 'a';
			
			if(child[now] == NULL)
			{
				child[now] = new trie();
			}
			child[now]->insert(word, idx+1);
		}
		
		bool find(string &word, int idx)
		{
			if(idx == word.size())
			{
				if(finish)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			
			int now = word[idx] - 'a';
			
			if(child[now] == NULL)
			{
				return false;
			}
			
			return child[now]->find(word, idx+1);
		}
};

int main(void)
{
//	freopen("B14425_input.txt", "r", stdin);
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
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
