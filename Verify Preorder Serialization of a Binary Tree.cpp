class Solution
{
public:
    bool isValidSerialization(string data)
    {
        int slots = 1, n = data.length();

        stringstream s(data);
        string str;

        while (getline(s, str, ','))
        {
            if (str == "#")
                slots--;
            else
                slots++;

            // cout << str << "  slots = " << slots << endl;

            if (slots == 0 && !s.eof())
            {
                return false;
            }
        }

        // cout<<"slots = "<<slots<<endl;
        if (slots != 0)
            return false;

        return true;
    }
};