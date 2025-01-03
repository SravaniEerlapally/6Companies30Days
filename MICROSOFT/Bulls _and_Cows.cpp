Approach:
1-Counting Bulls (Correct Digit in Correct Position)
2-Counting Cows (Correct Digit in Wrong Position):
  a) If the digits are not bulls (not in the correct position), update counts for each digit in separate arrays (arr1 and arr2).
  b) arr1 keeps track of the count of digits in the secret number (excluding bulls).
  c) arr2 keeps track of the count of digits in the guessed number (excluding bulls).
  d) After processing all digits, count the cows by summing the minimum count of each digit in arr1 and arr2.
3.By taking the minimum of arr1[i] and arr2[i] for each digit i, we are essentially counting how many times a digit appears in both arr1 and arr2. 
This ensures that we don't overcount common digits; we only count them as cows if there are matching digits in both the secret and guessed numbers.




/*example -1
string 1 = 1807
string 2 = 7810

in first loop we can detect that only 8 is common in both string therefore one BullCount =1 and we will also update both the count arrays.

idx - 0 1 2 3 4 5 6 7 8 9
secret- 1 1 0 0 0 0 0 1 0 0
guess - 1 1 0 0 0 0 0 1 0 0

Now from the second loop we will get the cowcounts which will be 3.
therefore solution will be -> 1A3B.

example -2
string1 = 1122
string2 = 2211

now we can clearly see that none character is matching at any index so bull count =0;
and the both the array will be
idx - 0 1 2 3 4 5 6 7 8 9
secret- 0 2 2 0 0 0 0 0 0 0
guess - 0 2 2 0 0 0 0 0 0 0

cowCount will be minimum from both array same index which will be 4

output will be 0A4B*/


class Solution {
public:
    string getHint(string secret, string guess) {
    

        int n = secret.size();
        int bullCount = 0, cowCount = 0 ;
        vector<int>s1(10,0);
        vector<int>g1(10,0);
        
        for(int i=0;i<n;i++){
            //bullCount
            if(secret[i]==guess[i]){
                bullCount++;
            }
            //cowCount
            else{
                int x = secret[i] - '0';
                int y = guess[i] - '0';

                // Update frequency counters
                s1[x]++;
                g1[y]++;

            }
        }
        for (int i = 0; i < 10; i++) {
            cowCount+= min(s1[i],g1[i]);
        }

        string ans="";
        ans+=to_string(bullCount)+"A" +to_string(cowCount) +"B";
        return ans;
   
        

    }
};
