# libcolor

A simple C library for printing colored and styled text to the terminal.

## Features

- **Basic Colors**: `print_red`, `print_green`, `print_blue`, `print_yellow`.
- **Semantic Messages**: `print_success`, `print_error`, `print_debug`.
- **Text Attributes**: Bold, Underline, Blink, Reverse.
- **Background Colors**: `BG_RED`, `BG_GREEN`, etc.
- **Printf-style Formatting**: Use format specifiers like `%d` and `%s`.

## Prerequisites

- GCC or C compiler
- make
- pkg-config

## Installation

1.  **Compile the library:**
    ```bash
    make
    ```

2.  **Install the library:**
    ```bash
    make install
    ```
    By default, this installs files to `$HOME/.local`. To specify a different path (e.g., `/usr/local`), use the `PREFIX` variable:
    ```bash
    make install PREFIX=/usr/local
    ```

## Usage

To use `libcolor` in your project, you must use `pkg-config` to supply the correct compiler and linker flags.

1.  **Include the header in your C file:**
    ```c
    #include <color.h>
    ```

2.  **Set up environment (if needed):**
    If you installed the library to a non-standard location like the default `$HOME/.local`, export the `PKG_CONFIG_PATH` variable. It is recommended to add this to your `~/.bashrc` or `~/.zshrc` file.
    ```bash
    export PKG_CONFIG_PATH=$HOME/.local/lib/pkgconfig:$PKG_CONFIG_PATH
    ```

3.  **Compile your program:**
    ```bash
    gcc test.c $(pkg-config --cflags --libs libcolor) -o test
    ```

## API Example

```c
#include <color.h>

// default is bold
int main(void) {
    // Basic color functions
    print_red("This is a red message.\n");
    print_green("This is a green message.\n");

    // Semantic functions
    print_success("Operation was successful.\n");
    print_error("An error occurred.\n");

    // Formatted string
    int item_count = 10;
    print_success("Processed %d items.\n", item_count);

    // Attributes and colors
    print_yellow("This is a bold yellow message.\n");
    print_red(BG_WHITE "Red text on a white background.\n");

    return 0;
}
```

## Using ANSI Macros Directly

For more control, you can use the color macros directly with `printf`:

```c
#include <color.h>
#include <stdio.h>

int main(void) {
    // Combine styles and colors
    printf(BOLD RED "Bold red text" RESET "\n");
    printf(UNDERLINE BLUE "Underlined blue text" RESET "\n");
    printf(GREEN BG_BLACK "Green on black" RESET "\n");
    
    // Always use RESET to avoid color bleeding
    printf(YELLOW "Warning" RESET " normal text\n");
    
    return 0;
}
```
