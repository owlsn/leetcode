// 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
// 坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
// 说明：你不能倾斜容器，且 n 的值至少为 2。

// 示例:
// 输入: [1,8,6,2,5,4,8,3,7]
// 输出: 49

//最直接的方式就是循环遍历数组，两两坐标计算水的容量

//双指针法的原理需要推导理解
//双指针法由短向长移动不会漏掉最优解的原因是因为
//s(ij)表示ij围成的面积，s(ij) = (j - i) * min(height[i], height[j])
//当heigth[i] < height[j]时,
//如果j--,s(i(j-1))=(j-1-i)*min(height[i],height[j-1])<=(j-1-i)*height[i]
//s(ij)=(j-i)*heigth[i]=(j-i-1)*heigth[i]+heigth[i]>=(j-1-i)*height[i]>=s(i(j-1))
//所以对于j--这一分支,面积是肯定小于s(ij)的，那么就只用考虑i++这一分支
//同理,当heigth[i] > height[j]时，就只用考虑j--这一分支

import java.lang.Math;

public class maxArea {

    public static void main(String[] args){
        maxArea test = new maxArea();
        int[] height = new int[]{1,8,6,2,5,4,8,3,7};
        System.out.println(test.maxArea(height));
    }

    // public int maxArea(int[] height) {
    //     int max = 0, temp = 0;
    //     for(int i = 0 ; i < height.length; i ++){
    //         for(int j = i + 1 ; j < height.length; j ++){
    //             temp = (j - i) * Math.min(height[i], height[j]);
    //             if(temp > max){
    //                 max = temp;
    //             }
    //         }
    //     }
    //     return max;
    // }

    public int maxArea(int[] height) {
        int max = 0, temp = 0, left = 0, right = height.length - 1;
        while(left < right){
            temp = (right - left) * Math.min(height[left], height[right]);
            if(temp > max){
                max = temp;
            }
            if(height[left] < height[right]){
                left ++ ;
            }
            else{
                right -- ;
            }
        }
        return max;
    }
}