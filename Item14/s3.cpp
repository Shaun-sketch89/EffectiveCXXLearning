//
// Created by 姚轩 on 2023/9/26.
//
#include <iostream>

class SomeKindOfResource{
public:
    SomeKindOfResource(int id)
    : resourceID(id)
    {
        std::cout << "resource ctor called" << std::endl;
    }
    ~SomeKindOfResource(){
        std::cout << "resource dtor called" << std::endl;
    }
    SomeKindOfResource(const SomeKindOfResource& rhs)
    : resourceID(rhs.resourceID)
    {
        std::cout << "resource copy ctor called" << std::endl;
    }
    SomeKindOfResource& operator=(const SomeKindOfResource& rhs){
        resourceID = rhs.resourceID;
        return *this;
    }
    void setResourceID(int id){
        resourceID = id;
    }
    int getResourceID(){
        return resourceID;
    }
private:
    int resourceID;
};

// raii class
// this class will copy the underlying resource (deep copy)
class ResourceManager{
public:
    ResourceManager(SomeKindOfResource* pr)
    : resource(pr)
    {}
    ~ResourceManager(){delete resource;}
    ResourceManager(const ResourceManager& rhs){
        // deep copy
        resource = new SomeKindOfResource(*rhs.resource);
    }
    ResourceManager& operator=(const ResourceManager& rhs){
        *resource = *rhs.resource;
        return *this;
    }
    void setResourceID(int id){
        resource ->setResourceID(id);
    }
    int getResourceID(){
        return resource -> getResourceID();
    }
private:
    SomeKindOfResource *resource;
};

int main(){
    ResourceManager resourceManager1(new SomeKindOfResource(1));
    // resource manager is copied
    ResourceManager resourceManager2(resourceManager1);
    ResourceManager resourceManager3(new SomeKindOfResource(5));
    resourceManager3 = resourceManager1;

    // test resource being managed is a deep copy
    resourceManager1.setResourceID(2);
    std::cout << resourceManager1.getResourceID() << std::endl;
    std::cout << resourceManager2.getResourceID() << std::endl;

    return 0;
}