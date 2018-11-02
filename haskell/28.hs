repeatEach [] repetitions = []
repeatEach list repetitions = 
  (take repetitions (repeat (head list))) ++ 
  (repeatEach (tail list) repetitions)

diagonalNumbers spiralSideLength = 
  1:(diagonalNumbers' 1 (repeatEach [2,4..spiralSideLength - 1] 4))

diagonalNumbers' lastNumber [] = []
diagonalNumbers' lastNumber stepSizes = 
  [currentNumber] ++ diagonalNumbers' currentNumber (tail stepSizes)
    where currentNumber = lastNumber + (head stepSizes)
