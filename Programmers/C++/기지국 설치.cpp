#include <iostream>
#include <vector>
using namespace std;

int answer = 0;

void cal(int cnt, int divide)
{
    if(cnt > 0)
    {
        if(cnt % divide == 0)
        {
            answer += cnt / divide;
        }
        else
        {
            answer += cnt / divide + 1;
        }   
    }
}

int solution(int n, vector<int> stations, int w)
{
    for(int i = 0; i < stations.size(); i++)
    {
        int val = stations[i];
        
        if(i == 0)
        {
            int first = 1;
            int last = val - w - 1;
            
            int cnt = last - first + 1;
            int divide = 2 * w + 1;
            
            cal(cnt, divide);
        }
        else
        {
            int first = stations[i-1] + w + 1;
            int last = val - w - 1;
            
            int cnt = last - first + 1;
            int divide = 2 * w + 1;
            
            cal(cnt, divide);
        }
    }
    
    int first = stations[stations.size()-1] + w + 1;
    int last = n;
    
    int cnt = last - first + 1;
    int divide = 2 * w + 1;
    
    cal(cnt, divide);

    return answer;
}
