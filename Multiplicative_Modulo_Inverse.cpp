// Mult. modulo inverse 
// Given two integers a and m, find modular multiplicative inverse of a under modulo 'm'. The MMI is an integer x such that
// ax congruent modulo 1 mod m
// In other words I can say that (a*x)%m==1
//One thing to note here is that x would be in the range 1 to m-1 as we are doing modulo m
// eg. if a=6 and m=7
// (6*x)%7 ==1 By brute force solution we can see x=6
// MMI will exist iff a and m are relatively prime i.e. gcd(a,m)=1

//Algorithm for MMI using Extended Eucid's algorithm
// ax+by=gcd(a,b)
// replace b=m in the equation
//ax+my=gcd(a,m)
// ax+my=1 Now take modulo m on both sides
// (ax)%m =1 or ax congr modulo 1 mod m
// Hence to find the MMI, I need to find the solution to ax+my=1 which can be solved using extended euclidean algorithm I would get x(which would be the MMI) and y though found is no required
#include <bits/stdc++.h>
using namespace std;
//Code for MMI
vector <int> extendedGCD(int a,int b){
	//We are reducing the equations in the steps, in the base case we will have b=0 as we had in the case of gcd
	if (b==0){
		//The situation would be like ax=a
		// so we can see that x=1 and y=0
		return {1,0,a}; //the third parameter a is the gcd in the base when b==0
	}
	vector <int>result=extendedGCD(b,a%b);
	//This is a bottom up way of this question as we are doing the calculations after recursive call is over
	int smallX=result[0];
	int smallY=result[1];
	int gcd=result[2];
	int x=smallY;
	int y=smallX-(a/b)*smallY;
	return {x,y,gcd};
}
int modInverse(int a,int m){
	vector <int> result=extendedGCD(a,m);
	int x=result[0];
	int gcd=result[2];
	if (gcd!=1){
		cout << "Multiplicative modulo incerse doesn't exist";
		return -1;
	}
	int ans=(x%m+m)%m; //x which is returned from the extended Euclid algorithm can be nagtive also, so we have to make it positive 
	return ans;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int a,m;
	cin>>a>>m; //should be relatively prime
	cout << modInverse(a,m) <<endl;
}