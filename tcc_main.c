#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gen_asm() {
    puts(".intel_syntax noprefix");
    puts(".global main");
    puts("main:");
    printf("  mov rax, 4\n");
    printf("  ret\n");
}

#define OPT_GEN_ASM "-S\0"
#define OPT_GEN_ASM_STRLEN strlen(OPT_GEN_ASM) + 1

int main(int argc, char const** argv)
{
    // printf("%s, %ld\n", OPT_GEN_ASM, OPT_GEN_ASM_STRLEN);
    if (argc >= 2 && strncmp(argv[1], OPT_GEN_ASM, OPT_GEN_ASM_STRLEN) == 0) {
        gen_asm();
        return 0;
    }

    puts("usage: tcc -S");
    // gen_asm();
}
