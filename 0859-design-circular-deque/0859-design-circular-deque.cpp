class MyCircularDeque {
private:
    vector<int>deq;
    int front;
    int rear;
    int currSize;
    int n;
public:
    MyCircularDeque(int k) {
        deq = vector<int>(k,0);
        front = 0;
        rear = k-1;
        currSize = 0;
        n = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        front = (front - 1 + n)%n;
        deq[front] = value;
        currSize++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        rear = (rear + 1)%n;
        deq[rear] = value;
        currSize++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())return false;
        front = (front + 1)%n;
        currSize--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        rear = (rear - 1 + n)%n;
        currSize--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return deq[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return deq[rear];
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */