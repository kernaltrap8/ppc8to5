#include <stdio.h>

int main() {
  int regval;
  // asm("xxlxor vs0, vs0, vs0");
  //  the alternative to xxlxor in P5
  //  would be vxor, which takes the values
  //  of two registers then zeros them, and puts
  //  them in a resulting register.
  asm("li vs0, 0x20" : "=r"(regval));
  printf("0x%x", regval);
  asm("vxor vs0, vs0, vs0");
  asm("li r1, vs0" : "=r"(regval));
  printf("0x%x", regval);
  return 0;
}
