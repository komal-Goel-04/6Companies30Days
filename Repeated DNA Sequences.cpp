class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> ans;
        unordered_set<string> seen, result;

        for (int i = 0; i < s.length(); i++)
        {
            string temp = s.substr(i, 10);

            if (seen.count(temp))
            {
                result.insert(temp);
            }
            else
            {
                seen.insert(temp);
            }
        }

        for (auto i : result)
            ans.push_back(i);

        return ans;
    }
};