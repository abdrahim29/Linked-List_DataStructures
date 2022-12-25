#include <iostream>
using namespace std;

class node
{
public:
    int key;
    int data;
    node *next;

    node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    node(int k, int d)
    {
        key = k;
        data = d;
        next = NULL; // edited
    }
};
class Link
{
public:
    node *head;

    Link()
    {
        head = NULL;
    }
    Link(node *n)
    {
        head = n;
    }

    node *nodeExists(int k)
    {
        node *temp = NULL;
        node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    void nodeAppend(node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "node already exists with the key" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "head node appended" << n << endl;
            }
            else
            {
                node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node appended" << n << endl;
            }
        }
    }

    void nodePrepend(node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "node already exists with the key" << endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "Prepended" << n << endl;
        }
    }

    void nodeInsert(int k, node *n)
    {
        node *ptr = nodeExists(k);

        if (ptr == NULL)
        {
            cout << "No node exists with the value";
        }
        else
        {

            if (nodeExists(n->key) != NULL)
            {
                cout << "node already exists with the key" << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "node inserted at key" << k << endl;
            }
        }
    }

    void nodeDelete(int k)
    {
        if (nodeExists(k) == NULL)
        {
            cout << "key doesn't exist";
        }
        else
        {
            if (head->key == k)
            {
                head = head->next;
            }
            else
            {
                node *temp = NULL;
                node *prevptr = head;
                node *currentptr = head->next;

                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }

                if (temp != NULL)
                {
                    prevptr->next = temp->next;
                    cout << "node deleted with key" << k << endl;
                }
            }
        }
    }
    void nodeUpdate(int k, int d)
    {

        node *ptr;
        ptr = nodeExists(k);

        ptr->data = d;

        cout << "node updated" << endl;
    }

    void nodePrint()
    {
        if (head == NULL)
        { // edited
            cout << "list empty";
        }
        else
        {
            node *temp = head;

            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->data << ") --> ";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    Link s;
    int k1, d1, opt, k2;

    do
    {
        cout << "\n 1. append node " << endl;
        cout << " 2. prepend node " << endl;
        cout << " 3. insert node " << endl;
        cout << " 4. delete node " << endl;
        cout << " 5. update node " << endl;
        cout << " 6. Clear Screen " << endl;

        cout << "\nSelect Option number: ";
        cin >> opt;
        node *n1 = new node();

        if (opt == 1)
        {
            cout << "enter key";
            cin >> k1;
            cout << "enter data";
            cin >> d1;

            n1->key = k1;
            n1->data = d1;

            s.nodeAppend(n1);
            s.nodePrint();
        }
        else if (opt == 2)
        {
            cout << "enter key";
            cin >> k1;
            cout << "enter data";
            cin >> d1;

            n1->key = k1;
            n1->data = d1;

            s.nodePrepend(n1);
            s.nodePrint();
        }
        else if (opt == 3)
        {
            cout << "enter key";
            cin >> k1;
            cout << "enter data";
            cin >> d1;
            cout << "enter key";
            cin >> k2;

            n1->key = k1;
            n1->data = d1;

            s.nodeInsert(k2, n1);
            s.nodePrint();
        }
        else if (opt == 4)
        {
            cout << "enter key";
            cin >> k2;

            s.nodeDelete(k2);
            s.nodePrint();
        }
        else if (opt == 5)
        {
            cout << "enter key";
            cin >> k2;
            cout << "enter new data";
            cin >> d1;

            s.nodeUpdate(k2, d1);
            s.nodePrint();
        }

    } while (opt != 6);

    s.nodePrint();

    return 0;
}