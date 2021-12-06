/*
 *  main.h
 *  
 *  It is the common header file for rest of the CPP files in the project
 *  
 *  Created on: 1-Oct-2021
 *     Authors: Aryan Mukerji
 */

#include <iostream>
#include <cstring>

#include "Person.h"
#include "Block.h"

using namespace std;
#define N 100

#ifndef MAIN_H
#define MAIN_H

// In main.cpp
void Title();
void PressEnter();
void ClearOS();

// In Keys.cpp
int keys(User &u);

// In SHA.cpp
string Object_to_SHA(Block a);
string String_to_SHA(string a);

#endif /* MAIN_H */
