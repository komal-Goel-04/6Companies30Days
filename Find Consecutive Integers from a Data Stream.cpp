class DataStream
{
public:
    int val, x;
    vector<int> v;
    DataStream(int value, int k)
    {
        val = value;
        x = k;
    }
    bool consec(int num)
    {

        if (v.empty() && num == val)
            v.push_back(num);
        else if (!v.empty() && num == v.back())
            v.push_back(num);
        else if (!v.empty() && num != v.back())
        {
            v.clear();
            // v.push_back(num);
        }

        return v.size() >= x;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */