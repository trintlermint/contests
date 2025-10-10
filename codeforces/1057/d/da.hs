import Control.Monad (replicateM_)

solveNotAlone :: [Int] -> Int
solveNotAlone arr =
    let n = length arr
        -- Iterate through each position and find optimal cost
        totalCost = sum (map (\i -> calculateCostAtPosition i arr n) [0..n-1])
    in totalCost

calculateCostAtPosition :: Int -> [Int] -> Int -> Int
calculateCostAtPosition i arr n =
    let curr = arr !! i
        left = arr !! ((i-1+n) `mod` n)
        right = arr !! ((i+1) `mod` n)
    in if curr == left || curr == right
       then 0  -- Already satisfies the condition
       else min (abs (curr - left)) (abs (curr - right))

main :: IO ()
main = do
    t <- readLn :: IO Int
    replicateM_ t $ do
        n <- readLn :: IO Int
        arr <- map read . words <$> getLine
        print $ solveNotAlone arr
