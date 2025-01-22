class Solution
{
public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        unordered_set<string> normalizedStartWords;
        for (string &word : startWords)
        {
            sort(word.begin(), word.end());
            normalizedStartWords.insert(word);
        }

        int count = 0;

        for (string &target : targetWords)
        {
            sort(target.begin(), target.end());
            for (int i = 0; i < target.size(); ++i)
            {
                string temp = target;
                temp.erase(temp.begin() + i);
                if (normalizedStartWords.find(temp) != normalizedStartWords.end())
                {
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};