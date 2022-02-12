#include "ItemType.h"
#include "ListNode.h"
#include "SortedLinkedList.h"
#include <iostream>

SortedLinkedList::SortedLinkedList() {
  head = NULL;
  currentPos = NULL;
  size = 0;
} //SortedLinkedList

SortedLinkedList::~SortedLinkedList() {

} //~SortedLinkedList

int SortedLinkedList::length() const {
  return size;
} //length

ListNode* SortedLinkedList::getHead() {
  return head;
} //getHead

void SortedLinkedList::insertItem(ItemType item) {
  ListNode* temp = head;
  bool flag = true;
  if (size == 0 || (item.compareTo((temp->item)) == ItemType::LESS)) {
    ListNode* newItem = new ListNode();
    newItem->item = item;
    newItem->next = head;
    head = newItem;
    flag = false;
    size ++;
  } else {
    for (int i = 0; i < size - 1; i ++) {
      if ((item.compareTo(temp->item) == ItemType::GREATER) && (item.compareTo((temp->next)->item) == ItemType::LESS)) {
	ListNode* newItem = new ListNode();;
	newItem->item = item;
	newItem->next = temp->next;
	temp->next = newItem;
	size ++;
	flag = false;
      } //if
    } //for
    if ((item.compareTo(temp->item) == ItemType::GREATER) && flag) {
      ListNode* newItem = new ListNode();
      newItem->item = item;
      newItem->next = NULL;
      temp->next = newItem;
      size ++;
    } //if
  } //if
} //insertItem


int SortedLinkedList::searchItem(ItemType item) {
  ListNode* temp = head;
  int index = 0;
  while ((temp->next) != NULL) {
    if (item.compareTo(temp->item) == ItemType::EQUAL) {
      return index;
    } else {
      temp = temp->next;
      index ++;
    } //if
  } //while
  return -1;
} //searchItem

void SortedLinkedList::deleteItem(ItemType item) {
  int index = this->searchItem(item);
  if (index == -1) {
    cout << "You cannot delete from an empty list." << endl;
  } else if (index == 0) {
    ListNode* temp = head->next;
    head = temp;
    size --;
  } else if (index == size - 1) {
    ListNode* temp = head;
    for (int i = 0; i < index - 1; i ++) {
      temp = temp->next;
    } //for
    temp->next = NULL;
    size --;
  } else {
    ListNode* temp = head;
    for (int i = 0; i < index - 1; i ++) {
      temp = temp->next;
    } //for
    temp->next = (temp->next)->next;
    size --;
  } //if
} //delteItem

ItemType SortedLinkedList::GetNextItem() {
  ItemType out = ItemType();
  if (size == 0) {
    cout << "List is empty." << endl;
    out.initialize(-1);
  } else if (itrPos == (size)) {
    cout << "The end of the list has reached" << endl;
    out.initialize(-1);
  } else if ((itrPos == 0) && (size != 0)) {
    currentPos = head->next;
    itrPos ++;
    out = (head->item);
  } else {
    ListNode* temp = currentPos;
    currentPos = currentPos->next;
    out = (temp->item);
    itrPos++;
  } //if
  return out;
} //getNextItem

void SortedLinkedList::ResetList() {
  currentPos = NULL;
  itrPos = 0;
} //ResetList


void SortedLinkedList::printList(){
  ListNode* temp = head;
  while ((temp->next) != NULL) {
    cout << ((temp->item).getValue()) << " ";
    temp = temp->next;
  } //while
  cout << endl;
} //printList

/**
 * Psudocode for merge:
 * 
 * Create temp var for head of calling list;
 * Iterate calling list using temp and calls insert on each;
 * Change temp to head of param list;
 * Iterates through param list using temp and calls insert on each;
 *
 * Psudocode for insert:
 * if list is empty:
 *     set head to new value;
 *     increment size;
 * else:
 *    iterate over calling list:
 *        if greater than current less than next:
 *            set next to temp;
 *            set current's next to new;
 *            set new next to temp;
 *            increment size;
 *    if not already added and is greater:
 *        set last elem's next to new elem;
 *        increment size;
 * 
 * Time Complexity:
 * If inserts are used as the metric: O(n) 
 * If compares are used as the metric: O(n^2)
 *
 */
/*
void SortedLinkedList::mergeList(SortedLinkedList list) {
  SortedLinkedList out = new SortedLinkedList();
  ListNode* temp;
  temp = head;
  for (int i = 0; i < size - 1; i ++) {
    out.insertItem(temp->item);
    temp = temp->next;
  } //for
  temp = list.getHead();
  bool flag = false;
  for (int i = 0; i < list.length() - 1; i ++) {
    if (out.searchItem(temp->item) == -1) {
      flag = true;
      break;
    } else {
      out.insertItem(temp->item);
      temp = temp->next;
    } //if
  } //for

  if (flag) {
    cout << "Sorry. You cannot insert the duplicate item." << endl;
  } else {
    
  } //if
} //mergeList
*/

void SortedLinkedList::mergeList(SortedLinkedList list) {
  ListNode* temp;
  temp = head;
  bool flag = false;
  while ((temp->next) != NULL) {
    if (list.searchItem(temp->item) == -1) {
      flag = true;
    } //if
  } //while

  if (flag) {
    cout << "Sorry. You cannot insert the duplicate item." << endl;
  } else {
    temp = list.getHead();
    while ((temp->next != NULL)) {
      this->insertItem(temp->item);
      temp = temp->next;
    } //while
    this->printList();
  } //if
  
} //mergeList

void SortedLinkedList::findCommonElements(SortedLinkedList list) {
}
