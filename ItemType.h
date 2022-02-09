#include <string>

using namespace std;

enum Comparison : string {GREATER, LESS, EQUAL};

class ItemType {
private:
    int value;
    
public:
    Itemtype();
    Comparison compareTo(ItemType item);
    int getValue() const;
    void initialize(int num);
};



