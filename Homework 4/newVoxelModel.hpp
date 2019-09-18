//
//  newVoxelModel.hpp
//  Homework 4
//
//  Created by Jason Ghiglieri on 2/14/18.
//  Copyright © 2018 Jason Ghiglieri. All rights reserved.
//

#ifndef newVoxelModel_hpp
#define newVoxelModel_hpp

#include <stdio.h>
#include <cstdint>
#include <cmath>

struct VoxelModel
{
    int cellsX;
    int cellsY;
    int cellsZ;
    
    uint8_t* bitMap;
};

VoxelModel allocateModel(int nx, int ny, int nz);

void clearModel(VoxelModel& model);

void fillModel(VoxelModel& model);

void deleteModel(VoxelModel& model);


int getIndex(const VoxelModel& model, int x, int y, int z);

void getXYZ(const VoxelModel& model, int index, int x, int y, int z);

int getByteNumber(int index);

uint8_t getBitNumber(int index);


bool getBit(const VoxelModel model, int x, int y, int z);

void setBit(VoxelModel& model, int x, int y, int z);

void clearBit(VoxelModel& model, int x, int y, int z);

void toggleBit(VoxelModel& model, int x, int y, int z);


void addSphere(VoxelModel& model, float cx, float cy, float cz, float radius);

void subtractSphere(VoxelModel& model, float cx, float cy, float cz, float radius);

void toggleSphere(VoxelModel& model, float cx, float cy, float cz, float radius);

#endif /* newVoxelModel_hpp */
