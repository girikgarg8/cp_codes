#include <bits/stdc++.h>
#define int long long int
const int N=1e5;
const int m=7;
using namespace std;
int fact[N];
int addm(int x,int y){
	return (x%m+y%m)%m;
} //Time complexity:O(1)
int subm(int x,int y){
	return ((x-y)%m+m)%m;
} //O(1) time complexity
int mulm(int x,int y){
	return ((x%m)*(y%m))%m;
} //O(1) time complexity
int powr(int x,int y){
	int res=1;
	while (y){
		if (y&1) res=mulm(res,x);
		y/=2;
		x=mulm(x,x);
	}
	return res;
} //O (log y) time complexity
int inv(int x){
	return powr(x,m-2);
} //uses the power function which has log y complexity
int divm(int x,int y){
	//For finding divison modulo, fermat's little theorem comes handy
	// Fermat's theorem says that a^p == a mod m where p is a prime number
	// dividing both sides by a : a^(p-1) == 1 mod m
	//again dividing both sides by a : a^(p-2) == a inverse mod m
	// from here I get a inverse mod m as a^(p-2) mod m
	// Hence (x/y)%m is (x mod m* y inverse mod m)%m = (x%m * y^(p-2)%m)%m
	// The part y^(p-2) will be calculated using fast exponentiation method

	return mulm(x,inv(y));
} 
 //log y time complexity
void calculate_factorial_under_mod(){
	fact[0]=1;
	for (int i=1;i<N;i++){
		fact[i]=mulm(fact[i-1],i);
	}
} //O(N) time complexity
int ncr(int n,int r){
	//ncr is n!/ (n-r)! r! so taking it modulo p would be (n!%p)*(r! inverse %p) * ((n-r)! inverse %p)%p
	return mulm(mulm(fact[n],inv(fact[r])),inv(fact[n-r]));
} //log y+log y gives log y time complexity
int32_t main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	// cout << addm(3,5) <<endl;
	// cout <<subm(3,5) <<endl;
	// cout << mulm(324,324) <<endl;
	// cout << divm(56,2) <<endl;
	calculate_factorial_under_mod();
	// cout << fact[5] <<endl;
	cout << ncr(5,2) <<endl;
	return 0;
}