//
//  SusiDatabaseQuerys.cpp
//  susi
//
//  Created by Marty Kostov on 5.06.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#include "SusiDatabaseQuerys.hpp"


SusiDatabaseQuerys::SusiDatabaseQuerys(SusiDatabase &susiDataBase)
    : dataBase(&susiDataBase) {
    
}

void SusiDatabaseQuerys::save() const {
    dataBase->save();
}


void SusiDatabaseQuerys::upload(const String &folder) {
    dataBase->upload(folder);
}

void SusiDatabaseQuerys::enroll(const unsigned int fn, const String &name,
                                const String &program, const unsigned short gruop) const {
    
    Student student = dataBase->students.getByFN(fn);
    
    if (student.fn != 0) {
        throw std::runtime_error("There is already student whit that fn!");
    }
    
    size_t programID = dataBase->programs.getIDByName(program);
    
    if (programID == 0) {
        throw std::runtime_error("There isn't program whit that name!");
    }
    
    dataBase->students.add(fn, name, programID, gruop);
    
    student = dataBase->students.getByFN(fn);
    
    Vector<Course> mandatoryCourses = dataBase->coursesInPrograms.getMandatoryForYear(programID, student.year);
    
    for (size_t i = 0; i < mandatoryCourses.size(); ++i) {
        dataBase->enrolleesInCourses.add(fn, mandatoryCourses[i].ID);
    }
}

void SusiDatabaseQuerys::advance(const unsigned int fn) {
    Student student = dataBase->students.getByFN(fn);
    
    
    
    if (student.fn == 0) {
        throw std::runtime_error("There isn't student whit that fn!");
    }
    
    size_t programID = dataBase->programs.getIDByName(student.program);
    
    Vector<Course> mandatoryCourses = dataBase->coursesInPrograms.getMandatoryForYear(programID, student.year + 1);
    
    for (size_t i = 0; i < mandatoryCourses.size(); ++i) {
        dataBase->enrolleesInCourses.add(fn, mandatoryCourses[i].ID);
    }
    
    dataBase->students.update_year(fn, student.year + 1);
}

void SusiDatabaseQuerys::change(const unsigned int fn, const String &option, const String &value) {
    
    Student student = dataBase->students.getByFN(fn);
    
    if (student.fn == 0) {
        throw std::runtime_error("There isn't student whit that fn.");
    }
    
    if (student.status == 2) {
        throw std::runtime_error("The student is interrupted!");
    }
    
    if (option == "program") {
        size_t programID = dataBase->programs.getIDByName(value);
        
        if (programID == 0) {
            throw std::runtime_error("There isn't program whit that name!");
        }
        
        Vector<Course> mandatoryCourses = dataBase->coursesInPrograms.getMandatoryToYear(programID, student.year);
        
        Vector<CourseReport> report = dataBase->enrolleesInCourses.get_report_by_fn(fn);
        
        for (size_t i = 0; i < mandatoryCourses.size(); ++i) {
            bool isCoursesPassed = false;
            for (size_t j = 0; j < report.size(); ++j) {
                if (mandatoryCourses[i].name == report[j].courseName) {
                    if (report[j].grade > 3) {
                        isCoursesPassed = true;
                    } else {
                        isCoursesPassed = false;
                    }
                    if (!isCoursesPassed) {
                        throw std::runtime_error("The student isn't passted all mandatory courses for that program!");
                    }
                }
            }
        }
        
        dataBase->students.update_program(fn, programID);
        
    } else if (option == "group") {
        unsigned short gruop = stoi(value);
        
        dataBase->students.update_group(fn, gruop);
        
    } else if (option == "year") {
        unsigned short year = stoi(value);
        
        Vector<CourseReport> report = dataBase->enrolleesInCourses.get_report_by_fn(fn);
        
        const int MAX_NOTTAKEN = 2;
        int countOfNottaken = 0;
        
        if (student.year + 1 != year) {
            throw std::runtime_error("Transfer to a course other than the next is not possible!");
        }
        
        for (size_t i = 0; i < report.size(); ++i) {
            if (report[i].grade < 3) {
                ++countOfNottaken;
                if (countOfNottaken > MAX_NOTTAKEN) {
                    throw std::runtime_error("The student has not taken enough exams!");
                }
            }
        }
        
        advance(fn);
    }
}

