num = File.open("../input/p8.txt", "r") { |f| f.readline }
largest_p = 1

0.upto 996 do |i|
  p = 1

  num[i, 5].each_byte { |b| p *= b - 48 }

  largest_p = p if p > largest_p
end

puts largest_p
