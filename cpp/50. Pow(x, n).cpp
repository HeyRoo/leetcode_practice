/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

方案： 快速幂
即：x^N = x22222.
*/

#include <iostream>

using namespace std;

class Solution{
public:
    double quick_iteration(double x, long long N){
        double res = 1.0;
        double x_con = x;
        while(N > 0){
            if(N % 2 == 1){
                // 当前N的最低位如果为1
                res *= x_con;
            }
            x_con *= x_con;
            // 将N右移一位
            N /= 2;
        }
        return res;
    }

    double quick_recursion(double x, long long N){
        cout << N << endl;
        double res = 1.0;
        double tmp;
        if( N > 0 ){
            // 判断是否整除，奇数要多乘一个x
            if( N % 2 == 1){
                res *= x;
            }
            tmp = quick_recursion(x, N / 2);
            res *= tmp * tmp;
        }
        return res;
    }

    double myPow(double x, int n){
        long long N = n;
        //  如果N为负数，则取倒数
        return N >= 0 ? quick_recursion(x, N) : 1.00 / quick_recursion(x, N);
    }
};


int main(int argc, char const *argv[])
{
    Solution s;

    double ans = s.myPow(2.00, -2);

    cout << "ans :" << ans;

    return 0;
}

