#include <gtest.h>
#include "Stack.h"
#include "Stack.cpp"

TEST(TStack, can_create_stack_with_positive_length) //Создание положительного
{
	ASSERT_NO_THROW(TStack<int> S_INT(5));
	ASSERT_NO_THROW(TStack<char> S_CHAR(5));
}

TEST(TStack, throws_when_create_stack_with_negative_length) //Ошибка при создании отрицательного
{
	ASSERT_ANY_THROW(TStack<int> S_INT(-5));
	ASSERT_ANY_THROW(TStack<char> S_CHAR(-5));
}

TEST(TStack, can_set_elem) //Добавление элемента
{
	TStack<int> S(5);
	ASSERT_NO_THROW(S.Push(1));
}

TEST(TStack, can_get_size) //Получить размер
{
	TStack<int> S(5);
	EXPECT_EQ(S.GetSize(), 5);
}

TEST(TStack, Is_Overflown) //контроль переполнения
{
	TStack<int> S(4);

	S.Push(1);
	S.Push(2);
	S.Push(3);
	S.Push(4);

	ASSERT_NO_THROW();
}

TEST(TStack, IS_Empty) //контроль пустоты
{
	TStack<int> S(4);

	S.Push(1);
	S.Push(2);
	S.Push(3);
	S.Push(4);

	ASSERT_NO_THROW();
}


TEST(TStack, can_clear_bit) //Удалить элемент
{
	TStack<int> S(4);

	S.Push(0);
	S.Push(1);
	S.Push(2);
	S.Push(3);

	ASSERT_NO_THROW(S.Top());
}


TEST(TStack, get_elem) //Получить элемент
{
	TStack<int> S(2);

	S.Push(0);
	S.Push(2);

	EXPECT_EQ(S.Peek(1), 2);
}


TEST(TStack, can_create_copy) //Копирование
{
	TStack<int> S1(5);
	S1.Push(1);
	TStack<int> S2 = S1;

	EXPECT_EQ(S1.Peek(1), S2.Peek(1));
}

TEST(TStack, throws_when_set_stack_with_too_large_index) //Ошибка, при добавлении лишнего элемента
{
	TStack<int> S(2);

	S.Push(1);
	S.Push(2);

	ASSERT_ANY_THROW(S.Push(3));
}

TEST(TStack, can_get_pointer) //Получить указатель
{
	TStack<int> S(2);

	S.Push(1);
	S.Push(2);

	ASSERT_NO_THROW(S.getPtr());
}

TEST(TStack, can_get_num) //Получить номер текущего элемента
{
	TStack<int> S(2);

	S.Push(1);
	S.Push(2);

	EXPECT_EQ(S.getNum(), 2);
}

TEST(TStack, can_get_MIN_elem) //Поиск минимального элемента
{
	TStack<int> S(3);

	S.Push(2);
	S.Push(4);
	S.Push(6);

	EXPECT_EQ(S.min_elem(), 2);
}

TEST(TStack, can_get_MAX_elem) //Поискмаксимального элемента
{
	TStack<int> S(3);

	S.Push(2);
	S.Push(4);
	S.Push(6);

	EXPECT_EQ(S.max_elem(), 6);
}