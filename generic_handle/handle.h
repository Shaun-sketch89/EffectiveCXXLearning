// 句柄类作用：
// 1. 提供管理使用计数和基础对象的操作。
// 2. 句柄类的用户无需关心指针的管理（比如不再需要实现拷贝控制成员以及析构成员）。
template <typename T>
class Handle {
public:
    Handle(T *p = 0): ptr(p), use(new std::size_t(1)) {}
    Handle(const Handle& h): ptr(h.ptr), use(h.use) { ++*use; }
    Handle& operator=(const Handle&);
    ~Handle();
    T& operator*();
    const T& operator*() const;
    T* operator->();
    const T* operator->() const;

private:
    T *ptr;
    std::size_t *use;
    void decr_use() {
        if(--*use == 0) {
            delete ptr;
            delete use;
        }
    }
};

template <typename T>
inline Handle<T>& Handle<T>::operator=(const Handle& rhs) {
    ++*rhs.use;
    decr_use();
    ptr = rhs.ptr;
    use = rhs.use;
    return *this;
}

template <typename T>
inline T& Handle<T>::operator*() {
    if(ptr) return *ptr;
    else throw std::logic_error("unbound Handle");
}

template <typename T>
inline const T& Handle<T>::operator*() const {
    if(ptr) return *ptr;
    else throw std::logic_error("unbound Handle");
}

template <typename T>   
inline T* Handle<T>::operator->() {
    if(ptr) return ptr;
    else throw std::logic_error("unbound Handle");
}

template <typename T>
inline const T* Handle<T>::operator->() const {
    if(ptr) return ptr;
    else throw std::logic_error("unbound Handle");
}

template <typename T>
inline Handle<T>::~Handle() { decr_use(); }