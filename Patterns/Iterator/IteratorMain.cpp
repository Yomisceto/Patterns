
#include "Iterator.h"

void IteratorCode() {
    std::cout << "________________Iterator with int______________________________________" << std::endl;
    Container<int> cont;

    for (int i = 0; i < 10; i++) { cont.add(i); }

    Iterator<int, Container<int>>* it = cont.CreateIterator();

    for (it->first(); !it->IsDone(); it->Next()) { std::cout << *it->Current() << std::endl; }

    delete it;
}
//
//int main(void)
//{
//   
//    IteratorCode();
//    return 0;
//}