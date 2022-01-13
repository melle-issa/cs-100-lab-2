#include "c-echo.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
    EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
    char* test_val[1]; test_val[0] = "./c-echo";
    EXPECT_EQ("", echo(1,test_val));
}

TEST(EchoTest, OneWord) { //first test case checks to make sure space isn't printed after only one word
    char* test_val[2]; test_val[0] = "./c-echo"; test_val[1] = "Hello";
    EXPECT_EQ("Hello", echo(2,test_val));
}

TEST(EchoTest, EmptyMiddleWord) { //second test case checks behavior if a word is missing in middle
    char* test_val[4]; test_val[0] = "./c-echo"; test_val[1] = "Hello"; test_val[2] = ""; test_val[3] = "World";
    EXPECT_EQ("Hello World", echo(4,test_val));
}

TEST(EchoTest, AllSpaces) { //third test case checks behavior if the whole array is spaces
    char* test_val[4]; test_val[0] = "./c-echo"; test_val[1] = " "; test_val[2] = " "; test_val[3] = " ";
    EXPECT_EQ("     ", echo(4,test_val));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
