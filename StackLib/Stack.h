#pragma once

template <class T>
class TStack
{
protected:
  T* arr;
  size_t size;
  size_t start;
public:
  TStack(size_t sz);
  TStack(const TStack<T>& st);
  TStack(TStack<T>&& st);
  ~TStack();

  size_t GetSize();
  size_t GetStart();
  bool IsFull();
  bool IsEmpty();
  
  void Push(T elem);
  T Top();
  void Pop();
  T& Peek(int _elem);
  TStack<T> operator=(const TStack<T>& st);
  TStack<T> operator=(TStack<T>&& st);
};

template<class T>
inline TStack<T>::TStack(size_t sz = 1)
{
  if (sz == 0)
    throw "size must be grather than zero";
  size = sz;
  start = 0;
  arr = new T[size];
  for (size_t i = 0; i < size; i++)
    arr[i] = {};
}

template<class T>
inline TStack<T>::TStack(const TStack<T>& st)
{
  if (st.arr == nullptr)
    throw "nothing to copy";
  size = st.size;
  start = st.start;
  arr = new T[size];
  for (size_t i = 0; i < size; i++)
    arr[i] = st.arr[i];
}

template<class T>
inline TStack<T>::TStack(TStack<T>&& st)
{
  size = st.size;
  start = st.start;
  arr = st.arr;

  st.size = 0;
  st.start = 0;
  st.arr = nullptr;
}

template<class T>
inline TStack<T>::~TStack()
{
  if (arr != nullptr)
  {
    delete[] arr;
    arr = nullptr;
    start = 0;
    size = 0;
  }
}

template<class T>
inline size_t TStack<T>::GetSize()
{
  return size;
}

template<class T>
inline size_t TStack<T>::GetStart()
{
  return start;
}

template<class T>
inline bool TStack<T>::IsFull()
{
  return (size == start);
}

template<class T>
inline bool TStack<T>::IsEmpty()
{
  return (start == 0);
}

template<class T>
inline void TStack<T>::Push(T elem)
{
  if (!IsFull())
  {
    arr[start] = elem;
    start++;
  }
  else
  {
    TStack<T> newStack(size * 2);
    for (size_t i = 0; i < start; i++)
      newStack.arr[i] = arr[i];
    newStack.arr[start] = elem;
    newStack.start = start + 1;
    *this = newStack;
  }
}

template<class T>
inline T TStack<T>::Top()
{
  if (!IsEmpty())
  {
    T res = arr[start - 1];
    return res;
  }
  else
    throw "Stack is empty";
}

template<class T>
inline void TStack<T>::Pop()
{
  if (!IsEmpty())
  {
    arr[start - 1] = 0;
    start--;
  }
  else
    throw "Stack is empty";
}

template<class T>
inline T& TStack<T>::Peek(int _elem)
{
  if (_elem < 0)
  {
    throw ("ERROR");
  }
  return arr[_elem];
}

template<class T>
inline TStack<T> TStack<T>::operator=(const TStack<T>& st)
{
  if (st.arr == nullptr)
    throw "nothing to copy";
  size = st.size;
  start = st.start;
  delete[] arr;
  arr = new T[size];
  for (size_t i = 0; i < size; i++)
    arr[i] = st.arr[i];

  return *this;
}

template<class T>
inline TStack<T> TStack<T>::operator=(TStack<T>&& st)
{
  size = st.size;
  start = st.start;
  arr = st.arr;

  st.size = 0;
  st.start = 0;
  st.arr = nullptr;

  return *this;
}