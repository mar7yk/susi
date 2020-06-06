//
//  SusiConsoleRemote.hpp
//  susi
//
//  Created by Marty Kostov on 5.06.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef SusiConsoleRemote_hpp
#define SusiConsoleRemote_hpp

#include <stdio.h>

#include "SusiDatabaseQuerys.hpp"

#include "command.h"

class SusiConsoleRemote {
    SusiDatabaseQuerys* querys;
    
    void printStudent(const Student& student) const;
    
    Command getCommand(const String& sCommad) const;
    
    void _help();
    void _enroll();
    void _advance();
    void _change();
    void _graduate();
    void _interrupt();
    void _resume();
    void _print() const;
    void _printall() const;
    void _enrollin();
    void _addgrade();
    void _protocol() const;
    void _report() const;
    void _addProgram();
    void _addCourse();
    void _addCourseToProgram();
    void _exit();
    
public:
    SusiConsoleRemote(SusiDatabaseQuerys &susiDatabaseQuerys);

    bool execut(const String& commad);
    
    void run();
};

#endif /* SusiConsoleRemote_hpp */
