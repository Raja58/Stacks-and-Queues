// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        23 Nov 2021
//  @Detail  :        Design Circular Queue (LeetCode)
//  ============================
//  -->

class MyCircularQueue {
public:
    
    vector<int> queue;
    int head, tail, size, curSize;
    
    MyCircularQueue(int k) {
        vector<int> temp(k);
        queue = temp;
        head = tail = 0;
        size = k;
        curSize = 0;
    }
    
    bool enQueue(int value) {
        if(curSize == size)
            return false;
        queue[tail] = value;
        tail = (tail + 1) % size;
        curSize++;
        return true;
    }
    
    bool deQueue() {
        if(curSize == 0)
            return false;
        head = (head + 1) % size;
        curSize--;
        return true;
    }
    
    int Front() {
        if(curSize == 0)
            return -1;
        return queue[head];
    }
    
    int Rear() {
        if(curSize == 0)
            return -1;
        return queue[(tail - 1 + size) % size];
    }
    
    bool isEmpty() {
        return curSize == 0;
    }
    
    bool isFull() {
        return curSize == size;
    }
};
