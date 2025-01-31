class ThroneInheritance
{
    string king;
    unordered_map<string, vector<string>> parenttochild;
    set<string> dead;

public:
    ThroneInheritance(string kingName)
    {
        king = kingName;
        parenttochild[king] = {};
    }

    void birth(string parentName, string childName)
    {
        parenttochild[parentName].push_back(childName);
    }

    void death(string name)
    {
        dead.insert(name);
    }

    void preOrder(string name, vector<string> &v)
    {
        if (dead.count(name) == 0)
            v.push_back(name);

        for (auto i : parenttochild[name])
        {
            preOrder(i, v);
        }
    }

    vector<string> getInheritanceOrder()
    {
        vector<string> v;
        preOrder(king, v);
        return v;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */