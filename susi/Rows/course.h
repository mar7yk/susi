//
//  course.h
//  susi
//
//  Created by Marty Kostov on 24.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef course_h
#define course_h

#include "string.hpp"

struct Course {
    size_t id;
    String name;
    bool optional;
};

#endif /* course_h */
