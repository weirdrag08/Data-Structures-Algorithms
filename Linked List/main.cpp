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

        else if(s == "mergeSort"){
            LinkedList *my_list = new LinkedList();
            int element, size;
            cin >> size;
            while(size--){
                cin >> element;
                my_list->addLast(element);
            }
           LinkedList output_ll = merge_sort(my_list-> head, my_list-> tail);
           output_ll.display();
        }

        else if(s == "removeDuplicatesSorted"){
            LinkedList my_list;
            int element, size;
            cin >> size;
            while(size--){
                cin >> element;
                my_list.addLast(element);
            }
            LinkedList *output_ll = remove_duplicates_sorted(my_list);
            output_ll-> display();
        }

        else if(s == "removeDuplicatesSortedWithoutFunction"){
            LinkedList my_list;
            int element, size;
            cin >> size;
            while (size--)
            {
                cin >> element;
                my_list.addLast(element);
            }
            Node *output_head = remove_duplicates_sorted_without_func(my_list);
            my_list.display();
            Node *temp = output_head;
            while(temp != NULL){
                cout << temp-> data << ' ';
                temp = temp-> next;
            }
            cout << '\n';
        }

        else if(s == "oddEven"){
            LinkedList my_list;
            int element, size;
            cin >> size;
            while(size--){
                cin >> element;
                my_list.addLast(element);
            }
            LinkedList *output_ll = oddEven(my_list);
            output_ll-> display();
        }
        else if(s == "displayReverse"){
            int size, element;
            cin >> size;
            while(size--){
                cin >> element;
                list.addLast(element);
            }
            list.displayReverse();
        }

        else if(s == "reversePR"){
            int size, element;
            cin >> size;
            while(size--){
                cin >> element;
                list.addLast(element);
            }
            list.reversePR();
        }
        else if(s == "isPalindrome"){
            int element, size;
            cin >> size;
            while(size--){
                cin >> element;
                list.addLast(element);
            }
            // list.isPalindrome();
        }
    } while (s != "quit");
}


                  