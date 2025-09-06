#include <iostream>

struct S1 { char a; int b; double c; char d;};  // 24 bytes
struct S2 { double c; int b; char a; char d; }; // 16 bytes
// Same fields, different layout + padding!

int main() {
    S1 s1 = {'a', 1, 2.0, 'd'};
    S2 s2 = {'a', 1, 2.0, 'd'};
    std::cout<< &s1.a << " " << &s1.b << " " << &s1.c << " " << &s1.d << std::endl;
    std::cout<< &s2.a << " " << &s2.b << " " << &s2.c << " " << &s2.d << std::endl;
    std::cout<< sizeof(s1.a) << " " << sizeof(s1.b) << " " << sizeof(s1.c) << " " << sizeof(s1.d) << std::endl;
    std::cout<< sizeof(s1) << " " << sizeof(s2) << std::endl;
    return 0;

}