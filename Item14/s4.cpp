//
// Created by 姚轩 on 2023/9/27.
//
/*

Transfer ownership of the underlying resource

choose std::auto_ptr and std::unique_ptr

differences:
1.
std::auto_ptr<int> p(new int);
std::auto_ptr<int> p2 = p;

std::unique_ptr<int> p(new int);
std::unique_ptr<int> p2 = std::move(p);

2.
auto_ptr will attempt to call delete
while unique_ptr can handle arrays correctly(call delete[])
*/