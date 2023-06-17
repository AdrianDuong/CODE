#include <bits/stdc++.h>
using namespace std;

void print(string pre, string remain) {
	if( remain.size()==0) {
		if( pre[0] != 0) {
				cout<<pre<<endl;
		}
	return;
}
	for( int i=0; i<remain.size(); i++) {
		string new_remain = remain.substr( 0, i) + remain.substr(i+1);
		print( pre + remain[i], new_remain);
	}
	}
int main(){
	int t;
	cin>>t;
	while(t--) {
		string n1, n2;
		cin>>n1>>n2;
		sort(n.begin(), n.end());
		print("", n);
	}
	return 0;
}
