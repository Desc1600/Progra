module Main exposing (..)

import Browser
import Html exposing (Html)
import Html.Events exposing (onClick)

--String.fromInt convertir string a enteros
 
type alias Modelo = String

modeloInicial : Modelo
modeloInicial = "0"

type alias Mensaje = String

actualizador : Mensaje -> Modelo -> Modelo              
actualizador mensaje modelo =  modelo ++ mensaje


vista : Modelo -> Html Mensaje
vista modelo = Html.div
    []
    [
        Html.text (modelo),
        Html.button [onClick "0"] [Html.text "0"],
        Html.button [onClick "1"] [Html.text "1"],
        Html.button [onClick "2"] [Html.text "2"],
        Html.button [onClick "3"] [Html.text "3"],
        Html.button [onClick "4"] [Html.text "4"],
        Html.button [onClick "5"] [Html.text "5"],
        Html.button [onClick "6"] [Html.text "6"],
        Html.button [onClick "7"] [Html.text "7"],
        Html.button [onClick "8"] [Html.text "8"],
        Html.button [onClick "9"] [Html.text "9"]
        ]

main = Browser.sandbox {
        init = modeloInicial,
        view = vista,
        update = actualizador
    }