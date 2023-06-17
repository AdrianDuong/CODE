#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin >> s;
	int m;
	cin >> m;
	while (m--) 
	{
		int l, r;
		cin>> l >> r;
		bool One = true;
		for (int i=l-1, j=r-1; i<j; i++, j--)
		{
			if( s[i] != s[j]) {
				One = false;
				break;
			}
		}
		if (One) 
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}
