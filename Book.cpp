#include "Book.h"
#include <iostream>
#include <iomanip>
using namespace std;

Book::Book(){
    this->ID = "";
    this->title = "";
    this->author = "";
    this->year = 0;
    this->totalCopies =0;
    this->availableCopies = 0;
}

Book::Book(std::string ID, std::string title) {
    this->ID = ID;
    this->title = title;
    this->author = "";
    this->year = 0;
    this->totalCopies = 1;
    this->availableCopies = 1;

}
Book::Book(std::string ID, std::string title, std::string author, int year){
    this->ID = ID;
    this->title = title;
    this->author = author;
    this->year = year;
    this->totalCopies = 1;
    this->availableCopies = 1;

}


std::string Book::getTitle(){
    return title;
}

std::string Book::getID(){
    return ID;
}
std::string Book::getauthor(){
    return author;
}

int Book::getYear(){
    return year;
}
int Book::getTotalCopies()  { return totalCopies; }
int Book::getAvailableCopies() { return availableCopies; }
int Book::getBorrowedCount() { return totalCopies - availableCopies; }
bool Book::isAvailable() { return availableCopies > 0; }

bool Book::setTitle(string title) {
    if (title.empty()) return false;
    this->title = title;
    return true;
}

bool Book::setAuthor(string author) {
    if (author.empty()) return false;
    this->author = author;
    return true;
}

bool Book::setYear(int year) {
    if (year < 1000 || year > 2026) return false;
    this->year = year;
    return true;
}

bool Book::setTotalCopies(int total) {
    int out = totalCopies - availableCopies;
    if (total < 1 || total < out) return false;
    totalCopies = total;
    availableCopies = total - out;
    return true;
}

bool Book::setCopies(int total, int available) {
    if (total < 1 || available < 0 || available > total) return false;
    totalCopies = total;
    availableCopies = available;
    return true;
}

bool Book::borrowCopy() {
    if (availableCopies <= 0) return false;
    availableCopies--;
    return true;
}

bool Book::returnCopy() {
    if (availableCopies >= totalCopies) return false;
    availableCopies++;
    return true;
}

void Book::display(){
    cout << left << setw(6) << ID
         << setw(16) << title
         << setw(10) << author
         << availableCopies << "/" << totalCopies << " available" << endl;
}

string Book::toFileLine(){
    return ID + "," + title + "," + author + "," +
           to_string(year) + "," + to_string(totalCopies) + "," +
           to_string(availableCopies);
}
