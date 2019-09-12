// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

// 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

// 示例:

// 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出: 6

//和之前的判断最大储水量的题目有类似之处
//使用双指针

public class trap {

    public static void main(String[] args) {
        trap test = new trap();
        int[] nums = new int[]{0,1,0,2,1,0,1,3,2,1,2,1};
        System.out.println(test.trap(nums));
    }

    public int trap(int[] height) {
        int left = 0, right = height.length - 1, left_max = 0, right_max = 0;
        int count = 0;
        while(left <= right){
            if(left_max < right_max){
                if(height[left] > left_max){
                    left_max = height[left];
                }
                else{
                    if(left_max != 0){
                        count += left_max - height[left];
                        // System.out.println("count:"+count+",left_max"+left_max+",height[left]:" + height[left]);
                    }
                }
                left ++;
            }
            else{
                if(height[right] > right_max){
                    right_max = height[right];
                }
                else{
                    if(right_max != 0){
                        count += right_max - height[right];
                        // System.out.println("count:"+count+",right_max"+right_max+",height[right]:" + height[right]);
                    }
                }
                right --;
            }
        }
        return count;
    }
}