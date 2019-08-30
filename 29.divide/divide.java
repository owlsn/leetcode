//给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
//返回被除数 dividend 除以除数 divisor 得到的商。
//示例 1:
//输入: dividend = 10, divisor = 3
//输出: 3

//示例 2:
//输入: dividend = 7, divisor = -3
//输出: -2
//说明:
//被除数和除数均为 32 位有符号整数。
//除数不为 0。
//假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。

//题目用java实现在边界条件判断的时候很容以溢出，就是在-(2^31)这里，
//如果不在边界条件的情况下，使用正常的移位相减代替除法
//被除数为边界条件的时候，改成移位相加

public class divide {

    public static void main(String[] args) {
        divide test = new divide();
        int dividend = -1010369383;
        int divisor = -2147483648;
        System.out.println(test.divide(dividend, divisor));
    }

    public int divide(int dividend, int divisor) {
        int sign = ((dividend > 0) ^ (divisor > 0))? -1 : 1;
        int count = 0,result = 0;
        if(divisor == 1){
            return dividend;
        }
        else if(divisor == -1){
            return ((dividend < 0 && -dividend > 0) || dividend > 0)?-dividend:((1<<31) - 1);
        }
        else if(divisor == - (1 << 31)){
            return (dividend == divisor)?1:0;
        }
        else{
            if(dividend == - (1 << 31)){
                divisor = (divisor < 0) ? -divisor: divisor;
                while(divisor < (1<<30)){
                    divisor <<= 1;
                    count ++;
                }
                while((count + 1) > 0){
                    while (-divisor >= dividend){
                        result += 1 << count;
                        dividend += divisor;
                    }
                    divisor >>= 1;
                    count --;
                }
                if(sign == -1){
                    result = -result;
                }
                return (result <= (1<<31) - 1 && result >= - (1 << 31))? result:((1<<31) - 1);
            }
            else{
                dividend = (dividend < 0) ? - dividend: dividend;
                divisor = (divisor < 0) ? -divisor: divisor;
                while(divisor <= dividend && divisor < (1<<30)){
                    divisor <<= 1;
                    count ++;
                }
                while((count + 1) > 0){
                    while (dividend >= divisor){
//                        System.out.println("dividend:" + dividend + ",divisor:" + divisor);
                        result += 1 << count;
                        dividend -= divisor;
                    }
                    divisor >>= 1;
                    count --;
                }
                if(sign == -1){
                    result = -result;
                }
                return (result <= (1<<31) - 1 && result >= - (1 << 31))? result:((1<<31) - 1);
            }
        }
    }
}