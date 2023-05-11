//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
  /*  bool isSafe(int row,int col,int board[N][N]),int val){
        
        for(int i = 0 ; i<N;i++){
            if(board[row][i]==val)
            return false ;
            if(board[i][col]==val)
            return false ;
            if(board[3 * (row/3)+ i/3][3 *(col/3) +i%3] == val)
            return false ;
            
        }
        return true ;
    }*/
    
    bool isSafe(int row, int col, int board[N][N], int val) {
    for(int i = 0 ; i<N;i++){
        if(board[row][i]==val)
            return false ;
        if(board[i][col]==val)
            return false ;
        if(board[3 * (row/3)+ i/3][3 *(col/3) +i%3] == val)
            return false ;
    }
    return true ;
}

    bool SolveSudoku(int board[N][N])  
    { 
        for(int i = 0 ; i<N ; i++){
            for(int j=0 ; j<N;j++){
                
                if(board[i][j] == 0){
                    for(int val=1 ;val<=9;val++){
                        if(isSafe(i,j,board,val)){
                            board[i][j]=val;
                            
                        if(SolveSudoku(board)== true)  {
                             return true ;
                        } 
                       
                        else
                        board[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true ;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int board[N][N]) 
    {
        SolveSudoku(board) ;
        for(int i = 0 ;i<N;i++){
            for(int j = 0 ; j<N ;j++){
                cout<<board[i][j]<<" " ;
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends