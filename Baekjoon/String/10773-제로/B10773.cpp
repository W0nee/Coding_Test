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

int N;
stack<int> st;
int ans;

int main(void)
{
//	freopen("B10773_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		
		if(num == 0)
		{
			st.pop();
		}
		else
		{
			st.push(num);
		}
	}
	
	while(!st.empty())
	{
		ans += st.top();
		st.pop();	
	}
	
	cout << ans;
	
	return 0;
}
