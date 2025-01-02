/* A subarray of nums is called incremovable if nums becomes strictly increasing on removing the subarray. 
  
  For example, the subarray [3, 4] is an incremovable subarray of [5, 3, 4, 6, 7] because removing this subarray changes the array [5, 3, 4, 6, 7] to [5, 6, 7] which is strictly increasing.

   Return the total number of incremovable subarrays of nums.
    
  Note that an empty array is considered strictly increasing.*/
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int last = -1;// to track last element
                bool flag = true;
                //loop to check each element within or outside of subarray
                for(int k=0;k<n;k++){
                    if(k>=i && k<=j){
                        //elements within subarray are skipped
                        continue;
                    }
                    if(last>=nums[k]){
                        flag = false;
                        break;
                    }
                    last = nums[k];
                }
                if(flag) cnt++;
            }
        }
        return cnt++;
    }
};
