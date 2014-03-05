(load "helper")

(define nums (iota 100 1 1))

(-
  (square (sum nums))
  (sum (map square nums)))
