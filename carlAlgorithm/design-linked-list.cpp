class MyLinkedList {
public:
    MyLinkedList() : head(new LinkedNode), _size(0) {
    }
    
    int get(int index) {
        if (index >= _size) return -1;
        auto ans = head->next;
        for (int i = 0; i != index; ++i)
        {
            ans = ans->next;
        }
        return ans->val;
    }
    
    void addAtHead(int val) {
        LinkedNode *node = new LinkedNode(val, head->next);
        head->next = node;
        ++_size;
    }
    
    void addAtTail(int val) {
        auto iter = head;
        while (iter->next != nullptr)
        {
            iter = iter->next;
        }
        iter->next = new LinkedNode(val);
        ++_size;
    }
    
    void addAtIndex(int index, int val) {
        if (index > _size) return;
        auto iter = head;
       
        for (int i = 0; i != index; ++i)
        {
            iter = iter->next;
        }
        auto t = iter->next;
        iter->next = new LinkedNode(val, t);
        ++_size;
    }
    
    void deleteAtIndex(int index) {
        if (index >= _size) return;
        auto iter = head;

        for (int i = 0; i != index; ++i)
        {
            iter = iter->next;
        }
        auto t = iter->next;
        iter->next = t->next;
        delete t;
        --_size;
    }

    ~MyLinkedList()
    {
        LinkedNode *i1 = head, *i2;
        while (i1 != nullptr)
        {
            i2 = i1->next;
            delete i1;
            i1 = i2;
        }

    }

private:
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        
        LinkedNode(int value, LinkedNode *n = nullptr) : val(value), next(n) {}
        LinkedNode() : next(nullptr) {}
    };
    LinkedNode *head;
    int _size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */