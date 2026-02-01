// Leetcode 31 : Next Permutation
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        //finding pivot
        for(int i = n - 2; i >= 0; i--){ 
            if(nums[i] < nums[i + 1]){
                pivot = i;
                break;
            }
        }

        //if array is in descending order
        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        //finding the element next greater than pivot and swapping
        for(int i = n - 1; i > pivot; i--){
            if(nums[i] > nums[pivot]){
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        //reversing the suffix
        reverse(nums.begin() + pivot + 1, nums.end());
        return;
    }

    void nextPermutation1(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
        return;
    }
};