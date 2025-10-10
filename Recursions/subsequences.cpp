#include<iostream>
#include<vector>
using namespace std;

void subsequence(int arr[],int index,int size,vector<vector<int>>&ans,vector<int> temp){
    if(index==size){
        ans.push_back(temp);
        return;
    }
    //not included
    subsequence(arr,index+1,size,ans,temp);
    //included
    temp.push_back(arr[index]);
    subsequence(arr,index+1,size,ans,temp);
}


int main(){
    int arr[] = {1,2};
    vector <vector<int>> ans;
    vector <int> temp;
    int n= 2;
    subsequence(arr,0,n,ans,temp);

    for(int i=0; i<ans.size();i++){
        for(int j=0; j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";   
        }
        cout<<endl;
    }
}