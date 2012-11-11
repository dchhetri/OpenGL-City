//
//  building.h
//  City
//
//  Created by Dibash Chhetri on 11/11/12.
//  Copyright (c) 2012 Dibash Chhetri. All rights reserved.
//

#ifndef __City__building__
#define __City__building__

#include "utility.h"


//note lives by the contract that building should have
//width of 1-unit, height is not limited but should be practical
class Building{
public:
    enum BuildingType{
        DEFAULT_UNIT
    };
private:
    BuildingType m_type;
    Vector3f m_position;
public:
    Building(const BuildingType& type = DEFAULT_UNIT);
    void render()const;
    
    
    //accessors/mutators
    Vector3f& position();
    const Vector3f& position()const;
    
private:
    void _renderDefaultBuilding()const;
};

#endif /* defined(__City__building__) */
