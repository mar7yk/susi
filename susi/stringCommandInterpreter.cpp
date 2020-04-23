//
//  stringCommandInterpreter.cpp
//  susi
//
//  Created by Marty Kostov on 23.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#include "stringCommandInterpreter.hpp"


bool StrCommandInterpr::execut(const String &newCommand) {
    bool toContinue = true;

    String sCommand = strtok(newCommand, " ");

    Command command = getCommand(sCommand);;

    switch (command) {
        case Command::invalid:
            std::cout << "command not found: " << sCommand << std::endl;
            break;
        case Command::save:
            database.save();
            break;
        case Command::help:
            _help();
            break;
        case Command::exit:
            _exit();
            toContinue = false;
            break;
        case Command::enroll:
            _enroll();
            break;
        case Command::advance:
            _advance();
            break;
        case Command::change:
            _change();
            break;
        case Command::graduate:
            _graduate();
            break;
        case Command::interrupt:
            _interrupt();
            break;
        case Command::resume:
            _resume();
            break;
        case Command::print:
            _print();
            break;
        case Command::printall:
            _printall();
            break;
        case Command::enrollin:
            _enrollin();
            break;
        case Command::addgrade:
            _addgrade();
            break;
        case Command::protocol:
            _protocol();
            break;
        case Command::report:
            _report();
            break;
        case Command::addProgram:
            _addProgram();
            break;
        case Command::addCourse:
            _addCourse();
            break;
        case Command::addCourseToProgram:
            _addCourseToProgram();
            break;
    }
    std::cout << std::endl;


    return toContinue;
}

void StrCommandInterpr::_enroll() {
    unsigned fn = (unsigned)stringToNum(strtok(NULL, " "));
    String program = strtok(NULL, " ");
    unsigned short gruop = stringToNum(strtok(NULL, " "));
    String name = strtok(NULL, " ");
    
    database.enroll(fn, program, gruop, name);
}

void StrCommandInterpr::_advance() {
    unsigned fn = (unsigned)stringToNum(strtok(NULL, " "));
    database.advance(fn);
}

void StrCommandInterpr::_change() {
    unsigned fn = (unsigned)stringToNum(strtok(NULL, " "));
    String option = strtok(NULL, " ");
    String value = strtok(NULL, " ");
    
    if (option == "program") {
        database.changeProgram(fn, value);
        
    } else if (option == "group") {
        unsigned short gruop = stringToNum(value);
        database.changeGruop(fn, gruop);
        
    } else if (option == "year") {
        unsigned short year = stringToNum(value);
        database.changeYear(fn, year);
        
    }
}

void StrCommandInterpr::_graduate() {
    unsigned fn = (unsigned)stringToNum(strtok(NULL, " "));
    database.graduate(fn);
}

void StrCommandInterpr::_interrupt() {
    unsigned fn = (unsigned)stringToNum(strtok(NULL, " "));
    database.interrupt(fn);
}

void StrCommandInterpr::_resume() {
    unsigned fn = (unsigned)stringToNum(strtok(NULL, " "));
    database.resume(fn);
}

void StrCommandInterpr::_print() {
    unsigned fn = (unsigned)stringToNum(strtok(NULL, " "));
    database.print(fn);
}

void StrCommandInterpr::_printall() {
    String program = strtok(NULL, " ");
    unsigned short year = stringToNum(strtok(NULL, " "));
    
    database.printall(program, year);
}

void StrCommandInterpr::_enrollin() {
    unsigned fn = (unsigned)stringToNum(strtok(NULL, " "));
    String course = strtok(NULL, " ");
    
    database.enrollin(fn, course);
}

void StrCommandInterpr::_addgrade() {
    unsigned fn = (unsigned)stringToNum(strtok(NULL, " "));
    String course = strtok(NULL, " ");
    double grade = stringToGrade(strtok(NULL, " "));
    
    
    database.addGrade(fn, course, grade);
}

void StrCommandInterpr::_protocol() {
    String course = strtok(NULL, " ");
    database.protocol(course);
}

void StrCommandInterpr::_report() {
    unsigned fn = (unsigned)stringToNum(strtok(NULL, " "));
    database.report(fn);
}

void StrCommandInterpr::_addProgram() {
    String program = strtok(NULL, " ");
    database.addProgram(program);
}

void StrCommandInterpr::_addCourse() {
    String course = strtok(NULL, " ");
    String type = strtok(NULL, " ");
    database.addCourse(course, type);
}

void StrCommandInterpr::_addCourseToProgram() {
    String course = strtok(NULL, " ");
    String program = strtok(NULL, " ");
    unsigned short year = stringToNum(strtok(NULL, " "));
    
    database.addCourseToProgram(course, program, year);
}

void StrCommandInterpr::_exit() {
    if (!database.isSaved) {
        std::cout << "You have not saved the latest changes!" << std::endl;
        std::cout << "Would you like to save it?" << std::endl;
        std::cout << "yes/no" << std::endl;
        String answer;
        std::cin >> answer;
        while (answer != "yes" && answer != "no") {
            std::cout << "Please, give answer!" << std::endl;
            std::cout << "yes/no" << std::endl;
            std::cin >> answer;
        }
        if (answer == "yes") {
            database.save();
        }
    }
    
    std::cout << std::endl;
    std::cout << "Exiting the program..." << std::endl;
}

Command StrCommandInterpr::getCommand(const String &sCommad) {
    if (sCommad == "save") return Command::save;
    if (sCommad == "help") return Command::help;
    if (sCommad == "exit") return Command::exit;
    if (sCommad == "enroll") return Command::enroll;
    if (sCommad == "advance") return Command::advance;
    if (sCommad == "change") return Command::change;
    if (sCommad == "graduate") return Command::graduate;
    if (sCommad == "interrupt") return Command::interrupt;
    if (sCommad == "resume") return Command::resume;
    if (sCommad == "print") return Command::print;
    if (sCommad == "printall") return Command::printall;
    if (sCommad == "enrollin") return Command::enrollin;
    if (sCommad == "protocol") return Command::protocol;
    if (sCommad == "report") return Command::report;


    if (sCommad == "add") {
        String sec = strtok(NULL, " ");
        if(sec == "grade")  return Command::addgrade;
        if(sec == "program")  return Command::addProgram;
        if(sec == "course")  return Command::addCourse;
        if(sec == "courseToProgram")  return Command::addCourseToProgram;
    }


    return Command::invalid;
}

void StrCommandInterpr::_help() {
    
}

size_t StrCommandInterpr::stringToNum(const String sID) {
    size_t num = 0;
    for (size_t i = 0; i < sID.lenght; ++i) {
        if (sID[i] < '0' || sID[i] > '9') {
            return 0;
        }
        size_t n = sID[i] - '0';
        num = (num*10) + n;
    }
    return num;
}

double StrCommandInterpr::stringToGrade(const String sID) {
    double num = 0;
    bool havePoint = false;
    double divider = 1;
    for (size_t i = 0; i < sID.lenght; ++i) {
        if (sID[i] == '.' && !havePoint) {
            havePoint = true;
            continue;
        } else if (sID[i] < '0' || sID[i] > '9') {
            return 0;
        }
        double n = sID[i] - '0';
        num = (num*10) + n;
        
        if (havePoint) {
            divider *= 10;
        }
    }
    
    return num /= divider;
}


