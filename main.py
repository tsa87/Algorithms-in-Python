import math

mod = lambda a, b : a - math.floor(a/b) * b
  
def gcd(a, b):
  """
  Input: Positive integers a, b.
  Output: Greatest common divisor of a, b.
  """
  if not a > b:
    a, b = b, a

  if b == 0:
    return a
  return gcd(b, mod(a,b))

def extended_euclid(a, b):
  """
  Input: Positive integers a, b.
  Output: Integers x, y, d such that d = gcd(a, b) and ax + by = d
  """
  if not a > b:
    a, b = b, a

  if b == 0:
    return (1, 0, a)

  (x_p, y_p, d) = extended_euclid(b, mod(a, b))
  return (y_p, x_p-math.floor(a/b)*y_p, d)

def mod_inverse(a, N):
  """
  Input: Positive integers a, N.
  Output: Positive integer x such that (a*x) mod N = 1 or false if no such x exists
  """  
  (x, y, d) = extended_euclid(a, N)
  return x if d == 1 else False

print(mod_inverse(21, 91))