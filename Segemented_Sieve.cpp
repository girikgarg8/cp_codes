#include <bits/stdc++.h>
using namespace std;
#define N 100000
//Problem PRIME1 on SPOJ
//Print all primes between numbers m and n, where maximum limit on them is 10^9
//If I construct a prime sieve of size 10^9, it woukd take 4*10^9 bytes in my system (nearly 4 GB) which will exceed the time limit and also the size of the array should not exceed 10^7 in the system
// Hence I need to use segmented sieve

//Algorithm of segmented sieve
// Let's say I have a query from m to n
// Then my segmented sieve array would be from indices 0 to n-m
// Now using the prime sieve I will find all the primes which are less than sqrt(N). This would require me to build a prime sieve of size sqrt(N)=10^5 which is acceptable
//  Once I have found out the primes less than N, then I will cross out all the multiples of these primes and the numbers left out would be prime numbers
// Space complexity analysis: building a prime sieve for sqrt(N) would be 10^5 elements and the segmented siieve would have (n-m) elements which would be 10^5 elements (given) Total space complexity would be 4*2*10^5 bytes
// The prime array would be precomputed 
int sieveArr[N+1]={0};
vector <int> primes; //using the sieve arr, I will find out the primes and then store them in the primes vector
void sieve(){
	sieveArr[2]=1;
	primes.push_back(2);
	for (long long i=3;i<=N;i+=2){
		sieveArr[i]=1;
	}
	for (long long i=3;i<=N;i++){
		if (sieveArr[i]){
			primes.push_back(i);
			for (long long j=i*i;j<=N;j+=i){
				sieveArr[j]=0;
			}
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	sieve(); //precompute the primes till N 
	int t;
	cin>>t;
	while (t--){
		int m,n;
		cin>>m>>n;
		vector <int> segment (n-m+1,0); //this is vector of size n-m+1

		for (auto p:primes){
			//stop when prime^2 >n
			if (p*p>n){
				break;
			}
			//otherwise we need to find the nearest starting point
			int start=(m/p)*p;

			//An extra optimisation to save some time
			if (p>=m && p<=n){ //if my prime lies in the range of sieve
				start=2*p;
			}
			//start marking the numbers as not prime from start
			for (int j=start;j<=n;j=j+p){
				if (j<m){
					continue; //if j is outside the range then continue
				}
				segment[j-m]=1; 
			}
			//primes stored as 0 in the segment
		}
		for (int i=m;i<=n;i++){
			if (segment[i-m]==0 && i!=1){
				cout << i <<endl;
			}
		}
		cout <<endl;
	}
}