require 'date'

s_date = Date.new(1901, 1, 1)
e_date = Date.new(2000, 12, 31)

puts (s_date..e_date).count { |d| d.sunday? && d.day == 1 }
