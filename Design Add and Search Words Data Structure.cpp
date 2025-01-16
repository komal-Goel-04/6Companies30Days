
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isterminal;

    // constructor
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isterminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    //-------------------------insert word------------------------------
    void insertutil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isterminal = true;
            return;
        }

        int index = 0;
        index = word[0] - 'a';

        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // absent
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursive call
        insertutil(child, word.substr(1));
    }
    void insertword(string word)
    {
        insertutil(root, word);
    }

    bool searchutil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
            return root->isterminal;

        bool ans = false;
        TrieNode *child;

        if (word[0] == '.')
        {
            for (int j = 0; j < 26; j++)
            {
                if (root->children[j] != NULL)
                {
                    child = root->children[j];
                    ans = searchutil(child, word.substr(1));
                    // return ans;
                }
                if (ans)
                    return true;
            }
        }
        else
        {
            int index = word[0] - 'a';
            if (root->children[index] != NULL)
            {
                child = root->children[index];
            }
            else
            {
                return false;
            }
            ans = searchutil(child, word.substr(1));
        }
        return ans;
    }
    bool searchword(string word)
    {
        return searchutil(root, word);
    }
};
class WordDictionary
{
public:
    Trie *t = new Trie();
    WordDictionary()
    {
        // Trie *t = new Trie();
    }

    void addWord(string word)
    {
        t->insertword(word);
    }

    bool search(string word)
    {
        return t->searchword(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
