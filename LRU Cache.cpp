class LRUCache
{
public:
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int>> m;

    int n;
    LRUCache(int capacity)
    {
        n = capacity;
    }

    void makeRecentlyUsed(int key)
    {
        dll.erase(m[key].first);
        dll.push_front(key);

        m[key].first = dll.begin();
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
            return -1;

        makeRecentlyUsed(key);
        return m[key].second;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            makeRecentlyUsed(key);
            m[key].second = value;
        }
        else
        {
            dll.push_front(key);
            m[key] = {dll.begin(), value};
            n--;
        }

        if (n < 0)
        {
            int todelete = dll.back();
            dll.pop_back();
            m.erase(todelete);
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */