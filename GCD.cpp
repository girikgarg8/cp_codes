#include <bits/stdc++.h>
using namespace std;
//GCD of two numbers a and b eg. 8 and 20
//Brute force way: Iterate from all numbers starting from 2 till min (a,b) 
//Complexity: O(min(a,b))

//Algorithm to calculate GCD
// Euclid Division Algorithm eg. GCD of 12 and 20
// 20=1*12+8
// 12=1*8+4
// 8= 2*4+0 
// 4=x*0+8
// stop here as remainder is zero, and divisor at this stage is the GCD of both the numbers
// Recursive defintion of Euclid division algorithm: GCD(a,b)=GCD(b,a%b);
// Base case is hit at the last step when  GCD(a,0)=a

int gcd(int a,int b){
	if (b==0){
		return a;
	}
	return gcd(b,a%b);
}
//Time complexity of this algorithm would be 
// First thing to note is that as I am doing modulo b so my number would lie betwen 0 to b-1
// Second thing to note is that a%b can be written in the form Dividend-Divisor*Quotient or a-b*floor (a/b)
// So the conclusion would be that 0<x<b-1 and x<=a-b
// adding these two inequlities I would get 2x<=a-1 or 2x<a or x<a/2
// Now gcd (a,b)=gcd (b,a%b)~=gcd (b,a/2)=gcd (a/2,a/2%b)
// Hence in two steps I am reducing the problem of gcd (a,b) to half gcd (a/2,a/2%b)
// Hence conversion of a to a/2 to a/4 and so on will take place in O(log a ) time

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int a,b;
	cin>>a>>b;
	cout << gcd(a,b);
	return 0;
}