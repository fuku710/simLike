//
//  debug.c
//  simLike
//
//  Created by Fukuda Naoto on 2017/10/28.
//  Copyright © 2017年 Fukuda Naoto. All rights reserved.
//

#include "debug.h"

/* For Debug */
void dPrintGroundInfo(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point target){
    printf("GroundPos :[%2d,%2d]\n",target.x,target.y);
    printf("GroundType:%2d\n",ground[target.x][target.y].type);
    printf("GroundPop :%2d\n",ground[target.x][target.y].population);
}
