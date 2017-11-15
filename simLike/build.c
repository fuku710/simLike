//
//  build.c
//  simLike
//
//  Created by Fukuda Naoto on 2017/11/13.
//  Copyright © 2017年 Fukuda Naoto. All rights reserved.
//

#include "build.h"

void buildRoad(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point point){
    int i,j;
    for(i = 0;i < STAGE_SIZE_X;i++){
        for(j = 0;j < STAGE_SIZE_Y;j++){
            if(ground[i][j].type == ROAD){
                mySolidRoad(i, j, 1);
            }
        }
    }
}

void buildBuilding(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point point){
    int i,j;
    int maxFloor = 0;
    int currentFloor;
    const int floorPop = 500;
    for(i = 0;i < STAGE_SIZE_X;i++){
        for(j = 0;j < STAGE_SIZE_Y;j++){
            if(ground[i][j].type == RESIDENCE_AREA){
                /*maxFloor = (ground[i][j].population / floorPop) > 9 ? 10 : (ground[i][j].population / floorPop);
                 for(currentFloor = 1;currentFloor <= maxFloor;currentFloor++) {
                 //printf("CurrentFloor:%d z:%f\n",currentFloor,(float)currentFloor * 0.25);
                 //myWireBuilding(i, j, currentFloor);
                 drawModel(model, i, j, currentFloor);
                 }*/
                
                if(ground[i][j].population > floorPop * 2){
                    maxFloor = (ground[i][j].population / floorPop) > 9 ? 10 : (ground[i][j].population / floorPop);
                    for(currentFloor = 1;currentFloor <= maxFloor;currentFloor++) {
                        //printf("CurrentFloor:%d z:%f\n",currentFloor,(float)currentFloor * 0.25);
                        mySolidBuilding(i, j, currentFloor);
                        //drawModel(model, i, j, currentFloor);
                    }
                }
                else if(ground[i][j].population > floorPop){
                    //drawModel(model, i, j, 1);
                    //myWSolidBuilding(i, j, 1);
                    mySolidHouse(i, j, 1);
                }
            }
        }
    }
}

void buildCommercialBuilding(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point point){
    int i,j;
    
    for(i = 0;i < STAGE_SIZE_X;i++){
        for(j = 0;j < STAGE_SIZE_Y;j++){
            if(ground[i][j].type == COMMERCIAL_AREA){
                if(ground[i][j].population > 200){
                    mySolidShop(i, j, 1);
                }
            }
        }
    }
}

void buildIndustrialBuilding(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point point){
    int i,j;
    for(i = 0;i < STAGE_SIZE_X;i++){
        for(j = 0;j < STAGE_SIZE_Y;j++){
            if(ground[i][j].type == INDUSTRIAL_AREA){
                if(ground[i][j].population > 200){
                    mySolidFactory(i, j, 1);
                }
            }
        }
    }
}

void buildLandmark(Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point point,GLMmodel* model){
    int i,j;
    
    for(i = 0;i < STAGE_SIZE_X;i++){
        for(j = 0;j < STAGE_SIZE_Y;j++){
            if(ground[i][j].type == LANDMARK &&
               ground[i + 1][j].type == LANDMARK &&
               ground[i][j - 1].type == LANDMARK &&
               ground[i + 1][j - 1].type == LANDMARK){
                drawModel(model, i, j , 1);
            }
        }
    }
}
