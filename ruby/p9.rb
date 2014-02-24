# We know that c = 1000 - a - b
#
# Since a < b < c & a + b + c == 1000,
# a, b can't be > 500
#
# So, for all possible pairs (a, b) where a, b are < 500,
# find a * b * c where a < b < c and c ^ 2 == a ^ 2 + b ^ 2

(1..500).to_a.permutation(2).each do |p|
  a, b = p.first, p.last
  c = 1000 - a - b

  if (a < b && b < c && c ** 2 == a ** 2 + b ** 2)
    puts a * b * c # 31875000
  end
end
