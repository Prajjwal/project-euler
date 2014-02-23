(load "helper")

(reduce + 0 (filter
            (lambda (n) (or (divides? 3 n) (divides? 5 n)))
            (iota 999 1 1)))
