//
//  groundManage.h
//  simLike
//
//  Created by Fukuda Naoto on 2017/10/20.
//  Copyright © 2017年 Fukuda Naoto. All rights reserved.
//

#ifndef groundManage_h
#define groundManage_h

#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>

#include "common.h"
#include "utility.h"
#include "drawModel.h"
#include "shape.h"


/* 図形描画系関数 */
/*
void myWireStage(int x,int y,int z,Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point cursor);
void mySolidStage(int x, int y, int z,Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point cursor);
void myWireBuilding(int x,int y,int z);
void mySolidBuilding(int x,int y,int z);
void myWireRoad(int x,int y,int z);
void mySolidRoad(int x,int y,int z);
 */

/* 人数増減 */
void incrementPopulation(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y]);
void decrementPopulation(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y]);

/* GroundType変更 */
void changeGroundType(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point point,GroundType type);

/* build関数:Ground情報から建造物を建てる */
/*
void buildRoad(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point point);
void buildBuilding(Ground gronud[STAGE_SIZE_X][STAGE_SIZE_Y],Point point);
void buildCommercialBuilding(Ground gronud[STAGE_SIZE_X][STAGE_SIZE_Y],Point point);
void buildIndustrialBuilding(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point point);
void buildLandmark(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point point,GLMmodel* model);
 */

#endif /* groundManage_h */
