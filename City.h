//
//  City.h
//  City
//
//  Created by Dibash Chhetri on 11/10/12.
//  Copyright (c) 2012 Dibash Chhetri. All rights reserved.
//

#ifndef __City__City__
#define __City__City__

#include <vector>
#include "vmath.h"
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>
#include "building.h"

//proceduraly generated city
class City{
private:
    float m_spacingBetweenBuildingFactor; //relative to building size
    unsigned m_numberOfBuildingPerBlock;
    unsigned m_numberOfBlocksPerStreet;
    unsigned m_numberOfStreet;
    std::vector<Building> m_buildings; //size depends on above property
public:
    void render()const;
    
    City(unsigned numberOfStreet = 8,
         unsigned numberOfBlocksPerStreet = 8,
         unsigned numberOfBuildingsPerBlocks = 1,
         float spacingBetweenBuildingFactor = 4);
    
private:
    void _renderSurface()const;
};

#endif /* defined(__City__City__) */
