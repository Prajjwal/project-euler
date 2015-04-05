import Data.List (nub)

x `divides` y = y `mod` x == 0

primeFactors n =
    let iter n prime primes
            | n < prime = nub primes
            | prime `divides` n = iter (n `div` prime) prime (prime:primes)
            | otherwise = iter n (prime + 1) primes
    in iter n 2 []

-- Our list of primeFactors is in descending order, so the head is the
-- largest one.
main = print $ head $ primeFactors 600851475143
