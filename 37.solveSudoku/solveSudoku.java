// 编写一个程序，通过已填充的空格来解决数独问题。

// 一个数独的解法需遵循如下规则：

// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
// 空白格用 '.' 表示。

// Note:

// 给定的数独序列只包含数字 1-9 和字符 '.' 。
// 你可以假设给定的数独只有唯一解。
// 给定数独永远是 9x9 形式的。

//使用回溯法，递归实现回溯法

public class solveSudoku {

    public static void main(String[] args) {
        solveSudoku test = new solveSudoku();
        char[][] board = 
        {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        };

        test.solveSudoku(board);

        for(int column = 0; column < 9; column ++){
            for(int row = 0; row < 9; row ++){
                System.out.print(board[row][column] + " ");
            }
            System.out.println(" ");
        }
    }

    public void solveSudoku(char[][] board) {
        //先初始化已经使用过的数字数组
        int[][] row_map = new int[9][10];
        int[][] column_map = new int[9][10];
        int[][][] table_map = new int[3][3][10];
        int digit = -1, num = 0;
        boolean row_check = true, column_check = true, table_check = true;
        for(int row = 0; row < 9; row ++){
            for(int column = 0; column < 9; column ++){
                if(board[row][column] != '.'){
                    digit = board[row][column] - '0';
                    //置1
                    row_map[row][digit] = 1;
                    column_map[column][digit] = 1;
                    table_map[row / 3][column / 3][digit] = 1;    
                }
            }   
        }
        //然后递归填充数字
        recurseSudoku(board, row_map, column_map, table_map, 0, 0);
    }

    private boolean recurseSudoku(char[][] board, int[][] row_map, int[][] column_map, int[][][] table_map, int row, int column){
        //判断一行是否遍历完成了
        if(column == 9){
            column = 0;
            row ++;
            if(row == 9){
                return true;
            }
        }
        if(board[row][column] == '.'){
            //挑选一个符合要求的数字
            for(int i = 1; i <= 9; i ++){
                if(row_map[row][i] == 0 && column_map[column][i] == 0 && table_map[row / 3][column / 3][i] == 0){
                    //置1
                    row_map[row][i] = 1;
                    column_map[column][i] = 1;
                    table_map[row / 3][column / 3][i] = 1;
                    board[row][column] = (char)(i + '0');
                    if(recurseSudoku(board, row_map, column_map, table_map, row, column + 1)){
                        return true;
                    }
                    //回溯复原
                    row_map[row][i] = 0;
                    column_map[column][i] = 0;
                    table_map[row / 3][column / 3][i] = 0;
                    board[row][column] = '.';
                }
            }
        }
        else{
            return recurseSudoku(board, row_map, column_map, table_map, row, column + 1);
        }
        return false;
    }
}
