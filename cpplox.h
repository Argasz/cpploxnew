#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <vector>
#ifndef CPPLOX_H
#define CPPLOX_H

int runFile(const std::string& path);
int runPrompt();
int run(const std::string& source);
void cpploxError(int line, const std::string& message);
void report(int line, const std::string& where, const std::string& message);

#endif
