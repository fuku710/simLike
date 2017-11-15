//
//  shape.h
//  simLike
//
//  Created by Fukuda Naoto on 2017/10/27.
//  Copyright © 2017年 Fukuda Naoto. All rights reserved.
//

#ifndef shape_h
#define shape_h

#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>

#include "common.h"
#include "material.h"

void myWireStage(int x,int y,int z,Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point cursor);
void mySolidStage(int x, int y, int z,Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point cursor);
void mySolidHouse(int x,int y,int z);
void mySolidShop(int x,int y,int z);
void mySolidFactory(int x,int y,int z);
void myWireBuilding(int x,int y,int z);
void mySolidBuilding(int x,int y,int z);
void myWireRoad(int x,int y,int z);
void mySolidRoad(int x,int y,int z);

#endif /* shape_h */
