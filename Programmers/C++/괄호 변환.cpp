#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int isRight(string p)
{
    stack<char> st;
    
    for(int i = 0; i < p.size(); i++)
    {
        if(p[i] == '(')
        {
            st.push(p[i]);
        }
        else
        {
            if(st.empty())
            {
                return 0;
            }
            
            st.pop();
        }
    }
    
    if(st.empty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEven(string p, int left, int right)
{
    int Open = 0;
    int Close = 0;
    string temp = "";
    
    for(int i = left; i <= right; i++)
    {
        if(p[i] == '(')
        {
            Open++;
        }
        else
        {
            Close++;   
        }
    }
    
    if(Open == Close)
    {
        return 1;
    }
    
    return 0;
}

string divide(string p, int left, int right)
{
    string temp = "";
    
    for(int i = left; i <= right; i++)
    {
        temp += p[i];
    }
    
    return temp;
}

string solution(string p) 
{
    if(p.empty())
    {
        return p;
    }
    
    int idx = -1;
    for(int i = 0; i < p.size(); i++)
    {
        if(isEven(p, 0, i) == 1)
        {
            idx = i;
            break;
        }
    }
    
    string u = divide(p, 0, idx);
    string v = divide(p, idx+1, p.size()-1);
    
    if(isRight(u) == 1)
    {
        return u + solution(v);
    }
    else
    {
        string nv = "(" + solution(v)  + ")";
        string nu = "";
        
        for(int i = 1; i <= u.size()-2; i++)
        {
            if(u[i] == '(')
            {
                nu += ")";
            }
            else
            {
                nu += "(";
            }
        }
        
        return nv + nu;
    }
}
