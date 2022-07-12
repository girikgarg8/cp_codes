//Question is to find the number of prime numbers in range from [a,b]. There would be q queries
//A,B and Q queries upti 10^6
// Not a wise idea to make a sieve every time from A to B and then find the countof primes as the queries could be overlapping in nature
//We will precompute by building the prime sieve upto N=1e6
// Then take a prefix array where prefix[i] will store number of primes till the index i by using prefix[i]=prefix[i-1]+1; if element at index is prime (from the sieve)
// To get the number of primes in the range [A,B] we will find it as prefix[r]-prefix[l-1]
//Time complexity: O(n log log n) for sieve+ O(n) for making the prefix array + O(Q*1) for q queries for finding number of primes in the range [A,B]
#include <bits/stdc++.h>
#define ll long long
#define N 1000
using namespace std;
int solve(int A,int B){
	vector <int> sieve(N,0);
	sieve[1]=sieve[0]=0;
	sieve[2]=1;
	//Mark all odd as prime initially because these are the candidates for being prime
	for (int i=3;i<=N;i+=2){
	    sieve[i]=1;
	}
	//start from 3 and matk all multiples of ith number (prime) as not prime
	for (int i=3;i<=N;i++){
		if (sieve[i]){
			for (ll j=i*i;j<=N;j=j+i){
				sieve[j]=0; //marking j as not prime
			}
		}
	}
	vector <int> prefix(N,0);
	for (int i=1;i<N;i++){
		if (sieve[i]){
			prefix[i]=prefix[i-1]+1;
		}
		else{
		    prefix[i]=prefix[i-1];
		}
	}
	return prefix[B]-prefix[A-1];
}
int main(){
	int q;
	cin>>q;
	while (q--){
	int A,B;
	cin>>A>>B;
	cout << solve(A,B) <<endl;
}
}