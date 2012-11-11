//
//  building.cpp
//  City
//
//  Created by Dibash Chhetri on 11/11/12.
//  Copyright (c) 2012 Dibash Chhetri. All rights reserved.
//

#include "building.h"


Building::Building(const BuildingType& type)
: m_type(type)
{}

void Building::render()const{
    switch (m_type)
    {
        case DEFAULT_UNIT:
            _renderDefaultBuilding();
            break;
    }
}

Vector3f& Building::position(){
    return m_position;
}
const Vector3f& Building::position()const{
    return m_position;
}

void Building::_renderDefaultBuilding()const{
    glTranslatef(m_position.x,m_position.y,m_position.z);
    glTranslatef(0.5f,0.5f,-0.5f); //translate so its bottom surface starts at (0,0,0)
    glutSolidCube(1.0f);
    glTranslatef(-0.5f,-0.5f,0.5f);
    glTranslatef(-m_position.x, -m_position.y, -m_position.z);
}