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

int S;

queue<pair<int, int>> q; // view, clip
int visited[1010][1010] = {0};

void BFS()
{	
	q.push({1, 0});
	visited[1][0] = 1;
	
	while(!q.empty())
	{
		int view = q.front().first;
		int clip = q.front().second;
		q.pop();
		
//		cout << view << " " << clip << endl;
		
		if(view == S)
		{
			cout << visited[view][clip] - 1;
			break;
		}
		
		for(int i = 1; i <= 3; i++)
		{
			int nview = view;
			int nclip = clip;
			
			if(i == 1) nclip = view;
			else if(i == 2) nview += clip;
			else if(i == 3) nview -= 1;
			
			if(!(1 <= nview && nview <= 1000))
			{
				continue;
			}
			
			if(visited[nview][nclip] == 0)
			{
				q.push({nview, nclip});
				visited[nview][nclip] = visited[view][clip] + 1;
			}
		}
	}
}

int main(void)
{
//	freopen("B14226_input.txt", "r", stdin);
	
	cin >> S;
	
	BFS();
	
	return 0;
}
