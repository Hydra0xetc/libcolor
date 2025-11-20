/**
 * @file color.h
 * @brief ANSI color codes and printing functions for terminal output
 *
 * This header provides macros for ANSI escape codes to colorize terminal text
 * and functions for convenient colored output with formatting.
 */

#ifndef COLOR_H
#define COLOR_H

// Text colors
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Background colors
#define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"

// Text styles
#define DIM       "\033[2m"
#define BOLD      "\033[1m"
#define UNDERLINE "\033[4m"
#define BLINK     "\033[5m"
#define REVERSE   "\033[7m"

// Reset
#define RESET "\033[0m"

/**
 * @brief Prints a success message with green color and [SUCCESS] prefix
 * @param str Format string (printf-style)
 * @param ... Variable arguments for the format string
 */
void print_success(const char *str, ...) __attribute__((format(printf, 1, 2)));

/**
 * @brief Prints a debug message with yellow color and [DEBUG] prefix to stderr
 * @param str Format string (printf-style)
 * @param ... Variable arguments for the format string
 */
void print_debug(const char *str, ...) __attribute__((format(printf, 1, 2)));

/**
 * @brief Prints an error message with red color and [ERROR] prefix to stderr
 * @param str Format string (printf-style)
 * @param ... Variable arguments for the format string
 */
void print_error(const char *str, ...) __attribute__((format(printf, 1, 2)));

/**
 * @brief Prints an error message with red color and [WARNING] prefix to stderr
 * @param str Format string (printf-style)
 * @param ... Variable arguments for the format string
 */
void print_warning(const char *str, ...) __attribute__((format(printf, 1, 2)));

/**
 * @brief Prints text in bold yellow color
 * @param str Format string (printf-style)
 * @param ... Variable arguments for the format string
 */
void print_yellow(const char *str, ...) __attribute__((format(printf, 1, 2)));

/**
 * @brief Prints text in bold red color
 * @param str Format string (printf-style)
 * @param ... Variable arguments for the format string
 */
void print_red(const char *str, ...) __attribute__((format(printf, 1, 2)));

/**
 * @brief Prints text in bold green color
 * @param str Format string (printf-style)
 * @param ... Variable arguments for the format string
 */
void print_green(const char *str, ...) __attribute__((format(printf, 1, 2)));

/**
 * @brief Prints text in bold cyan color
 * @param str Format string (printf-style)
 * @param ... Variable arguments for the format string
 */
void print_cyan(const char *str, ...) __attribute__((format(printf, 1, 2)));

/**
 * @brief Prints text in bold magenta color
 * @param str Format string (printf-style)
 * @param ... Variable arguments for the format string
 */
void print_magenta(const char *str, ...) __attribute__((format(printf, 1, 2)));

/**
 * @brief Prints text in bold blue color
 * @param str Format string (printf-style)
 * @param ... Variable arguments for the format string
 */
void print_blue(const char *str, ...) __attribute__((format(printf, 1, 2)));

#endif // COLOR_H
