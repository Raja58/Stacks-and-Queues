// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        23 Nov 2021
//  @Detail  :        Design Front Middle Back Queue (LeetCode)
//  ============================
//  -->

class FrontMiddleBackQueue {
public:
    deque<int> left, right;
    int size;
    FrontMiddleBackQueue() {
        size = 0;
    }
    
    void pushFront(int val) {
        if(size == 0)
        {
            left.push_front(val);
            size++;
            return;
        }
        
        left.push_front(val);
        if(size & 1)
        {
            right.push_front(left.back());
            left.pop_back();
        }
        size++;
    }
    
    void pushMiddle(int val) {
        if(size == 0)
        {
            left.push_front(val);
            size++;
            return;
        }
        
        if(size & 1)
        {
            right.push_front(left.back());
            left.pop_back();
        }
        left.push_back(val);
        size++;
    }
    
    void pushBack(int val) {
        if(size == 0)
        {
            left.push_front(val);
            size++;
            return;
        }
        
        right.push_back(val);
        if((size & 1) == 0)
        {
            left.push_back(right.front());
            right.pop_front();
        }
        size++;
    }
    
    int popFront() {
        if(size == 0)
            return -1;
        
        if(size == 1)
        {
            int result = left.front();
            left.pop_back();
            size--;
            return result;
        }
        
        int result = left.front();
        left.pop_front();
        if((size & 1) == 0)
        {
            left.push_back(right.front());
            right.pop_front();
        }
        size--;
        return result;
    }
    
    int popMiddle() {
        if(size == 0)
            return -1;
        
        if(size == 1)
        {
            int result = left.front();
            left.pop_back();
            size--;
            return result;
        }
        
        int result = left.back();
        left.pop_back();
        if((size & 1) == 0)
        {
            left.push_back(right.front());
            right.pop_front();
        }
        size--;
        return result;
    }
    
    int popBack() {
        if(size == 0)
            return -1;
        
        if(size == 1)
        {
            int result = left.front();
            left.pop_back();
            size--;
            return result;
        }
        
        int result = right.back();
        right.pop_back();
        if(size & 1)
        {
            right.push_front(left.back());
            left.pop_back();
        }
        size--;
        return result;
    }
};
