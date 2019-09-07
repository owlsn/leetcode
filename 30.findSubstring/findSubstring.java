//给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
//注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

//示例 1：
//输入：
//s = "barfoothefoobarman",
//words = ["foo","bar"]
//输出：[0,9]
//解释：
//从索引 0 和 9 开始的子串分别是 "barfoor" 和 "foobar" 。
//输出的顺序不重要, [9,0] 也是有效答案。

//示例 2：
//输入：
//s = "wordgoodgoodgoodbestword",
//words = ["word","good","best","word"]
//输出：[]

// "wordgoodgoodgoodbestword"
// ["word","good","best","good"]

//根据words数组中的字符串的长度，分为[0,,,word.length]组
//每一组都按照word.length进行移动，
//使用两个hashmap来判断子字符串中是否是符合要求的字串，先将words数组中的字符串都存在wordsmap中，有多个的值记录为个数
//existmap记录比较过程中的子字符，然后比较两个map中对应的key的数量，如果小于等于，则说明符合要求，如果不存在key或者existmap中的值大雨wordsmap，
//则说明该字串已经不符合要求的，就移动窗口从下一个开始查找

import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.HashMap;

public class findSubstring {

    public static void main(String[] args) {
        findSubstring test = new findSubstring();
        String s = "wordgoodgoodgoodbestword";
        String[] words = new String[]{"word", "good", "best", "good"};
        System.out.println(test.findSubstring(s, words));
    }

    public List<Integer> findSubstring(String s, String[] words) {
        if(s == "" || words.length == 0){
            return new ArrayList<Integer>();
        }
        HashMap<String, Integer> wordsMap = new HashMap<String, Integer>();
        HashMap<String, Integer> exist = new HashMap<String, Integer>();
        for(int i = 0; i < words.length; i ++){
            wordsMap.put(words[i], (wordsMap.containsKey(words[i]))?wordsMap.get(words[i]) + 1:1);
        }
        // for(String key : wordsMap.keySet()){
        //     System.out.println(key + ":" + wordsMap.get(key));
        // }
        int wordLength = words[0].length();
        ArrayList<Integer> result = new ArrayList<Integer>();
        for(int i = 0; i < wordLength; i ++){
            int left = i;
            // System.out.println("left:" + left + ",right:" + (left + words.length * wordLength) + ",s length:" + s.length());
            while(left + words.length * wordLength <= s.length()){
                exist.clear();
                for(int start = left; start < left + words.length * wordLength; start += wordLength){
                    String str = s.substring(start, start + wordLength);
                    if(wordsMap.containsKey(str)){
                        // System.out.println("wordsmap contains:" + str);
                        if(exist.containsKey(str)){
                            if(exist.get(str) < wordsMap.get(str)){
                                // System.out.println(str + "exist " + exist.get(str) + " ,wordsmap " + wordsMap.get(str));
                                exist.put(str, exist.get(str) + 1);
                            }
                            else{
                                //出现重复的字符串，需要将字符串从重复的位置左移一个单位长度
                                left = left + wordLength;
                                // System.out.println(str + " exists, restart at " + left);
                                break;
                            }
                        }
                        else{
                            exist.put(str, 1);
                        }
                    }
                    else{
                        left = start + wordLength;
                        break;
                    }
                    if(start + wordLength == left + words.length * wordLength){
                        result.add(start + wordLength - words.length * wordLength);
                        left = start + wordLength - words.length * wordLength + wordLength;
                        break;
                    }
                }
            }
        }
        return result;
    }
}