/*TASK:
Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to 
the left of the index is equal to the sum of all the numbers strictly to the indexs right.
If the index is on the left edge of the array, then the left sum is 0 because there are no
elements to the left. This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.*/

#include <iostream>
#include <vector>
using std::cout;
using std::vector;


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Long way would be to go index by index calculating both sides of it until the sought index was found
        int arrayLength = nums.size();
        int Lsum = 0;
        int totalSum = 0;

        for (int i= 0; i < arrayLength; i++){
            totalSum+=nums[i];
        }
        for (int i = 0; i < arrayLength; i++){
            Lsum+=nums[i];
            if (totalSum-Lsum == Lsum - nums[i]) return i;            
        }
        return -1;       
    }
};


int main(){
    vector<int> arrWithoutPivotIndex{-1,-1,0,-1,-1,0};
    vector<int> arrWithPivotIndex{1,7,3,6,5,6};
    Solution sol;
    cout << "Using array without pivot index: " << sol.pivotIndex(arrWithoutPivotIndex);
    cout << "\nUsing array with pivot index: " << sol.pivotIndex(arrWithPivotIndex);
}

