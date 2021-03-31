// #############################################################################
// This file contains the functions needed by fmap.f90 to call
// the std::map in C++
//
// Compilation command:
// g++ -c -g -Wall -Wextra -Werror cmap.cpp
//
// #############################################################################
#include <map>
#include <string>
using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

// Type to map the Fortran array
// Must match the `type, bind(c):: c_vec` in fmap.f90
typedef struct vec {
    double* data;
    int size;
} vec;

// Initialize pointer by calling map contructor
void mapInit(map<string,vec>*& mapping){
    mapping = new map<string,vec>();
    return;
}

// Insert a value in the map using a key
void mapAdd(map<string,vec>* mapping, char* fkey, int n, double* data){
    // Convert char* to string
    string key(fkey);
    // Fill the vec type
    vec value;
    value.data = data;
    value.size = n;
    // Map it
    mapping->insert( {key,value} );
    return;
}

// Get a value from map using a key
vec mapGet(map<string,vec>* mapping, char* fkey){
    // Convert char* to string
    string key(fkey);
    return(mapping->find(key)->second);
}

// Check id map is empty
bool mapIsEmpty(map<string,vec>* mapping){
    return(mapping->empty());
}


#ifdef __cplusplus
}
#endif