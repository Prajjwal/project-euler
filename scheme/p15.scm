; The bruteforce solution in scheme is quite elegant, but too slow.
; Instead, we can arrive at the answer quickly by calculating the binomial
; coefficient (a + b over b).
;
; http://mathworld.wolfram.com/LatticePath.html

(load "helper")

; The binomial coeficcient (n over k) is given by n! / k! * (n - k)!
; In this case
; n = a + b = 20 + 20 = 40, and
; k = a = 20.

(/ (factorial 40) (* (factorial 20) (factorial 20)))
