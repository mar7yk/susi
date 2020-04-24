//
//  studentInfo.h
//  susi
//
//  Created by Marty Kostov on 24.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef studentInfo_h
#define studentInfo_h

#include "string.hpp"

struct StudentInfo {
    unsigned fn;
    String name;
    String program;
    short unsigned year;
    short unsigned gruop;
    String status;
    double average;
};

#endif /* studentInfo_h */
