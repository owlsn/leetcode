// 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的数字可以无限制重复被选取。

// 说明：
// 所有数字（包括 target）都是正整数。
// 解集不能包含重复的组合。 

// 示例 1:
// 输入: candidates = [2,3,6,7], target = 7,
// 所求解集为:
// [
//   [7],
//   [2,2,3]
// ]

// 示例 2:
// 输入: candidates = [2,3,5], target = 8,
// 所求解集为:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]

//采用回溯法，依次用target减去所有的数，并且下次减的数不能比此次小
//如果target减到0说明符合要求，将存在stack中的数存入结果列表
//如果target<0则需要回溯

import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

public class combinationSum {

    public static void main(String[] args) {
        combinationSum test = new combinationSum();
        int[] candidates = new int[]{2,3,6,7};
        int target = 7;
        List<List<Integer>> result = test.combinationSum(candidates, target);
        System.out.println("result.size:" + result.size());
        for(int i = 0; i < result.size(); i ++){
            for(int j = 0; j < result.get(i).size(); j ++){
                System.out.print(result.get(i).get(j) + " ");
            }
            System.out.println(" ");
        }
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
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
                list.add(candidates[i]);
                recurseMinus(candidates, target - candidates[i], i, list, result);
                list.remove(list.size() - 1);
            }
        }
    }
}