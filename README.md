# Gra_tekstowa_projekt_zaliczeniowy_C
Projekt zaliczeniowy na przedmiot Technologie informacyjne, gra tekstowa w języku C.

Uzasadnienia dla zastosowania konretnych bibliotek:

#include <locale.h> //Gra korzysta z polskich znaków stąd zastosowanie tej biblioteki. (gra ma zmienne w języku angielskim, tekst wypisywany w konsoli jest w języku polskim)

#include <stdbool.h> //Program korzysta ze zmiennej bool w strukturze (która przetrzymuje dane gracza: umiejętności które pozyskał gracz podczas rozgrywki) bool jest użyty jako true/false dla umiejętności które posiada gracz.

#include <windows.h> //Program został napisany na widowsie jako gra na windowsa stąd użycie biblioteki windows.h + program używa system("cls") żeby zwiększyć czytelność tekstu w konsoli a funkcja ta działa tylko dla systemu windows.



To jest link do aplikacji miro gdzie znajduje się schemat blokowy do wglądu nie umieściłem go wewnątrz pdf'a z powodu rozmiaru shcematu dla całego programu:
https://miro.com/app/board/uXjVLs5Pwgw=/?share_link_id=302396363174

Zalecam z uwagi na zastosowane biblioteki kompilacje i uruchomienie programu na systemie Windows. Projekt został wykonany w ide VS2022 w języku C. Pliki main.c i plik tektowy zawierają kod do programu.
Kod w main.c ma kolorową czcionkę (składnia w pliku jest kolorowa)



Fabuła i zarys gry:
Gracz wciela się w postać Gęsi o imieniu Alfred. Zadaniem gracza jest zdobycie 20 worków karmy dla gęsi. W tym celu wyrusza do miasta gdzie, pożądany przedmiot można uzyskać na różne sposoby (tranzakcja, kradzież, kupno).
W miescie gracz musi odwiedzić wiele lokacji żeby zdobyć potrzebne mu przedmioty, walutę i umiejętności do osiągnięcia celu gry.
Zdobycie 20 worków karmy i powrót do rodzinnego domu (gniazda) uznawany jest za wygraną (sposobów na wygraną jest więcej niż 1)
