# Gra_tekstowa_projekt_zaliczeniowy_C
Gra tekstowa w języku C + link do schematu blokowego

Uzasadnienia dla zastosowania konretnych bibliotek:
#include <locale.h>//Gra korzysta z polskich znaków stąd zastosowanie tej biblioteki
#include <stdbool.h>//Program korzysta ze zmiennej bool w strukturze (która przetrzymuje dane gracza: umiejętności które posiada gracz, zasoby pozyskane przez gracza) bool jest użyty jako true/false dla umiejętności które posiada gracz
#include <windows.h>//Program został napisany na widowsie jako gra na windowsa stąd użycie biblioteki windows.h + program używa system("cls"); żeby zwiększyć czytelność tekstu w konsoli a funkcja ta działa tylko dla systemu windows


To jest link do aplikacji miro gdzie znajduje się schemat blokowy do wglądu nie umieściłem go wewnątrz pdf'a z powodu rozmiaru shcematu dla całego programu:
https://miro.com/app/board/uXjVLs5Pwgw=/?share_link_id=302396363174

W plikach w tym repozytorium umieściłem wersje kodu z kolorową składnią w pliku main C (ta wiersja nie posiada znaków polskich) oraz wersję z znakami polskimi bez kolorowej czcionki w pliku tektowym.
Zalecam uruchomienie gry w VS2022 (w tym ide projekt powstawał i był kompilowany). Polecam również skopiowanie kodu pliku tekstowego(zamiast main.c ponieważ posiaa on polskie znaki), skompilowanie i uruchomienie na komputerze z systemem windows.


