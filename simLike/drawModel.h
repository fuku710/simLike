//
//  drawModel.h
//  simLike
//
//  Created by Fukuda Naoto on 2017/10/29.
//  Copyright © 2017年 Fukuda Naoto. All rights reserved.
//

#ifndef drawModel_h
#define drawModel_h

#include <stdio.h>
#include "glm.h"

GLMmodel* loadModel(int modelNum);
void drawModel(GLMmodel* model,int x,int y,int z);

#endif /* drawModel_h */
