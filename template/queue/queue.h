#include <iostream>

// 声明依赖性
template <typename T>
class Queue;

template <typename T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <typename T>
class QueueItem {
    // Queue<T> 是 QueueItem<T> 的友元类
    friend class Queue<T>;
    QueueItem(const T& t): item(t), next(0) {}
    T item;
    QueueItem* next;
};

template <typename T>
class Queue {
    friend std::ostream& operator<< <T>(std::ostream&, const Queue&);
    public:
        Queue(): head(0), tail(0) {}
        Queue(const Queue& q): head(0), tail(0) {
            copy_elems(q);
        }
        ~Queue() {
            destroy();
        }
        Queue& operator=(const Queue&);
        T& front() {
            if (head == 0) throw std::runtime_error("front of empty queue");
            return head->item;
        }
        void push(const T&);
        void pop();
        bool empty() const {
            return head == 0;
        }
    private:
        QueueItem<T>* head;
        QueueItem<T>* tail;
        void destroy();
        void copy_elems(const Queue&);
};

template <typename T>
void Queue<T>::destroy() {
    while (!empty()) pop();
}

template <typename T>
void Queue<T>::copy_elems(const Queue& orig) {
    for (QueueItem<T>* src = orig.head; src; src = src->next) push(src->item);
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& rhs) {
    if (this == &rhs) return *this;
    destroy();
    copy_elems(rhs);
    return *this;
}

template <typename T>
void Queue<T>::push(const T& t) {
    QueueItem<T>* new_item = new QueueItem<T>(t);
    if (empty()) head = tail = new_item;
    else {
        tail->next = new_item;
        tail = new_item;
    }
}

template <typename T>
void Queue<T>::pop() {
    if (empty()) throw std::runtime_error("pop of empty queue");
    QueueItem<T>* p = head;
    head = head->next;
    delete p;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& q) {
    os << "<";
    for (QueueItem<T>* p = q.head; p; p = p->next) os << p->item << " ";
    os << ">";
    return os;
}
