// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.





#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize two arrays to store products to the left and right of each element
        vector<int> leftProducts(n, 1);
        vector<int> rightProducts(n, 1);
        
        // Calculate products to the left of each element
        int leftProduct = 1;
        for (int i = 0; i < n; ++i) {
            leftProducts[i] = leftProduct;
            leftProduct *= nums[i];
        }
        
        // Calculate products to the right of each element
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            rightProducts[i] = rightProduct;
            rightProduct *= nums[i];
        }
        
        // Calculate the final result by multiplying left and right products
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = leftProducts[i] * rightProducts[i];
        }
        
        return result;
    }
};
