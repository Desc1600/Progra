module Main exposing (..)

import Html exposing (Html, button, div, text)
import Html.Attributes exposing (style)
import Html.Events exposing (onClick)
import Browser
type alias Modelo = String
type alias Mensaje = String

modeloInicial : Modelo
modeloInicial = ""
actualizador : Mensaje -> Modelo -> Modelo
actualizador mensaje modelo = if mensaje == "C" then modeloInicial else modelo ++ mensaje

sumar x xs ys = 
    otro (String.toInt (String.fromChar x ++ String.reverse (String.fromList xs))) + otro (String.toInt (String.fromList ys))

multiplicacion x xs ys = 
    otro (String.toInt (String.fromChar x ++ String.reverse (String.fromList xs))) * otro (String.toInt (String.fromList ys))

otro : Maybe Int -> Int
otro n = case n of
    Just a -> a
    Nothing -> 0

respuestaAux vlist lista = case (vlist, lista) of
    (_, []) -> 0
    ([], x::xs) -> if x == '+' 
        then sumar '0' [] xs else if x == '*' then multiplicacion '0' [] xs else respuestaAux (x::[]) (xs)
    (x::xs, y::ys) -> if y == '+'
        then sumar x xs ys else if y == '*' then multiplicacion x xs ys else respuestaAux (x::y::xs) ys

respuesta modelo = respuestaAux [] (String.toList modelo)

pre mode = div [] [text (mode)]

vista : Modelo -> Html Mensaje
vista modelo = div [style "background" "#C0C0C0",
                    style "font-family" "Times New Roman", 
                    style "position" "absolute",
                    style "left" "500px"]
                   
        [pre modelo,
        div [style "height" "100px"] [        
        text (String.fromInt(respuesta  modelo))],       
        div [] [
        button [style "font-family" "Times New Roman",style "height" "100px",style"width" "100px",style "background" "#008080",style "color" "#FFFFFF",onClick "1"] [Html.text "1"],
        button [style "font-family" "Times New Roman",style "height" "100px",style"width" "100px",style "background" "#008080",style "color" "#FFFFFF",onClick "2"] [Html.text "2"],
        button [style "font-family" "Times New Roman",style "height" "100px",style"width" "100px",style "background" "#008080",style "color" "#FFFFFF",onClick "3"] [Html.text "3"],
        button [style "font-family" "Times New Roman",style "background" "#00FF00",style "color" "#FFFFFF",style "height" "100px",style"width" "60px",onClick "+"] [Html.text "+"],
        div [] [
        button [style "font-family" "Times New Roman",style "height" "100px",style"width" "100px",style "background" "#008080",style "color" "#FFFFFF",onClick "4"] [Html.text "4"],
        button [style "font-family" "Times New Roman",style "height" "100px",style"width" "100px",style "background" "#008080",style "color" "#FFFFFF",onClick "5"] [Html.text "5"],
        button [style "font-family" "Times New Roman",style "height" "100px",style"width" "100px",style "background" "#008080",style "color" "#FFFFFF",onClick "6"] [Html.text "6"],
        button [style "font-family" "Times New Roman",style "background" "#00FF00",style "color" "#FFFFFF",style "height" "100px",style"width" "60px",onClick "*"] [Html.text "*"],
        div [] [
        button [style "height" "100px",style"width" "100px",style "background" "#008080",style "color" "#FFFFFF",style "font-family" "Times New Roman",onClick "7"] [Html.text "7"],
        button [style "height" "100px",style"width" "100px",style "background" "#008080",style "color" "#FFFFFF",style "font-family" "Times New Roman",onClick "8"] [Html.text "8"],
        button [style "height" "100px",style"width" "100px",style "background" "#008080",style "color" "#FFFFFF",style "font-family" "Times New Roman",onClick "9"] [Html.text "9"],
        button [style "height" "100px",style"width" "60px",style "background" "#FF0000",style "color" "#FFFFFF",style "font-family" "Times New Roman",onClick "C"] [Html.text "C"],
        div [] [
        button [style "font-family" "Times New Roman",style "background" "#008080",style "color" "#FFFFFF",style "height" "100px" , style"width" "360px",onClick "0"] [Html.text "0"]
        ]]]]]

main =
    Browser.sandbox
        { init = modeloInicial
        , view = vista
        , update = actualizador
        }