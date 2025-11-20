#include "color.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Maximum length for formatted output to prevent excessive memory usage */
#define MAX_OUTPUT_LENGTH 8192

/**
 * @brief Internal helper function to print formatted text with color
 * @param stream Output stream (stdout or stderr)
 * @param color ANSI color code to apply
 * @param format Format string (like printf)
 * @param args Variable arguments list for format string
 *
 * Security improvements:
 * - NULL pointer validation
 * - Dynamic memory allocation instead of fixed buffer
 * - Proper error handling
 * - Memory safety with bounds checking
 */
static void print_color_format(FILE *stream,
                               const char *color,
                               const char *format,
                               va_list args) {
    /* Validate inputs */
    if (!stream || !color || !format) {
        return;
    }

    /* Print color code */
    fprintf(stream, "%s", color);

    size_t len = strlen(format);

    if (len > 0 && format[len - 1] == '\n') {
        /* Handle newline case: print RESET before newline */
        if (len == 1) {
            /* Just a newline */
            fprintf(stream, RESET "\n");
        } else if (len - 1 < MAX_OUTPUT_LENGTH) {
            /* Allocate dynamic buffer for format without newline */
            char *temp_format = (char *)malloc(len);
            if (!temp_format) {
                /* Fallback if allocation fails */
                vfprintf(stream, format, args);
                fprintf(stream, RESET);
                return;
            }

            memcpy(temp_format, format, len - 1);
            temp_format[len - 1] = '\0';

            vfprintf(stream, temp_format, args);
            free(temp_format);
            fprintf(stream, RESET "\n");
        } else {
            /* Format string too long, print without modification */
            vfprintf(stream, format, args);
            fprintf(stream, RESET);
        }
    } else {
        /* No newline at end, print normally */
        vfprintf(stream, format, args);
        fprintf(stream, RESET);
    }
}

/**
 * @brief Prints a success message with green color and [SUCCESS] prefix
 * @param format Format string (like printf) - MUST be from trusted source
 * @param ... Variable arguments matching the format string
 *
 * NOTE: The format parameter must come from a trusted source,
 * not directly from user input, to prevent format string attacks.
 *
 * Example: print_success("File %s created\n", filename);
 * Output: [SUCCESS] File test.txt created
 */
