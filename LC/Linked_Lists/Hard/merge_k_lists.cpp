/*

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists)
{
	ListNode *head = NULL, *l = NULL;
	int min, pos, i, k = lists.size(), flag = 1, hFlag = 1, tFlag = 1;
	auto iterator = lists.begin();

	while (true)
	{
		pos = -1;
		flag = 1;
		tFlag = 1;

		for (i = 0; i < k; i++)
		{
			if (iterator[i])
			{
				if (flag == 1)
				{
					min = iterator[i]->val;
					pos = i;
					flag = 0;
				}

				else
				{
					if (min > iterator[i]->val)
					{
						min = iterator[i]->val;
						pos = i;
					}
				}
			}
		}

		if (pos != -1)
		{
			ListNode *temp = new ListNode(iterator[pos]->val);

			if (hFlag == 1)
			{
				head = temp;
				l = temp;
				hFlag = 0;
			}

			else
			{
				l->next = temp;
				l = temp;
			}

			iterator[pos] = iterator[pos]->next;
		}

		for (i = 0; i < k; i++)
		{
			if (iterator[i])
				tFlag = 0;
		}

		if (tFlag)
			break;
	}

	return head;
}

int main()
{
	ListNode *l1 = NULL, *head1 = NULL, *head2 = NULL;
	vector <ListNode*> lists;
	int i = 0, n, x, flag = 1;

	cout << "\n Enter the number of elements: ";
	cin >> n;

	cout << "\n Enter the elements: ";

	while (i < n)
    {
    	cin >> x;

        ListNode* temp = new ListNode(x);

        if (flag == 1)
        {
            head1 = temp;
            l1 = temp;
            flag = 0;
        }

        else
        {
            l1->next = temp;
            l1 = temp;
        }

        i += 1;
    }

    i = 0;
    flag = 1;

    cout << "\n Enter the number of elements: ";
	cin >> n;

	cout << "\n Enter the elements: ";

	while (i < n)
    {
    	cin >> x;

        ListNode* temp = new ListNode(x);

        if (flag == 1)
        {
            head2 = temp;
            l1 = temp;
            flag = 0;
        }

        else
        {
            l1->next = temp;
            l1 = temp;
        }

        i += 1;
    }

    lists.push_back(head1);
    lists.push_back(head2);

	l1 = mergeKLists(lists);

	if (l1)
	{
		cout << "\n\n The new list is: ";

		while (l1)
		{
			if (l1->next != NULL)
				cout << l1->val << "->";
			else
				cout << l1->val;

			l1 = l1->next;
		}
	}

	else
		cout << "\n\n Empty list";

	cout << endl;

	return 0;
}
