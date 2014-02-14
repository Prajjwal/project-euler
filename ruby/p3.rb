n, largest_pf = 600851475143, 2

while (n > 1)
  if n % largest_pf == 0
    n /= largest_pf
  else
    largest_pf += 1
  end
end

puts largest_pf # 6857
