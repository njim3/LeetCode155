//
//  main.m
//  LeetCode155
//
//  Created by njim3 on 2018/11/22.
//  Copyright © 2018 njim3. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "MinStack.h"

int main(int argc, const char * argv[]) {
    
    int maxSize = 5;
    MinStack* obj = minStackCreate(maxSize);
    minStackPush(obj, 9);
    minStackPush(obj, 7);
    minStackPush(obj, 5);
    minStackPop(obj);
    
    int param_3 = minStackTop(obj);
    int param_4 = minStackGetMin(obj);
    
    printf("Top: %d, Min: %d.\n", param_3, param_4);
    
    minStackFree(obj);
    
    return 0;
}
