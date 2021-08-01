//
// Created by michealki on 2020-06-03.
//

#ifndef SELECTIONSORT_SORTTESTHELPER_H
#define SELECTIONSORT_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

namespace SortTestHelper{

    //返回一个在[rangeL,rangeR]范围内元素数量为n的随机整形数组
    int* generateRandomArray(int n, int rangeL, int rangeR){

        assert(rangeL < rangeR);
        int* arr = new int[n];
        srand(time(NULL)); //设置随机种子
        for (int i = 0; i < n; ++i) {
           arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    template <typename T>
    void printArray(T arr ,int n){
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    template <typename T>
    bool isSorted(T arr, int n, const string sortName){
        for (int i = 0; i < n - 1; ++i) {
            if(arr[i]>arr[i+1]){
                cout << "sort failed: " << sortName << ".";
                return false;
            }
        }
        return true;
    }

    template <typename T>
    void testSort(const string &sortName, void(*sort)(vector<T> &nums), vector<T> nums){
        clock_t startTime = clock();
        sort(nums);
        clock_t endTime = clock();

        assert(isSorted(nums.data(),nums.size(),sortName));

        cout << "使用" << sortName << "对" <<nums.size()<<"个元素进行排序，耗时: "<<(float)(endTime-startTime)/CLOCKS_PER_SEC << "s" <<endl;
    }

    int* copyIntArr(int arr[], int n){

        int* array = new int[n];
        copy(arr,arr+n,array);
        return array;
    }

    int* generateNearlyOrderedArray(int n, int swapTimes){
        int* arr = new int[n];
        for(int i = 0 ; i < n ; i++){
            arr[i] = i;
        }
        srand(time(NULL));
        for (int i = 0 ; i < swapTimes ; i++){
            int index0 = rand()%n;
            int index1 = rand()%n;
            swap( arr[index0] , arr[index1] );
        }
        return arr;
    }

    template <typename T>
    int getArrLength(T& arr){
        //T& arr是对变量的引用，而不是取地址(取地址是& arr，没有前面的类型声明)。
        //通过T& arr引用变量实际上是给实参变量取了一个叫做arr的别名。在内部使用arr就是对实参变量的操作。
        //这是C++对C的一个补充用法。
        return sizeof(arr)/ sizeof(arr[0]);

    }
}
#endif //SELECTIONSORT_SORTTESTHELPER_H
