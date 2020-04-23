//
//  stringCommandInterpreter.hpp
//  susi
//
//  Created by Marty Kostov on 23.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef stringCommandInterpreter_hpp
#define stringCommandInterpreter_hpp

#include <stdio.h>

#include "susiDatabase.hpp"
#include "command.h"

class StrCommandInterpr {
    SusiDatabase database;
    
    Command getCommand(const String& sCommad);
    
    static size_t stringToNum(const String sID);
    
    static double stringToGrade(const String sID);
    
    void _help();
    void _enroll();
    void _advance();
    void _change();
    void _graduate();
    void _interrupt();
    void _resume();
    void _print();
    void _printall();
    void _enrollin();
    void _addgrade();
    void _protocol();
    void _report();
    void _addProgram();
    void _addCourse();
    void _addCourseToProgram();
    void _exit();
    
public:
    
    bool execut(const String& commad);
};

#endif /* stringCommandInterpreter_hpp */
