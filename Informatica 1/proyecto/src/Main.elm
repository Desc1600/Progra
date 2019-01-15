module Main exposing (..)

import Canvas
import CanvasColor as Color exposing (Color)
import Html exposing (Html,div,button,text)
import Html.Attributes exposing (style)
import Html.Events exposing (onClick)
import Browser

type Fractalin = Sierpinsky| Koch | Limpiar

type alias Modelo = {dibufracta : Fractalin, n : Int}


modeloInicial : Modelo
modeloInicial = {dibufracta = Limpiar , n = 0}

type Mensaje = Dibuje Fractalin | Reps Int 


actualizador : Mensaje -> Modelo -> Modelo
actualizador mensaje modelo = case mensaje of 
    Dibuje a -> {dibufracta = a, n = 0}
    Reps a -> {dibufracta = modelo.dibufracta, n = if a == 1 
                                              then (modelo.n) + 1 
                                              else if a == 0 
                                              then (modelo.n)- 1 
                                              else modelo.n}

-- Las coordenadas de cada una de las esquinas del
-- poligono que se dibujara
fractal = [
    (300, 200),
    (400, 400),
    (200, 400)]

fractalp : List (Float, Float)
fractalp = [
    (300, 45),
    (500, 425),
    (100, 425),(300, 45),(300, 45)]

fractal2 : List (List (Float, Float))
fractal2 = [[
    (300, 200),
    (400, 400),
    (200, 400)]]
--sierpinsky

pm : (Float, Float) -> (Float, Float) -> (Float, Float)
pm x y = case (x,y) of
        ((x1 , y1),(x2, y2) ) ->  ((x1 + x2)/2, (y1 + y2)/2)

vuelta n = case n of
    x1::x2::x3::xs -> (pm x1 x2)::(pm x1 x3)::(pm x2 x3)::[]
    _ -> []

--trianguloizquierdo n = case n of 
   -- x1::x2::x3::xs -> x1::(pm x1 x2)::(pm x3 x1)::[]
   -- _ -> []

--trianguloderecho n = case n of 
   -- x1::x2::x3::xs -> x1::(pm x3 x1)::(pm x2 x3)::[]
    --_ -> []

--trianguloarriba n = case n of 
    --x1::x2::x3::xs -> x1::(pm x1 x2)::(pm x2 x3)::[]
   -- _ -> []

--recursion sn cont =  case (sn, cont) of 
       -- (0, []) -> []
       -- (0, x::xs) -> []
       -- (x , x::xs) -> (x::xs)::(vuelta())

--fase2 c x = 
    --if c == 0 then [] else 
        --case (x , vuelta x) of 
            --(x1::x2::x3::xxs , i1::i2::i3::iis) ->
             --   let
                  --  st1 = [x1 , i1 , i3 ]
                   -- st2 = [i1 , x2 , i2 ]
                  --  st3 = [i3 , i2 , x3 ]
               -- in
                --    [[(pm x1 x2),(pm x1 x3),(pm x3 x2)]] ++ fase2 (c-1) st1 ++ fase2 (c-1) st2 ++ fase2 (c-1) st3
           -- _ -> []

t3 : List (Float , Float) -> List (Float , Float)
t3 lm = case lm of 
    x1::x2::x3::xs -> x1::(pm x1 x2)::(pm x3 x1)::[]
    _ -> []

t4 : List (Float , Float) -> List (Float , Float)
t4 lm = case lm of 
    x1::x2::x3::xs -> x2::(pm x1 x2)::(pm x2 x3)::[]
    _ -> []

t5 : List (Float , Float) -> List (Float , Float)
t5 lm = case lm of 
    x1::x2::x3::xs -> x3::(pm x3 x1)::(pm x2 x3)::[]
    _ -> []

---fase : Int -> List (Float, Float) -> List(List (Float , Float))
--fase h n = case (h , n) of 
    ---(0 , []) -> []
   --(0 , x::xs) -> []
   -- (hs , x::xs) -> fase2(x , vuelta x)
  --  (_ , []) -> []

recu : Int -> List (Float, Float) -> List(List (Float , Float))
recu h n = case (h , n) of 
    (0 , []) -> []
    (0 , x::xs) -> []
    (hs , x::xs) -> (x::xs)::(vuelta (x::xs))::(recu (hs - 1)(t3(x::xs)))++(recu (hs - 1)(t4(x::xs)))++(recu (hs - 1)(t5(x::xs)))
    (_ , []) -> []

sierpinsky x = if x == 0 then fractal2 else recu x fractal 

