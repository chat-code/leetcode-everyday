/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start

#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    Node(int key, int value)
        :key(key),
         value(value), 
         next(nullptr), 
         prev(nullptr) { }
    void connect(Node* b) {
        next = b;
        b->prev = this;
    }
    void set_value(int value) {
        this->value = value;
    }
    Node* get_next() const {
        return next;
    }
    Node* get_prev() const {
        return prev;
    }
    int get_value() const { return value; }
    int get_key() const { return key; }
private:
    int value;
    int key;
    Node *prev;
    Node *next;
};

class DList {
public:
    DList(int s = 10)
        :cap(s),
         len(0),
         head(new Node(-1, -1)),
         tail(new Node(-1, -1)) {
        (*head).connect(tail);
    }
    int get_len() const { return len; }
    Node* push_front(int key, int value) {
        if (full()) { return nullptr; }
        Node* tmp = new Node(key, value);
        Node* prev_head = (*head).get_next();
        (*tmp).connect(prev_head);
        (*head).connect(tmp);
        ++len;
        return tmp;
    }
    Node* push_front(Node* tmp) {
        if (full()) { return nullptr; }
        Node* prev_head = (*head).get_next();
        (*tmp).connect(prev_head);
        (*head).connect(tmp);
        ++len;
        return tmp;
    }
    Node* push_back(int key, int value) {
        if (full()) { return nullptr; }
        Node* tmp = new Node(key, value);
        Node* prev_tail = (*tail).get_prev();
        (*prev_tail).connect(tmp);
        (*tmp).connect(tail);
        ++len;
        return tmp;
    }
    bool empty() const { 
        return len == 0 || (
            (*head).get_next() == tail &&
            (*tail).get_prev() == head
        ); 
    }
    bool full() const {
        return len == cap;
    }
    Node* pop_back() {
        if (empty()) return nullptr;
        Node* prev = (*tail).get_prev();
        Node* prev2 = (*prev).get_prev();
        (*prev2).connect(tail);
        // delete prev;
        --len;
        return prev;
    }
    Node* erase(Node* n) {
        if (empty()) { return nullptr; }
        Node* prev = (*n).get_prev();
        Node* next = (*n).get_next();
        (*prev).connect(next);
        --len;
        return n;
    }
    ~DList() {
        // TODO:
    }
private:
    Node *head;
    Node *tail;
    int cap;
    int len;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        dlist = new DList(capacity);
    }

    int get(int key) {
        unordered_map<int, Node*>::iterator it;
        it = nset.find(key);
        if (it != nset.end()) {
            // found
            Node* t = (*dlist).erase(it->second);
            (*dlist).push_front(t);
            if (t != nullptr) {
                return (*t).get_value();
            } else {
                cout << "t is nullptr" << endl;
                return -1;
            }
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        unordered_map<int, Node*>::iterator it;
        it = nset.find(key);
        if (it != nset.end()) {
            // found it
            Node* t = (*dlist).erase(it->second);
            (*t).set_value(value);
            (*dlist).push_front(t);
        } else {
            if ((*dlist).full()) {
                Node* t= (*dlist).pop_back();
                if (t == nullptr) {
                    return;
                }
                nset.erase((*t).get_key());
                delete t;
            }

            Node* t = (*dlist).push_front(key, value);
            if (t != nullptr) {
                nset[key] = t;
                // cout << "key = " << key << " value = " << value << endl;
            } else {
                cout << "push result nullptr" << endl;
            }
        }
    }
private:
    DList* dlist;
    unordered_map<int, Node*> nset;
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main() {
    LRUCache a(1);
    a.put(2, 1);
    cout << a.get(2) << endl;

    return 0;
}
