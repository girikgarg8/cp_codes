#include <bits/stdc++.h>
const int mod=1e9+7;
using namespace std;
long long int multiply(long long int a,long long int b,long long int c){
	long long int res=0;
	while (b){
		if (b&1){
			res=res+a;
			res=res%c;
		}
		a=2*a;
		a=a%c;
		b/=2; //or right shift b
	}
	return res;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int a,b,c;
	cin>>a>>b>>c;
	cout << multiply(a,b,c);
}