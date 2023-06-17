#include <bits/stdc++.h>

using namespace std;

int Testcase(){
	int n,m; 
	cin>>n>>m;
	vector<string> maze(n);
	for ( int i=0; i<n; i++) {
		cin>>maze[i];
	}
	int count=0;
	for ( int i=0; i<n; i++) {
		for( int j=0; j<n; j++) {
			if( maze[i][j]== '#') {
				if(( i==0 || maze[i-1][j]=='.') && (j==0 || maze[i][j-1]== '.')) {
					count++;
				}
			}
		}		
	}
	cout<<count<<endl;
	return count;
}
int main(){
	int T;
	cin>>T;
	while(T--){
	Testcase();
	}
	return 0;
}
