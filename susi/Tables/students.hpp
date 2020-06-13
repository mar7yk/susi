//
//  students.hpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#ifndef students_hpp
#define students_hpp

#include <stdio.h>

#include "string.hpp"
#include "vector.h"

#include "Table.h"

#include "programs.hpp"
#include "student.h"

class Students : public Table {
    struct StudentData {
        unsigned fn;
        String name;
        short unsigned year;
        size_t programID;
        short unsigned gruop;
        short unsigned status;
        double average;
    };
    
    Vector<StudentData> students;
    
    Programs& programs_;
    
    
    void load(const String& file) override;
    
    Student get(const StudentData& data) const;
    
public:
    Students(Programs& programs);
    
    void save() const override;
    
    void add(const unsigned fn, const String &name,
             const size_t programID, const unsigned short gruop);
    
    Student getByFN(const unsigned fn) const;
    
    Vector<Student> getByProgramIDAndYear(const size_t programID, const short unsigned gruop) const;
    
    void update_year(const unsigned fn, const short unsigned year);
    void update_group(const unsigned fn, const short unsigned gruop);
    void update_program(const unsigned fn, const size_t programID);
    void update_status(const unsigned fn, const short unsigned status);
    void update_average(const unsigned fn, const double average);
};

#endif /* students_hpp */
