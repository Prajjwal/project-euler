isPalindrome x =
    let str = show x
    in str == reverse str

main =
    let products = [x * y | x <- [100..999], y <- [110,121..999]]
        palindromes = filter isPalindrome products
    in print $ maximum palindromes
