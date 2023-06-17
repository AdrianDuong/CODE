#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	cin>> n >> q;
	vector<int> bits(n,0);
	while (q--) {
		int x,y;
		cin >> x >> y;
		for( int i=x-1; i<y; i++){
			bits[i] = 1-bits[i];
		}
	}
	for( int i=0; i<n; i++) {
		cout << bits[i] << " ";
	}
	cout << endl;
	return 0;
}
