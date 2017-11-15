//
//  main.c
//  simLike
//
//  Created by Fukuda Naoto on 2017/10/20.
//  Copyright © 2017年 Fukuda Naoto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>

#include "groundManage.h"
#include "common.h"
#include "debug.h"
#include "drawModel.h"
#include "material.h"
#include "shape.h"
#include "build.h"

//float distance = -20., twist = 0., elevation = 30., azimuth = 20.;
float distance = -20.0;
float twist = 0.0;
float elevation = -60.0;
float azimuth = 0.0;

int camera_x = 0,camera_y = 0,camera_z = 0;
int xBegin,yBegin;
int mButton;

Point cursor = {10,10};
Ground ground[STAGE_SIZE_X][STAGE_SIZE_Y];

GLMmodel *Model;

float ambient[] = {0.15,0.15,0.15,0.7};
float diffuse[] = {0.6,0.6,0.6,0.7};
float specular[] = {0.5,0.5,0.5,0.2};
float position[] = {0,-20,15,0};

float spot_ambient[] = {0.2,0.2,0.2,0.3};
float spot_diffuse[] = {0.7,0.7,0.7,0.3};
float spot_specular[] = {1.0,1.0,1.0,0.0};
float spot_position[] = {STAGE_SIZE_X / 2,STAGE_SIZE_Y * 2,10,1.0};

void display(void)
{
    void my_axis();
    
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glEnable(GL_DEPTH_TEST);// Z Buffer の有効範囲の指定
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHTING);
    
    glPushMatrix();
    
    camera_x = cursor.x + sin(azimuth * PI / 180) * distance;
    camera_y = cursor.y + cos(azimuth * PI / 180) * distance;
    camera_z = sin(elevation * PI / 180) * distance;
    
    //camera_x = cursor.x;
    //camera_y = cursor.y;
    
    /*視点設定*/
    gluLookAt(
              camera_x,
              camera_y,
              camera_z,
              cursor.x,
              cursor.y,
              1,
              0,0,1
              );
    
    
    /*LIGHT0*/
    
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_AMBIENT,ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.5);
    
    /*LIGHT1*/
    
    glLightfv(GL_LIGHT1, GL_AMBIENT,spot_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, spot_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, spot_specular);
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 2.5);
    glLightfv(GL_LIGHT1, GL_POSITION, spot_position);
    
    mySolidStage(STAGE_SIZE_X,STAGE_SIZE_Y,STAGE_SIZE_Z,ground,cursor);
    buildBuilding(ground, cursor);
    buildCommercialBuilding(ground, cursor);
    buildIndustrialBuilding(ground, cursor);
    buildLandmark(ground, cursor, Model);
    buildRoad(ground, cursor);
    
    //setMaterial(materialBlue);
    //glutSolidCube(2);
    
    //glTranslatef(1.0, 1.0, 2.0);
    /*drawModel(Model,15,10,1);
    mySolidFactory(10, 10, 1);
    mySolidShop(11, 10, 1);
    mySolidHouse(12, 10, 1);*/
    
    glPopMatrix();
    
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST); // Z Bufferの有効範囲の終わり
    glutSwapBuffers();
    glFlush();
}

void idle(void)
{
    //azimuth += 0.01;
    azimuth = azimuth > 360 ? 0: azimuth;
    azimuth = azimuth < 0 ? 360: azimuth;
    distance = distance > -10 ? -10 : distance;
    elevation = elevation < -180 ? -180: elevation;
    elevation = elevation > -45 ? -45 : elevation;
    incrementPopulation(ground);
    decrementPopulation(ground);
    glutPostRedisplay();
}

void myKbd(unsigned char key, int x, int y)
{
    switch (key){
        case 'w':
            cursor.y++;
            camera_y++;
            break;
        case 'a':
            cursor.x--;
            camera_x--;
            break;
        case 's':
            cursor.y--;
            camera_y--;
            break;
        case 'd':
            cursor.x++;
            camera_x++;
            break;
        case 'j':
            changeGroundType(ground,cursor,ROAD);
            break;
        case 'k':
            changeGroundType(ground,cursor,RESIDENCE_AREA);
            break;
        case 'l':
            changeGroundType(ground,cursor,COMMERCIAL_AREA);
            break;
        case ';':
            changeGroundType(ground,cursor,INDUSTRIAL_AREA);
            break;
        case 'u':
            changeGroundType(ground,cursor,LANDMARK);
            break;
        case 'i':
            dPrintGroundInfo(ground, cursor);
            break;
        case KEY_ESC:
            exit(0);
    }
    
    camera_x = cursor.x;
    camera_y = cursor.y;
    
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN){
        xBegin = x; /*ドラッグ開始点のx,y座標値を取得*/
        yBegin = y;
    }
    
    mButton = button;
}

void motion(int x, int y)
{
    int xDisp, yDisp;
    
    xDisp = x - xBegin; /*マウス移動距離の計算*/
    yDisp = y - yBegin;
    
    switch (mButton){
        case GLUT_LEFT_BUTTON:/*左ボタンのドラッグで物体の姿勢を変える*/
            elevation += (float)yDisp / 2.0;
            azimuth += (float)xDisp / 3.0;
            break;
        case GLUT_RIGHT_BUTTON:/*右ボタンのドラッグでズーム*/
            distance -= (float)yDisp / 10.0;
            break;
    }
    xBegin = x;/*次のステップのマウスの出発点*/
    yBegin = y;
    glutPostRedisplay();/*1ステップ分のドラッグの結果を描画に反映*/
}

void init(char *progname)
{
    int width = DISPLAY_WIDTH, height = DISPLAY_HEIGHT;
    float aspect = (float)width / (float)height;
    
    glClearColor(0.35, 0.65, 0.85, 1.0);
    
    Model = loadModel(0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30., aspect, 1., 100.);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow(argv[0]);
    
    /* CallBackFuntions */
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(myKbd);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    init(argv[0]);
    
    glutMainLoop();
    return(0);
}
