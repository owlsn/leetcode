// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

// 你的算法时间复杂度必须是 O(log n) 级别。
// 如果数组中不存在目标值，返回 [-1, -1]。

// 示例 1:
// 输入: nums = [5,7,7,8,8,10], target = 8
// 输出: [3,4]

// 示例 2:
// 输入: nums = [5,7,7,8,8,10], target = 6
// 输出: [-1,-1]

//二分查找
//找到目标元素后，分别在左右区间继续找,直到找不到为止，最后一次记录的位置就分别为左边界和右边界


public class searchRange {

    public static void main(String[] args) {
        searchRange test = new searchRange();
        int[] nums = new int[]{1, 2, 3, 4, 4, 5, 6, 7};
        int target = 4;
        System.out.println(test.searchRange(nums, target));
    }

    public int[] searchRange(int[] nums, int target) {
        int result_left = -1,  left = 0, right = nums.length - 1, temp_left = 0;
        while(left <= right){
            temp_left = binarySearch(nums, left, right, target);
            if(temp_left != -1){
                result_left = temp_left;
                right = temp_left - 1;
            }
            else{
                break;
            }
        }

        int result_right = -1, temp_right = 0;
        left = 0; 
        right = nums.length - 1;
        while(left <= right){
            temp_right = binarySearch(nums, left, right, target);
            // System.out.println(temp_right);
            if(temp_right != -1){
                result_right = temp_right;
                left = temp_right + 1;
            }
            else{
                break;
            }
        }
        // System.out.println("result_left:" + result_left + ",result_right:" + result_right);
        return new int[]{result_left, result_right};
    }

    private int binarySearch(int nums[], int left, int right, int target){
        int mid = -1, result = -1;
        while(left <= right){
            // System.out.println("left:" + left + ",right:" + right);
            mid = (left + right) / 2;
            if(target == nums[mid]){
                // System.out.println("nums[mid]:" + nums[mid] + ",mid:" + mid);
                result = mid;
                break;
            }
            else if(target > nums[mid]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return result;
    }
}