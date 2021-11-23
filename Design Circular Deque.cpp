// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        23 Nov 2021
//  @Detail  :        Design Circular Deque (LeetCode)
//  ============================
//  -->

class MyCircularDeque {
public:
    
    vector<int> deque;
    int head, tail, curSize, capacity;
    
    MyCircularDeque(int k) {
        vector<int> temp(k);
        deque = temp;
        head = tail = curSize = 0;
        capacity = k;
    }
    
    bool insertFront(int value) {
        if(curSize == capacity)
            return false;
        head = (head - 1 + capacity) % capacity;
        deque[head] = value;
        curSize++;
        return true;
    }
    
    bool insertLast(int value) {
         if(curSize == capacity)
            return false;
        deque[tail] = value;
        tail = (tail + 1 + capacity) % capacity;
        curSize++;
        return true;
    }
    
    bool deleteFront() {
        if(curSize == 0)
            return false;
        head = (head + 1 + capacity) % capacity;
        curSize--;
        return true;
    }
    
    bool deleteLast() {
        if(curSize == 0)
            return false;
        tail = (tail - 1 + capacity) % capacity;
        curSize--;
        return true;
    }
    
    int getFront() {
        if(curSize == 0)
            return -1;
        return deque[head];
    }
    
    int getRear() {
        if(curSize == 0)
            return -1;
        return deque[(tail - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return curSize == 0;
    }
    
    bool isFull() {
        return curSize == capacity;
    }
};
