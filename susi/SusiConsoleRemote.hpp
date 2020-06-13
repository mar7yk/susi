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

/// Служи за подаване на заявките към susi база данни през конзолзата
class SusiConsoleRemote {
    SusiDatabaseQuerys* querys;
    
    /// Показва информация за даден студент.
    void printStudent(const Student& student) const;
    
    /// Преобразува string команда в enum command.
    Command getCommand(const String& sCommad) const;
    
    void _help() const;
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
    void _upload();
    
    /// Изпълнява команда по подаден стринг.
    bool execut(const String& commad);
public:
    SusiConsoleRemote(SusiDatabaseQuerys &susiDatabaseQuerys);
    
    /// Стартира приложението.
    void run();
};

#endif /* SusiConsoleRemote_hpp */
