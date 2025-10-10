/*

No obstacles
only right and down movement is allowed
we are counting no of ways

*/



#include<iostream>
#include<vector>
using namespace std;

void helper(vector<vector<int>> &mat,int r,int c,string path,vector<string> &ans){
    int n = mat.size();
    if(r<0 ||c<0||r>=n || c>=n-1 || mat[r][c]==0) return;

    if(r== n-1 && c==n-1){
        ans.push_back(path);
        return;
    }
    mat[r][c] = -1;

    helper(mat,r+1,c,path+"D",ans);
    helper(mat,r-1,c,path+"U",ans);
    helper(mat,r,c-1,path+"L",ans);
    helper(mat,r,c+1,path+"R",ans);
    mat[r][c] = 1;
}

vector<string> findpath(vector<vector<int>> &mat){
    int n = mat.size();

    vector<string> ans;
    string path="";

    helper(mat,0,0,path,ans);

    return ans;
}



int main(){
    vector<vector<int>> mat ={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    
    vector<string> ans =  findpath(mat);
    for(string path:ans){
        cout<<path<<endl;
    }
}