#include <iostream>
#include "QueueArray.h"
#include "QueueList.h"
#include "DoubleLinkedList.h"
#include "StackArray.h"
#include "StackList.h"

using namespace std;


int main(void) {
    QueueList<int> q1;
    for (int i = 0; i < 10; i++)
        q1.enqueue(i);

    q1.print();

    move_first_to(q1, 5);

    q1.print();
}