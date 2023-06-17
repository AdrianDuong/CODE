#include<bits/stdc++.h>
using namespace std;
void pre(string &a)
{
	int n=a.size();
	while(true)
	{
		int x=0;
		while (a[x]=='0') x++;
		for( int i=x; i<n; i++) 
		cout<<a[i];
		cout<<endl;
		int k,l;
		for( k=n-2; k>=0; k--)
			if (a[k]<a[k+1]) 
			break;
			if(k<0) break;
			for (l=n-1; l>k; l--)
			if( a[k]<a[l]) break;
			swap(a[k],a[l]);
			for( int i=k+1, j=n-1; i<j; i++, j--) swap( a[i],a[j]);
	}
}
main()
{
	int t; 
	cin>>t;
	while(t--) {
		string s;
		cin>>s;
		sort(s.begin(), s.end());
		pre(s);
	}
}
