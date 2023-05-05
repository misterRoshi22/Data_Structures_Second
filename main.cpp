#include <iostream>
#include "QueueArray.h"
#include "QueueList.h"
#include "DoubleLinkedList.h"
#include "StackArray.h"
#include "StackList.h"
#include "OrderedList.h"

using namespace std;


int main(void) {
    QueueArray<int> q1;
    for (int i = 1; i <= 10; i++)
        q1.enqueue(i);

    OrderedList<int> o1;

    for (int i = 0; i < 20; i++) {
        int r = rand() % 20 + 1;
        o1.insert(r);
        o1.print();
    }


}