#include <iostream>

struct Node
{
    int data;
    Node* next;

    Node(const int iValue)
    {
        data = iValue;
        next = nullptr;
    }
};

class LinkedList
{
public:
    LinkedList()
    {
        _head = nullptr;
        _tail = nullptr;    
    }

    void append(const int iValue)
    {
        Node* aNewNode = new Node(iValue);
        if (!_head)
        {
            _head = aNewNode;
            _tail = aNewNode;
        }
        else
        {
            std::cout << std::endl;
            std::cout << "[APPEND][1] TAIL REF " << _tail << std::endl;
            _tail->next = aNewNode;
            std::cout << "[APPEND][2] TAIL REF " << _tail << std::endl;
            _tail = aNewNode;
            std::cout << "[APPEND][3] TAIL REF " << _tail << std::endl;
            std::cout << std::endl;
        }
    }

    void display()
    {
        std::cout << std::endl << "NULL";
        Node* aCurrentNode = _head;
        while(aCurrentNode)
        {
            std::cout << "  - >  " << aCurrentNode->data;
            aCurrentNode = aCurrentNode->next; 
        }
        std::cout << " -> NULL " << std::endl;
    }

    void reverse()
    {
        std::cout << "[REVERSE] PROCESSING . . . " << std::endl;

        if (!_head) return;

        Node* aPrevNode = nullptr;
        Node* aCurrentNode = _head;
        Node* aNextNode = nullptr;
        
        display();
        std::cout << "[REVERSE] OVERRIDING TAIL . . . " << std::endl;

        _tail = _head;

        display();

        while(aCurrentNode)
        {
            std::cout << "[REVERSE] LOOPING . . . " << std::endl;
            _head = aPrevNode;
            display();
            // SAVING 
            aNextNode = aCurrentNode->next;
            // OVERRIDING
            aCurrentNode->next = aPrevNode;
            // ADDVANCING
            aPrevNode    = aCurrentNode; 
            aCurrentNode = aNextNode;
        }
        // 
        _head = aPrevNode;
    }

 private:
    Node* _head;
    Node* _tail;

};


int main()
{
    std::cout << "[MAIN_START]" << std::endl;

    LinkedList aLinkedList;
    aLinkedList.append(10);
    aLinkedList.append(11);
    aLinkedList.append(12);
    aLinkedList.append(13);
    aLinkedList.display(); // Should display: (10) => (11) => (12) => (13)
    aLinkedList.reverse();
    aLinkedList.display(); // Should display: (13) => (12) => (11) => (10)

    std::cout << "[MAIN_END]" << std::endl;
    return 0;
}
