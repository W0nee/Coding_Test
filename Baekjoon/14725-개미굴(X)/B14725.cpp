#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

typedef struct node
{
	map<string, node*> child;
}node;

int N;
node *tree = new node();
node *cur;

void DFS(node *cur, int depth)
{
	map<string, node*>::iterator iter;
	for(iter = cur->child.begin(); iter != cur->child.end(); iter++)
	{
		for(int i = 0; i < depth; i++)
		{
			cout << "--";
		}
		
		cout << iter->first << endl;
		DFS(iter->second, depth+1);
	}
}

int main(void)
{
//	freopen("B14725_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{	
		cur = tree;
		
		int cnt;
		cin >> cnt;

		for(int j = 0; j < cnt; j++)
		{
			string word;
			cin >> word;
			
			if(cur->child.find(word) == cur->child.end())
			{
				node *newNode = new node();
				cur->child.insert({word, newNode});	
				cur = newNode;
			}
			else
			{
				cur = cur->child[word];
			}
		}
	}
	
	DFS(tree, 0);
	
	return 0;
}
