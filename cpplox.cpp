#include "cpplox.h"

using namespace std;

bool hadError = false;

int main(int argc, char** argv){
  if(argc > 2)
  {
    cout << "Usage: cpplox [script]";
    return 64;
  }
  else if(argc == 2)
  {
    return runFile(argv[1]);
  }
  else
  {
    return runPrompt();
  }
}

int runFile(const string& path)
{
  ifstream inFile;
  inFile.open(path);

  string content{istreambuf_iterator<char>(inFile), istreambuf_iterator<char>()};

  run(content);

  if(hadError) return 65;

  return 0;
}

int runPrompt()
{
  while(true)
  {
    cout << "\n> ";
    string input;
    getline(cin, input);
    run(input);
    hadError = false;
  }
}

int run(const string& source)
{
  Scanner scanner{};
  vector<unique_ptr<Token>> tokens = scanner.scanTokens();

  for(auto token : tokens)
  {
    cout << token;
  }
}

void error(int line, const string& message)
{
  report(line, "", message);
}

void report(int line, const string& where, const string& message)
{
  cout << "[line " << line << " ] Error" << where << ": " << message;
  hadError = true;
}
