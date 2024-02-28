//
// AlignedArray holds a consecutive memory space.
// Here we use it as an example class to implement the assignment operator introduced in item11 of C++ Effective
// Deep copy is done in assignment operator and two alternatives are implemented to strive for both self-assignment-safe and exception-safe code!!
// Created by 姚轩 on 2024/2/28.
//
#define ALIGNMENT 256
typedef float scalar_t;
const size_t ELEM_SIZE = sizeof(scalar_t);

class AlignedArray {
public:
    AlignedArray(const size_t size) {
        int ret = posix_memalign((void**)&ptr, ALIGNMENT, size * ELEM_SIZE);
        if (ret != 0) throw std::bad_alloc();
        this->size = size;
    }
    ~AlignedArray() { free(ptr); }
    AlignedArray& operator=(const AlignedArray& rhs){
        scalar_t* pOrig = ptr;
        int ret = posix_memalign((void**)&ptr, ALIGNMENT, rhs.size * ELEM_SIZE);
        if (ret != 0) throw std::bad_alloc();
        std::memcpy(ptr, rhs.ptr, rhs.size * ELEM_SIZE);
        free(pOrig);
        return *this;
    }
    size_t ptr_as_int() {return (size_t)ptr; }
private:
    scalar_t* ptr;
    size_t size;
};