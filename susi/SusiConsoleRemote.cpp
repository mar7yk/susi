//
//  SusiConsoleRemote.cpp
//  susi
//
//  Created by Marty Kostov on 5.06.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#include "SusiConsoleRemote.hpp"


SusiConsoleRemote::SusiConsoleRemote(SusiDatabaseQuerys &susiDatabaseQuerys)
    : querys(&susiDatabaseQuerys) {
    
    }

bool SusiConsoleRemote::execut(const String &newCommand) {
    bool toContinue = true;

    String sCommand = strtok(newCommand, " ");

    Command command = getCommand(sCommand);
    
    try {
        switch (command) {
            case Command::Invalid:
                std::cout << "command not found: " << sCommand << std::endl;
                break;
            case Command::Save:
                querys->save();
                break;
            case Command::Help:
                _help();
                break;
            case Command::Exit:
                _exit();
                toContinue = false;
                break;
            case Command::Enroll:
                _enroll();
                break;
            case Command::Advance:
                _advance();
                break;
            case Command::Change:
                _change();
                break;
            case Command::Graduate:
                _graduate();
                break;
            case Command::Interrupt:
                _interrupt();
                break;
            case Command::Resume:
                _resume();
                break;
            case Command::Print:
                _print();
                break;
            case Command::Printall:
                _printall();
                break;
            case Command::Enrollin:
                _enrollin();
                break;
            case Command::Addgrade:
                _addgrade();
                break;
            case Command::Protocol:
                _protocol();
                break;
            case Command::Report:
                _report();
                break;
            case Command::AddProgram:
                _addProgram();
                break;
            case Command::AddCourse:
                _addCourse();
                break;
            case Command::AddCourseToProgram:
                _addCourseToProgram();
                break;
            case Command::Upload:
                _upload();
                break;
        }
        
    } catch (std::invalid_argument& e) {
        std::cout << "Invalid input! " << std::endl;
        
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Error: unknown error" << std::endl;
    }
    
    std::cout << std::endl;


    return toContinue;
}

Command SusiConsoleRemote::getCommand(const String &sCommad) const {
    if (sCommad == "save") return Command::Save;
    if (sCommad == "help") return Command::Help;
    if (sCommad == "exit") return Command::Exit;
    if (sCommad == "enroll") return Command::Enroll;
    if (sCommad == "advance") return Command::Advance;
    if (sCommad == "change") return Command::Change;
    if (sCommad == "graduate") return Command::Graduate;
    if (sCommad == "interrupt") return Command::Interrupt;
    if (sCommad == "resume") return Command::Resume;
    if (sCommad == "print") return Command::Print;
    if (sCommad == "printall") return Command::Printall;
    if (sCommad == "enrollin") return Command::Enrollin;
    if (sCommad == "protocol") return Command::Protocol;
    if (sCommad == "report") return Command::Report;
    if (sCommad == "addgrade") return Command::Addgrade;
    if(sCommad == "addprogram") return Command::AddProgram;
    if(sCommad == "addcourse") return Command::AddCourse;
    if(sCommad == "addcoursetoprogram")  return Command::AddCourseToProgram;
    if(sCommad == "upload")  return Command::Upload;


    return Command::Invalid;
}

void SusiConsoleRemote::_enroll() {
    unsigned fn = stoi(strtok(NULL, " "));
    String program = strtok(NULL, " ");
    unsigned short gruop = stoi(strtok(NULL, " "));
    String name = strtok(NULL, "\n");
    
    querys->enroll(fn, name, program, gruop);
    
    std::cout << "You successfully enrolled new student." << std::endl;
}

void SusiConsoleRemote::_advance() {
    unsigned fn = stoi(strtok(NULL, " "));
    
    querys->advance(fn);
    
    std::cout << "You successfully enrolled a the student in the next course." << std::endl;
}

void SusiConsoleRemote::_change() {
    unsigned fn = stoi(strtok(NULL, " "));
    String option = strtok(NULL, " ");
    String value = strtok(NULL, " ");
    
    querys->change(fn, option, value);
    
    std::cout << "You successfully change student " << option << " of the student." << std::endl;
}

void SusiConsoleRemote::_graduate() {
    unsigned fn = stoi(strtok(NULL, " "));
    
    querys->graduate(fn);
    
    std::cout << "You marked the student as graduated" << std::endl;
}

