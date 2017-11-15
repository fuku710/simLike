//
//  drawModel.c
//  simLike
//
//  Created by Fukuda Naoto on 2017/10/29.
//  Copyright © 2017年 Fukuda Naoto. All rights reserved.
//

#include "drawModel.h"

char *modelName[2] = {
    "/Users/naoto/Xcode/simLike/simLike/model/LibertStatue.obj",
    "",};

GLMmodel* loadModel(int modelNum){
    GLMmodel* model = glmReadOBJ(modelName[modelNum]);
    glmFacetNormals(model);
    glmVertexNormals(model, 90);
    glmUnitize(model);
    glmLinearTexture(model);
    glmScale(model, 3.0);
    return model;
}

void drawModel(GLMmodel* model,int x,int y,int z){
    glPushMatrix();
    glTranslatef(x + 0.7, y - 0.5, z + 2.0);
    glRotated(90, 1.0, 0.0, 0.0);
    glmDraw(model,GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
    glPopMatrix();
}
