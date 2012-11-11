//
//  City.cpp
//  City
//
//  Created by Dibash Chhetri on 11/10/12.
//  Copyright (c) 2012 Dibash Chhetri. All rights reserved.
//

#include "City.h"
#include <OpenGL/OpenGL.h>
#include <algorithm>
#include <iostream>
using namespace std;

City:: City(unsigned numberOfStreet,
            unsigned numberOfBlocksPerStreet,
            unsigned numberOfBuildingsPerBlocks,
            float spacingBetweenBuildingFactor)
: m_numberOfStreet(numberOfStreet),
  m_numberOfBlocksPerStreet(numberOfBlocksPerStreet),
  m_numberOfBuildingPerBlock(numberOfBuildingsPerBlocks),
  m_spacingBetweenBuildingFactor(spacingBetweenBuildingFactor)
{
    m_buildings.resize(numberOfBuildingsPerBlocks * numberOfBlocksPerStreet * numberOfStreet);
        
    for(int i = 0; i < m_buildings.size(); ++i){
        float x = (i % m_numberOfBlocksPerStreet)* 4;
        float z = (i / m_numberOfBlocksPerStreet) * 4;
        float y = 0;
        m_buildings[i].position() = {x,y,-z};
        std::cout << "building[" << i << "] = " << m_buildings[i].position() << std::endl;
    }
}

void City::render()const{
    glTranslatef(-4.0f, 0.0f, 0.0f);
    //render surface
    _renderSurface();
    //render buildings
    std::for_each(std::begin(m_buildings), std::end(m_buildings), [](const Building& b){b.render();});
    glTranslatef(4.0f, 0.0f, 0.0f);
}


void City::_renderSurface()const{
    
#define USE_SINGLE_SURFACE
    

    glColor3f(0.2f,0.2f,0.2f);
#ifdef USE_SINGLE_SURFACE
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    const auto numOfBuildings = m_buildings.size();
    const float WIDTH = 4*(numOfBuildings/m_numberOfBlocksPerStreet) - 1;
    const float HEIGHT = 4*(numOfBuildings/m_numberOfBlocksPerStreet) - 1;
    cout << "width = " << WIDTH << endl;
    cout << "height = " << HEIGHT << endl;
    glBegin(GL_QUADS);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(WIDTH,0.0f,0.0f);
    glVertex3f(WIDTH,0.0f,-HEIGHT);
    glVertex3f(0.0f,0.0f,-HEIGHT);
    glEnd();
    
#else
    for(int i = 0; i < m_buildings.size(); ++i){
        int x = (i % m_numberOfBlocksPerStreet) * 2;
        int y = 0;
        int z = -(i/m_numberOfBlocksPerStreet) * 2;
        Vector3f bottomLeft = {x,y,z};
        Vector3f bottomRight = {bottomLeft.x + 1, bottomLeft.y, bottomLeft.z};
        Vector3f topRight = {bottomRight.x, bottomRight.y, bottomRight.z - 1};
        Vector3f topLeft = {bottomLeft.x, bottomLeft.y, bottomLeft.z - 1};
        cout << i << ": = " << bottomLeft << endl;
        glBegin(GL_QUADS);
            glVertex3f(bottomLeft.x,bottomLeft.y,bottomLeft.z);
            glVertex3f(topLeft.x, topLeft.y, topLeft.z);
            glVertex3f(topRight.x, topRight.y, topRight.z);
            glVertex3f(bottomRight.x, bottomRight.y, bottomRight.z);
        glEnd();
    }
#endif
    
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glColor3f(1.0f,1.0f,1.0f);
}