#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(string s) 
{
    int Min = 987654321;
    
    for(int k = 1; k <= s.size()/2 + 1; k++)
    {
        vector<string> temp;
        string result = "";
        int idx = 0;
        
        while(idx <= s.size()-1)
        {
            temp.push_back(s.substr(idx, k));
            idx += k;
        }
        
        int cnt = 1;
        
        for(int i = 0; i < temp.size()-1; i++)
        {
            if(temp[i] == temp[i+1])
            {
                cnt++;        
            }
            else
            {
                if(cnt == 1)
                {
                    result += temp[i];    
                }
                else
                {
                    result += to_string(cnt) + temp[i];            
                }
        
                cnt = 1;
            }
        }
        if(cnt == 1)
        {
            result += temp[temp.size()-1];    
        }
        else
        {
            result += to_string(cnt) + temp[temp.size()-1];            
        }
        
        Min = min(Min, (int)result.size());
    }
    
    return Min;
}
