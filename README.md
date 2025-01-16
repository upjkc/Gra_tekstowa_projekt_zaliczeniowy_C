# Gra_tekstowa_projekt_zaliczeniowy_C
Gra tekstowa w języku C + link do schematu blokowego

Uzasadnienia dla zastosowania konretnych bibliotek:
#include <locale.h> //Gra korzysta z polskich znaków stąd zastosowanie tej biblioteki. (gra ma zmienne w języku angielskim, tekst wypisywany w konsoli jest w języku polskim)
#include <stdbool.h> //Program korzysta ze zmiennej bool w strukturze (która przetrzymuje dane gracza: umiejętności które pozyskał gracz podczas rozgrywki) bool jest użyty jako true/false dla umiejętności które posiada gracz.
#include <windows.h> //Program został napisany na widowsie jako gra na windowsa stąd użycie biblioteki windows.h + program używa system("cls") żeby zwiększyć czytelność tekstu w konsoli a funkcja ta działa tylko dla systemu windows.


To jest link do aplikacji miro gdzie znajduje się schemat blokowy do wglądu nie umieściłem go wewnątrz pdf'a z powodu rozmiaru shcematu dla całego programu:
https://miro.com/app/board/uXjVLs5Pwgw=/?share_link_id=302396363174

Zalecam z uwagi na zastosowane biblioteki kompilacje i uruchomienie programu na systemie Windows. Projekt został wykonany w ide VS2022 w języku C. Pliki main.c i plik tektowy zawierają kod do programu.
Kod w main.c ma kolorową czcionkę (składnia w pliku jest kolorowa)



