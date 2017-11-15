//
//  utility.c
//  simLike
//
//  Created by Fukuda Naoto on 2017/10/27.
//  Copyright © 2017年 Fukuda Naoto. All rights reserved.
//

#include "utility.h"

int countExistsTypeAroundCell(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point myself,GroundType targetType,int range){
    int i,j;
    int halfRange = range / 2;
    int existsCounter = 0;
    for(i = myself.x - halfRange;i <= myself.x + halfRange;i++){
        for(j = myself.y - halfRange;j <= myself.y + halfRange;j++){
            if(i == myself.x && j == myself.y){
                /* 自分自身の除外 */
            }
            else if(ground[i][j].type == targetType){
                existsCounter++;
            }
        }
    }
    return existsCounter;
}
