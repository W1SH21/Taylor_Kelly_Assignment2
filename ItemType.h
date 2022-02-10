#include <string>

using namespace std;

enum Comparison {GREATER, LESS, EQUAL};

class ItemType {
private:
    int value;
    
public:
    ItemType();
    Comparison compareTo(ItemType item);
    int getValue() const;
    void initialize(int num);
};



