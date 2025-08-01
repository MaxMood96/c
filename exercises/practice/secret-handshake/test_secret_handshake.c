#include "secret_handshake.h"
#include "test-framework/unity.h"
#include <stdlib.h>

#define ARRAY_SIZE 4

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_commands_wink_for_1(void)
{
   const char *expected[] = { "wink", NULL, NULL, NULL };
   const char **actual = commands(1);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, ARRAY_SIZE);
   free(actual);
}

static void test_commands_double_blink_for_10(void)
{
   TEST_IGNORE();   // delete this line to run test
   const char *expected[] = { "double blink", NULL, NULL, NULL };
   const char **actual = commands(2);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, ARRAY_SIZE);
   free(actual);
}

static void test_commands_close_your_eyes_for_100(void)
{
   TEST_IGNORE();
   const char *expected[] = { "close your eyes", NULL, NULL, NULL };
   const char **actual = commands(4);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, ARRAY_SIZE);
   free(actual);
}

static void test_commands_jump_for_1000(void)
{
   TEST_IGNORE();
   const char *expected[] = { "jump", NULL, NULL, NULL };
   const char **actual = commands(8);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, ARRAY_SIZE);
   free(actual);
}

static void test_commands_combine_two_actions(void)
{
   TEST_IGNORE();
   const char *expected[] = { "wink", "double blink", NULL, NULL };
   const char **actual = commands(3);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, ARRAY_SIZE);
   free(actual);
}

static void test_commands_reverse_two_actions(void)
{
   TEST_IGNORE();
   const char *expected[] = { "double blink", "wink", NULL, NULL };
   const char **actual = commands(19);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, ARRAY_SIZE);
   free(actual);
}

static void test_commands_reversing_one_action_gives_the_same_action(void)
{
   TEST_IGNORE();
   const char *expected[] = { "jump", NULL, NULL, NULL };
   const char **actual = commands(24);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, ARRAY_SIZE);
   free(actual);
}

static void test_commands_reversing_no_actions_still_gives_no_actions(void)
{
   TEST_IGNORE();
   const char *expected[] = { NULL, NULL, NULL, NULL };
   const char **actual = commands(16);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, ARRAY_SIZE);
   free(actual);
}

static void test_commands_all_possible_actions(void)
{
   TEST_IGNORE();
   const char *expected[] = { "wink", "double blink", "close your eyes",
                              "jump" };
   const char **actual = commands(15);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, ARRAY_SIZE);
   free(actual);
}

static void test_commands_reverse_all_possible_actions(void)
{
   TEST_IGNORE();
   const char *expected[] = { "jump", "close your eyes", "double blink",
                              "wink" };
   const char **actual = commands(31);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, ARRAY_SIZE);
   free(actual);
}

static void test_commands_do_nothing_for_zero(void)
{
   TEST_IGNORE();
   const char *expected[] = { NULL, NULL, NULL, NULL };
   const char **actual = commands(0);
   TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, ARRAY_SIZE);
   free(actual);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_commands_wink_for_1);
   RUN_TEST(test_commands_double_blink_for_10);
   RUN_TEST(test_commands_close_your_eyes_for_100);
   RUN_TEST(test_commands_jump_for_1000);
   RUN_TEST(test_commands_combine_two_actions);
   RUN_TEST(test_commands_reverse_two_actions);
   RUN_TEST(test_commands_reversing_one_action_gives_the_same_action);
   RUN_TEST(test_commands_reversing_no_actions_still_gives_no_actions);
   RUN_TEST(test_commands_all_possible_actions);
   RUN_TEST(test_commands_reverse_all_possible_actions);
   RUN_TEST(test_commands_do_nothing_for_zero);

   return UNITY_END();
}
