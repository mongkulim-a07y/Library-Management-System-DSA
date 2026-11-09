#ifndef MEMBER_H
#define MEMBER_H

// TODO: declare class Member here
#include <string>

class Member {
public:
    static const int MAX_LOANS = 3;

private:
    std::string id;
    std::string name;
    std::string phone;
    std::string loanBookIds[MAX_LOANS];
    std::string loanDueDates[MAX_LOANS];
    int loanCount;

public:
    Member();
    Member(std::string id, std::string name);
    Member(std::string id, std::string name, std::string phone);

    std::string getId() ;
    std::string getName() ;
    std::string getPhone();
    int getLoanCount();
    std::string getLoanBookId(int index);
    std::string getLoanDueDate(int index);
    bool hasBook(std::string bookId);

    bool setName(std::string name);
    bool setPhone(std::string phone);

    bool addLoan(std::string bookId, std::string dueDate);
    bool removeLoan(std::string bookId);

    void display();
    std::string toFileLine();
};

#endif
