(define (divides? a b) (= (modulo b a) 0))

(define (sum xs) (reduce + 0 xs))

(define (factorial n)
  (define (iter n fact)
    (if (= n 0) fact (iter (- n 1) (* fact n))))
  (iter n 1))
