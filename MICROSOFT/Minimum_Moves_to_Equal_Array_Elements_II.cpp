/*
  *Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
  
  In one move, you can increment or decrement an element of the array by 1.
  
  Test cases are designed so that the answer will fit in a 32-bit integer.*/
 
/* Approach: 1. Sort the array , find the median and now find the absolute diff and add to the moves TC: O(nlogn) , SC: O(1)
             2. Without median, using 2pointers here 
                1st we sort the array then we place 2 pointer one at the ith * at begin & jth* at end of array
                now we'll add x to ith el & y to jth will be x=y we add to moves and 
                move i++,j--,once we reach at middle all will be equal x+y=0 
                tc:O(NlogN), SC:O(1)*/
 
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        int i = 0;
        int j = nums.size()-1;
        int moves = 0;
        while(i<j){
            moves+= nums[j]-nums[i];
            i++;
            j--;
        }
        return moves;

      // 2nd approach using median
      int n = nums.size();
      sort(begin(nums),end(nums));
      int median = nums[n/2];
      int moves = 0;
      for(auto num:nums){
        moves+=abs(num-median);
      }
      return moves;
    }
};
