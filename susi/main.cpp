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
    
//    database.addProgram("Informatics");
//
//
//
//    database.addCourse("UP", false);
//    database.addCourse("LA", false);
//    database.addCourse("AG", false);
//    database.addCourse("DIS1", false);
//
//    database.addCourse("OOP", false);
//    database.addCourse("VA", false);
//    database.addCourse("DSTR", false);
//    database.addCourse("DIS2", false);
//
//    database.addCourseToProgram("UP", "Informatics", 1);
//    database.addCourseToProgram("LA", "Informatics", 1);
//    database.addCourseToProgram("AG", "Informatics", 1);
//    database.addCourseToProgram("DIS1", "Informatics", 1);
//
//    database.addCourseToProgram("OOP", "Informatics", 2);
//    database.addCourseToProgram("VA", "Informatics", 2);
//    database.addCourseToProgram("DSTR", "Informatics", 2);
//    database.addCourseToProgram("DIS2", "Informatics", 2);
//
//
//    database.enroll(45709, "Informatics", 6, "Martin Kostov");
//
//    database.advance(45709);
//
//
//    database.addGrade(45709, "UP", 4);
//    database.addGrade(45709, "LA", 3);
//    database.addGrade(45709, "AG", 4);
//    database.addGrade(45709, "DIS1", 4);
    
    database.protocol("UP");
    
    database.save();
    
    return 0;
}
