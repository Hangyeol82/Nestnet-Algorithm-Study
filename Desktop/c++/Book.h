#ifndef BOOK_H 
#define BOOK_H
#include <string>
#include <ostream>

class Book
{
    std::string title;
    int price;
    int pages;

public:
    Book(const std::string & = std::string(), int = 0, int = 0); // 초기화 리스트를 사용해 볼 것 
    const std::string &getTitle() const;
    friend bool operator!(Book &);
    friend Book& operator++(Book &);
    friend Book operator++(Book &, int);
    friend std::ostream& operator<<(std::ostream&, const Book &);
};
#endif