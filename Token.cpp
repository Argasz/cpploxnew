#include "Token.h"

using namespace std;

const std::string tokenTypeToString(TokenType t)
{
	switch (t)
	{
	case TokenType::AND: return "AND";
	case TokenType::BANG: return "BANG";
	case TokenType::BANG_EQUAL: return "BANG";
	case TokenType::CLASS: return "CLASS";
	case TokenType::COMMA: return "COMMA";
	case TokenType::DOT: return "DOT";
	case TokenType::ELSE: return "ELSE";
	case TokenType::EOFF: return "EOFF";
	case TokenType::EQUAL: return "EQUAL";
	case TokenType::EQUAL_EQUAL: return "EQUAL_EQUAL";
	case TokenType::FALSE: return "FALSE";
	case TokenType::FOR: return "FOR";
	case TokenType::FUN: return "FUN";
	case TokenType::GREATER: return "GREATER";
	case TokenType::GREATER_EQUAL: return "GREATER_EQUAL";
	case TokenType::IDENTIFIER: return "IDENTIFIER";
	case TokenType::IF: return "IF";
	case TokenType::LEFT_BRACE: return "LEFT_BRACE";
	case TokenType::LEFT_PAREN: return "LEFT_PAREN";
	case TokenType::LESS: return "LESS";
	case TokenType::LESS_EQUAL: return "LESS_EQUAL";
	case TokenType::MINUS: return "MINUS";
	case TokenType::NIL: return "NIL";
	case TokenType::NUMBER: return "NUMBER";
	case TokenType::OR: return "OR";
	case TokenType::PLUS: return "PLUS";
	case TokenType::PRINT: return "PRINT";
	case TokenType::RETURN: return "RETURN";
	case TokenType::RIGHT_BRACE: return "RIGHT_BRACE";
	case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
	case TokenType::SEMICOLON: return "SEMICOLON";
	case TokenType::SLASH: return "SLASH";
	case TokenType::STAR: return "STAR";
	case TokenType::STRING: return "STRING";
	case TokenType::SUPER: return "SUPER";
	case TokenType::THIS: return "THIS";
	case TokenType::TRUE: return "TRUE";
	case TokenType::VAR: return "VAR";
	case TokenType::WHILE: return "WHILE";
	default: return "UNKNOWN";
	}
}

ostream& operator << (ostream& stream, const Token& token)
{
  stream << tokenTypeToString(token.type);

  stream << " " << token.lexeme;

  if(holds_alternative<string>(token.literal))
  {
    stream << " " << get<string>(token.literal);
  }
  else if(holds_alternative<double>(token.literal))
  {
    stream << " " << get<double>(token.literal);
  }
  else if(holds_alternative<bool>(token.literal))
  {
    stream << " " << get<bool>(token.literal);
  }
  else
  {
    stream << " nil ";
  }

  return stream;
}
