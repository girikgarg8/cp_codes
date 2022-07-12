//Question of the type Ax+By=GCD(a,b)  --> equation 1
// Solving this type of equation will have two applications
// Solving linear diophantine equations
// Finding multiplicative modulo inverse
// From euclid's algorithm GCD(a,b)=GCD(b,a%b)
// Hence Bx1 + (A%b) y1= GCD (B,A%B)
// Also we did one formula for a%b
// B x1 + (A-floor(a/b)*b)y1=gcd(a,b)
// B (x1-floor(A/B)*y1)+Ay1=GCD (A,B) -->equation 2

//On comparing the coefficient of A and B we get
// x=y1 and
// y=x1- floor(a/b)*y1
// This is the result of extended euclidean algorithm
// eg. 18x+30y=gcd(18,30)
#include <bits/stdc++.h>
using namespace std;
vector <int> extenedGCD(int a,int b){
	//We are reducing the equations in the steps, in the base case we will have b=0 as we had in the case of gcd
	if (b==0){
		//The situation would be like ax=a
		// so we can see that x=1 and y=0
		return {1,0,a}; //the third parameter a is the gcd in the base when b==0
	}
	vector <int>result=extenedGCD(b,a%b);
	//This is a bottom up way of this question as we are doing the calculations after recursive call is over
	int smallX=result[0];
	int smallY=result[1];
	int gcd=result[2];
	int x=smallY;
	int y=smallX-(a/b)*smallY;
	return {x,y,gcd};
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int a,b;
	cin>>a>>b;
	//ax+by=gcd(a,b)
	int x,y;
	vector <int> result=extenedGCD(a,b);
	cout << result[0] << " and " << result[1] <<endl;
	cout << "GCD is " << result[2] <<endl;
	return 0; 
}