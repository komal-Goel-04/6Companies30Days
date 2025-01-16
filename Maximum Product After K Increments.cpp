class Solution
{
public:
    int maximumProduct(vector<int> &nums, int k)
    {
        const int MOD = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto i : nums)
            pq.push(i);

        for (int i = 0; i < k; i++)
        {
            int temp = pq.top();
            pq.pop();
            temp++;
            pq.push(temp);
        }

        long long ans = 1;

        while (!pq.empty())
        {
            ans = (ans * pq.top()) % MOD;
            pq.pop();
        }
        return ans;
    }
};