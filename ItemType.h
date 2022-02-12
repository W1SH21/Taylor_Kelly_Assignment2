#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <string>

using namespace std;

class ItemType {
private:
    int value;
    
public:
    enum Comparison {GREATER, LESS, EQUAL};
    ItemType();
    Comparison compareTo(ItemType item);
    int getValue() const;
    void initialize(int num);
};

#endif
