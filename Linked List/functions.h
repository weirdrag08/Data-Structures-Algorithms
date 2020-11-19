#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    int size;


    LinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    int getSize()
    {
        return size;
    }

    void addLast(int data)
    {
        Node *new_node = new Node(data);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            size++;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
            size++;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << '\n';
    }

    void removeFirst()
    {
        if (size == 0)
        {
            cout << "List is empty" << '\n';
        }
        else if (size == 1)
        {
            Node *temp = head;
            head = NULL;
            tail = NULL;
            delete temp;
            size--;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            size--;
        }
    }

    int getFirst()
    {
        if (head == NULL)
        {
            return -1;
        }
        else
        {
            return head->data;
        }
    }

    int getLast()
    {
        if (head == NULL)
        {
            return -1;
        }
        else
        {
            return tail->data;
        }
    }

    int getAt(int index)
    {
        if (head == NULL)
        {
            cout << "List is empty" << '\n';
            return -1;
        }
        else if (index >= size || index < 0)
        {
            cout << "Invalid arguments" << '\n';
            return -1;
        }
        else
        {
            Node *temp = head;
            while (index != 0)
            {
                index--;
                temp = temp->next;
            }
            return temp->data;
        }
    }

    void addFirst(int value)
    {
        Node *new_node = new Node(value);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            size++;
        }
        else
        {
            new_node->next = head;
            head = new_node;
            size++;
        }
    }

    void addAt(int index, int value)
    {
        Node *new_node = new Node(value);
         if(index > size || index < 0)
        {
            cout << "Invalid arguments" << '\n';
            return;
        }

        else if (index == 0)  
        {
            if(head == NULL){
                head = new_node;
                tail = new_node;
                size++;
            }
            else{
                new_node->next = head;
                head = new_node;
                size++;
            }
        }

        else
        {
            Node *temp = head;
            int k = 0;
            while (k != index - 1)
            {
                k++;
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
            size++;
            if (index == size - 1)
            {
                tail = new_node;
            }
        }
      
    }

    void removeLast()
    {
        if (head == NULL)
        {
            cout << "List is empty" << '\n';
        }
        else if (size == 1)
        {
            Node *temp = head;
            head = NULL;
            tail = NULL;
            delete temp;
            size--;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            Node *to_delete = tail;
            tail = temp;
            tail->next = NULL;
            delete to_delete;
            size--;
        }
    }

    void removeAt(int index)
    {
        if (head == NULL)
        {
            cout << "List is empty" << '\n';
        }

        else if (index >= size || index < 0)
        {
            cout << "Invalid arguments" << '\n';
        }

        else if (index == 0)
        {
            Node *temp = head;
            if (size == 1)
            {
                head = NULL;
                tail = NULL;
                delete temp;
            }
            else
            {
                head = head->next;
                delete temp;
            }
            size--;
        }

        else if(index == size - 1){
            Node *temp = head;
            while(temp-> next != tail){
                temp = temp-> next;
            }
            Node *to_delete = tail;
            tail = temp;
            tail-> next = NULL;
            delete to_delete;
            size--;
        }
        else{
            Node *temp = head;
            int k = 0;
            while(k != index - 1){
                k++;
                temp = temp-> next;
            }
            Node *to_delete = temp-> next;
            temp-> next = temp-> next-> next;
            to_delete-> next = NULL;
            delete to_delete;
            size--;
        }
    }


void reverseDI(){
   if(head == NULL || size == 1){
       return;
   }
   else{
       Node *temp_head = head;
       for (int i = 0; i < size / 2; i++)
       {
           Node *temp = temp_head;
           while (temp->next != tail)
           {
               temp = temp->next;
           }
           int element;
           element = temp_head->data;
           temp_head->data = tail->data;
           tail->data = element;
           tail = temp;
           temp_head = temp_head->next;
       }
       Node *temp = head;
       while (temp->next != NULL)
       {
           temp = temp->next;
       }
       tail = temp;
   }
}

void reversePI2(){
    int i = 0;
    Node *temp_head = head;
    Node *temp_head_next = head->next;

    if (i == 0)
    {
        head->next = NULL;
        tail = head;
        i++;
    }
   
    
        Node *temp = temp_head_next;
        while (temp != NULL)
        {  
            temp = temp_head_next;
            temp_head_next = temp->next;
            temp->next = temp_head;
            temp_head = temp;
            if (temp_head_next == NULL)
            {
                head = temp;
                temp = NULL;
            }
            i++;
        }
  }  

//* Much Better solution {Keep a current and a previous}, {keep current leading the previous by one} and then {join current to previous} and then move {previous to current} and {current to current-> next(SAVE IT BEFORE YOU SET curr-> next to prev)}
void reversePI(){
    if(head == NULL || size == 1){
        return;
    }
    else{
        Node *prev = NULL;
        Node *curr = head;
        while(curr != NULL){
            Node *curr_next = curr-> next;
            curr-> next = prev;
            prev = curr;
            curr = curr_next;
        }
        Node *temp = head;
        head = tail;
        tail = temp; 
    }
}  

Node* mid(){
    Node *fast = head;
    Node *slow = head;
while(fast-> next != NULL && fast-> next-> next != NULL){
    fast = fast-> next-> next;
    slow = slow-> next;
}
    return slow;
}

Node* kthFromLast(int k){
    Node *temp = head;
    Node *slow = head;
    while(k--){
        temp = temp-> next;
    }
    Node *fast = temp;
    while(fast != tail){
        fast = fast-> next;
        slow = slow-> next;
    }
    return slow;
}

};

LinkedList* merge_two_sorted_ll(LinkedList l1, LinkedList l2)
{
    LinkedList *output_ll = new LinkedList();
    Node *head1 = l1.head;
    Node *head2 = l2.head;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            output_ll->addLast(head1->data);
            head1 = head1->next;
        }
        else
        {
            output_ll->addLast(head2->data);
            head2 = head2->next;
        }
    }
    if (head1 == NULL)
    {
        while (head2 != NULL)
        {
            output_ll->addLast(head2->data);
            head2 = head2-> next;
        }
    }
    else
    {
        while (head1 != NULL)
        {
            output_ll->addLast(head1->data);
            head1 = head1-> next;
        }
    }
    return output_ll;
}
