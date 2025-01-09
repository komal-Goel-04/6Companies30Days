class Solution
{
public:
    vector<int> v;
    vector<vector<int>> rectangles;

    int cntpoints(vector<int> r)
    {
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }

    Solution(vector<vector<int>> &rects)
    {
        rectangles = rects;
        int totpoints = 0;

        for (auto r : rects)
        {
            totpoints += cntpoints(r);
            v.push_back(totpoints);
        }
    }

    vector<int> pick()
    {
        int pt = rand() % v.back();
        int idx = upper_bound(v.begin(), v.end(), pt) - v.begin();

        vector<int> r = rectangles[idx];
        int x = rand() % (r[2] - r[0] + 1) + r[0];
        int y = rand() % (r[3] - r[1] + 1) + r[1];

        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */