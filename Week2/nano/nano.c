/**
 * @file nano.c
 * @author Ekaterina Miller
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "nano.h"

/**
 * @brief Determing in "nano" is in the string
 * 
 * @param w pointer to the string
 * @return true If "nano" is in the string
 * @return false If "nano" is not in the string
 */
enum bool nanoIsInWord(char * w){
    enum States state = Start;
    for (int i = 0; i<strlen(w); i++){

        switch (state)
        {
        case Start:
            state = processStart(w[i]);
            break;
        case StateN:
            state = processStateN(w[i]);
            break;
        case StateNA:
            state = processStateNA(w[i]);
            break;
        case StateNAN:
            state = processStateNAN(w[i]);
            break;
        case StateNANO:
            return True;
            break;

        default:
            break;
        }
    }
    return False; 
}
/**
 * @brief Check if character is 'n'
 * 
 * @param c character
 * @return enum States depands on 'n'
 */
enum States processStart(char c){
    return (c=='n')? StateN : Start;
}
/**
 * @brief Check if character is 'a'
 * 
 * @param c character
 * @return enum States depands on 'n'
 */
enum States processStateN(char c){
    return (c=='a')? StateNA : Start;
}
/**
 * @brief Check if character is 'n'
 * 
 * @param c character
 * @return enum States depands on 'n'
 */
enum States processStateNA(char c){
    return (c=='n')? StateNAN : Start;
}
/**
 * @brief Check if character is 'o'
 * 
 * @param c character
 * @return enum States depands on 'n'
 */
enum States processStateNAN(char c){
    return (c=='o')? StateNANO : Start;
}
