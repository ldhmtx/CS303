#include "func.h"
#include "queue.h"

using namespace std;

bool kor = false;

//main menu function
void cenmenu(bool &dog) {
    string menu = "\nWelcome to my assignment!\n1. Infix to Postfix\n2. Queue thing\n3. Quit\n>>";
    do { //while user wishes to continue
        cout << menu;
        char valj;
        cin >> valj;
        switch (valj) {
        case '1': //evaluating an infix equatiom to postfix
            i2f();
            break;
        case '2': //queue implementation
            qLaga();
            break;
        case '3': //exiting program
            cout << "See ya later.";
            kor = true;
            dog = false;
            break;
        default: //if given incorrect/unrecognized input
            cout << "Your input is not correct, try again.";
            break;
        }

    } while (kor == false);
}

//working with the operators
void bearbeta(char i, stack<char>& utvard, string& pf) {
    if (utvard.empty()) { //if the stack is still empty
        utvard.push(i);
    }
    else {
        //comparing precedence with top of stack
        if (precedence(i) > precedence(utvard.top())) {
            utvard.push(i);
        }
        else {
            while (!utvard.empty() && (precedence(i) <= precedence(utvard.top()))) {
                pf += utvard.top();
                utvard.pop();
            }
            utvard.push(i); //add to the stack
        }
    }
}

void i2f() {
    string uttryck = ""; //user input string
    cout << "Give me an expression to evaluate sir:\n>>";
    cin.ignore(); //if wrong input
    getline(cin, uttryck); //user input

    if (!goodBalance(uttryck)) { //checking balance of the equation the user gave
        cout << "This equation isn't balanced correctly.\n";
        return;
    }

    stack<char> utvard; //stack we use to iterate with
    string pf = ""; //resulting string

    for (char i : uttryck) { //for each character within the given string
        if (isdigit(i)) { //if a number
            pf += i;
        }
        else if (isOP(i)) { //if operator true
            bearbeta(i, utvard, pf);
        }
    }

    while (!utvard.empty()) { //if the stack isn't empty
        char i = utvard.top();
        utvard.pop();
        pf += i; //add remaining operators to equation
    }

    cout << pf << endl; //display to user
}

//checking if an operator or not
bool isOP(char i) {
    return (i == '+' || i == '-' || i == '*' || i == '/');
}

//assigning precedence
int precedence(char i) {
    if (i == '+' || i == '-') {
        return 1;
    }
    else if (i == '*' || i == '/') {
        return 2;
    }
    return 0;
}

//this is the equation that actually checks the parentheses if they are good or not
bool goodBalance(const string& giv) {
    stack<char> st;
    for (char j : giv) { //for the entirety of the given string
        if (j == '('||j=='['||j=='{') { //if a starting value
            st.push(j);
        }
        else if (j == ')' || j == ']' || j == '}') {  //if ending value
            if (st.empty() || (j == ')' && st.top() != '(') || (j == ']' && st.top() != '[') || (j == '}' && st.top() != '{')) {
                return false; // Unbalanced parentheses
            }
            st.pop();
        }
    }
    return st.empty(); // If the stack is empty, parentheses are balanced
}

//function showing basic example demonstrating queue class's functions
void qLaga()
{
    Queue example;

    cout << "Making a queue with 3 values: 1, 2, 3" << endl<<endl;

    //adding to queue
    example.enqueue(1);
    example.enqueue(2);
    example.enqueue(3);

    //displaying/doing stuff to the queue
    cout << "Front:" << example.front() << endl;
    cout << "Dequeue: " << example.dequeue() << endl;
    cout << "Front:" << example.front() << endl;
    cout << "Size:" << example.size() << endl;
}

