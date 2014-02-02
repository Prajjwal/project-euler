a, b, sum = 0, 1, 0

until b > 4E6
  sum += b if b.even?
  a, b = b, a + b
end

puts sum # 4613732
