/*Создайте класс IntSet для выполнения операций с множеством целых чисел. 
Реализовать операции добавления элемента, удаление элемента, проверку вхождения элемента, 
объединения множеств и вычитания одного множества из другого*/

#pragma once

#include <iostream>

class IntSet {

private:

    int p_size;

    int* p_set;


public:
    ~IntSet();

    IntSet();

    IntSet(int* set, int size);

    void setNumbers(int* set, int size);

    int check(int num);

    void addNumber(int num);

    void delNumber(int num);

    void unitSets(IntSet set);

    void subSets(IntSet set);

    void printSet();
    
};