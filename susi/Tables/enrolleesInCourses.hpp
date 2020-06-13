//
//  EnrolleesInCourses.hpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef EnrolleesInCourses_hpp
#define EnrolleesInCourses_hpp

#include <stdio.h>

#include "string.hpp"
#include "vector.h"

#include "Table.h"

#include "Students.hpp"
#include "Courses.hpp"
#include "StudentProtocol.h"
#include "CourseReport.h"

class EnrolleesInCourses : public Table {
    
    struct EnrolledInCourse {
        short unsigned studentFN;
        size_t courseID;
        double grade;
    };
    
    Vector<EnrolledInCourse> enrollees;
    
    Students& students_;
    Courses& courses_;
    
    void load(const String& file) override;
    
public:
    EnrolleesInCourses(Students& students, Courses& courses);
    
    void save() const override;
    
    void add(const short unsigned studentFN, const short unsigned courseID);
    
    void update_grade(const unsigned short studentFN, const short unsigned courseID, const double grade);
    
    Vector<StudentProtocol> get_protocol(const size_t courseID) const;
    
    Vector<CourseReport> get_report_by_fn(const unsigned fn);
};

#endif /* EnrolleesInCourses_hpp */
