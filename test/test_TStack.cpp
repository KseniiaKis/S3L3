#include <../gtest/gtest.h>
#include "Stack.h"
#include "Stack.cpp"

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> s(5));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(TStack<int> s(0));
}

TEST(TStack, can_create_copied_stack)
{
  TStack<int> s(5);

  ASSERT_NO_THROW(TStack<int> s1(s));
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
  TStack<int> s(5);
  TStack<int> s1(s);
  EXPECT_EQ(s, s1);
}

TEST(TStack, can_get_size)
{
  TStack<int> s(5);
  size_t l = 5;
  EXPECT_EQ(l, s.GetSize());
}

TEST(TStack, can_get_start)
{
  TStack<int> s(5);
  size_t st = 0;
  EXPECT_EQ(st, s.GetStart());
}

TEST(TStack, can_set_and_get_element)
{
  TStack<int> s(2);
  s.Push(1);

  EXPECT_EQ(1, s.Top());
}

TEST(TStack, assign_operator_change_stack_size)
{
  TStack<int> s(1);
  TStack<int> s1(4);
  s = s1;
  size_t l = 4;
  EXPECT_EQ(l, s.GetSize());
}

TEST(TStack, is_created_stack_full)
{
  TStack<int> s(1);
  EXPECT_EQ(false, s.IsFull());
}

TEST(TStack, is_created_stack_empty)
{
  TStack<int> s(1);
  EXPECT_EQ(true, s.IsEmpty());
}

TEST(TStack, top_dont_delete_element)
{
  TStack<int> s(2);
  s.Push(1);
  int a = s.Top();

  EXPECT_EQ(1, s.Top());
}

TEST(TStack, pop_delete_element)
{
  TStack<int> s(2);
  s.Push(1);
  s.Pop();
  size_t st = 0;
  EXPECT_EQ(st, s.GetStart());
}

TEST(TStack, pop_throw_when_empty)
{
  TStack<int> s(2);
  ASSERT_ANY_THROW(s.Pop());
}

TEST(TStack, top_throw_when_empty)
{
  TStack<int> s(2);
  ASSERT_ANY_THROW(s.Top());
}

TEST(TStack, push_change_size)
{
  TStack<int> s(1);
  s.Push(1);
  s.Push(2);
  size_t l = 2;
  EXPECT_EQ(l, s.GetSize());
}