#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>> t;
    cin.ignore();
    while (t--) 
    {
        string out;
        getline(cin, out);
        stack<int> s;
        for (int i = 0; i<out.length();i++) 
        {
            if (out[i]== '(') 
            {
                s.push(i);
            } 
            else if (out[i]==')') 
            {
                if (!s.empty()) 
                {
                    int start= s.top();
                    s.pop();
                    out[start]= '0';
                    out[i]= '1';
                } 
                else 
                {
                    out[i]= '-1';
                }
            }
        }
        while (!s.empty()) {
            int start = s.top();
            s.pop();
            out[start] = '-1';
        }
        cout << out<< endl;
    }
    return 0;
}
