//
//  command.h
//  susi
//
//  Created by Marty Kostov on 23.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef command_h
#define command_h

enum class Command {
    Invalid = -1,
    Save = 0,
    Help,
    Exit,
    Enroll,
    Advance,
    Change,
    Graduate,
    Interrupt,
    Resume,
    Print,
    Printall,
    Enrollin,
    Addgrade,
    Protocol,
    Report,
    AddProgram,
    AddCourse,
    AddCourseToProgram
};

#endif /* command_h */
