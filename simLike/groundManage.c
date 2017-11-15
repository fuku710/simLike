//
//  groundManage.c
//  simLike
//
//  Created by Fukuda Naoto on 2017/10/20.
//  Copyright © 2017年 Fukuda Naoto. All rights reserved.
//

#include "groundManage.h"

#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>
#include "common.h"
#include "material.h"

float material[] = {1.0,0.0,0.0};
float material2[] = {1.0,1.0,1.0};



void changeGroundType(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point point,GroundType type){
    ground[point.x][point.y].type = type;
    ground[point.x][point.y].population = 0;
    
    if(type == LANDMARK){
        ground[point.x + 1][point.y].type = LANDMARK;
        ground[point.x + 1][point.y].population = 0;
        ground[point.x][point.y - 1].type = LANDMARK;
        ground[point.x][point.y - 1].population = 0;
        ground[point.x + 1][point.y - 1].type = LANDMARK;
        ground[point.x + 1][point.y - 1].population = 0;
    }
}

void incrementPopulation(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y]){
    int i,j;
    for(i = 0;i < STAGE_SIZE_X;i++){
        for(j = 0;j < STAGE_SIZE_Y;j++){
            Point target = {i,j};
            if(countExistsTypeAroundCell(ground, target, ROAD, 5) != 0){
                switch (ground[i][j].type) {
                    case RESIDENCE_AREA://居住区画
                        ground[i][j].population++;
                        if(countExistsTypeAroundCell(ground, target, RESIDENCE_AREA, 5) >= 12){
                            ground[i][j].population += 5;
                        }
                        break;
                    case COMMERCIAL_AREA://商業区画
                        //ground[i][j].population++;
                        if(countExistsTypeAroundCell(ground, target, RESIDENCE_AREA, 7) >= 12){
                            ground[i][j].population += 15;
                        }
                        break;
                    case INDUSTRIAL_AREA://工業区画
                        //ground[i][j].population++;
                        if(countExistsTypeAroundCell(ground, target, RESIDENCE_AREA, 7) >= 6 &&
                           countExistsTypeAroundCell(ground, target, COMMERCIAL_AREA, 7) >= 6){
                            ground[i][j].population += 45;
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

void decrementPopulation(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y]){
    int i,j;
    
    for(i = 0;i < STAGE_SIZE_X;i++){
        for(j = 0;j < STAGE_SIZE_Y;j++){
            Point target = {i,j};
            if(countExistsTypeAroundCell(ground, target, ROAD, 5) == 0){
                ground[i][j].population -= 5;
            }
            if(ground[i][j].population < 0){
                ground[i][j].population = 0;
            }
            if(countExistsTypeAroundCell(ground, target, INDUSTRIAL_AREA, 9) != 0){
                ground[i][j].population -= 1;
            }
            if(countExistsTypeAroundCell(ground, target, INDUSTRIAL_AREA, 7) != 0){
                ground[i][j].population -= 2;
            }
            if(countExistsTypeAroundCell(ground, target, INDUSTRIAL_AREA, 5) != 0){
                ground[i][j].population -= 3;
            }
        }
    }
}


