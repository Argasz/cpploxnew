#ifndef CPPLOX_H
#define CPPLOX_H
#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <vector>
#include <variant>

typedef std::variant<std::string, double, bool, std::monostate, std::nullptr_t> varType;

int runFile(const std::string& path);
int runPrompt();
int run(const std::string& source);
void cpploxError(int line, const std::string& message);
void report(int line, const std::string& where, const std::string& message);

#endif
