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
int N;

class trie 
{
	public:
		trie *child[26];
	
	public:
		trie()
		{
			for(int i = 0; i < 26; i++)
			{
				child[i] = NULL;		
			}
		}		
		
		int toNum(char c)
		{
			if('A' <= c && c <= 'Z')
			{
				return c - 'A';
			}
			else
			{
				return c - 'a';
			}
		}
		
		void insert(string &word, int idx)
		{
			if(idx == word.size())
			{
				return;
			}
			
			int now = word[idx] - '0';
			
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
				for(int i = 0; i <= 9; i++)
				{
					if(child[i] != NULL)
					{
						return true;
					}
				}
				
				return false;
			}
			
			int now = word[idx] - '0';
			
			if(child[now] == NULL)
			{
				return false;
			}
			
			return child[now]->find(word, idx+1);
		}	
};

int main(void)
{
//	freopen("B5052_input.txt", "r", stdin);
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> T;
	
	while(T--)
	{
		trie *root = new trie();
		string phone[10010];
		bool Find = false;
		
		cin >> N;
		
		for(int i = 1; i <= N; i++)
		{
			cin >> phone[i];
			
			root->insert(phone[i], 0);
		}	
		
		for(int i = 1; i <= N; i++)
		{
			if(root->find(phone[i], 0))
			{
				Find = true;
				break;
			}
		}
		
		if(Find)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
	}
	
	return 0;
}
