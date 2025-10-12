#include "color.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Internal helper function to print formatted text with color
 * @param stream Output stream (stdout or stderr)
 * @param color ANSI color code to apply
 * @param format Format string (like printf)
 * @param args Variable arguments list for format string
 *
 * This function handles the color formatting and ensures the color reset
 * is properly placed, especially when dealing with newlines.
 */
static void print_color_format(FILE *stream, const char *color, const char *format, va_list args) {
    fprintf(stream, "%s", color);

    size_t len = strlen(format);
    if (len > 0 && format[len - 1] == '\n') {
        // Print without the last newline to place RESET before newline
        char temp_format[1024];
        strncpy(temp_format, format, len - 1);
        temp_format[len - 1] = '\0';
        vfprintf(stream, temp_format, args);
        fprintf(stream, RESET "\n");
    } else {
        vfprintf(stream, format, args);
        fprintf(stream, RESET);
    }
}

/**
 * @brief Prints a success message with green color and [SUCCESS] prefix
 * @param format Format string (like printf)
 * @param ... Variable arguments matching the format string
 *
 * Example: print_success("File %s created\n", "test.txt");
 * Output: [SUCCESS] File test.txt created
 */
void print_success(const char *format, ...) {
    printf(BOLD GREEN "[SUCCESS]" RESET);

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

/**
 * @brief Prints an error message with red color and [ERROR] prefix to stderr
 * @param format Format string (like printf)
 * @param ... Variable arguments matching the format string
 *
 * Example: print_error("Failed to open file: %s\n", "data.txt");
 * Output: [ERROR] Failed to open file: data.txt
 */
void print_error(const char *format, ...) {
    fprintf(stderr, BOLD RED "[ERROR]" RESET);

    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

/**
 * @brief Prints a debug message with yellow color and [DEBUG] prefix to stderr
 * @param format Format string (like printf)
 * @param ... Variable arguments matching the format string
 *
 * Example: print_debug("Variable x = %d\n", 42);
 * Output: [DEBUG] Variable x = 42
 */
void print_debug(const char *format, ...) {
    fprintf(stderr, BOLD YELLOW "[DEBUG]" RESET);

    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

/**
 * @brief Prints text in bold yellow color
 * @param format Format string (like printf)
 * @param ... Variable arguments matching the format string
 *
 * Example: print_yellow("Warning: Low memory\n");
 * Output: (text in yellow) Warning: Low memory
 */
void print_yellow(const char *format, ...) {
    va_list args;
    va_start(args, format);
    print_color_format(stdout, BOLD YELLOW, format, args);
    va_end(args);
}

/**
 * @brief Prints text in bold red color
 * @param format Format string (like printf)
 * @param ... Variable arguments matching the format string
 *
 * Example: print_red("Critical error detected!\n");
 * Output: (text in red) Critical error detected!
 */
void print_red(const char *format, ...) {
    va_list args;
    va_start(args, format);
    print_color_format(stdout, BOLD RED, format, args);
    va_end(args);
}

/**
 * @brief Prints text in bold green color
 * @param format Format string (like printf)
 * @param ... Variable arguments matching the format string
 *
 * Example: print_green("Operation completed\n");
 * Output: (text in green) Operation completed
 */
void print_green(const char *format, ...) {
    va_list args;
    va_start(args, format);
    print_color_format(stdout, BOLD GREEN, format, args);
    va_end(args);
}

/**
 * @brief Prints text in bold blue color
 * @param format Format string (like printf)
 * @param ... Variable arguments matching the format string
 *
 * Example: print_blue("Information: %s\n", "System started");
 * Output: (text in blue) Information: System started
 */
void print_blue(const char *format, ...) {
    va_list args;
    va_start(args, format);
    print_color_format(stdout, BOLD BLUE, format, args);
    va_end(args);
}
