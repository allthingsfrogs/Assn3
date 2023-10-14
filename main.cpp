#include <iostream>
#include <fstream>
#include "StackType.hpp"
using namespace std;

bool IsOperator (string c) { //determine if char c is an operator
    if ((c == "+") or (c == "-") or (c == "*") or (c == "/") or (c == "(") or (c == ")")) return true;
    else return false; //if false, char c is an operand not operator
}

int setPrecedence(string c) { //highest precendence to close ), lowest to open (, PEMDAS for the rest
    if (c == "/" or c == "*") return 3;
    else if (c == "+" or c == "-") return 2;
    else return 0; //operands have no precedence, they get printed immediately
}


bool isCharPrioritized(string x, string y) { //helper function to compare str with operators on stack
    int c1prec = setPrecedence(x);
    int c2prec = setPrecedence(y);
    if (c2prec >= c1prec) return true;
    else return false;
}

int main() {
    ofstream outfile; //ostream object for output.txt
    outfile.open("output.txt", ios::app);//ios:app allows for appending to file, does not overwrite contents    
    
    string infix; // input string
    StackType S; //our Stack

    while (getline(cin, infix)) {
        bool space_count = false;
        string postfix; //our output string
        string str; //current char in our input string
        bool op; //bool for if string char is an operator

        for (int i = 0; i < infix.length(); i++){ //for each line/infix expression
            str = infix.at(i);  
            
            if (str == " ") continue; //ignore whitespace, dont add into postfix expresion
            
            if (str == ";" or str == ".") break;

            op = IsOperator(str); //check if str is an operator
            if (op == false) postfix += str; //if not an operator, append to output string
            
            else if (str == "(") S.Push(str); //if its a ( then push to stack, ( and ) dont have an assigned precedence they are special cases
            
            else if (str == ")") { //add to our postfix any operators from stack, and pop off stack until ( is encountered
                while(S.Top() != "(") { //append to output and pop from stack until matching ( is encountered
                    postfix += S.Top();
                    S.Pop();
                } 
                S.Pop(); //pop remaining (
            }
            else { //op = true, str is an operator  
                //pop off all operators from stack that are >= str
                while ((!S.IsEmpty()) and (isCharPrioritized(str, S.Top()))) {            
                    postfix += S.Top(); //pop off all operators from stack that are >= str
                    S.Pop();
                }
                S.Push(str); //push str onto stack after done popping
            }
        }
        while (!S.IsEmpty()) { //print out anything left on stack
            postfix += S.Top();
            S.Pop();
        }
        cout << "Infix: " << infix << endl;
        cout << "Postfix: ";
        for (auto &c : postfix) { 
            if (isalpha(c) or ispunct(c)) cout << c << " "; 
        }
        cout << endl;
    }
    outfile.close(); //close that silly file

    return 0;
}

/*
(void walkStack(StackType& S) { //helper function to walk through and print entire stack
    string temp;
        while (S.IsEmpty())
            if (S.IsEmpty()) {  
                cout << "EMPTY" << endl;
                return;
            }
            temp = S.Top(); 
            cout << temp << " ";
            S.Pop();
}
*/