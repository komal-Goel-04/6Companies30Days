class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int m = nums[0].size();
        map<int, vector<pair<string, int>>> trimmedMap;

        for (int trimLen = 1; trimLen <= m; ++trimLen)
        {
            vector<pair<string, int>> trimmedList;
            for (int i = 0; i < n; ++i)
            {
                string trimmed = nums[i].substr(m - trimLen);
                trimmedList.push_back({trimmed, i});
            }
            trimmedMap[trimLen] = trimmedList;
        }

        vector<int> answer;

        for (auto &query : queries)
        {
            int k = query[0];
            int trim = query[1];

            auto &trimmedList = trimmedMap[trim];

            sort(trimmedList.begin(), trimmedList.end(), [](const pair<string, int> &a, const pair<string, int> &b)
                 {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second; });

            answer.push_back(trimmedList[k - 1].second);
        }

        return answer;
    }
};