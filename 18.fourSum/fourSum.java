// 给定一个包含 n 个整数的数组 nums 和一个目标值 target，
// 判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

// 注意：
// 答案中不可以包含重复的四元组。

// 示例：
// 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
// 满足要求的四元组集合为：
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]


// 和之前的三数之和类似
// 先将数组排序，取基准元素后，调用三数之和算法，然后将得到的结果合并

import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;

public class fourSum {

    public static void main(String[] args){
        fourSum test = new fourSum();
        int[] nums = new int[]{1,-2,-5,-4,-3,3,3,5};
        int target = -11;
        System.out.println(test.fourSum(nums, target));
    }

    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> list= new ArrayList<>();
        List<List<Integer>> result= new ArrayList<>();
        for(int i = 0; i < nums.length; i ++){
            if(nums[i] > target && nums[i] > 0){
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int index = i + 1;
            list = threeSum(Arrays.copyOfRange(nums, index, nums.length), target - nums[i]);
            for(int j = 0; j < list.size(); j ++){
                if(list.get(j).size() > 0){
                    // System.out.println(Arrays.asList(nums[i], list.get(j).get(0), list.get(j).get(1), list.get(j).get(2)));
                    result.add(Arrays.asList(nums[i], list.get(j).get(0), list.get(j).get(1), list.get(j).get(2)));
                }
                // result.add(list.get(j));
            }
        }
        return result;
    }

    public List<List<Integer>> threeSum(int[] nums, int target) {
        Arrays.sort(nums);
        // System.out.println(Arrays.toString(nums));
        int index = 0, left = 0, right = 0;
        List<List<Integer>> result = new ArrayList<>();
        int temp = -1;
        for(int i = 0; i < nums.length; i ++){
            if(nums[i] > target && nums[i] > 0){
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
                if(temp > target){
                    right --;
                }
                else if(temp < target){
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