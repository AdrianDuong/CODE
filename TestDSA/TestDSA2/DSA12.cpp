#include <iostream>
using namespace std;

const int MAXN = 1e4;

int a[MAXN];

void Ba(int i, int n) 
{
    if (i >= n || a[i] == -1) return;
    (2*i+1, n);
    cout << a[i] << " ";
    Ba(2*i+2, n);
}

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
        }
        for (int i = n; i < 2*n-1; i++) 
        {
            a[i] = -1;
        }
        Ba(0,n);
        cout << endl;
    }
    return 0;
}
