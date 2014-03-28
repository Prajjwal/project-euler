; Sum all fibonacci numbers upto 'n' that satisfy a predicate
(define (fib-sum n pred)
  (define (fib-sum-iter a b sum)
    (if (> b n)
      sum
      (fib-sum-iter b (+ a b) (if (pred b) (+ sum b) sum))))
  (fib-sum-iter 1 1 0))

(fib-sum 4E6 even?)
