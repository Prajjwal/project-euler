puts IO.readlines("../input/p13.txt").map { |n| n.to_i }.reduce(:+).to_s[0, 10]
