#include "color.h"
#include <stdio.h>

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
    fprintf(stdout, BOLD YELLOW);

    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);

    fprintf(stdout, RESET);
}

void print_red(const char *format, ...) {
    fprintf(stdout, BOLD RED);

    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);

    fprintf(stdout, RESET);
}

void print_green(const char *format, ...) {
    fprintf(stdout, BOLD GREEN);

    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);

    fprintf(stdout, RESET);
}

void print_blue(const char *format, ...) {
    fprintf(stdout, BOLD BLUE);

    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);

    fprintf(stdout, RESET);
}