void SusiConsoleRemote::_interrupt() {
    unsigned fn = stoi(strtok(NULL, " "));
    
    querys->interrupt(fn);
    
    std::cout << "You marked the student as interrupted" << std::endl;
}

void SusiConsoleRemote::_resume() {
    unsigned fn = stoi(strtok(NULL, " "));
    
    querys->resume(fn);
    std::cout << "Restores the student's student rights" << std::endl;
}

void SusiConsoleRemote::_print() const {
    unsigned fn = stoi(strtok(NULL, " "));
    Student student = querys->print(fn);
    
    printStudent(student);
}

void SusiConsoleRemote::_printall() const {
    String program = strtok(NULL, " ");
    unsigned short year = stoi(strtok(NULL, " "));
    
    Vector<Student> students = querys->printall(program, year);
    
    for (size_t i = 0; i < students.size(); ++i) {
        printStudent(students[i]);
    }
}

void SusiConsoleRemote::printStudent(const Student &student) const {
    
    String sStatus;
    switch (student.status) {
        case 1:
            sStatus = "recorded";
            break;
            

        case 2:
            sStatus = "interrupted";
            break;
        

        case 3:
            sStatus = "graduated";
            break;
            
        default:
            break;
    }
    
    
    
    std::cout << student.fn  << ", " << student.name << ", ";
    std::cout << "program " << student.program << ", ";
    std::cout << "year "<< student.year << ", ";
    std::cout << "gruop "<< student.gruop << ", ";
    std::cout << "status "<< sStatus << ", ";
    std::cout << "average "<< student.average << std::endl;
}

void SusiConsoleRemote::_enrollin() { 
    unsigned fn = stoi(strtok(NULL, " "));
    String course = strtok(NULL, " ");
    
    querys->enrollin(fn, course);
    
    std::cout << "You successfully enrolled the student in " << course << "." << std::endl;
}

void SusiConsoleRemote::_addgrade() { 
    unsigned fn = stoi(strtok(NULL, " "));
    String course = strtok(NULL, " ");
    double grade = stoi(strtok(NULL, " "));
    
    querys->addgrade(fn, course, grade);
    
    std::cout << "You successfully added a " << course << " grade for the student." << std::endl;
}

void SusiConsoleRemote::_protocol() const { 
    String course = strtok(NULL, " ");
    
    Vector<StudentProtocol> protocol = querys->protocol(course);
    
    typedef bool(*Lambda)(StudentProtocol& , StudentProtocol&);
    
    Lambda comp = [](StudentProtocol& student1, StudentProtocol& student2){
        if (student1.program < student2.program) {
            return true;
            
        } else if (student1.program == student2.program) {
            if (student1.gruop < student2.gruop) {
                return true;
                
            } else if (student1.gruop == student2.gruop) {
                if (student1.fn < student2.fn) {
                    return true;
                }
            }
        }
        
        return false;
    };
    
    std::sort(protocol.begin(), protocol.end(), comp);
    
    String program = "";
    short unsigned gruop = USHRT_MAX;
    
    for (size_t i = 0; i < protocol.size(); ++i) {
        if (program != protocol[i].program) {
            program = protocol[i].program;
            gruop = protocol[i].gruop;
            std::cout << std::endl << program << std::endl;
            std::cout << std::endl << "\tGruop " << gruop << std::endl << std::endl;
        }
        if (gruop != protocol[i].gruop) {
            gruop = protocol[i].gruop;
            std::cout << std::endl << "\tGruop " << gruop << std::endl << std::endl;
        }
        
        std::cout << "\t" << protocol[i].fn << ", " << protocol[i].name << " - " << protocol[i].grade << std::endl;
    }
    
}

void SusiConsoleRemote::_report() const { 
    unsigned fn = stoi(strtok(NULL, " "));
    
    Vector<CourseReport> report = querys->report(fn);
    
    for (size_t i = 0; i < report.size(); ++i) {
        std::cout << report[i].courseName << " - ";
        if (report[i].grade != 0) {
            std::cout << report[i].grade;
            
        } else {
            std::cout << "not passed";
        }
        
        std::cout << std::endl;
    }
    
    double average = querys->getAverage(fn);
    
    std::cout << std::endl << "average grade: " << average << std::endl;
    
    
}

