/* An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells 
(i.e., the average of the nine cells in the blue smoother). 
  If one or more of the surrounding cells of a cell is not present, we do not consider it in the average 
  (i.e., the average of the four cells in the red smoother). */

    Approach: 1.We make note of all 9 directions and traverse through matrix in all directions and make sum of all values and then do avg i.e sum/count. here we check whether they are inbound and then make sum
               and strore in O(mxn) matric T.C:O(mxn) S.C : O(mxn)
              2. As we add the prev row and left of current elements value get effected. So, we just store that in 1vector and top_corner variable in other variable and then using them we make sum
                 and make change in th egiven matrix only.TC:O(mxn) , SC:O(n)
class Solution {
public:
   
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        //row size
        int m = img.size();
        //col size
        int n = img[0].size();

        vector<int>prev(n);
        int top_corner=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                int sum = 0;
                int cnt = 0;
                
                // add bottom row [i+1]
                if(i+1<m){
                   
                    if(j-1>=0){
                        sum+=img[i+1][j-1];
                        cnt++;
                    }
                    sum+=img[i+1][j];
                    cnt++;
                    if(j+1<n){
                        sum+=img[i+1][j+1];
                        cnt++;
                    }
                }
                //right neighbour
                if(j+1<n){
                   sum+=img[i][j+1];
                   cnt++; 
                }
                
                //current cell
                sum+=img[i][j];
                cnt++;

                //left cell[i][j-1]
                if(j-1>=0){
                    sum+=prev[j-1];
                    cnt++;
                }
                //top row
                if(i-1>=0){
                    //[i-1][j-1]->top_corner
                    if(j-1>=0){
                        sum+=top_corner;
                        cnt++;
                    }
                    //[i-1][j],  [i-1][j+1]
                    sum+=prev[j];
                    cnt++;

                    if(j+1<n){
                        sum+=prev[j+1];
                        cnt++;
                    }
                }
                //store prev value of prev row
                if(i-1>=0){
                    top_corner = prev[j];
                }
                // store current value of [i][j]
                prev[j]=img[i][j];

                img[i][j] = sum/cnt;
            }
        }
        return img;
    }
};

