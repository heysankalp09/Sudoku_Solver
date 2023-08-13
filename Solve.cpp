#include<iostream>
#include<math.h>
using namespace std;

void Print(int board[][9],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isValid(int board[][9],int i, int j, int num, int n){

for( int x=0;x<n;x++){
    if(board[i][x]==num || board[x][j]==num){
        return false;
    }
}
    int rn = sqrt(n);
    int si = i - i % rn;
    int sj = j - j % rn;

    for(int x=si;x<si+rn;x++){
        for(int y=sj;y<sj+rn;y++){
            if(board[x][y]==num){
                return false;
            }
        }
    }
    return true;

}

bool SudokuSolver(int board[][9],int i,int j,int n){

    if(i==n){
        Print(board,n);
        return true;
    }

    if(j==n){
        return SudokuSolver(board,i+1,0,n);
    }

    if(board[i][j]!=0){
        return SudokuSolver(board,i,j+1,n);
    }

    for(int num=1;num<=9;num++){
        if(isValid(board,i,j,num,n)){
            board[i][j]=num;
            bool subAns = SudokuSolver(board,i,j+1,n);
            if(subAns){
                return true;
            }
        board[i][j]=0;

        }
    }
    return false;

}

