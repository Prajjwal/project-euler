# Compute all primes under a million using the sieve of eratosthenes.
# https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

n, sum = 2E6, 0
sieve = [].fill(true, (2..n))

2.upto Math.sqrt(n) do |i|
  if sieve[i]
    (i * i).step n, i do |j|
      sieve[j] = false
    end
  end
end

sieve.each_with_index { |b, i| sum += i if b }
puts sum
