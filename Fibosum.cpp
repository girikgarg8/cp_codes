#include <bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;
const int mod=1e9+7;
const int sz=2;
struct Mat{ //to avoid menace dur to pointers in 2D array
	int m[sz][sz];
	Mat(){
		memset(m,0,sizeof(m));
	}
	void identity(){
		for (int i=0;i<sz;i++){
			m[i][i]=1;
		}
	}
	Mat operator * (Mat a){
		Mat res;
		for (int i = 0; i < sz; i++)
		{
			for (int j=0;j<sz;j++){
				for (int k=0;k<sz;k++){
					res.m[i][j]+=m[i][k]*a.m[k][j];
					res.m[i][j]%=mod;
				}
			}
		}
		return res;
	}
};
int fib(int n){
	Mat res;
	res.identity();
	Mat T;
	T.m[0][0]=T.m[0][1]=T.m[1][0]=1;
	if (n<2) return n;
	n-=1;
	while (n){
		if (n&1) res=res*T;
		T=T*T;
		n/=2;
	}
	return (res.m[0][0])%mod;
}
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while (t--){
	int n,m;
	cin>>n>>m;
	cout << (fib(m+2)%mod-fib(n+1)%mod+mod)%mod <<endl;
	}
	return 0;
}