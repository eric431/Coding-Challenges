// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
 

// Constraints:

// 1 <= n <= 104


class Solution {
public:
    int numSquares(int n) {
        int root = sqrt(n);
        if(root * root == n)
        {
            return 1;
        }
    
        int i = root;        
        queue<int> q;             
        while(i * i > 0)
        {
            q.push(i*i);
            i--;
        }
        
        int min_cnt = INT_MAX;
        while(!q.empty())
        {
            int sq = q.front();
            q.pop();
            auto q2 = q;
            
            int c, rt, n_tmp2, cnt = 0;
            
            int n_tmp = n - (n/sq)*sq;
            cnt += n/sq;
            int cnt_cache = cnt;
            while(!q2.empty())
            {
                int f = q2.front();
                q2.pop();

                n_tmp2 = n_tmp - (n_tmp/f)*f;

                cnt = cnt_cache;
                cnt += (n_tmp/f);
                if(cnt > min_cnt)
                {
                    continue;
                }
                while(n_tmp2 > 0)
                {
                    rt = sqrt(n_tmp2);
                    f = rt * rt;
                    c = n_tmp2 / f;
                    cnt += c;
                    if(cnt > min_cnt)
                    {
                        break;
                    }

                    n_tmp2 -= c*f;
                }
                if(cnt < min_cnt)
                {
                    min_cnt = cnt;
                }
            }
            if(cnt < min_cnt)
            {
                min_cnt = cnt;
            }
        }
        
        return min_cnt;
    }
};