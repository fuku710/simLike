//
//  shape.c
//  simLike
//
//  Created by Fukuda Naoto on 2017/10/27.
//  Copyright © 2017年 Fukuda Naoto. All rights reserved.
//

#include "shape.h"

void myWireStage(int x,int y,int z,Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point cursor){
    int i,j,k;
    
    for(i = 0;i < x;i++){
        for(j = 0;j < y;j++){
            for(k = 0;k < z;k++){
                glPushMatrix();
                glTranslatef(i,j,k);
                if(ground[i][j].type == 1){
                    //glColor3f(0.0, 0.0, 0.0);
                }
                if(ground[i][j].type == 2){
                    glColor3f(0.0, 1.0, 0.0);
                }
                else if(cursor.x == i && cursor.y == j){
                    glColor3f(1.0, 0.0, 0.0);
                }
                else{
                    glColor3f(1.0, 1.0, 1.0);
                }
                glutWireCube(1.0);
                glPopMatrix();
            }
        }
    }
}

void mySolidStage(int x, int y, int z,Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y],Point cursor){
    int i,j,k;
    
    for(i = 0;i < x;i++){
        for(j = 0;j < y;j++){
            for(k = 0;k < z;k++){
                glPushMatrix();
                glTranslatef(i,j,k);
                setMaterial(materialGrass);
                if(ground[i][j].type == ROAD){
                    //glColor3f(0.0, 0.0, 0.0);
                }
                if(cursor.x == i && cursor.y == j){
                    glColor3f(1.0, 0.0, 0.0);
                    setMaterial(materialCursor);
                    //glMaterialfv(GL_FRONT, GL_DIFFUSE, material);
                    //glMaterialfv(GL_FRONT, GL_AMBIENT, material);
                }
                else if(ground[i][j].type == RESIDENCE_AREA){
                    //glColor3f(0.0, 1.0, 0.0);
                    setMaterial(materialResidenceArea);
                }
                else if(ground[i][j].type == COMMERCIAL_AREA){
                    setMaterial(materialCommercialArea);
                }
                else if(ground[i][j].type == INDUSTRIAL_AREA){
                    setMaterial(materialIndustrialArea);
                }
                else if(ground[i][j].type == LANDMARK){
                    setMaterial(materialLandmark);
                }
                else{
                    glColor3f(1.0, 1.0, 1.0);
                    //glMaterialfv(GL_FRONT, GL_DIFFUSE, material2);
                }
                glutSolidCube(1.0);
                glPopMatrix();
            }
        }
    }
}

void mySolidHouse(int x,int y,int z){
    int i;
    
    GLdouble Vertex[][3] = {
        {-0.5,-0.5,0.0},
        {-0.5,0.5,0.0},
        {0.5,0.5,0.0},
        {0.5,-0.5,0.0},
        {0.0,-0.5,0.65},
        {0.0,0.5,0.65},
    };
    
    int edge[][2] = {
        {0,1},
        {1,2},
        {2,3},
        {3,0},
        {0,4},
        {1,5},
        {2,5},
        {3,4},
        {4,5},
        {0,5},
        {3,5},
        {1,4},
        {2,4}
    };
    
    glPushMatrix();
    
    glTranslatef(x, y, z - 0.3);
    glScalef(0.8, 0.8, 0.6);
    glColor3f(0.0,0.0,1.0);
    setMaterial(materialGray);
    glutSolidCube(1.0);
    
    glPopMatrix();
    
    //屋根
    
    glPushMatrix();
    
    glTranslatef(x,y,z + 0.001);
    //glRotatef(270, 0, 0, 1);
    
    setMaterial(materialGreen);
    
    glBegin(GL_POLYGON);
    for(i = 0;i < 13;i++){
        glVertex3dv(Vertex[edge[i][0]]);
        glNormal3dv(Vertex[edge[i][0]]);
        glVertex3dv(Vertex[edge[i][1]]);
        glNormal3dv(Vertex[edge[i][1]]);
    }
    glEnd();
    
    glPopMatrix();
    
}

