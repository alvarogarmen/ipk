#include <iostream>
#include <list>
#include <algorithm>

void reverseList(std::list<int> &lst) {
    auto start = lst.begin();
    auto end = lst.end();
    --end; // Pointing to the last element

    while (start != end && start != std::prev(end)) {
        std::swap(*start, *end);
        ++start;
        --end;
    }
}

void zigzag(std::list<int> &lst) {
    lst.sort(); // Sort the list in ascending order

    std::list<int> result;
    auto it = lst.begin();
    auto end = lst.end();

    while (it != end) {
        if (it != end) {
            result.push_back(*it);
            ++it;
        }
        if (it != end) {
            --end;
            result.push_back(*end);
        }
    }

    lst = result;
}

void printList(const std::list<int> &lst) {
    for (const auto &elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::list<int> emptyList;
    std::list<int> oddList = {1, 3, 5, 7, 9};
    std::list<int> evenList = {2, 4, 6, 8};

    // Test reverseList function
    std::cout << "Testing reverseList function:" << std::endl;
    std::cout<<"Original lists: "<<std::endl;
    printList(oddList);
    printList(evenList);

    std::cout<<"Empty List: "<<std::endl;
    reverseList(emptyList);
    printList(emptyList);

    std::cout<<"Now with odd number of elements"<<std::endl;
    reverseList(oddList);
    std::cout<<"Reversed list: ";
    printList(oddList);
    std::cout<<"Now with even number of elements:"<<std::endl;
    reverseList(evenList);
    printList(evenList);

    // Test zigzag function
    std::cout << "Testing zigzag function:" << std::endl;
    std::cout<<"Empty List: "<<std::endl;

    zigzag(emptyList);
    printList(emptyList);
    std::cout<<"Now with odd number of elements"<<std::endl;

    zigzag(oddList);
    printList(oddList);
    std::cout<<"Now with even number of elements"<<std::endl;

    zigzag(evenList);
    printList(evenList);

    return 0;
}
