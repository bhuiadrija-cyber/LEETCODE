class MyCircularQueue {
public:
    int data;
    MyCircularQueue* next;
    int capacity;
    int size=0;;

    MyCircularQueue(int k) {
        capacity=k;
    }

    MyCircularQueue* front=NULL;
    MyCircularQueue* rear=NULL;
    
    bool enQueue(int val) {
        if(size==capacity) return false;
        MyCircularQueue* newNode=new MyCircularQueue(0);
        if (!newNode) {
            return false;
        }
        newNode->data=val;
        if (front == NULL) {
            front = rear = newNode;
            rear->next = front;
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
        size++;
        return true;
    }
    
    bool deQueue() {
        if (front == NULL) {
            return false;
        }
        MyCircularQueue* temp = front;
        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
            rear->next = front;
        }
        delete(temp);
        size--;
        return true;
    }
    bool isEmpty() {
        if(front==NULL) return true;
        return false;
    }
    
    bool isFull() {
        if(size==capacity) return true;
        return false;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return front->data;
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return rear->data;
    }
    
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
