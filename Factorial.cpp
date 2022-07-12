#include <bits/stdc++.h>
using namespace std;
//Factorial of a large number

void multiply(vector <int> &a,int no,int &size){
	int carry=0;
	for (int i=0;i<size;i++){
		int product=a[i]*no+carry;
		a[i]=product%10;
		carry=product/10;
	}
	//to handle the carry
	while (carry){
		a[size]=carry%10;
		carry=carry/10;
		size=size+1;
	}
}
void bigFactorial(int n){
	vector <int> a(1000,0); //right now assuming that factorial will be at most 1000 digits
	a[0]=1; //0 factorial is one
	int size=1; //size of the factorial value generated so far
	for (int i=2;i<=n;i++){
		multiply(a,i,size);
	}
	//Print the result in reverse order
	for (int i=size-1;i>=0;i--){
		cout << a[i];
	}
	cout <<endl;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	bigFactorial(n);
}