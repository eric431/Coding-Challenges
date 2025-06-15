#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        string s1;
        string s2;
        string s3;
        int n;
        int m;
        vector<vector<vector<int>>> memo;
        
        bool dp(int i, int j, int k){
            if(i > n || j > m){
                return false;
            } else if (i == n && j == m){            
                return true;
            } else if(i < n && j < m && memo[i][j][k] != -1){ 
                return memo[i][j][k]; 
            } 
    
            bool result;
            if(i < n && j < m && s1[i] == s3[k] && s2[j] == s3[k]){
                result = dp(i + 1, j, k + 1) || dp(i, j + 1, k + 1);
            } else if(i < n && s1[i] == s3[k]){
                result = dp(i + 1, j, k + 1);
            } else if(j < m && s2[j] == s3[k]){
                result = dp(i, j + 1, k + 1);
            } else {
                result = false;
            }
            
            return memo[i][j][k] = result;
        }
        
        bool isInterleave(string s1, string s2, string s3) {
            if((s1.size() + s2.size()) != s3.size()) return false;
                    
            this->s1 = s1;
            this->s2 = s2;
            this->s3 = s3;
            this->n = s1.size();
            this->m = s2.size();
            this->memo.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(s3.size(), -1)));
            
            return dp(0, 0, 0);
        }
    };