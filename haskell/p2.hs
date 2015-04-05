fibs =
    let gen x y = y : gen y (x + y)
    in gen 0 1

main =
    let terms = takeWhile (<4000000) $ filter even fibs
    in print $ sum terms
