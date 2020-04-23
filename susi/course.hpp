//
//  course.hpp
//  susi
//
//  Created by Marty Kostov on 23.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef course_hpp
#define course_hpp

#include <stdio.h>

#include "string.hpp"

struct Course {
    size_t id;
    String name;
    bool optional;
};

#endif /* course_hpp */
