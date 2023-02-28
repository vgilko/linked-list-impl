//
// Created by avmd on 28.02.23.
//

#include "list.h"

#include <iostream>

#ifndef UNTITLED1_TESTDUAL_H
#define UNTITLED1_TESTDUAL_H

using namespace lab618;

namespace DualLinkedListTest {

    void testGetSize() {
        CDualLinkedList<std::string> list;

        list.pushBack("AAA");
        list.pushBack("BBB");
        list.pushBack("CCC");

        if (list.getSize() != 3) {
            throw std::runtime_error("Invalid result. testGetSize");
        }

        std::cout << "OK | testGetSize\n";
    }

    void testGetSizeEmptyList() {
        CDualLinkedList<std::string> list;

        if (list.getSize() != 0) {
            throw std::runtime_error("Invalid result. testGetSizeEmptyList");
        }

        std::cout << "OK | testGetSizeEmptyList\n";
    }


    void testPopBackEmptyList() {
        CDualLinkedList<std::string> list;

        try {
            list.popBack();
        } catch (std::runtime_error &e) {
            std::cout << "OK | testPopBackEmptyList\n";
            return;
        }

        throw std::runtime_error("Invalid result. testPopBackEmptyList");
    }

    void testPopBack() {
        CDualLinkedList<std::string> list;

        list.pushBack("AAA");
        list.pushBack("BBB");
        list.pushBack("CCC");

        list.popBack();
        list.popBack();
        list.popBack();

        if (list.getSize() != 0) {
            throw std::runtime_error("Invalid result. testPopBack");
        }

        std::cout << "OK | testPopBack\n";
    }

    void testPopFrontEmptyList() {
        CDualLinkedList<std::string> list;

        try {
            list.popFront();
        } catch (std::runtime_error &e) {
            std::cout << "OK | testPopFrontEmptyList\n";
            return;
        }

        throw std::runtime_error("Invalid result. testPopFrontEmptyList");
    }


    void testPopBackOneElement() {
        CDualLinkedList<std::string> list;

        list.pushBack("AAA");

        list.popBack();

        if (list.getSize() != 0) {
            throw std::runtime_error("Invalid result. testPopBack");
        }

        std::cout << "OK | testPopBackOneElement\n";
    }

    void testPopFront() {
        CDualLinkedList<std::string> list;

        list.pushBack("AAA");
        list.pushBack("BBB");
        list.pushBack("CCC");

        list.popFront();
        list.popFront();
        list.popFront();

        if (list.getSize() != 0) {
            throw std::runtime_error("Invalid result. testPopFront");
        }

        std::cout << "OK | testPopFront\n";
    }

    void testPopFrontListOfOneElement() {
        CDualLinkedList<std::string> list;

        list.pushBack("AAA");

        list.popFront();

        if (list.getSize() != 0) {
            throw std::runtime_error("Invalid result. testPopFrontListOfOneElement");
        }

        std::cout << "OK | testPopFrontListOfOneElement\n";
    }


    void testErase() {
        CDualLinkedList<MyStruct> list;

        list.pushBack({1, 1.0});
        list.pushBack({2, 2.0});
        list.pushBack({3, 3.0});

        CDualLinkedList<MyStruct>::CIterator iter = list.begin();
        ++iter;
        list.erase(iter);

        if (list.getSize() != 2) {
            throw std::runtime_error("Invalid result. testErase");
        }

        if (!iter.isValid() ||
            iter != list.begin()) {
            throw std::runtime_error("Invalid result. testErase. Iter is not next value");
        }

        std::cout << "OK | testErase\n";
    }

