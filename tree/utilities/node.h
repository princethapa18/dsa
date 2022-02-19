#pragma once

class Node 
{
public:
    int data;
    Node * left;
    Node * right;
    Node(int val = 0) : data{val}, left{nullptr} , right{nullptr} {}
};