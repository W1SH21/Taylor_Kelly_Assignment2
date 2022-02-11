#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "ItemType.h"
#include "ListNode.h"
#include "SortedLinkedList.h"

using namespace std;

int main(int argc, char* argv[]) {
    ifstream fin;
    SortedLinkedList list;
    int num;
    fin.open(argv[1]); // read input file
    while (fin >> num) {
        ItemType number;
        number.initialize(num);
        list.insertItem(number);
    }
    fin.close();
    while (true) {
        string uinput;
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
            int ins;
            ItemType number;
            list.printList();
            cout << "Enter number: ";
            cin >> ins;
            cout << endl;
            number.initialize(ins);
            if (list.searchItem(number) == -1) {
                list.insertItem(number);
            } else {
                cout << "Sorry. You cannot insert the duplicate item." << endl;
            } // if
            list.printList();
        } else if (uinput == "d") {
            if (list.length() == 0) {
                cout << "You cannot delete from an empty list." << endl;
            } else {
                int del;
                ItemType number;
                list.printList();
                cout << "Enter value to delete: ";
                cin >> del;
                cout << endl;
                number.initialize(del);
                list.deleteItem(number);
                list.printList();
            } //if
        } else if (uinput == "s") {
            int search, index;
            ItemType number;
            cout << "Enter a value to search: ";
            cin >> search;
            number.initialize(search);
            index = list.searchItem(number);
            if (index == -1) {
                cout << "Item not found." << endl;
            } else {
                cout << "Index " << index << endl;
            } // if
        } else if (uinput == "n") {
            cout << list.GetNextItem().getValue() << endl;
        } else if (uinput == "r") {
            list.ResetList();
            cout << "Iterator reset." << endl;
        } else if (uinput == "a") {
            cout << "FUCK" << endl;
        } else if (uinput == "m") {
            string ulist;
            cout << "List elements separated by spaces in order: ";
            stringstream s(ulist);
            int temp;
            SortedLinkedList merger;
            while (s >> temp) {
                ItemType number;
                number.initialize(temp);
                merger.insertItem(number);
            }
            cout << "List 1: ";
            list.printList();
            cout << endl;
            cout << "List 2: ";
            merger.printList();
            cout << endl;
            list.mergeList(merger);
            list.printList();
        } else if (uinput == "t") {
            string ulist;
            cout << "List elements separated by spaces in order: ";
            stringstream s(ulist);
            int temp;
            SortedLinkedList intersector;
            while (s >> temp) {
                ItemType number;
                number.initialize(temp);
                intersector.insertItem(number);
            }
            cout << "List 1: ";
            list.printList();
            cout << endl;
            cout << "List 2: ";
            intersector.printList();
            cout << endl;
            list.findCommonElements(intersector);
            list.printList();
        } else if (uinput == "p") {
            list.printList();
        } else if (uinput == "l") {
            cout << "List length is " << list.length() << endl;
        } else if (uinput == "q") {
            return 0;
        } else {
            cout << "Invalid command, try again!" << endl;
        } // read user input
    } // command line input loop
} // main
