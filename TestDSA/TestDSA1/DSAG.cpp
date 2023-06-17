#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll k, f[93], f2[93];
ll solve(int n, ll k)
{
	if (n==0) return 1;
	if (n==1) return 0;
	if (k<f[n]) return solve(n-1, k);
	return f2[n-1]+solve( n-2, k-f[n]);
}
int main() {
	int t;
	cin>>t;
	f[0]=0; f[1]=1;
	for(int i=2; i<93; i++)
	f[i]=f[i-1]+f[i-2];
	f2[0]=1; f2[1]=0; f2[2]=1; f2[3]=1;
	for( int i=4; i<93;i++)
	f2[i]=f2[i-1] + f2[i-2];
	while(t--)
	{
		cin>>n>>k;
		cout<<solve(n, k)<<endl;
	}
}
