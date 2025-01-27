class Solution
{
public:
    int solve1(int k, int step, bool prevdown, int jump)
    {
        if (step > k + 1)
            return 0;

        int ways = 0;
        if (step == k)
            ways++;

        if (prevdown == true)
            ways += solve1(k, step - 1, false, jump);

        ways += solve1(k, step + pow(2, jump), true, jump + 1);

        return ways;
    }

    unordered_map<string, int> m;
    int solve2(int k, int step, bool prevdown, int jump)
    {
        if (step > k + 1)
            return 0;

        string key = to_string(step) + "_" + to_string(jump) + "_" + to_string(prevdown);

        if (m.find(key) != m.end())
            return m[key];

        int ways = 0;
        if (step == k)
            ways++;

        if (prevdown == true)
            ways += solve2(k, step - 1, false, jump);

        ways += solve2(k, step + pow(2, jump), true, jump + 1);

        return m[key] = ways;
    }

    int waysToReachStair(int k)
    {
        return solve2(k, 1, true, 0);
    }
};