
import Data.Bits
import Control.Monad

-- Convert integer to binary representation (without leading zeros)
toBinary :: Int -> [Int]
toBinary 0 = [0]
toBinary n = reverse $ helper n
  where
    helper 0 = []
    helper n = (n `mod` 2) : helper (n `div` 2)

-- Reverse binary and convert to integer
reverseBinary :: Int -> Int
reverseBinary n =
  let binary = toBinary n
      reversed = reverse binary
  in foldl (\acc bit -> acc * 2 + bit) 0 reversed

-- Check if n can be expressed as x XOR f(x)
canBeXORed :: Int -> Bool
canBeXORed 0 = True  -- Special case: n=0 is always possible
canBeXORed n =
  let revN = reverseBinary n
  in n == revN

solve :: [Int] -> [String]
solve = map (\n -> if canBeXORed n then "YES" else "NO")

main :: IO ()
main = do
    t <- readLn :: IO Int
    testCases <- replicateM t readLn :: IO [Int]
    mapM_ putStrLn (solve testCases)
