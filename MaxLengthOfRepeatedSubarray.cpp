class Solution {
    public:
        int max_len = 0;
        vector<int> nums1;
        vector<int> nums2;
        vector<vector<int>> memo;
        
        int dp_solver(int i, int j){
            if (i == nums1.size() || j == nums2.size()){ 
                return memo[i][j] = 0;
            } else if (memo[i][j] != -1){ 
                return memo[i][j]; 
            }
            
            memo[i][j] = (nums1[i] == nums2[j]) + dp_solver(i + 1, j + 1);
            memo[i + 1][j] = dp_solver(i + 1, j);
            memo[i][j + 1] = dp_solver(i, j + 1);
            
            auto tmp_max = max({memo[i + 1][j], memo[i][j + 1], memo[i][j]});
            max_len = max(max_len, tmp_max);      
            
            if(nums1[i] == nums2[j]) return memo[i][j];
            
            return 0;
        }
        
        int findLength(vector<int>& nums1, vector<int>& nums2) {
            this->nums1 = nums1;
            this->nums2 = nums2;
            
            int n = nums1.size();
            int m = nums2.size();
            this->memo.resize(n + 1, vector<int>(m + 1, -1));
            
            dp_solver(0, 0);
            
            return max_len;
        }
    };