//
//  material.h
//  simLike
//
//  Created by Fukuda Naoto on 2017/10/31.
//  Copyright © 2017年 Fukuda Naoto. All rights reserved.
//

#ifndef material_h
#define material_h

#include <stdio.h>
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>

/* Material構造体
 --------------------
 マテリアル情報
 --------------------
 GLfloat ambient[4] :環境光
 GLfloat diffuse[4] :拡散光
 GLfloat specular[4]:鏡面光
 GLfloat shiness[4] :鏡面光の指数
 */

typedef struct {
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat shininess;
} MaterialStruct;

extern MaterialStruct materialWhite;
extern MaterialStruct materialGray;

extern MaterialStruct materialRed;
extern MaterialStruct materialGreen;
extern MaterialStruct materialBlue;

extern MaterialStruct materialRoad;

extern MaterialStruct materialCursor;

extern MaterialStruct materialResidenceArea;
extern MaterialStruct materialCommercialArea;
extern MaterialStruct materialIndustrialArea;
extern MaterialStruct materialLandmark;

extern MaterialStruct materialGrass;

void setMaterial(MaterialStruct materialName);

#endif /* material_h */
