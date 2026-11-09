#include <iostream>
#include "BOOK.H"
#include "MEMBER.H"
using namespace std;
int main() {
    // TODO: load files, show the main menu, save files

    Book b("B001", "C++ Primer", "Lippman", 2012);
    b.setTotalCopies(3);
    b.display();                          // expect 3/3 available
    b.borrowCopy();
    b.display();                          // expect 2/3 available
    cout << b.toFileLine() << endl;       // expect B001,C++ Primer,Lippman,2012,3,2

    Book empty;
    cout << empty.isAvailable() << endl;  // expect 0
    cout << empty.borrowCopy() << endl;   // expect 0

    // Member tests
    Member m("M001", "Sok Dara", "098765432");
    cout << m.addLoan("B001", "21-11-2026") << endl;   // expect 1
    cout << m.addLoan("B001", "21-11-2026") << endl;   // expect 0 (same book twice)
    cout << m.addLoan("B002", "21-11-2026") << endl;   // expect 1
    cout << m.addLoan("B003", "21-11-2026") << endl;   // expect 1
    cout << m.addLoan("B004", "21-11-2026") << endl;   // expect 0 (limit of 3)
    m.removeLoan("B002");
    m.display();                          // expect 2 loans: B001 and B003
    cout << m.addLoan("B000", "21-11-2026") << endl;
    cout << m.toFileLine() << endl;       // expect M001,Sok Dara,098765432,B001:21-11-2026;B003:21-11-2026
    return 0;
}
