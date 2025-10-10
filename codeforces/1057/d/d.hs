import Control.Monad (replicateM_)
import Data.List (minimumBy)

import Data.Function (on)

test :: [Int] -> Int
test arr = 
    let n = length arr
        costs = minCost arr n
    in costs

minCost :: [Int] ->Int ->Int
minCost arr n =
    let circArr = arr ++ [head arr, arr !! 1] -- for pos, calc min ops needed
        dp = map (\i -> minOps i circArr) [0..n-1]
    in sum dp

-- @ pos i
minOps :: Int -> [Int] -> Int
minOps i circArr =
    let current = circArr !! i
        l = circArr !! (i-1+length circArr) `mod` length circArr
        r = circArr !! (i+1)
    in if current == l|| current == r
       then 0  -- satsified or choose min cos
       else min (abs (current - l)) (abs (current - r))

main :: IO ()
main = do
    t <- readLn :: IO Int
    replicateM_ t $ do
        n <- readLn :: IO Int
        arr <- map read . words <$> getLine
        print $ test arr
