#include <iostream>
template<typename T>
class NamedObject{
public:
    NamedObject(std::string& name, const T& value)
    :nameValue(name),
     objectValue(value)
    {}
    /*
    NamedObject(const NamedObject<T>& rhs){
        nameValue = rhs.nameValue;
        objectValue = rhs.objectValue;
    }
    NamedObject<T>& operator=(const NamedObject<T>& rhs){
        nameValue = rhs.nameValue;
        objectValue = rhs.objectValue;
        return *this;
    }
     */
private:
    std::string& nameValue;
    const T objectValue;
};

int main() {
    std::string newDog("Persephone");
    std::string oldDog("Satch");
    NamedObject<int> p(newDog, 2);
    NamedObject<int> s(oldDog, 36);
    // code won't be compiled with following code
    //p = s;

    return 0;
}
