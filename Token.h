#ifndef TOKEN_H
#define TOKEN_H
#include "TokenType.h"
#include <string>
#include "cpplox.h"
class Token
{
 private:
  TokenType type;
  std::string lexeme;
  varType literal;
  int line;
 public:
  Token(TokenType type, std::string& lexeme, varType literal, int line)
      : type(type), lexeme(lexeme), literal(literal), line(line){};
  friend std::ostream& operator << (std::ostream& stream, const Token& token);
};

std::ostream& operator << (std::ostream& stream, const Token& token);
#endif
