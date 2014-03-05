(define (divides? a b) (= (modulo b a) 0))

(define (sum xs) (reduce + 0 xs))
