a, b, count = 1, 1, 2

while b.to_s.size < 1000
  count += 1
  a, b = b, a + b
end

puts count
