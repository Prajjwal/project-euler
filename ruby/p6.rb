sum_of_squares = (1..100).map { |n| n * n }.reduce(:+)
square_of_sum = (1..100).reduce(:+) ** 2
puts square_of_sum - sum_of_squares # 25164150
