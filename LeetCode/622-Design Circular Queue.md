
英文链接: https://leetcode.com/problems/design-circular-queue/  
中文链接: https://leetcode-cn.com/problems/design-circular-queue/

能通过，但不满足题意

```
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        // not v.isFull()
        if(isFull())
        {
            return false;
        }
        else
        {
            v.push_back(value);
            return true;
        }
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        // not v.isEmpty()
        if(isEmpty())
        {
            return false;
        }
        else
        {
            v.erase(v.begin());
            return true;
        }
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return isEmpty() ? -1 : v.front();
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty() ? -1 : v.back();
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return v.size() == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return v.size() == size;
    }

private:
    vector<int> v;
    int size;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */
```


```
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        data.resize(k);
        head = k - 1;
        tail = 0;
        size = k;
        cnt = 0;
    }
    
    bool enQueue(int value) {
        if (isFull())
        {
            return false;
        }

        // 不要写错 tail 的下标
        data[tail] = value;
        tail = (tail + 1) % size;
        ++cnt;

        return true;
    }
    
    bool deQueue() {
        // 不要写成 isFull
        if (isEmpty())
        {
            return false;
        }

        head = (head + 1) % size;
        --cnt;

        return true;
    }
    
    int Front() {
        // 一定不要遗漏 isEmpty() 的判断
        // 不要写成 return isEmpty() ? -1 : (head + 1) % size;
        return isEmpty() ? -1 : data[(head + 1) % size];
    }
    
    int Rear() {
        // 一定不要遗漏 isEmpty() 的判断
        // 不要写成 return isEmpty() ? -1 : (tail - 1 + size) % size;
        return isEmpty() ? -1 : data[(tail - 1 + size) % size];
    }
    
    bool isEmpty() {
        // return cnt == 0 ? true : false;
        return cnt == 0;
    }
    
    bool isFull() {
        // return cnt == size ? true : false;
        return cnt == size;
    }

private:
    vector<int> data;
    int head, tail, size, cnt;
};
```

(tail - 1 + size) % size 不能写成 (tail - 1) % size

["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear"]  
[[3],[1],[2],[3],[4],[]]

Output  
[null,true,true,true,false,0]  
Expected  
[null,true,true,true,false,3]
