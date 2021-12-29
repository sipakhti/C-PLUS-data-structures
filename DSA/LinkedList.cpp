#include <iostream>

using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node* next;
    };
    Node* head;
    Node* tail;
    int size;

    public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    // copy constructor
    LinkedList(const LinkedList& other)
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
        Node* temp = other.head;
        while(temp != nullptr)
        {
            push_back(temp->data);
            temp = temp->next;
        }
    }
    // destructor
    ~LinkedList()
    {
        Node* temp = head;
        // delete all nodes
        while(temp != nullptr)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    /**
     * @brief inserts a value at the end of the list
     * 
     * @param data 
     */
    void push_back(int data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        if(head == nullptr) // if list is empty
        {
            head = newNode;
            tail = newNode;
        }
        else // if list is not empty
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    /**
     * @brief inserts a value at the beginning of the list
     * 
     * @param data 
     */
    void push_front(int data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        if(head == nullptr) // if list is empty
        {
            head = newNode;
            tail = newNode;
        }
        else // if list is not empty
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    /**
     * @brief removes the last element of the list
     * 
     */
    void pop_back()
    {
        if(head == nullptr) // if list is empty
        {
            return;
        }
        else if(head == tail) // if list has only one element
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else 
        {
            Node* temp = head;
            while(temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        size--;
    }

    /**
     * @brief removes the first element of the list
     * 
     */
    void pop_front()
    {
        if(head == nullptr) // if the list is empty
        {
            return;
        }
        else if(head == tail) // if list has only one element
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size--;
    }

    /**
     * @brief inserts a value at a given index
     * 
     * @param index 
     * @param data 
     */
    void insert(int data, int index)
    {
        if(index < 0 || index > size) // if the index is out of bounds
        {
            return;
        }
        else if(index == 0) // if its the first index
        {
            push_front(data);
        }
        else if(index == size) // if its the last index
        {
            push_back(data);
        }
        else
        {
            // create a new node
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = nullptr;
            // find the node before the index
            Node* temp = head;
            for(int i = 0; i < index - 1; i++)
                temp = temp->next;
            // insert the new node
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }
    }

    /**
     * @brief removes a value at a given index
     * 
     * @param index 
     */
    void erase(int index)
    {
        // if the index is out of bounds
        if(index < 0 || index >= size)
        {
            return;
        }
        // if its the first index
        else if(index == 0)
        {
            pop_front();
        }
        // if its the last index
        else if(index == size - 1)
        {
            pop_back();
        }
        else
        {
            // find the node before the index
            Node* temp = head;
            for(int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            // delete the node
            Node* temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
            size--;
        }
    }

    /**
     * @brief returns the value at a given index
     * 
     * @param index 
     * @return value at the index or nulltpr if the index is out of bounds
     */
    int& operator[](int index)
    {
        // if the index is out of bounds
        if(index < 0 || index >= size)
        {
            cerr << "Index out of bounds" << endl;
            return nullptr;
        }
        else
        {
            // find the node at the index
            Node* temp = head;
            for(int i = 0; i < index; i++)
                temp = temp->next;
            return temp->data;
        }
    }

    /**
     * @brief returns the size of the list
     * 
     * @return int 
     */
    int size()
    {
        return size;
    }

    void print()
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // equality operator
    bool operator==(const LinkedList& other)
    {
        // if the sizes are different
        if(size != other.size)
            return false;
        // if the sizes are the same
        Node* temp = head;
        Node* temp2 = other.head;
        // compare each element
        // TODO: make this more efficient
        // using a doubly linked list we can traverse the list in O(n/2) time if we use multi threading to move from each end of the list concurrently
        while(temp != nullptr)
        {
            // if the data is different
            if(temp->data != temp2->data)
                return false;
            temp = temp->next;
            temp2 = temp2->next;
        }
        return true;
    }

    // assignment operator
    LinkedList& operator=(const LinkedList& other)
    {
        // if the they are the same
        if(this == &other)
        {
            return *this;
        }
        Node* temp = head;
        // delete all the existing nodes
        while(temp != nullptr)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
        // reset the state of the list
        head = nullptr;
        tail = nullptr;
        size = 0;
        // copy the other list
        temp = other.head;
        while(temp != nullptr)
        {
            push_back(temp->data);
            temp = temp->next;
        }
        return *this;
    }

    // add operator
    /**
     * @brief concatenates two lists
     * 
     * @param other 
     * @return LinkedList& 
     */
    LinkedList& operator+(const LinkedList& other)
    {

        LinkedList* newList = new LinkedList;
        // copy the first list
        Node* temp = head;
        while(temp != nullptr)
        {
            newList->push_back(temp->data);
            temp = temp->next;
        }
        // copy the second list
        temp = other.head;
        while(temp != nullptr)
        {
            newList->push_back(temp->data);
            temp = temp->next;
        }
        return *newList;
    }

    // subtract operator
    LinkedList& operator-(const LinkedList& other)
    {
        LinkedList* newList = new LinkedList;
        // copy the first list
        Node* temp = head;
        while(temp != nullptr)
        {
            newList->push_back(temp->data);
            temp = temp->next;
        }
        // copy the second list
        temp = other.head;
        while(temp != nullptr)
        {
            // removes the value from the list if it exists in the other list
            newList->erase(newList->find(temp->data));
            temp = temp->next;
        }
        return *newList;
    }

    /**
     * @brief finds the index of a value
     * 
     * @param data 
     * @return index of the value or -1 if the value is not in the list
     */
    int find(int data)
    {
        Node* temp = head;
        int index = 0;
        while(temp != nullptr)
        {
            if(temp->data == data)
            {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }

};