void print_success(const char *format, ...) {
    if (!format)
        return;

    printf(BOLD GREEN "[SUCCESS] " RESET);

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

/**
 * @brief Prints an error message with red color and [ERROR] prefix to stderr
 * @param format Format string (like printf) - MUST be from trusted source
 * @param ... Variable arguments matching the format string
 *
 * NOTE: The format parameter must come from a trusted source,
 * not directly from user input, to prevent format string attacks.
 *
 * Example: print_error("Failed to open file: %s\n", filename);
 * Output: [ERROR] Failed to open file: data.txt
 */
void print_error(const char *format, ...) {
    if (!format)
        return;

    fprintf(stderr, BOLD RED "[ERROR] " RESET);

    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

/**
 * @brief Prints a debug message with yellow color and [DEBUG] prefix to stderr
 * @param format Format string (like printf) - MUST be from trusted source
 * @param ... Variable arguments matching the format string
 *
 * NOTE: The format parameter must come from a trusted source,
 * not directly from user input, to prevent format string attacks.
 *
 * Example: print_debug("Variable x = %d\n", 42);
 * Output: [DEBUG] Variable x = 42
 */
void print_debug(const char *format, ...) {
    if (!format)
        return;

    fprintf(stderr, BOLD YELLOW "[DEBUG] " RESET);

    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

/**
 * @brief Prints a warning message with magenta color and [WARNING] prefix to
 * stderr
 * @param format Format string (like printf) - MUST be from trusted source
 * @param ... Variable arguments matching the format string
 *
 * NOTE: The format parameter must come from a trusted source,
 * not directly from user input, to prevent format string attacks.
 *
 * Example: print_warning("ffmpeg not found\n");
 * Output: [WARNING] ffmpeg not found
 */
void print_warning(const char *format, ...) {
    if (!format)
        return;

    fprintf(stderr, BOLD MAGENTA "[WARNING] " RESET);

    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

/**
 * @brief Prints text in bold yellow color
 * @param format Format string (like printf) - MUST be from trusted source
 * @param ... Variable arguments matching the format string
 *
 * NOTE: The format parameter must come from a trusted source,
 * not directly from user input, to prevent format string attacks.
 *
 * Example: print_yellow("Warning: Low memory\n");
 * Output: (text in yellow) Warning: Low memory
 */
void print_yellow(const char *format, ...) {
    if (!format)
        return;

    va_list args;
    va_start(args, format);
    print_color_format(stdout, BOLD YELLOW, format, args);
    va_end(args);
}

/**
 * @brief Prints text in bold red color
 * @param format Format string (like printf) - MUST be from trusted source
 * @param ... Variable arguments matching the format string
 *
 * NOTE: The format parameter must come from a trusted source,
 * not directly from user input, to prevent format string attacks.
 *
 * Example: print_red("Critical error detected!\n");
 * Output: (text in red) Critical error detected!
 */
void print_red(const char *format, ...) {
    if (!format)
        return;

    va_list args;
    va_start(args, format);
    print_color_format(stdout, BOLD RED, format, args);
    va_end(args);
}

/**
 * @brief Prints text in bold green color
 * @param format Format string (like printf) - MUST be from trusted source
 * @param ... Variable arguments matching the format string
 *
 * NOTE: The format parameter must come from a trusted source,
 * not directly from user input, to prevent format string attacks.
 *
 * Example: print_green("Operation completed\n");
 * Output: (text in green) Operation completed
 */
void print_green(const char *format, ...) {
    if (!format)
        return;

    va_list args;
    va_start(args, format);
    print_color_format(stdout, BOLD GREEN, format, args);
    va_end(args);
}

/**
 * @brief Prints text in bold blue color
 * @param format Format string (like printf) - MUST be from trusted source
 * @param ... Variable arguments matching the format string
 *
 * NOTE: The format parameter must come from a trusted source,
 * not directly from user input, to prevent format string attacks.
 *
 * Example: print_blue("Information: %s\n", "System started");
 * Output: (text in blue) Information: System started
 */
void print_blue(const char *format, ...) {
    if (!format)
        return;

    va_list args;
    va_start(args, format);
    print_color_format(stdout, BOLD BLUE, format, args);
    va_end(args);
}

/**
 * @brief Prints text in bold cyan color
 * @param format Format string (like printf) - MUST be from trusted source
 * @param ... Variable arguments matching the format string
 *
 * NOTE: The format parameter must come from a trusted source,
 * not directly from user input, to prevent format string attacks.
 *
 * Example: print_cyan("Warning opertion terminated\n");
 * Output: (text in cyan) Warning opertion terminated
 */
void print_cyan(const char *format, ...) {
    if (!format)
        return;

    va_list args;
    va_start(args, format);
    print_color_format(stdout, BOLD CYAN, format, args);
    va_end(args);
}

/**
 * @brief Prints text in bold magenta color
 * @param format Format string (like printf) - MUST be from trusted source
 * @param ... Variable arguments matching the format string
 *
 * NOTE: The format parameter must come from a trusted source,
 * not directly from user input, to prevent format string attacks.
 *
 * Example: print_magenta("Warning opertion terminated\n");
 * Output: (text in magenta) Warning opertion terminated
 */
void print_magenta(const char *format, ...) {
    if (!format)
        return;

    va_list args;
    va_start(args, format);
    print_color_format(stdout, BOLD MAGENTA, format, args);
    va_end(args);
}

/**
 * @brief Safely prints user-provided text with color (for untrusted input)
 * @param stream Output stream
 * @param color Color code to use
 * @param text User text to print (will be escaped, no format specifiers)
 *
 * Use this function when printing user-provided strings to prevent
 * format string vulnerabilities.
 *
 * Example: print_safe_colored(stdout, GREEN, user_input);
 */
void print_safe_colored(FILE *stream, const char *color, const char *text) {
    if (!stream || !color || !text)
        return;

    fprintf(stream, "%s%s" RESET, color, text);
}

/**
 * @brief Safely prints user-provided text without color (for untrusted input)
 * @param text User text to print (will be escaped, no format specifiers)
 *
 * Use this function when printing user-provided strings to prevent
 * format string vulnerabilities.
 *
 * Example: print_safe(user_input);
 */
void print_safe(const char *text) {
    if (!text)
        return;

    fputs(text, stdout);
}
