//
//  main.cpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//

#include <iostream>

#include "string.hpp"
//#include "stringCommandInterpreter.hpp"

#include "SusiConsoleRemote.hpp"

void test(SusiDatabaseQuerys& querys) {
    SusiConsoleRemote interpr(querys);
    
    interpr.execut("addprogram Informatics");
    
    interpr.execut("addcourse UP mandatory");
    interpr.execut("addcourse LA mandatory");
    interpr.execut("addcourse AG mandatory");
    interpr.execut("addcourse DIS1 mandatory");

    interpr.execut("addcourse OOP mandatory");
    interpr.execut("addcourse VA mandatory");
    interpr.execut("addcourse DSTR mandatory");
    interpr.execut("addcourse DIS2 mandatory");

    interpr.execut("addcourse OOP-practicum optional");


    interpr.execut("addcoursetoprogram UP Informatics 1");
    interpr.execut("addcoursetoprogram LA Informatics 1");
    interpr.execut("addcoursetoprogram AG Informatics 1");
    interpr.execut("addcoursetoprogram DIS1 Informatics 1");

    interpr.execut("addcoursetoprogram OOP Informatics 2");
    interpr.execut("addcoursetoprogram VA Informatics 2");
    interpr.execut("addcoursetoprogram DSTR Informatics 2");
    interpr.execut("addcoursetoprogram DIS2 Informatics 2");

    interpr.execut("addcoursetoprogram OOP-practicum Informatics 2");


    interpr.execut("enroll 45709 Informatics 6 Martin Petyov Kostov");

    interpr.execut("addgrade 45709 UP 4");
    interpr.execut("addgrade 45709 LA 3");
    interpr.execut("addgrade 45709 AG 4");
    interpr.execut("addgrade 45709 DIS1 4");

    interpr.execut("advance 45709");

    interpr.execut("enrollin 45709 OOP-practicum");
}

void addUsiers(SusiDatabaseQuerys& querys) {
    SusiConsoleRemote interpr(querys);
    
    interpr.execut("enroll 45728 Informatics 1 Thanh Ikraam Leighton");
    interpr.execut("enroll 45729 Informatics 1 Sunny Anat Chioma");
    interpr.execut("enroll 45730 Informatics 2 Alemayehu Li Jiang");
    interpr.execut("enroll 45731 Informatics 2 Dilshad Liron Mtendere");
    interpr.execut("enroll 45732 Informatics 2 Kevyn Akachi Tinashe");
    interpr.execut("enroll 45733 Informatics 2 Nevada Mohana Mayamiko");
    interpr.execut("enroll 45734 Informatics 3 Kyo Amardeep Amour");
    interpr.execut("enroll 45735 Informatics 3 Guiying Seong Kiran");
    interpr.execut("enroll 45736 Informatics 3 Ainsley Shiori Cyan");
    interpr.execut("enroll 45737 Informatics 3 Chandra Khorshid Nicky");
    interpr.execut("enroll 45738 Informatics 3 Cahaya Ayomide Hunter");
    
    interpr.execut("enroll 45739 IS 1 Idowu Willie Surinder");
    interpr.execut("enroll 45740 IS 2 Evren Lhamo Sibonakaliso");
    interpr.execut("enroll 45741 IS 2 Olamide Lian Apurva");
    interpr.execut("enroll 45742 IS 3 Carolina Nikola Anne");
    interpr.execut("enroll 45743 IS 3 Albertina Miriam Antonina");
    
    interpr.execut("enroll 45744 KN 1 Esen Rain Arin");
    interpr.execut("enroll 45745 KN 1 Navneet Collyn Yuval");
    interpr.execut("enroll 45746 KN 1 Ping Eser Lành");
    interpr.execut("enroll 45747 KN 2 Marie Cevahir Citlali");
    interpr.execut("enroll 45749 KN 2 Jothi Tabassum McKenzie");
    interpr.execut("enroll 45750 KN 3 Karma Oluwaseun Teddie");
    interpr.execut("enroll 45751 KN 3 Ash Nur Fungai");
    interpr.execut("enroll 45752 KN 3 Briar Kiran Chinweuba");
    
    
    interpr.execut("enroll 45753 SI 1 Esme Zohar Robbie");
    interpr.execut("enroll 45754 SI 1 Aviyah Akuchi Hennie");
    interpr.execut("enroll 45755 SI 1 Dikla Temple Olufunmilayo");
    interpr.execut("enroll 45756 SI 2 Tshering Ime Kayin");
    interpr.execut("enroll 45757 SI 2 Jae Kanta Zohar");
}

int main() {
    
    SusiDatabase dataBase;
    SusiDatabaseQuerys querys(dataBase);
    
//    addUsiers(querys);
    
    SusiConsoleRemote consoleRemote(querys);
    
    String command;
    
//    do {
//        std::cout << "> ";
//        getline(std::cin, command, 1000);
//
//    } while (consoleRemote.execut(command));
    
    consoleRemote.run();
    
    
    return 0;
}
