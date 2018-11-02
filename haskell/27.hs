quadraticFormula :: Integral a => a -> a -> a -> a
quadraticFormula n a b = n^2 + a*n + b

permutations = [(a,b) | a <- [-999..999], b <- [-999..999]]

primesCount (a,b) = primesCount' (a,b) [0..]
primesCount' (a,b) l = 
  if isPrime(quadraticFormula (head l) a b) 
  then 1 + (primesCount' (a,b) (tail l))
  else 0

isPrime :: Integral n => n -> Bool
isPrime n 
  | n < 2 = False
  | n == 2 = True
  | n > 2 = not $ (2:[3, 5 .. root n]) `divides'` n

root :: Integral n => n -> n
root = floor . sqrt . fromIntegral

divides' :: Integral n => [n] -> n -> Bool
divides' [] dividend = False
divides' (x:xs) dividend = x `divides` dividend || divides' xs dividend

divides :: Integral n => n -> n -> Bool
divides divisor dividend = dividend `mod` divisor == 0
