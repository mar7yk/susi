//
//  Course.h
//  susi
//
//  Created by Marty Kostov on 24.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef Course_h
#define Course_h

#include "string.hpp"

struct Course {
    size_t ID;
    String name;
    bool optional;
};

#endif /* Course_h */
