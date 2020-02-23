#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <stdbool.h> 
#include <math.h>

typedef unsigned long long int u64;

void swap(u64* arr, int e1, int e2) {
  u64 temp = arr[e1];
  arr[e1] = arr[e2];
  arr[e2] = temp;
}

//https://stackoverflow.com/questions/6127503/shuffle-array-in-c
void fisher_yates_shuffle(unsigned int n, u64* arr) {
  srand(time(0)); 
  for (int i = 0; i < n; i++){
    if ((n-1-i) > 0) {
      swap(arr, i, i+(rand() % (n-1-i)));
    }
  } 
}

// return x^y mod N 
u64 modexp(u64 x, u64 y, u64 N){
  if (y == 0) return 1;
  u64 z = modexp(x, floor(y/2), N);
  if ((y & 1) == 0) return (z*z) % N;
  else return (x*z*z) % N;
}


// Error rate lower bounded by Pi(i=0 to k){((N-1)/2-i)/(N-1-i)}
// Does not take into account of Carmichael numbers.
bool is_prime(u64 N, int k){
  if (N < 2) return false;
  if (k > (N-1)) k = N-1;

  // An array of "a" (1<= a < N)
  u64* arr = (u64*)malloc((N-1) * sizeof(u64)); 
  for (u64 i = 0; i < N-1; i++){
    arr[i] = i+1;
  }
  fisher_yates_shuffle(N-1, arr);

  for (int i = 0; i < k; i++){
    if (modexp(arr[i], N-1, N) != 1) { 
      return false;
    }
  }
  return true;
}

int main() {
  for (int i = 1; i < 100; i ++){
    bool result = is_prime(i, 10); //Error rate lesser than about 1%
    printf("%d is %s\n", i, result ? "Prime" : "Not prime");
  }
}