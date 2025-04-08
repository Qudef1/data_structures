#include "Picture.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstring>
#include <algorithm>


void insertionSort(Picture pics[], int size) {
    for (int i = 1; i < size; i++) {
        Picture temp = pics[i];
        int j = i - 1; 
        while (j >= 0 && pics[j].year > temp.year) { 
            pics[j + 1] = pics[j];
            j--;
        }
        pics[j + 1] = temp; 
    }
}

void selectionSort(Picture pics[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (strcmp(pics[j].name, pics[minIndex].name) < 0) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            Picture temp = pics[i];
            pics[i] = pics[minIndex];
            pics[minIndex] = temp;
        }
    }
}
bool binSearch(Picture pics[],const int year,int size){
    int l = 0;
    int r = size-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(pics[mid].year==year){
            return true;
        }
        else if(pics[mid].year>year){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return false;

}
void bubbleSort(Picture pic[],int size){
    for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (pic[i].length>pic[j].length)
                {
                    std::swap(pic[i],pic[j]);
                }
            }
        }
}
