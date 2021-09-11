#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;  //max array size
int phs[N];   //to keep track of plus values
int mhs[N];   //to keep track of minus value

vector<int> hashSort(vector<int> arr){

	for(int i=0;i<arr.size();++i){    //hashing the input array
		if(arr[i]<0){
			mhs[(-arr[i])] += 1;
		}else{
			phs[arr[i]] += 1;
		}
	}

	vector<int> sorted; 
	for(int i=N-1;i>=0;--i){   //sorting the minus values
		if(mhs[i] > 0){
			for(int j=0;j<mhs[i];j++){
				sorted.push_back(-i);
			}
		}
	}

	for(int i=0;i<N;++i){     //sorting the plus values
		if(phs[i] > 0){
			for(int j=0;j<phs[i];j++){
				sorted.push_back(i);
			}
		}
	}
	return sorted;
}

int main(){
	int n; cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	arr = hashSort(arr);
	for(auto elements : arr){
		cout<<elements<<" ";
	}
}
