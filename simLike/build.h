//
//  build.h
//  simLike
//
//  Created by Fukuda Naoto on 2017/11/13.
//  Copyright © 2017年 Fukuda Naoto. All rights reserved.
//

#ifndef build_h
#define build_h

#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>

#include "common.h"
#include "utility.h"
#include "drawModel.h"
#include "shape.h"

/* build関数:Ground情報から建造物を建てる */
void buildRoad(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point point);
void buildBuilding(Ground gronud[STAGE_SIZE_X][STAGE_SIZE_Y],Point point);
void buildCommercialBuilding(Ground gronud[STAGE_SIZE_X][STAGE_SIZE_Y],Point point);
void buildIndustrialBuilding(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point point);
void buildLandmark(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point point,GLMmodel* model);


#endif /* build_h */