    void testEraseLastElement() {
        CDualLinkedList<MyStruct> list;

        list.pushBack({1, 1.0});
        list.pushBack({2, 2.0});

        CDualLinkedList<MyStruct>::CIterator iter = list.begin();
        ++iter;
        list.erase(iter);

        if (list.getSize() != 1) {
            throw std::runtime_error("Invalid result. testEraseLastElement");
        }

        if (list.begin().getData().a != 1) {
            throw std::runtime_error("Invalid result. testEraseLastElement. First element after deletion is invalid.");
        }

        if (iter != list.begin()) {
            throw std::runtime_error("Invalid result. testEraseLastElement. Iter is not previous value");
        }


        std::cout << "OK | testEraseLastElement\n";
    }

    void testEraseFirstElement() {
        CDualLinkedList<MyStruct> list;

        list.pushBack({1, 1.0});
        list.pushBack({2, 2.0});
        list.pushBack({3, 3.0});

        CDualLinkedList<MyStruct>::CIterator iter = list.begin();
        list.erase(iter);

        if (list.getSize() != 2) {
            throw std::runtime_error("Invalid result. testEraseFirstElement");
        }

        if (list.begin().getData().a != 2) {
            throw std::runtime_error("Invalid result. testEraseFirstElement. First element after deletion is invalid.");
        }

        if (list.end().getData().a != 3) {
            throw std::runtime_error("Invalid result. testEraseFirstElement. Last element after deletion is invalid.");
        }

        if (iter.isValid()) {
            throw std::runtime_error("Invalid result. testEraseFirstElement. Iter is not previous value");
        }

        std::cout << "OK | testEraseFirstElement\n";
    }

    void testEraseOneElement() {
        CDualLinkedList<MyStruct> list;

        list.pushBack({1, 1.0});

        CDualLinkedList<MyStruct>::CIterator iter = list.begin();
        list.erase(iter);

        if (list.getSize() != 0) {
            throw std::runtime_error("Invalid result. testEraseOneElement");
        }

        if (iter.isValid()) {
            throw std::runtime_error("Invalid result. testEraseOneElement. Iter is not previous value");
        }

        std::cout << "OK | testEraseOneElement\n";
    }


    void testPushFrontEmptyList() {
        CDualLinkedList<std::string> list;

        list.pushFront("AAA");

        if (list.getSize() != 1) {
            throw std::runtime_error("Invalid result. testPushFrontEmptyList");
        }

        if (list.begin().getData() != "AAA") {
            throw std::runtime_error("Invalid result. testPushFrontEmptyList. Invalid data of first element");
        }

        std::cout << "OK | testPushFrontEmptyList\n";
    }

    void testPushFront() {
        CDualLinkedList<std::string> list;

        list.pushFront("CCC");
        list.pushFront("BBB");
        list.pushFront("AAA");

        if (list.getSize() != 3) {
            throw std::runtime_error("Invalid result. pushFront");
        }

        if (list.begin().getData() != "AAA") {
            throw std::runtime_error("Invalid result. pushFront. Invalid data of first element");
        }

        CDualLinkedList<std::string>::CIterator firstElementIterator = list.begin();
        CDualLinkedList<std::string>::CIterator lastElementIterator = list.end();

        ++firstElementIterator;
        --lastElementIterator;

        if (firstElementIterator.getData() != "BBB" ||
            firstElementIterator.getData() != lastElementIterator.getData()) {
            throw std::runtime_error("Invalid result. pushFront. Invalid data of second element");
        }


        if (list.end().getData() != "CCC") {
            throw std::runtime_error("Invalid result. pushFront. Invalid data of last element");
        }

        std::cout << "OK | pushFront\n";
    }


    void testClear() {
        CDualLinkedList<std::string> list;

        list.pushFront("AAA");
        list.pushFront("BBB");
        list.pushFront("CCC");

        list.clear();

        if (list.getSize() != 0) {
            throw std::runtime_error("Invalid result. testClear");
        }

        std::cout << "OK | testClear\n";
    }

    void testClearEmptyList() {
        CDualLinkedList<std::string> list;

        list.clear();

        if (list.getSize() != 0) {
            throw std::runtime_error("Invalid result. testClearEmptyList");
        }

        std::cout << "OK | testClearEmptyList\n";
    }


