module Mainn exposing (..)
-- Tipo Polomorfico
-- 
-- Tipo Monomorfico
-- concat : List Int -> List int -> List int
concat bs cs = 
 case (bs, cs) of
    ([], _) -> cs
    (_ ,[]) -> bs
    (b::bss, _) -> b::concat bss cs  

zip : List a -> List b -> List (a,b)
zip bss css =
    case (bss, css) of
        ([], _) -> [] 
        (_ ,[]) -> []
        (a::bs, b::cs) -> (a,b)::zip bs cs 

diverge a = diverge a

type Maybe = Some Int | None

get : List Int -> Int -> Maybe
get bss i =
    case (i,bss) of
        (_,[]) -> None
        (0, b::_) -> Some b
        (ix, b::bs) -> get bs (ix-1)