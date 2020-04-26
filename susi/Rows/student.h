//
//  student.h
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef student_h
#define student_h

#include <stdio.h>

#include "string.hpp"

struct Student {
    unsigned fn;
    String name;
    short unsigned year;
    size_t programID;
    short unsigned gruop;
    short unsigned status;
    double average;
};

#endif /* student_h */
