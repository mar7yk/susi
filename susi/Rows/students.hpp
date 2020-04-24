//
//  students.hpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef students_hpp
#define students_hpp

#include <stdio.h>
#include <fstream>

#include "student.hpp"
#include "string.hpp"

#include "programs.hpp"
#include "studentInfo.h"

class Students {
    const static String file;
    
//    struct Student {
//        unsigned fn;
//        String name;
//        short unsigned year;
//        size_t programID;
//        short unsigned gruop;
//        short unsigned status;
//        double average;
//    };

    
    size_t size;
    size_t capacity;
    Student* students;
    
    void resize(const size_t newCapacity);
    
    void display(const Student& student, const Programs& allPrograms) const;
    
    StudentInfo getInfo(const Student& student, const Programs& allPrograms) const;
    
public:
    Students();
    ~Students();
    
    void save();
    
    void add(const unsigned fn, const String &name, const size_t programID, const unsigned short gruop);
    
    Student &get(const unsigned fn) const;
    
    StudentInfo info(const unsigned fn, const Programs& allPrograms) const;
    
    void info(const size_t programID, const short unsigned year, const Programs& allPrograms) const;
};

#endif /* students_hpp */
