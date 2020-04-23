//
//  main.cpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#include <iostream>

#include "susiDatabase.hpp"

int main() {
    
    SusiDatabase database;
    
    database.addProgram("Informatics");
    
    database.addCourse("OOP", 1);
    database.addCourse("VA", 1);
    database.addCourse("DSTR", 1);
    
    database.addCourseToProgram("OOP", "Informatics");
    database.addCourseToProgram("VA", "Informatics");
    database.addCourseToProgram("DSTR", "Informatics");
    
    
    database.enroll(45709, "Informatics", 6, "Martin Kostov");
    
    database.enrollin(45709, "OOP");
    database.enrollin(45709, "VA");
    database.enrollin(45709, "DSTR");
    
    database.addGrade(45709, "OOP", 6);
    
    database.report(45709);
    
    return 0;
}
