#ifndef AUTOCOMPLETE_PREDICTIONS_H
#define AUTOCOMPLETE_PREDICTIONS_H

#if defined(_WIN32) || defined(__CYGWIN__) || defined(_WIN64)
    #if defined(BUILD_SHARED)
        #define LIB extern __declspec(dllexport)
    #else
        #define LIB
    #endif
#elif defined(__APPLE__) || defined(__unix__) || defined(__unix) || defined(unix) || defined(__linux__)
    #define LIB extern __attribute__((visibility("default")))
#else
    #error unsupported platform
#endif

#include "tree.h"
#include "vector.h"

typedef Vector Tokens;

enum predict_type {
    FAILURE  = 0,
    EXACTLY  = 1,
    PROBABLY = 2,
};
typedef enum predict_type PredictType;

/**
 * Structure containing vector of predictions
 * and prediction type
 */
struct predictions {
    PredictType type;
    Tokens* tokens;
};
typedef struct predictions Predictions;

/**
 * Function for creating predictions
 * by rules and input string
 *
 * @param rules - Rules from config file
 * @param input - The entered string
 * @param optional_brackets - Characters which optional values begin
 *
 * @return Predictions for current input
 */
LIB Predictions *predictions_create(Tree *rules, char *input, char *optional_brackets);

/**
 * Deallocating prediction struct
 * @param predict - Struct for deallocating
 */
LIB void predictions_free(Predictions* predict);

/**
 * Split string to tokens by delimiter
 *
 * @param str - Input string
 * @param delimiter - Input delimiter character
 *
 * @return Vector of tokens
 */
LIB Tokens* split(char *str, char delimiter);

/**
 * Function for token creation
 *
 * @param str - Input string
 * @param str_len - Length of input string
 *
 * @return Allocated token
 */
LIB char* token_create(char* str, unsigned str_len);

/**
 * Function for deallocating
 * vector of tokens
 *
 * @param tokens - Vector for deallocating
 */
LIB void tokens_free(Tokens* tokens);

/**
 * Function for checking if string
 * contains special characters
 *
 * @param str - Input string
 * @param chars - Special characters
 *
 * @return True if contains or False
 */
LIB int contain_chars(const char* str, const char* chars);

#endif // AUTOCOMPLETE_PREDICTIONS_H