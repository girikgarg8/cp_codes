#include <bits/stdc++.h>
#include <ctime>
#include <algorithm>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	auto start_time=clock();
	int n;
	cin>>n;
	int *arr=new int [n];
	for (int i=0;i<n;i++){
		arr[i]=i;
	}
	sort(arr,arr+n);
	auto end_time=clock();
	cout << "Time taken is " << end_time-start_time <<endl;
	return 0;
}