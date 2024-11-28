#include "queue.h"

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
template <typename Iter>
void Queue<T>::assign(Iter begin, Iter end) {
    destroy();
    copy_elems(begin, end);
}

template <typename T>
template <typename Iter>
void Queue<T>::copy_elems(Iter begin, Iter end) {
    for (Iter i = begin; i != end; ++i) push(*i);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& q) {
    os << "<";
    for (QueueItem<T>* p = q.head; p; p = p->next) os << p->item << " ";
    os << ">";
    return os;
}