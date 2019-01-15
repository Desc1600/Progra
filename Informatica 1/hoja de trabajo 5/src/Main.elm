module Main exposing (..)
esPrimo n = primo 2 n 
primo div n =
    if n == 1
    then False
    else if n == 2 
    then True
    else if modBy div n == 0
    then False
    else if div == n-1
    then True
    else primo (div+1) n

fibonachi: Int-> Int
fibonachi x = 
    if x == 0
    then 0
    else if x == 1
    then 1
    else if x > 1
    then fibonachi(x-1) + fibonachi(x-2)
    else 0

primos: Int->List Int
primos n =
    if n<1
    then []
    else if esPrimo n == False 
    then primos (n-1)
    else n::primos (n-1)

nprimos:Int-> List Int
nprimos n = lprimos (n,2)
lprimos (n,num) =
    if n == 0
    then []
    else if esPrimo num == False
    then lprimos (n, num +1)
    else num:: lprimos (n-1, num +1)
