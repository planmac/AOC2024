import Data.List

lineToPair :: String -> [Int]
lineToPair ln = 
    let ws = words ln
        ns = map read ws
        a = ns!!0
        b = ns!!1
    in [a,b]


main = do
    inp <- readFile "day1.txt"
    let lns = lines inp
        prs = map lineToPair lns
        [a,b] = transpose prs
        as = sort a
        bs = sort b
        df = zipWith (-) as bs
        ab = map abs df
        sm = foldl (+) 0 ab
    print sm
