//
//  newSurfaceExtraction.hpp
//  Homework 4
//
//  Created by Jason Ghiglieri on 2/14/18.
//  Copyright © 2018 Jason Ghiglieri. All rights reserved.
//

#ifndef newSurfaceExtraction_hpp
#define newSurfaceExtraction_hpp

#include <stdio.h>
#include "newVoxelModel.hpp"

enum FaceType {
    NX,
    NY,
    NZ,
    PX,
    PY,
    PZ
};

struct Triangle{
    float normal[3];
    float v1[3];
    float v2[3];
    float v3[3];
};

void writeSTL(const VoxelModel model, const char* filename);

uint32_t findTriangles(int x, int y, int z, const VoxelModel model, FILE* file);

void writeTriangles(Triangle& t1, Triangle& t2, FILE* file);

void extractFace(int x, int y, int z, FaceType face, Triangle& t1, Triangle& t2);

#endif /* newSurfaceExtraction_hpp */
