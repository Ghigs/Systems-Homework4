//
//  newVoxelModel.cpp
//  Homework 4
//
//  Created by Jason Ghiglieri on 2/14/18.
//  Copyright © 2018 Jason Ghiglieri. All rights reserved.
//

#include "newVoxelModel.hpp"

VoxelModel allocateModel(int nx, int ny, int nz)
{
    VoxelModel* model = new VoxelModel();
    model->cellsX = nx;
    model->cellsY = ny;
    model->cellsZ = nz;
    model->bitMap = new uint8_t[((nx*ny*nz)/8)+1];
    
    clearModel(*model);
    
    return *model;
}


void clearModel(VoxelModel& model)
{
    for (int i = 0; i < ((model.cellsX * model.cellsY * model.cellsZ)/8)+1; i++)
    {
        model.bitMap[i] = 0;
    }
}


void fillModel(VoxelModel& model)
{
    for (int i = 0; i < ((model.cellsX * model.cellsY * model.cellsZ)/8)+1; i++)
    {
        uint8_t maxVal = ~0;
        model.bitMap[i] = maxVal;
    }
}


void deleteModel(VoxelModel& model)
{
    delete [] model.bitMap;
    model.bitMap = NULL;
    model.cellsX = 0;
    model.cellsY = 0;
    model.cellsZ = 0;
}



// Method for retrieving the index of the given X, Y, Z coordinates
int getIndex(const VoxelModel& model, int x, int y, int z)
{
    int resultIndex = 0;
    
    resultIndex = ((x * (model.cellsY * model.cellsZ)) + (y * model.cellsZ) + z);
    
    return resultIndex;
}


// Method for retrieving the X value of a given index
void getXYZ(const VoxelModel& model, int index, int& x, int& y, int& z)
{
    x = index / (model.cellsY * model.cellsZ);
    index -= (x * model.cellsY * model.cellsZ);
    
    y = index / model.cellsZ;
    index -= (y * model.cellsZ);
    
    z = index;
}


int getByteNumber(int index)
{
    int result = index / 8;
    return result;
}


uint8_t getBitNumber(int index)
{
    int result = index % 8;
    return result;
}


bool getBit(const VoxelModel model, int x, int y, int z)
{
    int index = getIndex(model, x, y, z);
    int byte = getByteNumber(index);
    int bit = getBitNumber(index);
    
    uint8_t comparator = 1 << bit;
    
    if ((model.bitMap[byte] | comparator) == model.bitMap[byte])
    {
        return true;
    }
    else
    {
        return false;
    }
}


void setBit(VoxelModel& model, int x, int y, int z)
{
    int index = getIndex(model, x, y, z);
    int byte = getByteNumber(index);
    int bit = getBitNumber(index);
    
    uint8_t comparator = 1 << bit;
    
    model.bitMap[byte] = model.bitMap[byte] | comparator;
}


void clearBit(VoxelModel& model, int x, int y, int z)
{
    int index = getIndex(model, x, y, z);
    int byte = getByteNumber(index);
    int bit = getBitNumber(index);
    
    uint8_t comparator = 1 << bit;
    comparator = ~comparator;
    
    model.bitMap[byte] = model.bitMap[byte] & comparator;
}


void toggleBit(VoxelModel& model, int x, int y, int z)
{
    int index = getIndex(model, x, y, z);
    int byte = getByteNumber(index);
    int bit = getBitNumber(index);
    
    uint8_t comparator = 1 << bit;
    
    if ((model.bitMap[byte] | comparator) == model.bitMap[byte])
    {
        comparator = ~comparator;
        model.bitMap[byte] = model.bitMap[byte] & comparator;
    }
    else
    {
        model.bitMap[byte] = model.bitMap[byte] | comparator;
    }
}


void addSphere(VoxelModel& model, float cx, float cy, float cz, float radius)
{
    for (int x = 0; x < model.cellsX; x++)
    {
        for (int y = 0; y < model.cellsY; y++)
        {
            for (int z = 0; z < model.cellsZ; z++)
            {
                if (pow(x-cx, 2) + pow(y-cy, 2) + pow(z-cz, 2) < pow(radius, 2))
                {
                    setBit(model, x, y, z);
                }
            }
        }
    }
}


void subtractSphere(VoxelModel& model, float cx, float cy, float cz, float radius)
{
    for (int x = 0; x < model.cellsX; x++)
    {
        for (int y = 0; y < model.cellsY; y++)
        {
            for (int z = 0; z < model.cellsZ; z++)
            {
                if (pow(x-cx, 2) + pow(y-cy, 2) + pow(z-cz, 2) < pow(radius, 2))
                {
                    clearBit(model, x, y, z);
                }
            }
        }
    }
}


void toggleSphere(VoxelModel& model, float cx, float cy, float cz, float radius)
{
    for (int x = 0; x < model.cellsX; x++)
    {
        for (int y = 0; y < model.cellsY; y++)
        {
            for (int z = 0; z < model.cellsZ; z++)
            {
                if (pow(x-cx, 2) + pow(y-cy, 2) + pow(z-cz, 2) < pow(radius, 2))
                {
                    toggleBit(model, x, y, z);
                }
            }
        }
    }
}
