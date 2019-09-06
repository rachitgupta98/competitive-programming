
#include <bits/stdc++.h> 
using namespace std;

int main(){
    
    int n=5;
    int arr[n] = {2,4,6,1,4};
    
    vector<vector<int>>R(n);
    R[0].push_back(arr[0]);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if((arr[i] > arr[j]) && (R[i].size() < R[j].size()+1)){
                R[i] = R[j];
            }
        }
        R[i].push_back(arr[i]);
    }
    // extracting the bigger size arr in adjacency list
    vector<int>res = R[0];
    for(vector<int>x : R){
        if(x.size() > res.size()){
            res = x;
        }
    }
    // output the longest increasing subsequence
    for(auto y : res){
        cout<< y <<" ";
    }
    return 0;
}