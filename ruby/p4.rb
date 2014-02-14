class Integer
  def palindrome?
    self == self.to_s.reverse.to_i
  end
end

largest = 0

100.upto 999 do |i|
  110.step 999, 11 do |j|
    p = i * j
    largest = p if (p > largest && p.palindrome?)
  end
end

puts largest # 906609
