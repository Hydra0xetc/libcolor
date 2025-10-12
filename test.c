#include <color.h>
#include <stdio.h>

// default is bold
int main(void) {
    // Basic color functions
    print_red("This is a red message.\n");
    print_green("This is a green message.\n");

    // Semantic functions
    print_success(" Operation was successful.\n");
    print_error(" An error occurred.\n");
    print_warning(" ffmpeg not found\n");

    // Formatted string
    int item_count = 10;
    print_success(" Processed %d items.\n", item_count);

    // Attributes and colors
    print_red(BG_WHITE "Red text on a white background\n");
    print_yellow("This is a bold yellow message.\n");

    // Using printf
    // Combine styles and colors
    printf(BOLD RED "Bold red text" RESET "\n");
    printf(UNDERLINE BLUE "Underlined blue text" RESET "\n");
    printf(GREEN BG_BLACK "Green on black" RESET "\n");

    // Always use RESET to avoid color bleeding
    printf(YELLOW "Warning" RESET " normal text\n");

    return 0;
}
