//
//  utility.h
//  simLike
//
//  Created by Fukuda Naoto on 2017/10/27.
//  Copyright © 2017年 Fukuda Naoto. All rights reserved.
//

#ifndef utility_h
#define utility_h

#include <stdio.h>
#include "common.h"

int countExistsTypeAroundCell(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point myself,GroundType targetType,int range);

#endif /* utility_h */
