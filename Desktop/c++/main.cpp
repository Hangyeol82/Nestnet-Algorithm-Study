#include "Book.h"
#include <iostream>
using namespace std;
int main()
{
    Book book1("벼룩시장", 0, 50), book2("C++", 10000, 1000); // 가격은 0
    if (!book1)
        cout << "공짜다" << endl;
    cout << ++book2 << endl;
    cout << book2++ << endl;
    cout << book2 << endl;
}