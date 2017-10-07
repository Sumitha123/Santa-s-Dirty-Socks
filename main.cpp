//
//  main.cpp
//  Santa
//
//  Created by Sumitha on 5/17/17.
//  Copyright © 2017 Sumitha. All rights reserved.
//

#include <iostream>
using namespace std;

int scale(int,int);
int scale(int x,int y){
    if (x > y)
        return 1;
    else
        return 2;
};
int divide(int set[],int low,int mid,int high){
    static int set1[512] = {};
    static int set2[512] = {};
    int set1Weight = 0,set2Weight = 0;
    for(int i = low; i <= mid; i++){
        
        set1[i] = set[i];
        set1Weight = set1Weight + set1[i];
    }
    for(int i = mid+1; i <=high;i++){
        set2[i] = set[i];
        set2Weight = set2Weight + set2[i];
    }
    int result = scale(set1Weight,set2Weight);
    if(result == 1){
        high = mid;
        mid = (low + high)/2;
        if (low==mid){
            return low;
        }
        else{
            return divide(set1,low,mid,high);
        }
    }
    else{
        low = mid+1;
        mid = (low + high)/2;
        if (low==mid){
            return low;
        }
        else{
            return divide(set2,low,mid,high);
        }
    }
    
}

int main() {
    int set[1024] = {};
    int length = 1024;
    int low = 1;
    int mid;
    int high = 1024;
    mid = (low + high)/2;
    
    for(int i = 1; i <= length; i++){
        set[i] = 100;
    }
    //setting the index of the heavier box.
    set[177] = 110;
   
    int index = divide(set,low,mid,high);
    cout << "index of the heavier box = " << index << endl;
    
    
    return 0;
}
