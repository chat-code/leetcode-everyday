class MyCircularQueue {
public:
  MyCircularQueue(int k)
    : v(k, 0), h{}, r{}, size{}, capacity{k} {}
 
  bool enQueue(int value) {
    if (isFull()) return false;
    v[r] = value;
    r = (r + 1) % capacity;
    ++size;
    return true;
  }
    
  bool deQueue() {
    if (isEmpty()) return false;
    h = (h + 1) % capacity;
    --size;
    return true;
  }
  
  int Front() {
    if (isEmpty()) return -1;
    return v[h];
  }
  
  int Rear() {
    if (isEmpty()) return -1;
    return v[(r - 1 + capacity) % capacity];
  }
  
  bool isEmpty() {
    return !size;
  }
  
  bool isFull() {
    return size == capacity;
  }
  
private:
  vector<int> v;
  int h, r;    // head & rear
  int capacity;
  int size;
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

