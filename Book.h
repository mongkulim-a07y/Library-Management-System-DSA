#ifndef BOOK_H
#define BOOK_H
#include <string>
// TODO: declare class Book here
class Book {
private:
    std::string ID;
    std::string title;
    std::string author;
    int year;
    int totalCopies;
    int availableCopies;
public:
    Book();
    Book(std::string ID, std::string title);
    Book(std::string ID, std::string title, std::string author, int year);

    std::string getTitle();
    std::string getID();
    std::string getauthor();
    int getYear();
    int getTotalCopies();
    int getAvailableCopies();
    int getBorrowedCount();
    bool isAvailable();

    bool setTitle(std::string title);
    bool setAuthor(std::string author);
    bool setYear(int year);
    bool setTotalCopies(int total);
    bool setCopies(int total, int available);

    bool borrowCopy();
    bool returnCopy();


    void display();
    std::string toFileLine();
};


#endif
