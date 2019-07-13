// 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
// 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
// 你可以假设 nums1 和 nums2 不会同时为空。

// 示例 1:
// nums1 = [1, 3]
// nums2 = [2]
// 则中位数是 2.0

// 示例 2:
// nums1 = [1, 2]
// nums2 = [3, 4]
// 则中位数是 (2 + 3)/2 = 2.5

//nums1和nums2有序
//若先将两个数组合并，则时间复杂度至少为O(m+n)
//采用二分查找的方式
//中位数的位置是将num1和num2划分为数字个数相等的两部分part1和part2，并且有max(part1) < min(part2)
//则根据这个等式条件可以由num1的一个位置i确定num2的一个位置j
//条件为：i + j = num1.length - i + num2.length - j ( + 1)
//相对应的num1和num2也会被分为两部分，假设为num1A，num1B和num2A，num2B，(都有可能为空)
//那么有max(num1A) < min(num2B)和max(num1B) < min(num2A)
//根据上述条件，则可以依次搜索符合要求的中位数
//首先根据划分为相等的两部分的要求，获得对应的划分
//然后根据是否满足划分条件判断是否为所要求的数
//搜索过程可以用二分法进行
//最终的结果如果numA.length + numB.length是奇数，那么，中位数就是max(part1)
//如果是偶数，则是(max(part1) + min(part2))/2

import java.lang.Math;

class findMedianSortedArrays {

     public static void main(String[] args){
        findMedianSortedArrays test = new findMedianSortedArrays();
        // int[] nums1 = new int[]{1, 3};
        // int[] nums2 = new int[]{2};

        int[] nums1 = new int[]{};
        int[] nums2 = new int[]{1};

        System.out.print(test.findMedianSortedArrays(nums1, nums2));
    }

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] numsA = nums1;
        int[] numsB = nums2;
        if(nums1.length > nums2.length){
            numsB = nums1;
            numsA = nums2;
        }
        int min = 0, max = numsA.length, len = (numsA.length + numsB.length + 1)/2;
        int j = 0, i = 0;
        double result = 0.0;
        while(min <= max){
            i = (min + max) / 2;
            j = len - i;
            //i过大
            if(i > min && numsA[i - 1] > numsB[j]){
                max = i - 1;
            }
            //i过小
            else if(i < max && numsA[i] < numsB[j - 1]){
                min = i + 1;
            }
            //i为中位数位置
            else{
                int maxLeft = 0;
                if(i == 0){
                    maxLeft = numsB[j - 1];
                }
                else if(j == 0){
                    maxLeft = numsA[i - 1];
                }
                else{
                    maxLeft = Math.max(numsB[j - 1], numsA[i - 1]);
                }
                if((numsA.length + numsB.length) % 2 == 1){
                    return maxLeft;
                }

                int minRight = 0;
                if(i == numsA.length){
                    minRight = numsB[j];
                }
                else if(j == numsB.length){
                    minRight = numsA[i];
                }
                else{
                    minRight = Math.min(numsA[i], numsB[j]);
                }
                
                result = (minRight + maxLeft) / 2.0;
                return result;
            }
        }
        return result;
    }
}