class Solution
{
public:
    Node *linkdelete(Node *head, int n, int m)
    {
        Node *temp = head;
        Node *prev = NULL;

        while (temp != NULL)
        {
            int m1 = m;
            while (m1-- && temp != NULL)
            {
                prev = temp;
                temp = temp->next;
            }

            int n1 = n;
            while (n1-- && temp != NULL)
                temp = temp->next;

            prev->next = temp;
        }
        return head;
    }
};