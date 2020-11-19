#include <iostream>
#include "functions.h"
using namespace std;
int main()
{
    LinkedList list;
    string s;
    do
    {
        cin >> s;
        if (s == "addLast")
        {
            int data;
            cin >> data;
            list.addLast(data);
        }
        else if (s == "display")
        {
            list.display();
        }
        else if (s == "size")
        {
            cout << list.getSize() << '\n';
        }
        else if (s == "removeFirst")
        {
            list.removeFirst();
        }
        else if (s == "getFirst")
        {
            int element = list.getFirst();
            if (element == -1)
            {
                cout << "List is empty" << '\n';
            }
            else
            {
                cout << element << '\n';
            }
        }
        else if (s == "getLast")
        {
            int element = list.getLast();
            if (element == -1)
            {
                cout << "List is empty" << '\n';
            }
            else
            {
                cout << element << '\n';
            }
        }
        else if (s == "getAt")
        {
            int index;
            cin >> index;
            int element = list.getAt(index);
            if (element != -1)
            {
                cout << element << '\n';
            }
        }
        else if (s == "addFirst")
        {
            int value;
            cin >> value;
            list.addFirst(value);
        }
        else if (s == "addAt")
        {
            int index, value;
            cin >> index >> value;
            list.addAt(index, value);
        }
        else if (s == "removeAt")
        {
            int index;
            cin >> index;
            list.removeAt(index);
        }
        else if (s == "removeLast")
        {
            list.removeLast();
        }

        else if(s == "reverseDI"){
            list.reverseDI();
        }
        else if(s == "reversePI"){
            list.reversePI();
        }

        else if(s == "mid"){
            cout << list.mid()-> data << '\n';
        }

        else if(s == "kthFromEnd"){
            int index;
            cin >> index;
            cout << list.kthFromLast(index)-> data << '\n';
        }

        else if(s == "mergeTwoSortedLists"){
            LinkedList l1, l2;
            int element, size1, size2;
            cin >> size1;
            while(size1--){
                cin >> element;
                l1.addLast(element);
            }
            cin >> size2;
            while(size2--){
                cin >> element;
                l2.addLast(element);
            }
            LinkedList *output_ll = merge_two_sorted_ll(l1, l2);
            output_ll-> display();
            l1.display();
            l2.display();
        }

    } while (s != "quit");
}


                  