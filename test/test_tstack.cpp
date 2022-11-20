#include "TStack.h"
#include <gtest.h>

using testing::Types;

template <class T>
class TStackTest : public testing::Test {};
typedef Types<int, double> Implementations;

TYPED_TEST_CASE(TStackTest, Implementations);

TYPED_TEST(TStackTest, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<TypeParam> st(3));
}

TYPED_TEST(TStackTest, can_add_item_into_stack)
{
  TStack<TypeParam> st(3);
  ASSERT_NO_THROW(st.Push(0));
}

TYPED_TEST(TStackTest, can_pop_item_from_stack)
{
  TStack<TypeParam> st(3);
  st.Push(0);
  ASSERT_NO_THROW(st.Pop());
}

TYPED_TEST(TStackTest, pop_item_from_stack_returns_correct)
{
  TStack<TypeParam> st(3);
  st.Push(0);
  EXPECT_EQ(st.Pop(), 0);
}

TYPED_TEST(TStackTest, can_check_stack_emptiness)
{
  TStack<TypeParam> st(3);
  EXPECT_EQ(st.IsEmpty(), true);
}

TYPED_TEST(TStackTest, can_check_stack_fullness)
{
  TStack<TypeParam> st(1);
  st.Push(0);
  EXPECT_EQ(st.IsFull(), true);
}

TYPED_TEST(TStackTest, cannot_add_item_into_full_stack)
{
  TStack<TypeParam> st(1);
  st.Push(0);
  ASSERT_ANY_THROW(st.Push(0));
}

TYPED_TEST(TStackTest, cannot_pop_item_from_empty_stack)
{
  TStack<TypeParam> st(3);
  st.Push(0);
  st.Pop();
  ASSERT_ANY_THROW(st.Pop());
}