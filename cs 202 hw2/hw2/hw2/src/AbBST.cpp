#include "AbBST.h"
#include "AbBinaryNode.h"
#include <cstddef>
#include<iostream>
using namespace std;



AbBST::AbBST()
{
    //ctor
}

AbBST::~AbBST()
{
    //dtor
}

AbBinaryNode* Insert(int val){

    AbBinaryNode *newArray =  new AbBinaryNode[2];
    (*newArray).item = val;
    (*newArray).left = 0;
    (*newArray).right = 0;
    return newArray;
}

void insert(int val){

    AbBinaryNode *arr = Insert(val);

    while(true){
        if (arr[n] < val)



    }


}



int getHeight(){

}
