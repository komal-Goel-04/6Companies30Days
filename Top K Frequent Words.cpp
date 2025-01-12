class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> m;
        vector<string> ans;

        for (auto i : words)
            m[i]++;

        auto comp = [](const pair<int, string> &a, const pair<int, string> &b)
        {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);

        for (auto i : m)
        {
            pq.push({i.second, i.first});
        }

        for (int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};