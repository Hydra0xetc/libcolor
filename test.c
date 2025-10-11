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
    print_yellow(BOLD "This is a bold yellow message.\n");
    print_red(BG_WHITE "Red text on a white background.\n");

    return 0;
}
