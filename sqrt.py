"""
Floor square root function is implemented without using any library.
Algorithm inspired by the explanation from:
https://medium.com/i-math/how-to-find-square-roots-by-hand-f3f7cadf94bb
"""
def div(x,y):
  quotient = x // y
  remainder = x - y * quotient
  return quotient, remainder

def floor_sqrt(x):
  """Input: Positive interger x.  
  Output: x^(1/2).
  """
  if x < 0:
    return -1
  
  base = {0:0, 1:1}
  if x in base:
    return base[x]

  x_prime, _ = div(x, 4)
  a = floor_sqrt(x_prime)

  residual = x - 4*a*a
  b = 0
  while not (4*a*b + b*b > residual):
    b = b + 1
  b = b - 1

  return b + 2*a



# Verification
import math 
TEST_RANGE = 100000
correct = 0
for i in range(10000,TEST_RANGE):
  if math.floor(math.sqrt(i)) != floor_sqrt(i): 
    print("Incorrect at {}".format(i))
  else:
    correct = correct + 1
print("Correct {} out of {}".format(correct, TEST_RANGE))