    void testEraseAndNextLastElement() {
        CDualLinkedList<MyStruct> list;

        list.pushBack({1, 1.0});
        list.pushBack({2, 2.0});

        CDualLinkedList<MyStruct>::CIterator iter = list.begin();
        ++iter;
        list.eraseAndNext(iter);

        if (list.getSize() != 1) {
            throw std::runtime_error("Invalid result. testEraseLastElement");
        }

        if (list.begin().getData().a != 1) {
            throw std::runtime_error(
                    "Invalid result. testEraseAndNextLastElement. First element after deletion is invalid.");
        }

        if (iter.isValid()) {
            throw std::runtime_error("Invalid result. testEraseAndNextLastElement. Iter is not next value");
        }

        std::cout << "OK | testEraseAndNextLastElement\n";
    }

    void testEraseAndNextFirstElement() {
        CDualLinkedList<MyStruct> list;

        list.pushBack({1, 1.0});
        list.pushBack({2, 2.0});
        list.pushBack({3, 3.0});

        CDualLinkedList<MyStruct>::CIterator iter = list.begin();
        list.eraseAndNext(iter);

        if (list.getSize() != 2) {
            throw std::runtime_error("Invalid result. testEraseAndNextFirstElement");
        }

        if (list.begin().getData().a != 2) {
            throw std::runtime_error(
                    "Invalid result. testEraseAndNextFirstElement. First element after deletion is invalid.");
        }

        if (list.end().getData().a != 3) {
            throw std::runtime_error(
                    "Invalid result. testEraseAndNextFirstElement. Last element after deletion is invalid.");
        }

        if (!iter.isValid() || iter.getData().a != 2) {
            throw std::runtime_error("Invalid result. testEraseAndNextFirstElement. Iter is not next value");
        }

        std::cout << "OK | testEraseAndNextFirstElement\n";
    }

    void testEraseAndNextOneElement() {
        CDualLinkedList<MyStruct> list;

        list.pushBack({1, 1.0});

        CDualLinkedList<MyStruct>::CIterator iter = list.begin();
        list.eraseAndNext(iter);

        if (list.getSize() != 0) {
            throw std::runtime_error("Invalid result. testEraseAndNextOneElement");
        }

        if (iter.isValid()) {
            throw std::runtime_error("Invalid result. testEraseAndNextOneElement. Iter is not next value");
        }

        std::cout << "OK | testEraseAndNextOneElement\n";
    }

    void testEraseAndNext() {
        CDualLinkedList<MyStruct> list;

        list.pushBack({1, 1.0});
        list.pushBack({2, 2.0});
        list.pushBack({3, 3.0});

        CDualLinkedList<MyStruct>::CIterator iter = list.begin();
        ++iter;
        list.eraseAndNext(iter);

        if (list.getSize() != 2) {
            throw std::runtime_error("Invalid result. testEraseAndNext");
        }

        if (!iter.isValid() ||
            iter != list.end()) {
            throw std::runtime_error("Invalid result. testEraseAndNext. Iter is not next value");
        }

        std::cout << "OK | testEraseAndNext\n";
    }

    void runTestsOnDualLinkedList() {
        testGetSize();
        testGetSizeEmptyList();

        testPopBackEmptyList();

        testPopBack();
        testPopBackOneElement();

        testPopFrontEmptyList();
        testPopFront();
        testPopFrontListOfOneElement();

        testErase();
        testEraseLastElement();
        testEraseFirstElement();
        testEraseOneElement();

        testPushFront();
        testPushFrontEmptyList();

        testClear();
        testClearEmptyList();

        testEraseAndNextLastElement();
        testEraseAndNextFirstElement();
        testEraseAndNextOneElement();
        testEraseAndNext();

        std::cout << "\nAll tests passed\n";
    }
};
#endif //UNTITLED1_TESTDUAL_H
