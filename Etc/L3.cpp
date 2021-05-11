#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int in[1010];
int out[1010];
int inRoom[1010];
vector<int> room;
int inIdx;
int meet[1010];

void enter(int x)
{
	inRoom[x] = 1;
	
	for(int i = 0; i < room.size(); i++)
	{
		meet[room[i]]++;
	}
	meet[x] = room.size();
	
	room.push_back(x);	
}

void leave(int x)
{
	for(int i = 0; i < room.size(); i++)
	{
		if(room[i] == x)
		{
			room.erase(room.begin() + i);
			break;
		}
	}
}

int main(void)
{
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> in[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		cin >> out[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		int cur_out = out[i];
		
		// 방에 있어야 나감 
		while(inRoom[cur_out] == 0)
		{
			enter(in[++inIdx]);
		}
		
		leave(cur_out);
	}
	
	for(int i = 1; i <= N; i++)
	{
		cout << meet[i] << " ";
	}
 	
	return 0;
}

