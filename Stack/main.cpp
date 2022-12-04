#include <iostream>
#include "Stack.h"
using namespace std;

int main()
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
  return 0;
}