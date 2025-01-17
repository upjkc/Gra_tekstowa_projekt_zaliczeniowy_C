# Gra_tekstowa_projekt_zaliczeniowy_C
Projekt zaliczeniowy na przedmiot Technologie informacyjne, gra tekstowa w języku C.

Uzasadnienia dla zastosowania konkretnych bibliotek:

#include <locale.h> //Gra korzysta z polskich znaków, stąd zastosowanie tej biblioteki. Gra ma zmienne w języku angielskim, tekst wypisywany w konsoli jest w języku polskim.

#include <stdbool.h> //Program korzysta ze zmiennej bool w strukturze, która przetrzymuje dane gracza - umiejętności, które pozyskał gracz podczas rozgrywki (bool jest użyty jako true/false dla umiejętności, które posiada gracz).

#include <windows.h> //Program został napisany na Widows'ie jako gra na Windows, stąd użycie biblioteki windows.h. Dodatkowo program używa system ("cls"), żeby zwiększyć czytelność tekstu w konsoli, a funkcja ta działa tylko dla systemu Windows.



To jest link do aplikacji Miro, gdzie znajduje się schemat blokowy - do wglądu. Nie umieściłem go wewnątrz pdf'a z powodu rozmiaru shcematu dla całego programu:
https://miro.com/app/board/uXjVLs5Pwgw=/?share_link_id=302396363174

Zalecam z uwagi na zastosowane biblioteki kompilacje i uruchomienie programu na systemie Windows. Projekt został wykonany w IDE VS2022 w języku C. Pliki main.c i plik tekstowy zawierają kod do programu.
Kod w main.c ma kolorową czcionkę (składnia w pliku jest kolorowa).



Fabuła i zarys gry:
Gracz wciela się w postać Gęsi o imieniu Alfred. Zadaniem gracza jest zdobycie 20 worków karmy dla gęsi. W tym celu wyrusza do miasta, gdzie pożądany przedmiot można uzyskać na różne sposoby (transakcja, kradzież, kupno).
W mieście gracz musi odwiedzić wiele lokacji, żeby zdobyć potrzebne mu przedmioty, walutę i umiejętności do osiągnięcia celu gry.
Zdobycie 20 worków karmy i powrót do rodzinnego domu (gniazda) uznawany jest za wygraną (sposobów na wygraną jest więcej niż 1).
