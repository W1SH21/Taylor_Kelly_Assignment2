#include <string>
#include <fstream>
#include <iostream>
#include "ItemType.h"
#include "ListNode.h"
#include "SortedLinkedList.h"

using namespace std;

int main(int argc, char* argv[]) {
    while (true) {
        string uinput, slist;
        SortedLinkedList list;
        ifstream fin;
        fin.open(argv[1]); // read input file
        while (fin) {
            
        }
        fin.close();
        cout << "Commands:" << endl;
        cout << "(i) - Insert value" << endl;
        cout << "(d) - Delete value" << endl;
        cout << "(s) - Search value" << endl;
        cout << "(n) - Print next iterator value" << endl;
        cout << "(r) - Reset iterator" << endl;
        cout << "(a) - Delete alternate nodes" << endl;
        cout << "(m) - Merge two lists" << endl;
        cout << "(t) - Intersection" << endl;
        cout << "(p) - Print list" << endl;
        cout << "(l) - Print length" << endl;
        cout << "(q) - Quit program" << endl;
        cin >> uinput;
        if (uinput == "i") {
            
        } else if (uinput == "d") {
            
        } else if (uinput == "s") {
            
        } else if (uinput == "n") {
            
        } else if (uinput == "r") {
            
        } else if (uinput == "a") {
            
        } else if (uinput == "m") {
            list.mergeList();
        } else if (uinput == "t") {
            
        } else if (uinput == "p") {
            
        } else if (uinput == "l") {
            
        } else if (uinput == "q") {
            return 0;
        } else {
            cout << "Invalidcommand, try again!" << endl;
        } // read user input
    } // command line input loop
} // main
