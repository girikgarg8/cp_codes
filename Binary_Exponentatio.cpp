#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a,long long int b){
	long long int res=1;
	while (b){
		if (b&1)
			res=res*a;
		a=a*a;
		b/=2; //or right shift b
	}
	return res;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int a,b;
	cin>>a>>b;
	cout << power(a,b);
}