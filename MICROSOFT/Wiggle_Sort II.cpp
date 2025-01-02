/* Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

You may assume the input array always has a valid answer*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        //copy array & sort
        vector<int>nums1(nums);
        sort(nums1.begin(),nums1.end());

        // initialize 3pointer i, j, k
        // i to place  from begin elements , k to place mid elements from sorted array
        // j is index where to place we traverse from last index to 1st

        int i =0 ;
        int j = n-1;
        int k = j/2+1;
        while(j>=0){
            if(j%2==1){
                //kth 
                nums[j] = nums1[k];
                k++;
            }
            else{
                nums[j] = nums1[i];
                i++;
            }
            j--;
        }
    }
};
