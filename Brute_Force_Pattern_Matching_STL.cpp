/*
Sequence in which the topics will be discussed:
brute force string matching
trie data structure
pattern matching using trie
polynomial hash function
rolling hash function
rabin-karp algorithm
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	string text="ababaababbbbabaaa";
	string pat="aba";
	int m=pat.size();
	int n=text.size();
	for (int i=0;i+m<=n;i++){ //i+m<=n because when I want a substring of length m....I can start at max from the index n-m
		if (text.substr(i,m)==pat){
			cout << "Substring found starting at index "<< i << "\n";
		}
	}
	return 0;
	//Time complexity: O(m) for substring and I am doing the substring (n-m) times....so total time complexity is O((n-m)*m)
	//Maximum possible value of this time complexity would be when n=2m and in that case it would be O(n^2/4)
}