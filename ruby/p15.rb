def factorial(n)
  n.downto(2).reduce(:*)
end

# Answer is the binomial coefficient (a + b over b), which in this case is
# (40 over 20).
puts factorial(40) / (factorial(20) ** 2)
