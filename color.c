#include "color.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static void print_color_format(FILE *stream, const char *color, const char *format, va_list args) {
    fprintf(stream, "%s", color);

    size_t len = strlen(format);
    if (len > 0 && format[len - 1] == '\n') {
        // Print without the last newline
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

void print_success(const char *format, ...) {
    printf(BOLD GREEN "[SUCCESS]" RESET);

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

void print_error(const char *format, ...) {
    fprintf(stderr, BOLD RED "[ERROR]" RESET);

    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

void print_debug(const char *format, ...) {
    fprintf(stderr, BOLD YELLOW "[DEBUG]" RESET);

    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

void print_yellow(const char *format, ...) {
    va_list args;
    va_start(args, format);
    print_color_format(stdout, BOLD YELLOW, format, args);
    va_end(args);
}

void print_red(const char *format, ...) {
    va_list args;
    va_start(args, format);
    print_color_format(stdout, BOLD RED, format, args);
    va_end(args);
}

void print_green(const char *format, ...) {
    va_list args;
    va_start(args, format);
    print_color_format(stdout, BOLD GREEN, format, args);
    va_end(args);
}

void print_blue(const char *format, ...) {
    va_list args;
    va_start(args, format);
    print_color_format(stdout, BOLD BLUE, format, args);
    va_end(args);
}
