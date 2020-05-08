/*
  Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

  You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty())
            return -1;
        int res = nums[0], count = 1;
        for(int i=1; i<nums.size();i++){
            if(nums[i]==res)
                count++;
            else
                count--;
            if(count < 0){
                res = nums[i];
                count = 0;
            }
        }
        return res;
        
    }
};
