class Solution {
    static int flag = 0;
    public void solveSudoku(char[][] board) {
        solve(board, 0, 0);
    }

    public void solve(char[][] board, int row, int col){

        // Base Case hit then do flag = 1 (to stop all pending calls)
        if(row == 9)
        {
            flag = 1;
            return;
        }

        if(board[row][col] != '.')                  // if element prefilled then skip
        {
            if(col != 8)
                solve(board, row, col+1);
            else
                solve(board, row+1, 0);
        }

        else{
            for(char ch='1'; ch<='9'; ch++){
                flag=0;
                if(isValid(board, row, col, ch)){
                    board[row][col] = ch;
                    if(col != 8)
                        solve(board, row, col+1);
                    else
                        solve(board, row+1, 0);

                    if(flag == 1) return;           // Agar poora shi se fill jaye to exit (Solution found)
                    
                    board[row][col] = '.';          // Backtracking    
                }
            }
        }
    }
    public boolean isValid(char[][] board, int row, int col, char num){
        // check row;
        for(int j=0; j<9; j++)
            if(board[row][j] == num) return false;
        
        // check column
        for(int i=0; i<9; i++)
            if(board[i][col] == num) return false;

        // check 3 x 3 grid
        int sr = row/3*3;
        int sc = col/3*3;
        for(int i=sr; i<sr+3; i++){
            for(int j=sc; j<sc+3; j++)
                if(board[i][j] == num) return false;
        }
        return true;
    }
}