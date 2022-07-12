#include <bits/stdc++.h>
using namespace std;
#define N 10000
void factorisation_brute(int n){ 
	for (int i=2;i<=n;i++){ //O(n) approach, in case n is prime this loop will run n times
		if (n%i==0){
			int cnt=0;
			while (n%i==0){
				n=n/i;
				cnt++;
			}
			cout << i << "^" <<cnt << ",";
		}
	}
}
void factorisation_optimised(int n){
	//Optimisation is for eg.99 then after finding 3 and 3 we are left with 11 ad in the brute force apporach we are running the loop from i=3 to i=11 for n=11
	//However if a number is composite then we will always find a prime factor which would be less than or equal to square root n, so we will run the loop till square root n instead of n
	// After the loop ends, if n is not equal to 1, then it means that n is itself a prime number and we will print that number
	for (int i=2;i*i<=n;i++){ //O(n) approach, in case n is prime this loop will run n times
		if (n%i==0){
			int cnt=0;
			while (n%i==0){
				n=n/i;
				cnt++;
			}
			cout << i << "^" <<cnt << ",";
		}
	}
	if (n!=1){
		cout << n << "^"<<"1";
	} //Time complexity of this method is O(square root n)
}
void factorisation_using_sieve(int n){
	//we will construct an array using the sieve
	// at each array location we will store the minimum prime factor of that number 
	vector <int> sieve(n+1,0);
	vector <int> primes;
	sieve[1]=sieve[0]=0;
	sieve[2]=1;
	//Mark all odd as prime initially because these are the candidates for being prime
	for (int i=3;i<=n;i+=2){
	    sieve[i]=1;
	}
	//start from 3 and matk all multiples of ith number (prime) as not prime
	for (int i=3;i<=n;i++){
		if (sieve[i]){
			for (int j=i*i;j<=n;j=j+i){
				sieve[j]=0; //marking j as not prime
			}
		}
	}
	for (int i=2;i<=n;i++){
		if (sieve[i])
		primes.push_back(i);
	}
	for (int i=2;i<=n;i++){
	    sieve[i]=INT_MAX;
	}
	for (int p=0;p<primes.size();p++){
		sieve[primes[p]]=primes[p];
		for (int j=primes[p]*primes[p];j<=n;j+=primes[p]){
		    if (primes[p]<sieve[j])
			sieve[j]=primes[p];
		}
	}

	while (n!=1){
		cout << sieve[n] <<",";
		n/=sieve[n];
	} //Complexity of this approach for Q queries: time complexity of while loop to reduce number to 1 is log n for 1 query hence for Q queries it would be Q logn + n log log n for precomputation
}
int main(){
	int n;
	cin>>n;
	factorisation_using_sieve(n);
	return 0;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	factorisation_using_sieve(n);
	return 0;
}