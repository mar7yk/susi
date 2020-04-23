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
    invalid = -1,
    save = 0,
    help,
    exit,
    enroll,
    advance,
    change,
    graduate,
    interrupt,
    resume,
    print,
    printall,
    enrollin,
    addgrade,
    protocol,
    report,
    addProgram,
    addCourse,
    addCourseToProgram
};

#endif /* command_h */
