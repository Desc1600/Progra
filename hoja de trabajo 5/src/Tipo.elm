module Tipo exposing (..)
type Natural =Suc Natural | Cero

enteroANatural :Int-> Natural
enteroANatural i = 
    if i == 0
    then Cero
    else Suc(enteroANatural (i-1))
    
naturalAEntero :Natural-> Int
naturalAEntero n = case n of 
    Cero -> 0   
    Suc i -> 1+ naturalAEntero i

--sumar n1 n2 = case (n1,n2) of
  --  (cero,n2_) -> n2_
   -- (n1_ ,cero) -> n1_
   -- (Suc n1_, Suc n2_) ->Suc(sumar n1_ n2_)

--mult n1 n2 = case (n1.n2) of 
  --  (Cero, n2_) -> Cero
   -- (n1_ , Cero) -> Cero
    --(Suc n1_ , n2_)-> sumar n2_ (mult n1_ n2_)

type Figura = Circulo Float
    | Cuadro Float
    | Triangulo Float Float

area: Figura -> Float
area figura =case figura of 
    Circulo r ->Basics.pi *r *r 
    Cuadro l -> l*l
    Triangulo l1 l2 -> l1 * (sqrt((l1/2)*(l1/2)+l2*l2))

type List a = Cons a (List a) | Nil

crearList: [a] -> MiList a
crearLista 1 = case 1 of 
    []->Nil
    x::Xs -> cons x (crearLista xs)