/**
 * @file nano.h
 * @author Ekaterina Miller
 * @date 2023-09-01
 */
#ifndef NANO_H
#define NANO_H
#include <string.h>
enum States {Start,StateN, StateNA, StateNAN, StateNANO};
enum bool {False, True};

enum bool nanoIsInWord(char * w);
enum States processStart(char c);
enum States processStateN(char c);
enum States processStateNA(char c);
enum States processStateNAN(char c);
#endif