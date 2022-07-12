#include <bits/stdc++.h>
using namespace std;
//This is a prefix trie i.e. it will store all the prefixes of my current string andf if I need to perform any operation on prefixes of string,I can use prefix trie
class TrieNode{
	bool isTerminal;
	TrieNode * child[26];
	// char ch;--->this is not required because character is indicatd by the varibale i which ranges from 0 to 25
public:
	TrieNode(){
		isTerminal=false;
		for (int i=0;i<26;i++){
			child[i]=NULL;
		}
	}
};
class Trie{
private:
TrieNode *root;
public:
Trie(){
	root=new TrieNode();
}
bool search(string str){
	TrieNode *temp;
	




	





	
}













};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
}