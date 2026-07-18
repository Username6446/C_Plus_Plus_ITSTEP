#pragma once
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int* createArray(size_t size);
void fillArray(int* arr, size_t size, int min = 1, int max = 10);
void printArray(int* arr, size_t size, string prompt = "");
void deleteArray(int*& arr);

void pushBack(int*& arr, int& size, int value);
void pushFront(int*& arr, int& size, int value);

void popBack(int*& arr, int& size);
void popFront(int*& arr, int& size);



void insert(int*& arr, int& size, int value, int index);
void deleteInd(int*& arr, int& size, int index);

int* deletePrime(int*& arr, int& size);
void distributionByArrays(int*& arr, int& size, int*& res1, int*& res2, int*& res3, int& len1, int& len2, int& len3);