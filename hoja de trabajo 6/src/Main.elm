module Main exposing (..)

type Natural = Suc Natural | Cero  

enteroANatural : Int -> Natural
enteroANatural i = if i == 0 then Cero else Suc (enteroANatural(i-1))

sumar : Natural -> Natural -> Natural
sumar n1 n2 = case (n1, n2) of 
    (Cero, n2_) -> n2_
    (n1_, Cero) -> n1_
    (Suc n1_,Suc n2_) ->  Suc (Suc (sumar n1_ n2_))

restar : Natural -> Natural -> Natural
restar n1 n2 = case (n1, n2) of 
    (Cero,n2_) -> Cero
    (n1_,Cero) -> n1_
    (Suc n1_,Suc n2_) ->  restar n1_ n2_


multiplicacion : Natural -> Natural -> Natural
multiplicacion n1 n2 = case (n1,n2) of
    (Cero, n2_) -> Cero
    (n1_,Cero) -> Cero
    (n1_, Suc n2_) ->  sumar n1_ (multiplicacion n1_ n2_)

divn : Natural -> Natural -> Natural -> Natural
divn n1 n2 n = case (n1, n2, n) of
    (Cero , n2_ , n_) -> n_
    (n1_, Cero , n_) -> Cero    
    (n1_,  n2_ , n_) -> divn (restar n1_ n2_) n2_ (Suc n_)

division : Natural -> Natural -> (Natural, Natural)
division n1_ n2_ =
    if multiplicacion (divn n1_ n2_ Cero) n2_ == n1_ 
    then (divn n1_ n2_ Cero, Cero) 
    else (restar (divn n1_ n2_ Cero) (Suc Cero), restar (n1_ )(multiplicacion (restar(divn n1_ n2_ Cero)(Suc Cero)) n2_ ))


type GExpresion x = Valor x
    | Suma (GExpresion x) (GExpresion x)
    | Mult (GExpresion x) (GExpresion x)

type alias Expresion = GExpresion Int

type Estado = Final Int 
    | Parce (List Char)
