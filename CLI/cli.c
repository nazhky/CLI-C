#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cli.h"

static void print_help(const char *program) {
    printf("Usage: %s <command> [arguments]\n\n", program);
    printf("Commands:\n");
    printf("  help           Show this message\n");
    printf("  hello <name>   Greet someone\n");
    printf("  add <a> <b> <c>    Add three numbers\n");
    printf("  multiply <a> <b>\n");
}

static int cmd_hello(int argc, char *argv[]) {
    if (argc < 3) {
        printf("hello needs a name\n");
        return 1;
    }
    printf("Hello, %s!\n", argv[2]);
    return 0;
}

static int cmd_add(int argc, char *argv[]) {
    if (argc < 5) {
        printf("add needs three numbers\n");
        return 1;
    }
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    int c = atoi(argv[4]);
    printf("%d + %d + %d = %d\n", a, b, c, a + b + c);
    return 0;
}

static int cmd_multiply(int argc, char *argv[]){
    if (argc < 4){
        printf("needs two numbers\n");
        return 1;
    }
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    printf("%d + %d = %d\n", a, b, a * b);
    return 0;
}

int cli_run(int argc, char *argv[]) {
    if (argc < 2) {
        print_help(argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "help") == 0) {
        print_help(argv[0]);
        return 0;
    }
    if (strcmp(argv[1], "hello") == 0) {
        return cmd_hello(argc, argv);
    }
    if (strcmp(argv[1], "add") == 0) {
        return cmd_add(argc, argv);
    }
    if (strcmp(argv[1], "multiply") == 0){
        return cmd_multiply(argc, argv);
    }

    printf("Unknown command: %s\n\n", argv[1]);
    print_help(argv[0]);
    return 1;
}
