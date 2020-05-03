//
//  main.cpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#include <iostream>

#include "string.hpp"
#include "stringCommandInterpreter.hpp"

int main() {
    
    StrCommandInterpr interpr;
    
//    interpr.execut("add program Informatics");
//
//    interpr.execut("add course UP compulsory");
//    interpr.execut("add course LA compulsory");
//    interpr.execut("add course AG compulsory");
//    interpr.execut("add course DIS1 compulsory");
//
//    interpr.execut("add course OOP compulsory");
//    interpr.execut("add course VA compulsory");
//    interpr.execut("add course DSTR compulsory");
//    interpr.execut("add course DIS2 compulsory");
//
//    interpr.execut("add course OOP-practicum optional");
//
//
//    interpr.execut("add courseToProgram UP Informatics 1");
//    interpr.execut("add courseToProgram LA Informatics 1");
//    interpr.execut("add courseToProgram AG Informatics 1");
//    interpr.execut("add courseToProgram DIS1 Informatics 1");
//
//    interpr.execut("add courseToProgram OOP Informatics 2");
//    interpr.execut("add courseToProgram VA Informatics 2");
//    interpr.execut("add courseToProgram DSTR Informatics 2");
//    interpr.execut("add courseToProgram DIS2 Informatics 2");
//
//    interpr.execut("add courseToProgram OOP-practicum Informatics 2");
//
//
//    interpr.execut("enroll 45709 Informatics 6 Martin Petyov Kostov");
//
//    interpr.execut("add grade 45709 UP 4");
//    interpr.execut("add grade 45709 LA 3");
//    interpr.execut("add grade 45709 AG 4");
//    interpr.execut("add grade 45709 DIS1 4");
//
//    interpr.execut("advance 45709");
//
//    interpr.execut("enrollin 45709 OOP-practicum");
    
    String command;

    do {
        std::cout << "> ";
        getline(std::cin, command, 1000);

    } while (interpr.execut(command));
    
    return 0;
}