void SusiConsoleRemote::_addProgram() {
    String program = strtok(NULL, " ");
    
    querys->addprogram(program);
    
    std::cout << "You successfully added new program." << std::endl;
}

void SusiConsoleRemote::_addCourse() {
    String course = strtok(NULL, " ");
    String sOptional = strtok(NULL, " ");
    
    bool optional;
    
    if (sOptional == "optional") {
        optional = true;
    } else if (sOptional == "mandatory") {
        optional = false;
    } else {
        throw std::runtime_error("Please add is course mandatory!");
    }
    
    querys->addcourse(course, optional);
    
    std::cout << "You successfully added new course." << std::endl;
}


void SusiConsoleRemote::_addCourseToProgram() {
    String course = strtok(NULL, " ");
    String program = strtok(NULL, " ");
    short unsigned year = stoi(strtok(NULL, " "));
    
    querys->addcoursetoprogram(program, course, year);
    
    std::cout << "You successfully added new course to " << program << "." << std::endl;
}


void SusiConsoleRemote::_exit() {
    querys->save();
    std::cout << "Exiting the program..." << std::endl;
}

void SusiConsoleRemote::_help() const {
    std::cout << "enroll <fn> <program> <group> <name>:" << std::endl;
    std::cout << "\tenrollment of a student with name <name> in 1 course of <program> in <group> and with faculty number <fn>." << std::endl;
    std::cout << std::endl;
    
    std::cout << "advance <fn>:" << std::endl;
    std::cout << "\tenrolls a student in the next course." << std::endl;
    std::cout << std::endl;
    
    std::cout << "change <fn>:" << std::endl;
    std::cout << "\t<option> is one of program, group, year." << std::endl;
    std::cout << "\tTransfers the student with faculty number <fn> to a new program, group group or year set by <value>." << std::endl;
    std::cout << std::endl;
    
    std::cout << "graduate <fn>:" << std::endl;
    std::cout << "\tMark the student as a graduate." << std::endl;
    std::cout << std::endl;
    
    std::cout << "interrupt <fn>:" << std::endl;
    std::cout << "\tMarks the student with faculty number <fn> as interrupted." << std::endl;
    std::cout << std::endl;
    
    std::cout << "resume <fn>:" << std::endl;
    std::cout << "\tRestores the student rights of the student with faculty number <fn>." << std::endl;
    std::cout << std::endl;
    
    std::cout << "print <fn>:" << std::endl;
    std::cout << "\tDisplays a report for the student with faculty number <fn>." << std::endl;
    std::cout << std::endl;
    
    std::cout << "enrollin <fn> <course>:" << std::endl;
    std::cout << "\tEnrolls the student with faculty number <fn> in the course named <course>." << std::endl;
    std::cout << std::endl;
    
    std::cout << "addgrade <fn> <course> <grade>:" << std::endl;
    std::cout << "\tAdds a <grade> for the <course> to the student with faculty number <fn>." << std::endl;
    std::cout << std::endl;
    
    std::cout << "protocol <course>:" << std::endl;
    std::cout << "\tDisplays protocols for all students enrolled in a <course>." << std::endl;
    std::cout << std::endl;
    
    std::cout << "report <fn>:" << std::endl;
    std::cout << "\tDisplays an academic report of a student's grades (list of all exams, relevant grades and student achievement)." << std::endl;
    std::cout << std::endl;
    
    std::cout << "addprogram <program>:" << std::endl;
    std::cout << "\tRegisters a <program> in susi." << std::endl;
    std::cout << std::endl;
    
    std::cout << "addcourse <course>:" << std::endl;
    std::cout << "\tRegisters a <course> in susi." << std::endl;
    std::cout << std::endl;
    
    std::cout << "addcoursetoprogram <program> <course> <year>:" << std::endl;
    std::cout << "\tAdds <course> for <year> of <program>." << std::endl;
    std::cout << std::endl;
    
    std::cout << "upload <folder>:" << std::endl;
    std::cout << "\tUpdate the information in susi with that in <folder>." << std::endl;
    std::cout << std::endl;
}

void SusiConsoleRemote::_upload() {
    String folder = strtok(NULL, " ");;
    
    querys->upload(folder);
}

void SusiConsoleRemote::run() {
    
    String command;
    
    do {
        std::cout << "> ";
        getline(std::cin, command, 1000);

    } while (execut(command));
    
}



