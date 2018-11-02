permutations :: Integral a => a -> a -> [(a,a)]
permutations min max = [(a,b) | a <- [min..max], b <- [min..max]]

pow :: Integral a => (a,a) -> a
pow (a,b) = a^b

powers min max = map pow (permutations min max)

sortedAndDistinct :: Integral a => [a] -> [a]
sortedAndDistinct [] = []
sortedAndDistinct list = 
  (sortedAndDistinct less) ++ [pivot] ++ (sortedAndDistinct more)
  where
    pivot = list !! ((length list) `div` 2)
    less = [n | n <- list, n < pivot]
    more = [n | n <- list, n > pivot]
