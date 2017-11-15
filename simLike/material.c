//
//  material.c
//  simLike
//
//  Created by Fukuda Naoto on 2017/10/31.
//  Copyright © 2017年 Fukuda Naoto. All rights reserved.
//

#include "material.h"

MaterialStruct materialWhite = {
    {1.0,1.0,1.0,0.0},
    {1.0,1.0,1.0,0.0},
    {1.0,1.0,1.0,0.0},
    10
};

MaterialStruct materialGray = {
    {0.7,0.7,0.7,1.0},
    {0.3,0.3,0.3,1.0},
    {0.1,0.1,0.1,1.0},
    10
};

MaterialStruct materialRed = {
    {0.8,0.2,0.2,0.5},
    {0.3,0.1,0.1,0.5},
    {0.0,0.0,0.0,0.5},
    10
};

MaterialStruct materialGreen = {
    {0.2,0.8,0.2,0.5},
    {0.1,0.3,0.1,0.5},
    {0.0,0.0,0.0,0.5},
    10
};

MaterialStruct materialBlue = {
    {0.2,0.2,0.8,0.5},
    {0.1,0.1,0.3,0.5},
    {0.0,0.0,0.0,0.5},
    10
};

MaterialStruct materialRoad = {
    {0.30,0.30,0.30,0.5},
    {0.05,0.05,0.05,0.5},
    {0.0,0.0,0.0,1.0},
    10
};

MaterialStruct materialCursor = {
    {0.5,0.5,0.0,1.0},
    {0.5,0.5,0.0,0.0},
    {0.05,0.05,0.05,1.0},
    10
};

MaterialStruct materialResidenceArea = {
    {0.0,0.5,0.0,1.0},
    {0.0,0.5,0.0,0.0},
    {0.05,0.05,0.05,1.0},
    10
};

MaterialStruct materialCommercialArea = {
    {0.0,0.0,0.5,1.0},
    {0.0,0.0,0.5,0.0},
    {0.05,0.05,0.05,1.0},
    10
};

MaterialStruct materialIndustrialArea = {
    {0.5,0.0,0.0,1.0},
    {0.5,0.0,0.0,0.0},
    {0.05,0.05,0.05,1.0},
    10
};

MaterialStruct materialLandmark = {
    {0.5,0.5,0.1,1.0},
    {0.9,0.9,0.3,0.0},
    {0.05,0.05,0.05,1.0},
    10
};

MaterialStruct materialGrass = {
    {0.3,0.7,0.2,1.0},
    {0.2,0.3,0.2,0.3},
    {0.6,0.9,0.8,0.1},
    64
};

void setMaterial(MaterialStruct materialName){
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialName.ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialName.diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialName.specular);
    glMaterialf(GL_FRONT, GL_SHININESS, materialName.shininess);
}
