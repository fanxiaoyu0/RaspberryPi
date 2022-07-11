#include <stdio.h>

typedef struct {
  unsigned short pc;
  unsigned short target;
} BTBEntry;

int main(){
    BTBEntry a;
    a.pc=100;
    a.target=200;
    printf("%hu\n",a.pc);
}