#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void errorf(char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  fprintf(stderr, "\n");
  exit(1);
}

void asm_printf(char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vfprintf(stdout, fmt, ap);
  fprintf(stdout, "\n");
}

void gen_asm() {
  asm_printf(".intel_syntax noprefix");
  asm_printf(".global main");
  asm_printf("main:");
  asm_printf("  mov rax, 4");
  asm_printf("  ret");
}

#define OPT_GEN_ASM "-S\0"
#define OPT_GEN_ASM_STRLEN strlen(OPT_GEN_ASM) + 1

int main(int argc, char const** argv)
{
  if (argc >= 2 && strncmp(argv[1], OPT_GEN_ASM, OPT_GEN_ASM_STRLEN) == 0) {
    gen_asm();
    return 0;
  }

  puts("usage: tcc -S");
}
