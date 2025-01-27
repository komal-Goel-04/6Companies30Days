#include <cmath> // For mathematical functions like pow
class Solution
{
public:
    long long N = (long long)pow(10, 9) + 7;

    long long powMod(long long num, long long p)
    {
        if (p == 0)
            return 1;

        long long temp = powMod(num, p / 2);
        if (p % 2 == 0)
            return (temp * temp) % N;
        else
            return ((temp * temp) % N * (num % N)) % N;
    }

    int minNonZeroProduct(int p)
    {
        long long max = (1LL << p) - 1;
        long long power = powMod(max - 1, (max - 1) / 2);
        power = ((power % N) * (max % N)) % N;

        return (int)power;
    }
};
