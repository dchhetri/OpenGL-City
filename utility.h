//
//  utility.h
//  City
//
//  Created by Dibash Chhetri on 11/9/12.
//  Copyright (c) 2012 Dibash Chhetri. All rights reserved.
//

#ifndef City_utility_h
#define City_utility_h


#include "vmath.h"
#include <GLUT/GLUT.h>
#include <string>

namespace Utility{

    const float PI = 3.1415265359;
    const float PIdiv180 = 3.1415265359/180.0;
    
    static void drawMessage(const std::string& msg, const Vector3f& pos) {
        glRasterPos3f(pos.x, pos.y, pos.z);
        for (int i = 0; i < msg.size(); i++) {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg[i]);
        }
    }
    
}

#endif
