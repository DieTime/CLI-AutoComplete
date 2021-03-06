#ifndef AUTOCOMPLETE_NODE_H
#define AUTOCOMPLETE_NODE_H

#include "vector.h"

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

/**
 * Node of rules tree
 *
 * Contains self token and
 * vector of children nodes
 */
struct node {
    char* token;
    struct vector* children;
};
typedef struct node Node;


/**
 * Create node by token and token_length
 *
 * @param token - Node containing string
 * @param token_length - Length of string
 *
 * @return Created Node
 */
LIB Node* node_create(char* token, unsigned token_length);


/**
 * Function for free Node
 * and all his children
 *
 * @param node - Node for deallocating
 */
LIB void node_free(Node* node);

#endif // AUTOCOMPLETE_NODE_H