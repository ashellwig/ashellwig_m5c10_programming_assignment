/**
 * @file ashwig_util.hh
 * @author Ashton Scott Hellwig (ahellwig@student.cccs.edu)
 * @brief This file contains global function declarations and definitions used
 * to emulate system-dependent Windows libraries, debugging print functions, and
 * details regarding exception handling.
 * @date 2020-05-10
 */

#ifndef ASHWIG_UTIL_HH_INCLUDED
#  define ASHWIG_UTIL_HH_INCLUDED

#  include <exception>

namespace ashwig_util {
// --- GENERAL FUNCTIONS ---
void pauseprompt();

// ---DEBUG HELPERS ---
/**
 * @brief This file contains macros, definitions, and attribues when either
 * compiling with `-DDebug` or without `-DNDEBUG`. To utilize these functions,
 * the previously mentioned compiler flags must be used.
 */
inline namespace ashwig_debug {
/**
 * @brief Prints the output of a function call when it is sent to stderr rather
 * than stdout. Use for debugging assistance.
 */
#  define verbose_print(message, ...)                                          \
    std::cerr << "[" << __FILE__ << "]: "                                      \
              << "[" << __PRETTY_FUNCTION__ << "]: "                           \
              << "[line:" << __LINE__ << "] >> " << message << __VA_ARGS__     \
              << std::endl;
} // namespace ashwig_debug

// --- EXCEPTIONS ---
/**
 * @brief This file contains the definitions of exceptions classes to be used
 * in the programming assignments for FRCC's CSC160 at CCCOnline.
 */
inline namespace ashwig_exceptions {
/**
 * @brief Provides exception types for additional debugging information.
 */
class Chapter6InputException : public std::exception {
public:
  virtual const char *what() const throw() {
    return "Cannot have first input higher than the second.";
  }
};

class Chapter7InputException : public std::exception {
public:
  virtual const char *what() const throw() {
    return "Invalid string. Ensure it is in the format of:\n[FirstName] "
           "[LastName] [000-00-000] [S0000000] [password]";
  }
};
} // namespace ashwig_exceptions
} // namespace ashwig_util

#endif

// vim: set et ts=2 sw=2 ft=cpp:
