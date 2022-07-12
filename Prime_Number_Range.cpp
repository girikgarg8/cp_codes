//Calculating prime numbers in a range eg. from 1 to 1e6 then
// Brute force will take O(n*n) time complexity
// Square root method will take O(n*root n) time complexity
// Another method prime sieve will solve it in O (n*log log n)
//Prime sieve (sieve of eratosthenes)
//An optimisation in prime sieve method is to start crossing the primes starting from p^2 instead of 2p
#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define N 1000
#define ll long long 
using namespace std;
void primeSieve(vector<int> &sieve){
	//Mark 0 and 1 as not prime
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
}
int32_t main(){
	vector <int> sieve(N,0);
	primeSieve(sieve);
	for (int i=0;i<N;i++){
	if (sieve[i])
		cout << i << " ";
    }
    return 0;
}