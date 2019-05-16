#include "AbBinaryNode.h"
#include <cstddef>
#include<iostream>
using namespace std;

AbBinaryNode::AbBinaryNode()
{
    AbBinaryNode *newArray =  new AbBinaryNode;
    (*newArray).item = 0;
    (*newArray).left = 0;
    (*newArray).right = 0;

}

AbBinaryNode::AbBinaryNode(int &nodeItem, int left, int right)
{
    AbBinaryNode *newArray =  new AbBinaryNode;
    (*newArray).item = nodeItem;
    (*newArray).left = left;
    (*newArray).right = right;
}

AbBinaryNode::~AbBinaryNode()
{
    //dtor
}
