def sum_proper_divisors(n)
  (1..(n/2)).select { |x| x if n % x == 0 }.reduce(:+)
end

def amicable?(a)
  b = sum_proper_divisors(a)
  (a != b) && (sum_proper_divisors(b) == a)
end

puts (2..9999).select { |n| n if amicable?(n) }.reduce(:+)
