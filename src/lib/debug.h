#pragma once

#include <iostream>
#include <cstdlib>
#include <sstream>




template<typename... Args>
void debug_print(const char* message, Args&&... args) {
    std::ostringstream oss;
    (oss << ... << args) << "\n";
    std::cerr << message << oss.str();
}


template<typename... Args>
[[noreturn]]
void debug_panic(const char* file, int line, const char* function, const char* message, Args&&... args) {
    /*std::ostringstream oss;
    (oss << ... << args) << "\n";*/
    //std::cerr << message << oss.str() 
    debug_print(message, args...);
    std::cerr << "Program exited at " << file << ":" << line <<  " in " << function << "\n";
    std::exit(EXIT_FAILURE);
}


#define PANIC(...) do { debug_panic(__FILE__,__LINE__,__func__,__VA_ARGS__); } while(0)


#ifndef NDEBUG
#define debug(...) do { debug_print(__VA_ARGS__); } while (0)
#define ASSERT(expr) do { if (!(expr)) { PANIC("Assertion '", #expr, "' failed"); }} while (0)
#else
#define debug(...) ((void)0)
#define ASSERT(expr) ((void)0)
#endif
