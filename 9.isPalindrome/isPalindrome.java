// 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

// 示例 1:
// 输入: 121
// 输出: true

// 示例 2:
// 输入: -121
// 输出: false
// 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

// 示例 3:
// 输入: 10
// 输出: false
// 解释: 从右向左读, 为 01 。因此它不是一个回文数。

//数字逆转然后判断是否相等
//负号直接判断不相等

public class isPalindrome {

    public static void main(String[] args){
        isPalindrome test = new isPalindrome();
        int num = 101;
        System.out.println(test.isPalindrome(num));
    }

    public boolean isPalindrome(int x) {
        boolean isPalindrome = false;
        if(x < 0){
            return false;
        }
        else{
            int remain = 0, num = x, result = 0;
            do{
                remain = num % 10;
                num = num / 10;
                //不会越界
                // if(result > Integer.MAX_VALUE / 10 || (result == Integer.MAX_VALUE / 10 && remain > 7)){
                //     return false;
                // }
                // if(result < Integer.MIN_VALUE / 10 || (result == Integer.MIN_VALUE / 10 && remain < -8)){
                //     return false;
                // }
                result = result * 10 + remain;
            }while(num != 0);
            if(x == result){
                return true;
            }
        }
        return isPalindrome;
    }
}