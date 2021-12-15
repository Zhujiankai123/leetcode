#include <iostream>
#include <ctime>
#include <vector>

class Fibonacci01{
    // 使用纯递归调用的方式计算斐波那契数列
private:
    long long f(int n){
        if (n == 0 || n == 1)
            return n;
        else
            return f(n-1) + f(n-2);
    };
public:
    long long calcFabionacci(int n){
        // 返回f(n)
        return f(n);
    }
};

class Fibonacci02{
    // 使用递归调用+记忆化搜索的方式计算斐波那契数列
private:
    std::vector<long long> fibs;
    long long f(int n){
        if (n == 0 || n == 1){
            fibs[n] = n;
            return n;
        }

        fibs[n-1] = fibs[n-1] == -1 ? f(n-1) : fibs[n-1];
        fibs[n-2] = fibs[n-2] == -1 ? f(n-2) : fibs[n-2];
        fibs[n] = fibs[n-1] + fibs[n-2];
        return fibs[n];
    };
public:
    long long calcFabionacci(int n){
        if (n == 1)
            fibs = std::vector<long long>(n+1,-1);
        // 返回f(n)
        return f(n);
    }
};

class Fibonacci03{
private:
    std::vector<long long> memo;
public:
    long long calcFabionacci(int n){
        assert(n>0);
        memo = std::vector<long long>(n+1,-1);
        memo[0] = 0;
        memo[1] = 1;

        for (int i = 2; i < n+1; ++i) {
            memo[i] = memo[i-1] + memo[i-2];
        }
        return memo[n];
    }
};

int main() {
    clock_t start = clock();
    int n = 100;
//    Fibonacci01 fibonacci = Fibonacci01();
//    Fibonacci02 fibonacci = Fibonacci02();
    Fibonacci03 fibonacci = Fibonacci03();
    for (int i = 1; i <= n; ++i) {
       std::cout<<fibonacci.calcFabionacci(i);
       if (i != n)
           std::cout<<", ";
       else
           std::cout<<"."<<std::endl;
    }
    clock_t end = clock();
    std::cout<<"Using: " << (float)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
}

