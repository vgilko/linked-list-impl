//
// Created by avmd on 28.02.23.
//
#include "SingleLinkedList.h"
#include "list.h"
#include <stdexcept>
#include <iostream>

using namespace lab618;

namespace SingleLinkedListTest {

    void testErase() {
        CSingleLinkedList<MyStruct> list;

        list.pushBack({1, 1.0});
        list.pushBack({2, 2.0});
        list.pushBack({3, 3.0});

        CSingleLinkedList<MyStruct>::CIterator iter = list.begin();
        ++iter;
        list.erase(iter);

        if (list.getSize() != 2) {
            throw std::runtime_error("Invalid result. testErase");
        }

        std::cout << "OK | testErase\n";
    }


    void testEraseLastElement() {
        CSingleLinkedList<MyStruct> list;

        list.pushBack({1, 1.0});
        list.pushBack({2, 2.0});

        CSingleLinkedList<MyStruct>::CIterator iter = list.begin();
        ++iter;
        list.erase(iter);

        if (list.getSize() != 1) {
            throw std::runtime_error("Invalid result. testEraseLastElement");
        }

        std::cout << "OK | testEraseLastElement\n";
    }

    void testEraseFirstElement() {
        CSingleLinkedList<MyStruct> list;

        list.pushBack({1, 1.0});
        list.pushBack({2, 2.0});
        list.pushBack({3, 3.0});

        CSingleLinkedList<MyStruct>::CIterator iter = list.begin();
        list.erase(iter);

        if (list.getSize() != 2) {
            throw std::runtime_error("Invalid result. testEraseFirstElement");
        }

        std::cout << "OK | testEraseFirstElement\n";
    }

    void testEraseOneElement() {
        CSingleLinkedList<MyStruct> list;

        list.pushBack({1, 1.0});

        CSingleLinkedList<MyStruct>::CIterator iter = list.begin();
        list.erase(iter);

        if (list.getSize() != 0) {
            throw std::runtime_error("Invalid result. testEraseOneElement");
        }

        std::cout << "OK | testEraseOneElement\n";
    }

    void testClear() {
        CSingleLinkedList<MyStruct> list;

        list.pushBack({1, 1.0});
        list.pushBack({2, 2.0});

        list.clear();

        if (list.getSize() != 0) {
            throw std::runtime_error("Invalid result. testClear");
        }

        std::cout << "OK | testClear\n";
    }

    void testClearEmptyList() {
        CSingleLinkedList<MyStruct> list;

        list.clear();

        if (list.getSize() != 0) {
            throw std::runtime_error("Invalid result. testClearEmptyList");
        }

        std::cout << "OK | testClearEmptyList\n";
    }

    void testClearListOfOneElement() {
        CSingleLinkedList<MyStruct> list;

        list.pushBack({1, 1.0});
        list.clear();

        if (list.getSize() != 0) {
            throw std::runtime_error("Invalid result. testClearListOfOneElement");
        }

        std::cout << "OK | testClearListOfOneElement\n";
    }

    void testPushFront() {
        CSingleLinkedList<MyStruct> list;

        list.pushBack({2, 2.0});
        list.pushFront({1, 1.0});

        const MyStruct &data = list.begin().getData();
        if (data.a != 1) {
            throw std::runtime_error("Invalid result. testPushFront. data.a not valid");
        }

        if (data.b != 1.0) {
            throw std::runtime_error("Invalid result. testPushFront. data.b not valid");
        }

        if (list.getSize() != 2) {
            throw std::runtime_error("Invalid result. testPushFront");
        }

        std::cout << "OK | testPushFront\n";
    }

    void testPushFrontEmptyList() {
        CSingleLinkedList<MyStruct> list;

        list.pushFront({1, 1.0});

        const MyStruct &data = list.begin().getData();
        if (data.a != 1) {
            throw std::runtime_error("Invalid result. testPushFrontEmptyList. data.a not valid");
        }

        if (data.b != 1.0) {
            throw std::runtime_error("Invalid result. testPushFrontEmptyList. data.b not valid");
        }

        std::cout << "OK | testPushFrontEmptyList\n";
    }

    int runTestsOnSingleLinkedList() {
        testErase();
        testEraseLastElement();
        testEraseFirstElement();
        testEraseOneElement();

        testClear();
        testClearEmptyList();
        testClearListOfOneElement();

        testPushFront();
        testPushFrontEmptyList();

        std::cout << "\nAll tests passed\n";
    }
}