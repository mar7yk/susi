//
//  enrolleesInCourses.hpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef enrolleesInCourses_hpp
#define enrolleesInCourses_hpp

#include <stdio.h>

#include "string.hpp"
#include "students.hpp"
#include "courses.hpp"
#include "programs.hpp"

class EnrolleesInCourses {
    const static String file;
    
    struct EnrolledInCourse {
        short unsigned studentFN;
        size_t courseID;
        double grade;
    };
    
    size_t size;
    size_t capacity;
    EnrolledInCourse* enrollees;
    
    void resize(const size_t newCapacity);
    
    void display(const EnrolledInCourse &enrollee, const Students &allStudents) const;
    
public:
    EnrolleesInCourses();
    ~EnrolleesInCourses();
    
    void add(const short unsigned studentFN, const short unsigned courseID);
    
    void displayForStudent(const unsigned short studentFN, const Courses &allCourses) const;
    
    void save();
    
    void addGrade(const unsigned short studentFN, const short unsigned courseID, const double grade);
    
    void infoForEnrollees(short unsigned courseID, const Students& allStudents) const;
    
    double getNewAverage(const short unsigned studentFN) const;
};

#endif /* enrolleesInCourses_hpp */
