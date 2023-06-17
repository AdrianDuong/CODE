#include<iostream>
#include<string>
using namespace std;

string F(int n) {
	if( n==0) return "A";
	if( n==1) return "B";
	return F(n-1)+F(n-2);
}

int main(){
	int t;
	cin>>t;
	while(t--) {
		int n, k;
		cin>>n>> k;
		string fn= F(n);
		int countA=0;
		for( int i=0; i<k; i++){
			if( fn[i]== 'A') countA++;
	}
	cout<<countA<<endl;
	}
	return 0;
}
