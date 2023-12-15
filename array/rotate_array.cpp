/*

189. leetcode rotate array



Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.




*/






class Solution {
public:
    void help(vector<int>& nums, int begin, int end) {
        int t = begin + end;
        for (int i = begin; i < t / 2; i++) {
            int temp = nums[i];
            nums[i] = nums[t - i - 1];
            nums[t - i - 1] = temp;
        }
    }

    void rotate(vector<int>& nums, int k) {
        
            k = k % nums.size(); //crucial
            help(nums, 0, nums.size());
            help(nums, 0, k);
            help(nums, k, nums.size());
        
        
        
    }
};
