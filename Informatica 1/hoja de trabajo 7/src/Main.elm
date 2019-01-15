module Main exposing (..)
suma: Int -> Int -> Int 
suma n1 n2 = n1 + n2

mult: Int -> Int -> Int 
mult n1 n2 = n1 * n2

type Expresion  =  Suma Expresion Expresion
    | Mult Expresion Expresion 
    | Valor Int
    
reducir:((Int -> Int -> Int), (Int -> Int -> Int)) -> Expresion -> Int 
reducir (sumar, multipl) exp = case exp of
    Suma exp1 exp2 -> sumar (reducir (sumar, multipl) exp1)  (reducir (sumar, multipl) exp2)
    Mult exp1 exp2 -> multipl (reducir (sumar, multipl) exp1)  (reducir (sumar, multipl) exp2)
    Valor x -> x
    
