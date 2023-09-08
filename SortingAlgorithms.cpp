#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int len){
    int minIndex,temp;
    for(int i=0;i<len;i++){
        minIndex=i;
        for(int j=i+1;j<len;j++){
            if(arr[minIndex]>arr[j]){
                minIndex=j;
            }
            temp=arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
        }
    }
}

void insertSort(int arr[],int len){
    for(int i=1;i<len;i++){
        int j=i-1;
        int key=arr[i];
        while(j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void bubbleSort(int arr[],int len){
    for(int i=1;i<len-1;i++){
        bool swap=false;
        for(int j=0;j<len-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap=true;
            }
        }
        if(!swap){
            break;

        }
    }


}


int main(){
    int arr[9]={5,6,8,12,34,56,7,89,12};
    bubbleSort(arr,9);

    for(int i:arr){
        cout<<i<<" ";
    }
}