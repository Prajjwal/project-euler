# Helper methods for problems that deal in primes

# Compute all primes up to n using the sieve of eratosthenes.
# https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
def primes_upto(n)
  sieve = [].fill(true, (2..n))

  2.upto Math.sqrt(n) do |i|
    (i * i).step(n, i) { |j| sieve[j] = false } if sieve[i]
  end

  sieve.each_index.select { |i| i if sieve[i] }
end
