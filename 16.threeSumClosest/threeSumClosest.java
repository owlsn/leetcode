// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

// 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
// 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

// 和上题差不多，先对数组排序，然后确定一个基准元素后用双指针法
// 当最后判断结果的时候，如果和大于最小的值就可以直接跳过了

import java.lang.Math;
import java.util.Arrays;

public class threeSumClosest {

    public static void main(String[] args){
        threeSumClosest test = new threeSumClosest();
        int[] nums = new int[]{0,1,2};
        int target = 3;
        System.out.println(test.threeSumClosest(nums, target));
    }

    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        // System.out.println(Arrays.toString(nums));
        int left = 0, right = 0;
        int temp = 0, result = 0, pre = Integer.MAX_VALUE;
        for(int i = 0; i < nums.length; i ++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            left = i + 1;
            right = nums.length - 1;
            while(left < right){
                temp = nums[i] + nums[left] + nums[right];
                // System.out.println("nums[i]"+i+" + nums[left]"+left+" + nums[right]"+right +"temp" +temp+ "Math.abs(temp - target)"+Math.abs((temp - target)));
                if(Math.abs((temp - target)) < Math.abs(pre)){
                    // System.out.println(temp);
                    pre = Math.abs((temp - target));
                    result = temp;
                }
                if(temp > target){
                    right --;
                }
                else if(temp < target){
                    left ++;
                }
                else{
                    return temp;
                }
            }
        }
        return result;
    }
}