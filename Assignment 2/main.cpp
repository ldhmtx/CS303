#include "linked.h"
#include "linked.cpp"
#include "employee.h"
#include "non-pro.h"
#include "pro.h"

int main() {
    //Question 1 Outputs using predetermined values:
    cout << "Question 1 Ouput:\n\nTesting all functions with given list 1-5: \n\n";
    Single_Linked_List<int> sll;
    sll.push_back(1);
    sll.push_back(2);
    sll.push_back(3);
    sll.push_back(4);
    sll.push_back(5);

    sll.print_list();
    
    cout << "Inserting values 9 at the front and 8 in the back: ";
    sll.push_front(9);
    sll.push_back(8);
    sll.print_list();

    cout << "Removing the front/back values we just added: ";
    sll.pop_front();
    sll.pop_back();
    sll.print_list();

    cout << "Front: " << sll.front() << std::endl;
    cout << "Back: " << sll.back() << std::endl;
    
    cout << "Inserting 41 at index 4: ";
    sll.insert(4,41);
    sll.print_list();

    cout << "Finding 41 in the list and returning found index: ";
    int hitt = sll.find(41);
    if (hitt == -1) {
        cout << "Item not found";
    }
    else {
        cout << hitt; 
    }

    //Question 2 Outpus using predetermined people:
    cout << endl << "-Question 2 Output-" << endl;
    //professional employee
    Professional Professional("Example Man", 13.5, 40);
    Professional.print();

    cout << endl;
    //non professional employee
    NonPro NonPro("Other Man", 11.5, 40);
    NonPro.print();
    return 0;
}