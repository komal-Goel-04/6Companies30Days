class Solution
{
public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        int alen = a.length();
        int blen = b.length();
        int slen = s.length();
        vector<int> a_indices, b_indices;

        for (int i = 0; i <= slen - alen; i++)
        {
            if (s.substr(i, alen) == a)
            {
                a_indices.push_back(i);
            }
        }
        for (int i = 0; i <= slen - blen; i++)
        {
            if (s.substr(i, blen) == b)
            {
                b_indices.push_back(i);
            }
        }

        vector<int> ans;
        int j = 0;

        for (int i : a_indices)
        {
            j = 0;
            while (j < b_indices.size() && abs(b_indices[j] - i) > k)
            {
                j++;
            }
            if (j < b_indices.size() && abs(b_indices[j] - i) <= k)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};