#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include "ListNode.h"

class SortedLinkedList {

private:
  ListNode *head;
  ListNode *currentPos;
  int size;
  int itrPos;

  
  
 public:

  SortedLinkedList();

  ~SortedLinkedList();

    ListNode* getHead();
  int length() const;
  void insertItem(ItemType item);
  void deleteItem(ItemType item);
  int searchItem(ItemType item);
  ItemType GetNextItem();
  void ResetList();
  void printList();
  void mergeList(SortedLinkedList list);
  void findCommonElements(SortedLinkedList list);
}; //SortedLinkedList

#endif
