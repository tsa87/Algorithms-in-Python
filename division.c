#include <stdio.h>

typedef unsigned long long int u64;

struct divison_result {
  u64 q;
  u64 r;
};

struct divison_result divide(u64 x, u64 y) {
  struct divison_result result = {0, 0};
  if (x == 0) return result;
  result = divide(x>>1, y);
  result.q = result.q<<1;
  result.r = result.r<<1;
  if ((x & 0x1) == 1){
    result.r++;
  }
  if (result.r >= y){
    result.r = result.r - y;    
    result.q++;
  }
  return result;
}

int main() {
  struct divison_result result;
  u64 x = 184467440737095516;
  u64 y = 8446744073709551;
  result = divide(x, y);
  printf("%llu divided by %llu:\n", x, y);
  printf("quotient=%llu, remainder=%llu\n", result.q, result.r);
}