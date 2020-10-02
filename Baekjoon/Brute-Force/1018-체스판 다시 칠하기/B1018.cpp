#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int row, col;
int Map[55][55];
int Min = 99999999;

int main(void)
{
//	freopen("B1018_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		string input;
		cin >> input;
		
		for(int j = 0; j < input.size(); j++)
		{
			Map[i][j+1] = input[j];
		}
	}
	
	for(int i = 1; i <= row-7; i++)
	{
		for(int j = 1; j <= col-7; j++)
		{
			int cnt1 = 0;
			int cnt2 = 0;
			
			for(int m = i; m < i+8; m++)
			{
				for(int n = j; n < j+8; n++)
				{
					if(m % 2 == 1 && n % 2 == 1)
					{
						if(Map[m][n] != 'B')
						{
							cnt1++;
						}
					}
					else if(m % 2 == 1 && n % 2 == 0)
					{
						if(Map[m][n] != 'W')
						{
							cnt1++;
						}
					}
					else if(m % 2 == 0 && n % 2 == 1)
					{
						if(Map[m][n] != 'W')
						{
							cnt1++;
						}
					}
					else if(m % 2 == 0 && n % 2 == 0)
					{
						if(Map[m][n] != 'B')
						{
							cnt1++;
						}
					}
					
					if(m % 2 == 1 && n % 2 == 1)
					{
						if(Map[m][n] != 'W')
						{
							cnt2++;
						}
					}
					else if(m % 2 == 1 && n % 2 == 0)
					{
						if(Map[m][n] != 'B')
						{
							cnt2++;
						}
					}
					else if(m % 2 == 0 && n % 2 == 1)
					{
						if(Map[m][n] != 'B')
						{
							cnt2++;
						}
					}
					else if(m % 2 == 0 && n % 2 == 0)
					{
						if(Map[m][n] != 'W')
						{
							cnt2++;
						}
					}
				}
			}
			
			Min = min({Min, cnt1, cnt2});
		}
	}
	
	cout << Min;
	
	return 0;
}
