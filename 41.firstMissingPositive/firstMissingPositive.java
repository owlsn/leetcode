
// 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

// 示例 1:
// 输入: [1,2,0]
// 输出: 3

// 示例 2:
// 输入: [3,4,-1,1]
// 输出: 2

// 示例 3:
// 输入: [7,8,9,11,12]
// 输出: 1

// 说明:
// 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。

//将数字的下标作为索引键，将值的符号作为是否存在的标识，负号表示存在，正号表示不存在

import java.lang.Math;

public class firstMissingPositive {

    public static void main(String[] args) {
        firstMissingPositive test = new firstMissingPositive();
        int[] nums = new int[]{2, 1};
        for(int i = 0; i < nums.length; i ++){
            System.out.print(nums[i] + " ");
        }
        System.out.println(" ");
        System.out.println(test.firstMissingPositive(nums));
        for(int i = 0; i < nums.length; i ++){
            System.out.print(nums[i] + " ");
        }
    }

    public int firstMissingPositive(int[] nums) {
        if(nums.length == 1){
            if(nums[0] == 1){
                return 2;
            }
            else{
                return 1;
            }
        }
        //预处理，将小于0和大于n的数都替换为1,并且判断1是否存在，如果不存在，那么结果就是1
        int flag1 = -1;
        for(int i = 0; i < nums.length; i ++){
            if(nums[i] == 1){
                flag1 = 1;
            }
            if(nums[i] <= 0 || nums[i] > nums.length){
                nums[i] = 1;
            }
        }
        if(flag1 == -1){
            return 1;
        }
        // for(int i = 0; i < nums.length; i ++){
        //     System.out.print(nums[i] + " ");
        // }
        // System.out.println(" ");
        //将存在的数都置负号,第n个数存在下标为0的位置
        for(int i = 0; i < nums.length; i ++){
            if(nums[i] > 0){
                nums[nums[i] % nums.length] = -1 * Math.abs(nums[nums[i] % nums.length]);
            }
            else if(nums[i] < 0){
                nums[-1 * (nums[i] %  nums.length)] = -1 * Math.abs(nums[-1 * (nums[i] %  nums.length)]);
            }
        }
        //从第一个元素向后，第一个大于0的数就为结果
        int flag = -1, result = 1;
        for(int i = 1; i < nums.length; i ++){
            if(nums[i] > 0){
                result = i;
                flag = 1;
                break;
            }
        }
        //如果从第一个元素到最后一个都不存在大于0的数，那么判断下标为0的元素，即第n个元素是否大于0，如果是，那么结果为n，如果不是结果为n+1
        if(flag == -1){
            if(nums[0] > 0){
                return nums.length;
            }
            else{
                return nums.length + 1;
            }
        }
        else{
            return result;
        }
    }
}