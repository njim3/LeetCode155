//
//  MinStack.c
//  LeetCode155
//
//  Created by njim3 on 2018/11/22.
//  Copyright © 2018 njim3. All rights reserved.
//

#include "MinStack.h"
#include <malloc/malloc.h>
#include <stdlib.h>

MinStack* minStackCreate(int maxSize)
{
    MinStack* minStack = (MinStack*)malloc(sizeof(MinStack));
    
    if (!minStack)
        return NULL;
    
    minStack->base = (int*)malloc(sizeof(int) * maxSize);
    
    if (!minStack->base)
        return NULL;
    
    minStack->maxSize = maxSize;
    minStack->top = 0;
    
    return minStack;
}

void minStackPush(MinStack* obj, int x)
{
    if ((obj->top + 1) == obj->maxSize)
        return ;
    
    obj->base[obj->top++] = x;
    
    if (obj->top == 1)
        obj->minData = x;
    else
        obj->minData = x > obj->minData ? obj->minData : x;
}

void minStackPop(MinStack* obj)
{
    if (obj->top == 0)
        return ;
    
    int topData = obj->base[obj->top - 1];
    
    if (obj->top - 1 == 0) {
        obj->minData = 0;
    } else {
        if (topData == obj->minData) {
            int minData = obj->base[0];
            
            for (int i = 0; i < obj->top - 1; ++i) {
                if (obj->base[i] < minData) {
                    minData = obj->base[i];
                }
            }
            
            obj->minData = minData;
        }
    }
    
    obj->top--;
}

int minStackTop(MinStack* obj)
{
    if (obj->top == 0)
        return 0;
    
    return obj->base[obj->top - 1];
}

int minStackGetMin(MinStack* obj)
{
    if (obj->top == 0)
        return 0;
    
    return obj->minData;
}

void minStackFree(MinStack* obj)
{
    free(obj->base);
    free(obj);
}

