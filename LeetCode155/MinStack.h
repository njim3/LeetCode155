//
//  MinStack.h
//  LeetCode155
//
//  Created by njim3 on 2018/11/22.
//  Copyright © 2018 njim3. All rights reserved.
//

#ifndef MinStack_h
#define MinStack_h

typedef struct {
    int* base;
    
    int top;
    int maxSize;
    
    int minData;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize);
void minStackPush(MinStack* obj, int x);
void minStackPop(MinStack* obj);
int minStackTop(MinStack* obj);
int minStackGetMin(MinStack* obj);
void minStackFree(MinStack* obj);

#endif /* MinStack_h */
