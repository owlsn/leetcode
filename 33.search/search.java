// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

// 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

// 你可以假设数组中不存在重复的元素。

// 你的算法时间复杂度必须是 O(log n) 级别。

//还是用二分法，
//先找到旋转元素，然后可以知道target在哪个区域，然后再在这个区域使用二分查找

public class search {

    public static void main(String[] args) {
        search test = new search();
        int[] nums = new int[]{6, 7, 8, 1, 2, 3, 4, 5};
        int target = 6;
        System.out.println(test.search(nums, target));
    }

    public int search(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        int index = -1, mid = -1;
        while(left < right){
            mid = (left + right) / 2;
            if(nums[mid] > nums[mid + 1]){
                index = mid;
                break;
            }
            else{
                if(nums[mid] > nums[left]){
                    left = mid;
                }
                else{
                    right = mid;
                }
            }
        }
        // System.out.println("index:" + index);
        if(index != -1){
            if(target > nums[0]){
                left = 0;
                right = index;
            }
            else if(target < nums[0]){
                left = index + 1;
                right = nums.length - 1;
            }
            else{
                return 0;
            }
        }
        else{
            left = 0;
            right = nums.length - 1;
        }
        return binarySearch(nums, left, right, target);
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