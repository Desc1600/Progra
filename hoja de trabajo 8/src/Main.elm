module Main exposing (..)
--Serie 1 
zipWith : (a -> b -> c) -> List a -> List b -> List c
zipWith ss xs ys  = case (xs, ys) of
    ([], ys_) -> []
    (xs_, []) -> []
    (z::zs, y::yss) -> ss z y ::zipWith ss zs ys

--Serie 2
groupBy : (x -> Bool) -> List x -> (List x, List x) 
groupBy num lista = (simon num lista, nelSimon num lista)

simon x lista = case lista of 
    [] -> []
    (y::yss) -> if x y 
                then simon x yss 
                else y:: simon x yss

nelSimon x lista = case lista of 
    [] -> []
    (z::zss) -> if x z then z:: nelSimon x zss else nelSimon x zss

--Serie
bind : Maybe x -> (x -> Maybe x) -> Maybe x
bind x y = case x of 
    Nothing -> Nothing 
    Just xx -> y xx 
    
