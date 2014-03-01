require_relative "include/primes"

# TODO: Stop pulling numbers out of thin air and figure out the actual upper
# bound for the nth prime.
puts primes_upto(5E5)[10000]
