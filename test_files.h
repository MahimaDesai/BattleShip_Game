#ifndef TEST_FILES_H_
#define TEST_FILES_H_

#include "ConsoleView.h"
#include "Shot.h"

/**
 *  @brief : Method to implement assert statement
 *
 *  @return :   void
 *
 *  @param[in] condition	: Test condition
 *  @param[in] failedMessage	: Failed test message
 *
 **/
void assertTrue(bool condition, std::string failedMessage);

/**
 *  @brief :	To check part 1 test cases
 *
 *  @return :   void
 *
 *
 **/
void part1tests();

/**
 *  @brief :	To check part 2 test cases
 *
 *  @return :   void
 *
 *
 **/
void part2tests();

/**
 *  @brief :	To check part 3 test cases
 *
 *  @return :   void
 *
 *
 **/
void part3tests();

#endif /* TEST_FILES_H_ */
