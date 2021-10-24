
//Problem Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>res;
        int left=0,right=numbers.size()-1;
        while(left<=right)
        {
            if(numbers[left]+numbers[right]==target)
            {
                res.push_back(left+1);
                res.push_back(right+1);
                break;
            }
            else if(numbers[left]+numbers[right]>target)
            {
                right--;
            }
            else
                left++;
        }
        return res;
    }
};