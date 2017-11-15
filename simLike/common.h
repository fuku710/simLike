//
//  common.h
//  simLike
//
//  Created by Fukuda Naoto on 2017/10/26.
//  Copyright © 2017年 Fukuda Naoto. All rights reserved.
//

#ifndef common_h
#define common_h

#define PI 3.141592

#define KEY_ESC 27

#define DISPLAY_WIDTH 800
#define DISPLAY_HEIGHT 450


#define STAGE_SIZE_X 50
#define STAGE_SIZE_Y 50
#define STAGE_SIZE_Z 1

/* 列挙型GroundType
 -------------------
 地面タイプ
 -------------------
 NONE = 0               :なし（デフォルト)
 ROAD = 1               :道路
 RESIDENCE_AREA = 2     :居住区画
 COMMERCIAL_AREA = 3    :商業区画
 INDUSTRIAL_AREA = 4    :工業区画
 LANDMARK = 5           :ランドマーク
*/

typedef enum {
    NONE,
    ROAD,
    RESIDENCE_AREA,
    COMMERCIAL_AREA,
    INDUSTRIAL_AREA,
    LANDMARK
} GroundType;

/* Point構造体
 --------------------
 座標情報
 --------------------
 int x : x座標
 int y : y座標
 */

typedef struct {
    int x;
    int y;
} Point;

/* Ground構造体
 --------------------
 地面情報
 --------------------
 enum groundType type       : 地面タイプ
 int population : 人口
 */

typedef struct {
    GroundType type;
    int population;
} Ground;

#endif /* common_h */
