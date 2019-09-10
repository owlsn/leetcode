// 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
// 必须原地修改，只允许使用额外常数空间。

// 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

//寻找到a[i-1] < a[i]的第一个i，然后将a[i-1]和后面第一个大于a[i-1]的数调换位置
//然后将a[i-1]后面的数逆序排列即可
//具体的原因是下一个排列的规律，在a[i-1] < a[i]的第一个i的时候，i-1后面的数都是有序排列的
//而将a[i-1]与a[j]调换位置之后，后面的数也都是有序排列的，但是按照大小来说，原排列的下一个排列，应该是a[i-1]换成下一个大于a[i-1]的数即a[j]
//而后面的排列是逆序的排列

public class nextPermutation {

    public static void main(String[] args) {
        nextPermutation test = new nextPermutation();
        int[] nums = new int[]{1, 2, 3, 4, 5, 6, 9, 8, 7};
        for(int i = 0; i < nums.length; i ++){
            System.out.println(nums[i]);
        }
        System.out.println("done");
        test.nextPermutation(nums);
        for(int i = 0; i < nums.length; i ++){
            System.out.println(nums[i]);
        }
    }

    public void nextPermutation(int[] nums) {
        int a = -1;
        for(int i = nums.length - 1; i > 0 ; i --){
            if(nums[i] > nums[i - 1]){
                a = i - 1;
                break;
            }
        }
        if(a != -1){
            int b = 0;
            for(int i = nums.length - 1; i >= 0; i --){
                if(nums[i] > nums[a]){
                    b = i;
                    break;
                }
            }
            swap(nums, a, b);
            reverse(nums, a + 1);
        }
        else{
            //没有修改过，没有下一个排列，那么将数组逆序就是最小排列
            reverse(nums, 0);
        }
    }

    private void swap(int[] nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    private void reverse(int[] nums, int start){
        int i = start, j = nums.length - 1;
        while(i < j){
            swap(nums, i, j);
            i ++;
            j --;
        }
    }
}