--koch
p1 : (Float, Float) -> (Float, Float) -> (Float, Float)
p1 x y = case (x, y) of
    ((x1, y1), (x2, y2)) -> (((x1 + (1/2) * x2) / (1 + (1/2))), ((y1 + (1/2) * y2) / (1 + (1/2))))

p2 : (Float, Float) -> (Float, Float) -> (Float, Float)
p2 x y = case (x, y) of
    ((x1, y1), (x2, y2)) -> (((x1 + (2 * x2)) / (3)), ((y1 + (2 * y2)) / (3)))

pmx : (Float, Float) -> (Float, Float)
pmx x = case x of
    (x2, y2) -> (((x2 * (cos(degrees 60))) - y2 * (sin(degrees 60))), ((x2 * sin(degrees 60) + y2 * cos(degrees 60))))

rot x y = case (x, y) of
    ((x1, y1), (x2, y2)) -> ((x1 + x2), (y1 + y2))

rotar : (Float, Float) -> (Float, Float) -> (Float, Float)
rotar x y = case (x, y) of
    ((x1, y1), (x2, y2)) -> rot (pmx ((x1 - x2), (y1 - y2))) (x2, y2)

ttri lista = case lista of
    [] -> []
    x1::x2::xs -> x1::(p1 x1 x2)::(rotar (p1 x1 x2) (p2 x1 x2))::(p2 x1 x2)::(ttri (x2::xs))
    _ -> []

koch2 n lista = if n == 0 then lista else koch2 (n - 1) (ttri lista)

koch n = koch2 n fractalp

--Para que inicie vacio
inicial = []

dibujarTriangulo : List (List (Float, Float)) -> Canvas.Commands -> Canvas.Commands
dibujarTriangulo triangulo context = case triangulo of 
    [] -> context
    x::xs -> dibujar x (dibujarTriangulo xs context)

--fold : (b -> a -> b) -> b -> List a -> b
--fold acc base lista =  case lista of
      --  [] -> base
       -- x::xs -> acc (fold acc base xs) x



-- Dada una lista de coordenadas, esta funcion
-- genera los comandos necesarios para dibujar
-- las lineas que connectan dichas coordenadas

dibujar triangulo context =
    let
        acc (x,y) s = s |> Canvas.lineTo x y
    in
        case triangulo of
            (x0,y0)::xs ->
                List.foldl acc (Canvas.moveTo x0 y0 context) xs
                |> Canvas.lineTo x0 y0
            _ -> context


-- Funcion que genera el html que corresponde al
-- poligono siendo dibujado

vista : Modelo -> Html Mensaje
vista modelo = div[style "background" "#53918B"]
    [
    div [style "display" "flex", style "justify-content" "Center",style "align-items" "Center"]
    [button [onClick (Dibuje Sierpinsky),style "height" "90px" , style"width" "90px",style "background" "#01FFAA",style "color" "#000000",style "font-family" "Comic Sans Ms"] [text "SIERPINSKI"],
     button [onClick (Dibuje Koch),style "height" "90px" , style"width" "90px",style "background" "#21618C",style "color" "#FDFEFE",style "font-family" "Comic Sans Ms"] [text "KOCH"],
     button [onClick (Dibuje Limpiar),style "height" "90px" , style"width" "90px",style "background" "#A93226",style "color" "#FDFEFE",style "font-family" "Purisa"] [text "LIMPIAR"]
     ],

    div[style "display" "flex",style "justify-content" "center",style "align-items" "center"]
    [button [onClick (Reps (0)), style "height" "90px" , style"width" "90px",style "background" "#A93226",style "color" "#FDFEFE"] [Html.text "<---"],
    let
        width = 600
        height = 600
        poligono = if (modelo.dibufracta) == Koch
                   then dibujar (koch (modelo.n))
                   else if (modelo.dibufracta) == Sierpinsky
                   then dibujarTriangulo (sierpinsky (modelo.n))
                   else if (modelo.dibufracta) == Limpiar 
                   then dibujar inicial
                   else dibujar inicial
    in
        Canvas.element
            width
            height
            [style "border" "5px solid black",
             style "background" "#1DAB41"]
            (
                Canvas.empty
                |> Canvas.beginPath
                |> Canvas.clearRect 0 0 width height
                |> poligono
                |> Canvas.stroke
            )    
    ,button [onClick (Reps (1)),style "height" "90px" , style"width" "90px",style "background" "#23D300  ",style "color" "#000000"] [Html.text "--->"]
    ],div[style "color" "#000000",style "font-family" "Purisa"][text ("EN HONOR A NETOGALLO")]
    ]

main =
    Browser.sandbox
        { init = modeloInicial
        , view = vista
        , update = actualizador
        }