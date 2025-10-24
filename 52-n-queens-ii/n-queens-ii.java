class Solution {
    public int totalNQueens(int n) {
        List<List<String>>ans =  new ArrayList<>();
        char[][] board = new char[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                board[i][j] = '.';
            }
        }
        Queens(board, 0, ans);
        return ans.size();
    }
    private void Queens(char[][] board, int row, List<List<String>>ans){
        int n = board.length;

        if(row == n){
            List<String>collection = new ArrayList<>();
            for(int i=0; i<n; i++){
                String str = "";
                for(int j=0; j<n; j++){
                    str += board[i][j];
                }
                collection.add(str);
            }
            ans.add(collection);
        }

        for(int j=0; j<n; j++){
            if(isSafe(board, row, j)){
                board[row][j] = 'Q';

                Queens(board, row+1, ans);

                board[row][j] = '.';               // backtracking
            }
        }
    }
    public boolean isSafe(char[][] board, int row, int col){
        int n = board.length;

        // Check vertical (North and South)
        for(int i=0; i<n; i++)
        {    if(board[i][col] == 'Q')
                return false;
        }

        // check horizontal (West and East)
        for(int j=0; j<n; j++)
        {    if(board[row][j] == 'Q') 
                return false;
        }

        // CHECKING DIAGONALS
            
            // 1. North West
            int i=row, j=col;
            while(i>=0 && j>=0){
                if(board[i][j] == 'Q') return false;
                i--;
                j--;
            }
            
            // 2. North East
            i=row;
            j=col;
            while(i>=0 && j<n){
                if(board[i][j] == 'Q') return false;
                i--;
                j++;
            }

            // 3. South West
            i=row;
            j=col;
            while(i<n && j>=0){
                if(board[i][j] == 'Q') return false;
                i++;
                j--;
            }

            // 4. South East
            i=row;
            j=col;
            while(i<n && j<n){
                if(board[i][j] == 'Q') return false;
                i++;
                j++;
            }
        
        return true;
    }
}


