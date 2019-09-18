//
//  main.cpp
//  Homework 4
//
//  Created by Jason Ghiglieri on 2/13/18.
//  Copyright © 2018 Jason Ghiglieri. All rights reserved.
//

#include <iostream>
#include "newSurfaceExtraction.hpp"
#include "newVoxelModel.hpp"

int main(int argc, const char * argv[])
{
    int nx = 50;
    int ny = 30;
    int nz = 50;
    
    VoxelModel model = allocateModel(nx, ny, nz);
    
    
    // Creates a model resembling a ship from Star Wars.
    // Look up "Trade Federation Battleship" on google images to see the inspiration.
    addSphere(model, 25, 15, 25, 25);
    subtractSphere(model, 25, 15, 25, 18);
    for (int x = 0; x < nx; x++)
    {
        for (int y = 0; y < ny; y++)
        {
            for (int z = 0; z < nz; z++)
            {
                
                if (y < 12 || y > 18 || (z < 25 && (x > 18 && x < 32)))
                {
                    clearBit(model, x, y, z);
                }
                
                if (z > 33 && (x > 22 && x < 28) && (y > 12 && y < 18))
                {
                    setBit(model, x, y, z);
                }
            }
        }
    }
    toggleSphere(model, 25, 15, 27, 7);
    
    writeSTL(model, "newFile.stl");
}
