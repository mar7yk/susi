//
//  Student.h
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include <stdio.h>

#include "string.hpp"

struct Student {
    unsigned fn;
    String name;
    String program;
    short unsigned year;
    short unsigned gruop;
    short unsigned status;
    double average;
};

#endif /* Student_h */
