#include <string>
#include "ItemType.h"

ItemType::ItemType() {
}

ItemType::Comparison ItemType::compareTo(ItemType item) {
    if (item.getValue() > value) {
        return LESS;
    } else if (item.getValue() < value) {
        return GREATER;
    } else {
        return EQUAL;
    } //if
} // compareTo

int ItemType::getValue() const {
    return value;
} // getValue

void ItemType::initialize(int num) {
    value = num;
} // initialize
