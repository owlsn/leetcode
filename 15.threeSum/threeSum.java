// 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
// 注意：答案中不可以包含重复的三元组。

// 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
// 满足要求的三元组集合为：
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

// 先排序，然后用双指针法
// 基准元素选择左边的元素，一开始选择中间元素为基准元素，则判断重复元素的时候会出现问题

import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.LinkedList;

public class threeSum {

    public static void main(String[] args){
        threeSum test = new threeSum();
        // int[] nums = new int[]{-2,0,1,1,2};
        // int[] nums = new int[]{0, 0, 0, 0};
        // int[] nums = new int[]{-1,0,1,2,-1,-4};
        int[] nums = new int[]{-2,0,0,2,2};
        System.out.println(test.threeSum(nums));
    }

    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        // System.out.println(Arrays.toString(nums));
        int index = 0, left = 0, right = 0;
        List<List<Integer>> result = new ArrayList<>();
        int temp = -1;
        for(int i = 0; i < nums.length; i ++){
            if(nums[i] > 0){
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            left = i + 1;
            right = nums.length - 1;
            while(left < right){
                // System.out.println("nums[i]"+i+" + nums[left]"+left+" + nums[right]"+right);
                temp = nums[i] + nums[left] + nums[right];
                if(temp > 0){
                    right --;
                }
                else if(temp < 0){
                    left ++;
                }
                else{
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    while(left < right && nums[left] == nums[left + 1]){
                        left ++;
                    }
                    while(left < right && nums[right] == nums[right - 1]){
                        right --;
                    }
                    left ++;
                    right --;
                }
            }
        }
        return result;
    }
}