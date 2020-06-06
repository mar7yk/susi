//
//  SusiDatabaseQuerys.hpp
//  susi
//
//  Created by Marty Kostov on 5.06.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef SusiDatabaseQuerys_hpp
#define SusiDatabaseQuerys_hpp

#include <stdio.h>

#include "SusiDatabase.h"

class SusiDatabaseQuerys {
    SusiDatabase* dataBase;
    
public:
    SusiDatabaseQuerys(SusiDatabase& susiDataBase);
    
    void save();
    
    void enroll(const unsigned int fn, const String &name, const String& program, const unsigned short gruop);
    
    void advance(const unsigned int fn);
    
    void change(const unsigned int fn, const String& option, const String& value);
    
    void graduate(const unsigned int fn);
    
    void interrupt(const unsigned int fn);
    
    void resume(const unsigned int fn);
    
    Student print(const unsigned int fn) const;
    
    Vector<Student> printall(const String &program, const unsigned short gruop);
    
    void enrollin(const unsigned int fn, const String& courseName);
    
    void addgrade(const unsigned short fn, const String &courseName, const double grade);
    
    Vector<StudentProtocol> protocol(const String &courseName);
    
    Vector<CourseReport> report(const unsigned short fn);
    
    double getAverage(const unsigned short fn);
    
    void addprogram(const String &program);
    
    void addcourse(const String &courseName, const bool optional);
    
    void addcoursetoprogram(const String &program, const String &courseNameconst, short unsigned year);
};

#endif /* SusiDatabaseQuerys_hpp */