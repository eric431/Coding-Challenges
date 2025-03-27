#include <iostream>
#include <vector>

using namespace std;

class EvenFibonacci
{
    public:
        EvenFibonacci(){}

        long long even_fibonacci()
        {
            int max_nums = 4e6;

            vector<long> dp(2);
            dp[0] = 1;
            dp[1] = 2;

            long long sum {2};
            
            for(auto i{0}; i < max_nums - 2; ++i)
            {
                dp[0] += dp[1];
                if(dp[0] % 2 == 0) sum += dp[0];

                dp[1] += dp[0];
                if(dp[0] % 2 == 1) sum += dp[1];
            }

            return sum;
        }
};


int main()
{
    EvenFibonacci test;

    cout << test.even_fibonacci() << endl;

    return 0;
}