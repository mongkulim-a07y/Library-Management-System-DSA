#include "Member.h"
#include <iostream>
using namespace std;
// TODO: write the method code for Member here
    Member::Member(){
        this->id = "";
        this->name = "";
        this->phone = "";
        loanCount = 0;
    }

    Member::Member(std::string id, std::string name){
        this->id = id;
        this->name = name;
        this->phone = "";
        loanCount = 0;
    }

    Member::Member(std::string id, std::string name, std::string phone){
        this->id = id;
        this->name = name;
        this->phone = phone;
        loanCount = 0;
    }

    string Member::getId(){return id;}
    string Member::getName() {return name;}
    string Member::getPhone(){return phone;}
    int Member::getLoanCount(){return loanCount;}
    string Member::getLoanBookId(int index){ return loanBookIds[index]; }
    string Member::getLoanDueDate(int index){ return loanDueDates[index]; }


    bool Member::hasBook(string bookID){
        for (int i=0;i<loanCount;i++){
            if(loanBookIds[i] == bookID){
                return true;
            }
        }
        return false;
    }

    bool Member::setName(string name){
        if(name.empty()){
            return false;
        }
        this->name = name;
        return true;
    }

    bool Member::setPhone(string phone){
        if(phone.empty()){
            return false;
        }
        this->phone = phone;
        return true;
    }

    bool Member::addLoan(string bookID, string dueDate){
        if(loanCount >= MAX_LOANS || hasBook(bookID)) {
            return false;
        }
        loanBookIds[loanCount] = bookID;
        loanDueDates[loanCount] = dueDate;
        loanCount++;
        return true;
    }

    bool Member::removeLoan(string bookID){
        for(int i=0;i<loanCount ;i++){
            if(loanBookIds[i] == bookID){
                for (int j = i; j < loanCount - 1; j++) {
                loanBookIds[j] = loanBookIds[j + 1];
                loanDueDates[j] = loanDueDates[j + 1];
                }
                loanCount--;
                return true;
            }
        }
        return false;
    }

void Member::display() {
    cout << "ID:     " << id << endl;
    cout << "Name:   " << name << endl;
    cout << "Phone:  " << phone << endl;
    cout << "Loans:  " << loanCount << " of " << MAX_LOANS << endl;
    for (int i = 0; i < loanCount; i++)
        cout << "        " << loanBookIds[i]
             << ", due " << loanDueDates[i] << endl;
}


string Member::toFileLine(){
    string loans = "";
    for (int i = 0; i < loanCount; i++) {
        if (i > 0) loans += ";";
        loans += loanBookIds[i] + ":" + loanDueDates[i];
    }
    return id + "," + name + "," + phone + "," + loans;
}
