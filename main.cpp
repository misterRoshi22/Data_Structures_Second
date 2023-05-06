#include <iostream>
#include "QueueArray.h"
#include "QueueList.h"
#include "DoubleLinkedList.h"
#include "StackArray.h"
#include "StackList.h"
#include "OrderedList.h"

using namespace std;

void test_queue_array() {
    QueueArray<int> queue;
    for (int i = 0; i != 5; i++)
        queue.enqueue(i);
    queue.dequeue();
    queue.dequeue();
    int val = queue.get_first();
    queue.enqueue(val);

    queue.print();
}

void test_stack_array() {
    StackArray<int> stack;
    for (int i = 0; i != 5; i++)
        stack.push(i);
    stack.pop();
    stack.pop();
    int val = stack.get_top();
    stack.push(val);

    stack.print();
}

void test_order_list() {
    OrderedList<int> list1, list2;
    int x;
    x = 5;
    list1.insert(x);
    x = 7;
    list1.insert(x);
    x = 3;
    list1.insert(x);
    x = 4;
    list2.insert(x);
    x = 9;
    list2.insert(x);
    list1.merge_list(list2);
}

//Function to merge k ordered list into one list
template<class T>
OrderedList<T> merge_k_lists(OrderedList<T> arr[], int k) {
    Node<T> *curr[k];
    for (int i = 0; i < k; i++)
        curr[i] = arr[i].get_head();
    OrderedList<int> final_list;

    while (1) {

        int j = 0;
        for (int i = 0; i < k; i++) {
            if (curr[i] == nullptr) j++;
        }
        if (j == k) break;
        Node<T> *min_node = curr[0];
        int min_index = 0;
        int nulls = 0;
        for (int i = 0; i < k; i++) {
            if (!curr[min_index] && curr[i])
                min_index = i;
            else if (curr[min_index] && curr[i]) {
                if (curr[i]->val() < curr[min_index]->val())
                    min_index = i;
            }
        }
        final_list.insert(curr[min_index]->val());
        curr[min_index] = curr[min_index]->get_next();
    }

    return final_list;
}


void merge_k_list_tester() {
    OrderedList<int> arr[5];
    for (int i = 0; i < 5; i++) {
        int r = rand() % 10 + 1;
        for (int j = 0; j < r; j++) {
            int s = rand() % 100 + 1;
            arr[i].insert(s);
        }
        arr[i].print();
    }

    OrderedList<int> final_list = merge_k_lists(arr, 5);
    final_list.print();
}

const int N = 10;

//Function to partially reverse queue

int main(void) {
    OrderedList<int> o1;
    for (int i = 1; i < 5; i++)
        for (int j = 0; j < i; j++)
            o1.insert(i);
    o1.print();
    o1.remove_duplicates();
    o1.print();
}