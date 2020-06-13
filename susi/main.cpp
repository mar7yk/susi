//
//  main.cpp
//  susi
//
//  Created by Marty Kostov on 22.04.20.
//  Copyright © 2020 Marty Kostov. All rights reserved.
//


#include "SusiDatabase.h"
#include "SusiDatabaseQuerys.hpp"
#include "SusiConsoleRemote.hpp"


int main() {
    
    SusiDatabase dataBase;
    SusiDatabaseQuerys querys(dataBase);
    SusiConsoleRemote consoleRemote(querys);
    
    consoleRemote.run();
    
    
    return 0;
}
