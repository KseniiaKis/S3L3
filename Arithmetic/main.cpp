#include <iostream>
#include "Stack.h"
#include "Map.h"
#include <string.h>
#include "Str.h"
#include <ctype.h>
#include "Arithmetic.h"

using namespace std;

void testStack()
{
  TStack<int> stop(2);
  stop.Push(3);
  stop.Push(4);
  cout << "size1=" << stop.GetSize() << endl;
  stop.Push(5);
  cout << "size2=" << stop.GetSize() << endl;
  cout << "start2=" << stop.GetStart() << endl;
  cout << "elem = " << stop.Top() << endl;
  cout << "start3=" << stop.GetStart() << endl;
  cout << "elem1 = " << stop.Top() << endl;
  cout << "start4=" << stop.GetStart() << endl;
  stop.Pop();
  cout << "start5=" << stop.GetStart() << endl;
  cout << "elem2 = " << stop.Top() << endl;
}

void testMap()
{
  int key[4] = { 1,2,3,4 };
  bool val[4] = { 1,0,0,1 };

  int key2[4] = { 5,6,7,8 };
  bool val2[4] = { 0,1,1,1 };

  size_t size = 4;
  TMap<int, bool> map(size, key, val);
  TMap<int, bool> map1(map);
  TMap<int, bool> map2(size, key2, val2);

  map1 = map2;
  cout << map1;
  cout << map2[12];
}

void testString()
{
  char b = '2';
  cout << double(int(b) - 48);
}

//void testMap2()
//{
//  TMap<int, double> map(1);
//  map.Insert(1, 1.2);
//  map.Insert(2, 2.4);
//  map.Insert(2, 5);
//  //map[3] = 10;
//  //cin >> map;
//  cout << map;
//}

void testChar()
{
  int len = 1;
  TString infix(len, 'c');
  cin >> infix;

  char opers[4] = { '+', '-', '*', '/' };
  int priors[4] = { 1, 1, 2, 2 };
  TMap<char, int> pri(4, opers, priors);

  TMap<char, char> lex(1);
  for (size_t i = 0; i < infix.GetLen(); i++)
  {
    char l = infix[i];
    if (isdigit(l) != 0)
      lex.Insert(l, 'c', 0);
    else if (isalpha(l) != 0)
      lex.Insert(l, 'v', 0);
    else if (pri.IsInsertKey(l) || l == '(' || l == ')')
      lex.Insert(l, 'o', 0);
    else
      throw invalid_argument("Expression has invalid arguments");
  }
  cout << lex;
}

void testSetOpers()
{
  char symvols[3] = { 'a','b','2' };
  char lex[3] = { 'v','v','c' };
  double valu[3] = { 0.0,0.0,2 };

  TMap<char, char> lexems(3, symvols, lex);
  TMap<char, double> operands(3, symvols, valu);

  for (size_t i = 0; i < operands.Count(); i++)
    if (lexems[operands.GetKey(i)] == 'v')
    {
      cout << "Value of key " << operands.GetKey(i) << ":";
      cin >> operands[operands.GetKey(i)];
    }
  cout << operands;
}

void testArithmetic()
{
  TString exp("(a+2)*(c-d/e)");
  TArithmeticExpression expr(exp);
  cout << expr.GetInfix() << endl;
  cout << expr.GetPostfix() << endl;
  cout << expr.GetOperands() << endl;
  expr.SetOperands();
  cout << expr.GetOperands() << endl;
  cout << expr.Calculate() << endl;
}

int main()
{
  try
  {
    //testSetOpers();
    //testChar();
    //testMap2();
    //testMap();
    //testStack();
    //testString();
    testArithmetic();
  }
  catch (exception& ex)
  {
    cout << ex.what();
  }

  return 0;
}