void SusiDatabaseQuerys::graduate(const unsigned int fn) {
    Student student = dataBase->students.getByFN(fn);
    
    if (student.fn == 0) {
        throw std::runtime_error("There isn't student whit that fn.");
    }
    
    size_t programID = dataBase->programs.getIDByName(student.program);
    
    Vector<Course> mandatoryCourses = dataBase->coursesInPrograms.getMandatoryForAllYear(programID);
    
    Vector<CourseReport> report = dataBase->enrolleesInCourses.get_report_by_fn(fn);
    
    for (size_t i = 0; i < mandatoryCourses.size(); ++i) {
        bool isCoursesPassed = false;
        for (size_t j = 0; j < report.size(); ++j) {
            if (mandatoryCourses[i].name == report[j].courseName) {
                if (report[j].grade > 3) {
                    isCoursesPassed = true;
                } else {
                    isCoursesPassed = false;
                }
                if (!isCoursesPassed) {
                    throw std::runtime_error("The student isn't passted all mandatory courses for that program!");
                }
            }
        }
    }
    
    dataBase->students.update_status(fn, 3);
}

void SusiDatabaseQuerys::interrupt(const unsigned int fn) {
    Student student = dataBase->students.getByFN(fn);
    
    if (student.fn == 0) {
        throw std::runtime_error("There isn't student whit that fn!");
    }
    
    if (student.status == 3) {
        throw std::runtime_error("The student is graduated!");
    }
    
    if (student.status == 2) {
        throw std::runtime_error("The student is interrupted!");
    }
    
    dataBase->students.update_status(fn, 2);
}

void SusiDatabaseQuerys::resume(const unsigned int fn) {
    Student student = dataBase->students.getByFN(fn);
    
    if (student.fn == 0) {
        throw std::runtime_error("There isn't student whit that fn!");
    }
    
    if (student.status == 3) {
        throw std::runtime_error("The student is graduated!");
    }
    
    if (student.status == 1) {
        throw std::runtime_error("The student isn't interrupted!");
    }
    
    dataBase->students.update_status(fn, 1);
}

Student SusiDatabaseQuerys::print(const unsigned int fn) const {
    Student student = dataBase->students.getByFN(fn);
    
    if (student.fn == 0) {
        throw std::runtime_error("There isn't student whit that fn!");
    }
    
    return student;
}

Vector<Student> SusiDatabaseQuerys::printall(const String &program, const unsigned short gruop) const { 
    size_t programID = dataBase->programs.getIDByName(program);
    
    if (programID == 0) {
        throw std::runtime_error("There isn't program whit that name!");
    }
    
    Vector<Student> result = dataBase->students.getByProgramIDAndYear(programID, gruop);
    
    return result;
}

void SusiDatabaseQuerys::enrollin(const unsigned int fn, const String &courseName) {
    Student student = dataBase->students.getByFN(fn);
    
    if (student.fn == 0) {
        throw std::runtime_error("There isn't student whit that fn!");
    }
    
    if (student.status == 2) {
        throw std::runtime_error("The student is interrupted!");
    }
    
    Course course = dataBase->courses.getByName(courseName);
    
    if (course.ID == 0) {
        throw std::runtime_error("There isn't course whit that name!");
    }
    
    size_t programID = dataBase->programs.getIDByName(student.program);
    
    Vector<Course> optionalCourses = dataBase->coursesInPrograms.getOptional(programID);

    bool isOptional = false;
    
    for (size_t i = 0; i < optionalCourses.size(); ++i) {
        if (optionalCourses[i].ID == course.ID) {
            isOptional = true;
            break;
        }
    }
    
    if (!isOptional) {
        throw std::runtime_error("That course is not optional for program of the student");
    }
    
     Vector<CourseReport> report = dataBase->enrolleesInCourses.get_report_by_fn(fn);
    
    for (size_t i = 0; i < report.size(); ++i) {
        if (report[i].courseName == course.name) {
            throw std::runtime_error("The student is already enroll in that course");
        }
    }
    
    dataBase->enrolleesInCourses.add(fn, course.ID);
}

