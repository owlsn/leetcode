// 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

// candidates 中的每个数字在每个组合中只能使用一次。

// 说明：
// 所有数字（包括目标数）都是正整数。
// 解集不能包含重复的组合。 

// 示例 1:
// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
// 所求解集为:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]

// 示例 2:
// 输入: candidates = [2,5,2,1,2], target = 5,
// 所求解集为:
// [
//   [1,2,2],
//   [5]
// ]

//和上一道题同理，不过这里数字是能使用一次
//数字只能是有一次的判断方式,当i何pre相等的时候就跳过

import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

public class combinationSum2 {

    public static void main(String[] args) {
        combinationSum2 test = new combinationSum2();
        int[] candidates = new int[]{10, 1, 2, 1, 6, 6, 7, 5};
        int target = 8;
        List<List<Integer>> result = test.combinationSum2(candidates, target);
        System.out.println("result.size:" + result.size());
        for(int i = 0; i < result.size(); i ++){
            for(int j = 0; j < result.get(i).size(); j ++){
                System.out.print(result.get(i).get(j) + " ");
            }
            System.out.println(" ");
        }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        Arrays.sort(candidates);
        recurseMinus(candidates, target, 0, list, result);
        return result;
    }

    public void recurseMinus(int[] candidates, int target, int pre, List<Integer> list, List<List<Integer>> result){
        if(target == 0){
            // System.out.println("target = 0");
            result.add(new ArrayList<>(list));
            return;
        }
        // System.out.println("target:" + target);
        for(int i = pre; i < candidates.length; i ++){
            if(target - candidates[i] >= 0){
                //判断元素是否重复
                if(i > pre && candidates[i] == candidates[i - 1]){
                    continue;
                }
                list.add(candidates[i]);
                recurseMinus(candidates, target - candidates[i], i + 1, list, result);
                list.remove(list.size() - 1);
            }
        }
    }
}
