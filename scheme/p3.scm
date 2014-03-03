(load "helper")

(define (largest-prime-factor num)
  (define (iter n prime)
    (if (> n 1)
      (if (divides? prime n)
        (iter (/ n prime) prime)
        (iter n (+ prime 1)))
      prime))
  (iter num 2))

(largest-prime-factor 600851475143)
