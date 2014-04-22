puts (1..1000).each.map { |x| x ** x }.reduce(:+).to_s[-10..-1]
