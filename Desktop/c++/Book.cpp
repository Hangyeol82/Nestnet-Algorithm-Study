#include "Book.h"
using namespace std;


Book::Book(const string &title, int price, int pages)
: title(title), price(price), pages(pages){} // 초기화 리스트를 사용해 볼 것

const string& Book::getTitle() const{
    return title;
}

bool operator!(Book &book){
    return book.price == 0;
}

Book& operator++(Book &book){
    book.price+=(book.price/10);
    return book;
}

Book operator++(Book &book, int x){
    Book tmp = book;
    book.price+=(book.price/10);
    return tmp;
}

ostream &operator<<(ostream& out, Book& book){
    return out << "책이름: " << book.title << "가격: " << book.price << "페이지수: " << book.pages;
}
