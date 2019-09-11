// 判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

// 说明:
// 一个有效的数独（部分已被填充）不一定是可解的。
// 只需要根据以上规则，验证已经填入的数字是否有效即可。
// 给定数独序列只包含数字 1-9 和字符 '.' 。
// 给定数独永远是 9x9 形式的。

//根据规则判断即可
//一遍扫描，定义三个数组，记录已经存在的数，
//row[num][digit]=1代表第num行的digit数字已经有了
//column[num][digit]=1代表第num列的digit数字已经有了
//num = (row / 3) * 3 + column / 3表示第num个9ge
//table[num][digit]代表第num个9格的digit数字已经有了

import java.util.HashMap;

public class isValidSudoku {

    public static void main(String[] args) {
        isValidSudoku test = new isValidSudoku();
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

        System.out.println(test.isValidSudoku(board));
    }

    public boolean isValidSudoku(char[][] board) {
        int[][] row_map = new int[9][10];
        int[][] column_map = new int[9][10];
        int[][] table_map = new int[9][10];
        int digit = -1, num = 0;
        boolean row_check = true, column_check = true, table_check = true;
        for(int row = 0; row < 9; row ++){
            for(int column = 0; column < 9; column ++){
                if(board[row][column] != '.'){
                    digit = board[row][column] - '0';
                    // System.out.println("row:" + row + ",column:" + column + ",digit:" + digit);
                    //判断行列
                    if(row_map[row][digit] != 0 || column_map[column][digit] != 0){
                        // System.out.println("row or column" + ",row:" + row + ",column:" + column);
                        return false;
                    }
                    //判断9格
                    //第几个9格
                    num = (row / 3) * 3 + column / 3;
                    if(table_map[num][digit] == 1){
                        // System.out.println("table");
                        return false;
                    }
                    //置1
                    row_map[row][digit] = 1;
                    column_map[column][digit] = 1;
                    table_map[num][digit] = 1;    
                }
            }   
        }
        return true;
    }

}