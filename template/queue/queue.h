#pragma once

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
        template <typename Iter>
        Queue(Iter begin, Iter end): head(0), tail(0) {
            copy_elems(begin, end);
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
        template <typename Iter>
        void assign(Iter, Iter);
    private:
        QueueItem<T>* head;
        QueueItem<T>* tail;
        void destroy();
        void copy_elems(const Queue&);
        template <typename Iter>
        void copy_elems(Iter, Iter);
};
/*
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
*/

// 包含编译模型，这一策略使我们能够保持头文件和实现文件的分享， 同时保证编译器在编译使用模板的代码时能看到两种文件。
// 可能的问题是如果两个或多个单独编译的源文件使用同一模板， 这些编译器将为每个文件中的模板产生一个实例。 
// 在链接的时候，或者在预链接阶段，编译器会选择一个实例化而丢弃其他的
// 编译性能会显著降低
#include "queue.cc"