void mySolidShop(int x,int y,int z){
    
    glPushMatrix();
    
    glTranslatef(x, y, z - 0.3);
    glScalef(0.8, 0.8, 0.6);
    glColor3f(0.0,0.0,1.0);
    setMaterial(materialGray);
    glutSolidCube(1.0);
    
    glPopMatrix();
    
    //屋根
    
    glPushMatrix();
    
    glTranslatef(x,y,z + 0.001);
    glScalef(1.0, 1.0, 0.2);
    setMaterial(materialBlue);
    glutSolidCube(1.0);
    
    glPopMatrix();
    
}

void mySolidFactory(int x,int y,int z){
    int i;
    
    GLdouble Vertex[][3] = {
        {-0.5,-0.5,0.0},
        {-0.5,0.5,0.0},
        {0.0,0.5,0.0},
        {0.0,-0.5,0.0},
        {0.0,-0.5,0.45},
        {0.0,0.5,0.45},
    };
    
    int edge[][2] = {
        {0,1},
        {1,2},
        {2,3},
        {3,0},
        {0,4},
        {1,5},
        {2,5},
        {3,4},
        {4,5},

    };

    
    glPushMatrix();
    
    glTranslatef(x, y, z - 0.3);
    glScalef(0.8, 0.8, 0.6);
    setMaterial(materialGray);
    glutSolidCube(1.0);
    
    glPopMatrix();
    
    //屋根
    
    glPushMatrix();
    
    glTranslatef(x,y,z + 0.001);
    glScalef(0.8, 0.8, 1.0);
    
    setMaterial(materialRed);
    
    glBegin(GL_POLYGON);
    for(i = 0;i < 9;i++){
        glVertex3dv(Vertex[edge[i][0]]);
        glNormal3dv(Vertex[edge[i][0]]);
        glVertex3dv(Vertex[edge[i][1]]);
        glNormal3dv(Vertex[edge[i][1]]);
    }
    glEnd();
    
    glPopMatrix();
    
    //屋根2
    
    glPushMatrix();
    
    
    glTranslatef(x + 0.4,y,z + 0.001);
    glScalef(0.8, 0.8, 1.0);
    
    setMaterial(materialRed);
    
    glBegin(GL_POLYGON);
    for(i = 0;i < 9;i++){
        glVertex3dv(Vertex[edge[i][0]]);
        glVertex3dv(Vertex[edge[i][1]]);
    }
    glEnd();
    
    glPopMatrix();
}


void myWireBuilding(int x,int y,int z){
    glPushMatrix();
    
    glTranslatef(x, y, z);
    glScalef(0.8, 0.8, 1.0);
    glColor3f(0.0,0.0,1.0);
    glutWireCube(1.0);
    
    glPopMatrix();
}

void mySolidBuilding(int x,int y,int z){
    glPushMatrix();
    
    glTranslatef(x, y, z);
    glScalef(0.8, 0.8, 1.0);
    glColor3f(0.0,0.0,1.0);
    setMaterial(materialGray);
    glutSolidCube(1.0);
    glutWireCube(1.0);
    glPopMatrix();
}

void myWireRoad(int x,int y,int z){
    glPushMatrix();
    
    glTranslatef(x, y, z - 0.5);
    glScalef(1.0, 1.0, 0.1);
    glColor3f(0.0, 0.0, 0.0);
    glutWireCube(1.0);
    
    glPopMatrix();
}

void mySolidRoad(int x,int y,int z){
    glPushMatrix();
    
    glTranslatef(x, y, z - 0.5);
    glScalef(1.0, 1.0, 0.1);
    glColor3f(0.0, 0.0, 0.0);
    setMaterial(materialRoad);
    glutSolidCube(1.0);
    
    glPopMatrix();
}
