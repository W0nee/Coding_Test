#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
vector<int> xpos;
vector<int> ypos;
int ans;

int main(void) 
{
//	freopen("B7571_input.txt", "r", stdin);

	cin >> N >> M;
	
	for(int i = 1; i <= M; i++)
	{
		int x, y;
		cin >> x >> y;
		
		xpos.push_back(x);
		ypos.push_back(y);
	}
	
	sort(xpos.begin(), xpos.end());
	sort(ypos.begin(), ypos.end());	
	

	int x = xpos[M/2];
	int y = ypos[M/2];
	
	for(int i = 0; i < xpos.size(); i++)
	{
		ans += abs(xpos[i]-x);
	}
	
	for(int i = 0; i < ypos.size(); i++)
	{
		ans += abs(ypos[i]-y);
	}
	
	cout << ans;
	
	return 0;
}