void SusiDatabaseQuerys::addgrade(const unsigned short fn, const String &courseName, const double grade) { 
    Student student = dataBase->students.getByFN(fn);
    
    if (student.fn == 0) {
        throw std::runtime_error("There isn't student whit that fn!");
    }
    
    if (student.status == 2) {
        throw std::runtime_error("The student is interrupted!");
    }
    
    Course course = dataBase->courses.getByName(courseName);
    
    if (course.ID == 0) {
        throw std::runtime_error("There isn't course whit that name!");
    }
    
    Vector<CourseReport> report = dataBase->enrolleesInCourses.get_report_by_fn(fn);
    
    double average = 0;
    
    bool isEnroll = false;
    for (size_t i = 0; i < report.size(); ++i) {
        if (report[i].courseName == course.name) {
            isEnroll = true;
        } else {
            double grade = report[i].grade;
            if (grade == 0) {
                grade = 2;
            }
            average += grade;
        }
    }
    
    if (!isEnroll) {
        throw std::runtime_error("The student isn't enroll in this course");
    }
    
    average += grade;
    
    average /= report.size();
    
    dataBase->students.update_average(fn, average);
    
    dataBase->enrolleesInCourses.update_grade(fn, course.ID, grade);
    
}

Vector<StudentProtocol> SusiDatabaseQuerys::protocol(const String &courseName) const {
    
    Course course = dataBase->courses.getByName(courseName);
    
    if (course.ID == 0) {
        throw std::runtime_error("There isn't course whit that name!");
    }
    
    Vector<StudentProtocol> protocol = dataBase->enrolleesInCourses.get_protocol(course.ID);
    
    return protocol;
}

Vector<CourseReport> SusiDatabaseQuerys::report(const unsigned short fn) const { 
    Student student = dataBase->students.getByFN(fn);
    
    if (student.fn == 0) {
        throw std::runtime_error("There isn't student whit that fn!");
    }
    
    Vector<CourseReport> report = dataBase->enrolleesInCourses.get_report_by_fn(fn);
    
    return report;
}

double SusiDatabaseQuerys::getAverage(const unsigned short fn) const { 
    Student student = dataBase->students.getByFN(fn);
    
    return student.average;
}

void SusiDatabaseQuerys::addprogram(const String &program) {
    size_t programID = dataBase->programs.getIDByName(program);
    
    if (programID != 0) {
        throw std::runtime_error("There is already program whit that name!");
    }
    
    dataBase->programs.add(program);
}

void SusiDatabaseQuerys::addcourse(const String &courseName, const bool optional) {
    Course course = dataBase->courses.getByName(courseName);
    
    if (course.ID != 0) {
        throw std::runtime_error("There is already course whit that name!");
    }
    
    dataBase->courses.add(courseName, optional);
}

void SusiDatabaseQuerys::addcoursetoprogram(const String &program, const String &courseName, const short unsigned year) { 
    size_t programID = dataBase->programs.getIDByName(program);
    
    if (programID == 0) {
        throw std::runtime_error("There isn't program whit that name!");
    }
    
    Course course = dataBase->courses.getByName(courseName);
    
    if (course.ID == 0) {
        throw std::runtime_error("There isn't course whit that name!");
    }
    
    bool isAdded = dataBase->coursesInPrograms.isAdded(course.ID, programID);
    
    if(isAdded) {
        throw std::runtime_error("That course is already in that prognram!");
    }
    
    dataBase->coursesInPrograms.add(course.ID, programID, year);
}
