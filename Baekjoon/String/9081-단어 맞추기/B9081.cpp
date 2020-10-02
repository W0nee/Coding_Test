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
		string s;
		bool flag = false;
		int stopIdx = 0;	
		
		cin >> s;
		
		for(int i = s.size()-2; i >= 0; i--)
		{
			for(int j = s.size()-1; j >= i+1; j--)
			{
				if(s[i] < s[j])
				{
					char temp = s[i];
					s[i] = s[j];
					s[j] = temp;
					
					stopIdx = i;
					flag = true;
					
					break;
				}	
			}
			
			if(flag)
			{
				sort(s.begin()+stopIdx+1, s.end());

				break;
			}
		}
		
		cout << s << "\n";
	}
	
	return 0;
}
