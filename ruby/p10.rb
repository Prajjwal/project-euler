require_relative "include/primes"

puts primes_upto(2E6).reduce(:+)
