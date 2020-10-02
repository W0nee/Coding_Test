#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct HORSE
{
	int pos;
	bool ten;
	bool twenty;
	bool thirty;	
}HORSE;

int order[11]; 
int dice[11];
int Map[40][10];
int Max = 0;

int check_same(HORSE horse[5])
{
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			if(i != j)
			{
				if(horse[i].pos == horse[j].pos && horse[i].pos > 0)
				{
					return 1;
				}
			}
		}
	}
	
	return 0;
}

int cal()
{
	HORSE horse[5];
	int score = 0;
	for(int i = 1; i <= 4; i++)
	{
		horse[i].pos = 0;
		horse[i].ten = false;
		horse[i].twenty = false;
		horse[i].thirty = false;
	}
	
	for(int i = 1; i <= 10; i++)
	{
		// 도착한 말을 다시 고르는 경우
		if(horse[order[i]].pos == -1)
		{
			return 0;
		}
		
		if(horse[order[i]].ten)
		{
			int findIdx = 0;
			for(int k = 1; k <= 7; k++)
			{
				if(horse[order[i]].pos == Map[10][k])
				{
					findIdx = k;	
				}	
			}	
			
			if(findIdx+dice[i] >= 8)
			{
				horse[order[i]].pos = -1;
				continue;	
			}
			
			if(Map[10][findIdx+dice[i]] >= 100)
			{
				horse[order[i]].pos = Map[10][findIdx+dice[i]];	
				score += horse[order[i]].pos / 10;
				
			}
			else
			{
				horse[order[i]].pos = Map[10][findIdx+dice[i]];	
				score += horse[order[i]].pos;
			}
		}
		else if(horse[order[i]].twenty)
		{
			int findIdx = 0;
			for(int k = 1; k <= 6; k++)
			{
				if(horse[order[i]].pos == Map[20][k])
				{
					findIdx = k;	
				}	
			}	
			
			if(findIdx+dice[i] >= 7)
			{
				horse[order[i]].pos = -1;
				continue;	
			}
			
			if(Map[20][findIdx+dice[i]] >= 100)
			{
				horse[order[i]].pos = Map[20][findIdx+dice[i]];	
				score += horse[order[i]].pos / 10;
				
			}
			else
			{
				horse[order[i]].pos = Map[20][findIdx+dice[i]];	
				score += horse[order[i]].pos;
			}
		}
		else if(horse[order[i]].thirty)
		{
			int findIdx = 0;
			for(int k = 1; k <= 7; k++)
			{
				if(horse[order[i]].pos == Map[30][k])
				{
					findIdx = k;	
				}	
			}	
			
			if(findIdx+dice[i] >= 8)
			{
				horse[order[i]].pos = -1;
				continue;	
			}
			
			if(Map[30][findIdx+dice[i]] >= 100)
			{
				horse[order[i]].pos = Map[30][findIdx+dice[i]];	
				score += horse[order[i]].pos / 10;
				
			}
			else
			{
				horse[order[i]].pos = Map[30][findIdx+dice[i]];	
				score += horse[order[i]].pos;
			}
		}
		else
		{
			horse[order[i]].pos += 2*dice[i];
			if(horse[order[i]].pos > 40)
			{
				horse[order[i]].pos = -1;
				continue;
			}

			score += horse[order[i]].pos;
			
			if(horse[order[i]].pos == 10) horse[order[i]].ten = true;
			else if(horse[order[i]].pos == 20) horse[order[i]].twenty = true;
			else if(horse[order[i]].pos == 30) horse[order[i]].thirty = true;
		}
		
		// 같은 곳에 말이 있는 경우 
		if(check_same(horse))
		{
			return 0;	
		}
	}
	
	return score;
}

void DFS(int cnt)
{
	if(cnt == 11)
	{
		Max = max(cal(), Max);
		
		return;
	}
	
	for(int i = 1; i <= 4; i++)
	{
		order[cnt] = i;
		DFS(cnt+1);	
	}
}

int main(void)
{
//	freopen("B17825_input.txt", "r", stdin);
	
	Map[10][1] = 13, Map[10][2] = 160, Map[10][3] = 19, Map[10][4] = 25, Map[10][5] = 300, 
	Map[10][6] = 35, Map[10][7] = 40;
	
	Map[20][1] = 220, Map[20][2] = 240, Map[20][3] = 25, Map[20][4] = 300, Map[20][5] = 35,
	Map[20][6] = 40;
	
	Map[30][1] = 280, Map[30][2] = 27, Map[30][3] = 260, Map[30][4] = 25, Map[30][5] = 300,
	Map[30][6] = 35, Map[30][7] = 40;
	
	
	for(int i = 1; i <= 10; i++)
	{
		cin >> dice[i];
	}
	
	DFS(1);
	
	cout << Max;
	
	return 0;
}
