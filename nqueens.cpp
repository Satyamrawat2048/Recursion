#include<bits/stdc++.h>
using namespace std;

    bool issafe(int row,int col, vector<string > board, int n)
    { //check upper diag
        int duprow=row ;
        int dupcol=col;
            
            while(row>=0 && col>=0)
            {
                if(board[row][col]=='Q')return false ;
                row--;col--;
            }
        col=dupcol ;
        row=duprow ;
        while(col>=0 )
        {
            if(board[row][col]=='Q') return false ;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(row<n && col>=0)
        {
           if(board[row][col]=='Q') return false ;
            row++;
            col--;
        }
        return true ;
    }
    void solve(int col ,vector<string> &board,vector<vector<string>>&ans, int n)
    {  if(col==n)
        {
            ans.push_back(board) ;
            return ;
        }
        for(int row=0;row<n ; row++)
        {
            if(issafe(row,col,board,n))
            {
                board[row][col]='Q';
                solve(col+1, board, ans , n);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>> ans ;
        vector<string> board(n);
        
        string s(n,'.');
        for(int i=0  ; i< n; i++)
            board[i]=s ;
        
        solve(0,board,ans,n);
        return ans ;
 }
   
int main(){
    vector<vector<string>> s= solveNQueens(4);

    for(auto i:s)
    {
        for(auto j:i)
        cout<<j<<' ';
        cout<<endl ;
    }
 return 0;
}
//optimised
// void solve(int col ,vector<string> &board,vector<vector<string>>&ans,vector<int>&left,vector<int>&upper,vector<int>&lower, int n)
//     {
//         if(col==n)
//         {
//             ans.push_back(board) ;
//             return ;
//         }
//         for(int row=0;row<n ; row++)
//         {
//             if(left[row]==0 &&lower[row+col]==0 &&upper[n-1+col-row]==0)
//             {
//                 board[row][col]='Q';
//                 left[row]=1 ;
//                 lower[row+col]=1 ;
//                 upper[n-1+col-row]=1 ;
                
//                 solve(col+1,board,ans,left,upper,lower,n) ;
//                 board[row][col]='.';
//                 left[row]=0;
//                 lower[row+col]=0;
//                 upper[n-1+col-row]=0;
//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(int n) {
//          vector<vector<string>> ans ;
//         vector<string> board(n);
//         string s(n,'.');
        
//         for(int i=0  ; i< n; i++)
//         {
//             board[i]=s ;
//         }
//        vector<int> left(n,0),upperdiag(2*n-1,0),lowerdiag(2*n-1,0) ;

//         solve(0,board,ans,left,upperdiag,lowerdiag,n);
//         return ans ;
//     }