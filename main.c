


/*




Jednoręki Bandyta - by Jacek Puchałko

      ___________
     /___________\
     |  _______  | ({})
     |  |7|7|7|  |  ||
     |  ```````  |__||
     |:::::::::::|---'
     |  BIG WIN  |
     |:::::::::::|
     |___________|


      ___________
     /___________\
     |  _______  | ({})
     |  |7|7|7|  |  ||
     |  ```````  |__||
     |:::::::::::|---'
     |           |
     |:::::::::::|
     |___________|

 Gęś - by Jacek Puchałko
      ______
     /\     \
    /  |  @ >
   /___|__   )
         |  |
         |  |
         |  |
         |-- \ _________ _
        /     /         \  \__
       |               _/   _/
       \_      _____/     _/
         \_           ___/
           \___    __/
               \_|/
                ||
               _||
              >__/

   _____  .____   ________________________________________
  /  _  \ |    |  \_   _____/\______   \_   _____/\______ \
 /  /_\  \|    |   |    __)   |       _/|    __)_  |    |  \
/    |    \    |___|     \    |    |   \|        \ |    `   \
\____|__  /_______ \___  /    |____|_  /_______  //_______  /
        \/        \/   \/            \/        \/         \/
______________ ______________
\__    ___/   |   \_   _____/
  |    | /    ~    \    __)_
  |    | \    Y    /        \
  |____|  \___|_  /_______  /
                \/        \/
  ________ ________   ________    ____________________
 /  _____/ \_____  \  \_____  \  /   _____/\_   _____/
/   \  ___  /   |   \  /   |   \ \_____  \  |    __)_
\    \_\  \/    |    \/    |    \/        \ |        \
 \______  /\_______  /\_______  /_______  //_______  /
        \/         \/         \/        \/         \/


 Martwa Gęś robi szpagat - by Jacek Puchałko

       ______      _____ _________ _
      /\     \____/     /         \  \__
     /  |   X  ___                _/   _/
    /___|_____)  \_      _____/     _/
|^^________________\_           ___/________________^^|
|____________________\_________/______________________|


City -- art from https://www.asciiart.eu/buildings-and-places/cities
                                    +
                                   / \
 _____        _____     __________/ o \/\_________      _________
|o o o|_______|    |___|               | | # # #  |____|o o o o  | /\
|o o o|  * * *|: ::|. .|               |o| # # #  |. . |o o o o  |//\\
|o o o|* * *  |::  |. .| []  []  []  []|o| # # #  |. . |o o o o  |((|))
|o o o|**  ** |:  :|. .| []  []  []    |o| # # #  |. . |o o o o  |((|))
|_[]__|__[]___|_||_|__<|____________;;_|_|___/\___|_.|_|____[]___|  |



Racoon by Joan Stark - art from https://www.asciiart.eu/animals/cats

                 __        .-.
             .-"` .`'.    /\\|
     _(\-/)_" ,  .   ,\  /\\\/
    {(#b^d#)} .   ./,  |/\\\/
    `-.(Y).-`  ,  |  , |\.-`
         /~/,_/~~~\,__.-`
        ////~    // ~\\
      ==`==`   ==`   ==`
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>//Gra korzysta z polskich znaków stąd zastosowanie tej biblioteki
#include <ctype.h>
#include <stdbool.h>//Program korzysta ze zmiennej bool w strukturze (która przetrzymuje dane gracza: umiejętności które posiada gracz, zasoby pozyskane przez gracza) bool jest użyty jako true/false dla umiejętności które posiada gracz
#include <stdlib.h>
#include <time.h>
#include <windows.h>//Program został napisany na widowsie jako gra na windowsa stąd użycie biblioteki windows.h + program używa system("cls"); żeby zwiększyć czytelność tekstu w konsoli

typedef struct {
    char name[50];
    bool using_money_ability;
    //bool using_printer_ability;
    //bool inspired;
    int money;
    int goose_food;
    int junk_sphere;
    int garbage_can_lid;
    int rotten_carrot;
    int broken_light_bulb;
} Goose;

//Globalna zmienna alfred
Goose alfred = {
    "Alfred",               // Imię gęsi
    false,                  // Umiejętność korzystania z pieniędzy
    //false,                  // Umiejętność korzystania z drukarki
    //false,                  // Zainspirowanie gęsi
    0,                      // Ilość pieniędzy
    0,                      // Ilość worków karmy
    0,                      // Kula śmieci
    0,                      // Pokrywa od kubła na śmieci
    0,                      // przegniła marchewka
    0                       // Nie działająca żarówka
};

void start();
void way_to_the_city();
void way_threw_the_forest();
void city_menu();
void go_back_to_the_city();
void print_goose_info();
//void update_ability(bool using_money, bool using_printer, bool inspired);
void add_money(int amount);
void add_goose_food(int amount);
//void add_junk_part(int junk_sphere, int garbage_can_lid, int rotten_carrot, int broken_light_bulb);
void bank_menu();
void bank_worker();
void shop_menu();
void shopseller_fight();
void casino_menu();
void slot_machine();
void mini_Zoo_menu();
void work_in_the_mini_zoo();
void rubbish_dump_menu();
void go_back_to_home_ending();





char city_building_choice;
int casino_enters_counter = 0;

void print_goose_info() {
    printf("Gęś o imieniu %s:\n", alfred.name);
    printf("Umiejętności:\n");
    printf("  - Korzystanie z pieniędzy: %s\n", alfred.using_money_ability ? "Tak" : "Nie");
    printf("Pieniądze i Karma:\n");
    printf("  - Ilość pieniędzy: %d\n", alfred.money);
    printf("  - Ilość worków karmy: %d\n", alfred.goose_food);
    printf("Części śmieciowego bałwana:\n");
    printf("  - Kule śmieciowe: %d\n", alfred.junk_sphere);
    printf("  - Pokrywy od kubła na śmieci: %d\n", alfred.garbage_can_lid);
    printf("  - przegniłe marchewki: %d\n", alfred.rotten_carrot);
    printf("  - Nie działające żarówki: %d\n", alfred.broken_light_bulb);

    go_back_to_the_city();
}



//  0 - money_makeing 
void update_ability(int ability_to_update, bool new_value) {
    if (ability_to_update == 0) {
        alfred.using_money_ability = new_value;
    }

}

void add_money(int amount) {
    alfred.money += amount;
}

void add_goose_food(int amount) {
    alfred.goose_food += amount;
}

void add_junk_part(int item_to_update, int add_amount) {
    if (item_to_update == 0) {
        alfred.junk_sphere += add_amount;
    }
    else if (item_to_update == 1) {
        alfred.garbage_can_lid += add_amount;
    }
    else if (item_to_update == 2) {
        alfred.rotten_carrot += add_amount;
    }
    else if (item_to_update == 3) {
        alfred.broken_light_bulb += add_amount;
    }
}

void reset_players_stats() {
    alfred.broken_light_bulb = 0;
    alfred.garbage_can_lid = 0;
    alfred.goose_food = 0;
    //alfred.inspired = false;
    alfred.junk_sphere = 0;
    alfred.money = 0;
    alfred.rotten_carrot = 0;
    alfred.using_money_ability = false;
    //alfred.using_printer_ability = false;
}

void go_back_to_the_city() {
    do {
        char back_to_the_city[3]; 

        printf("Żeby powrócić do mapy miasta wpisz (m)\n");
        if (scanf("%2s", back_to_the_city) != 1) { 
            printf("Wystąpił błąd przy odczycie danych. Spróbuj jeszcze raz\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (strlen(back_to_the_city) == 1 && back_to_the_city[0] == 'm') {
            city_menu();
            break;
        }
        else {
            printf("Podałeś niepoprawną wartość. Spróbuj jeszcze raz\n");
            while (getchar() != '\n'); 
        }
    } while (1);
}


void go_back_to_home_ending() {
    while (1) {
        char last_choice[3];

        printf("Czy napewno chcesz użyć tej opcji?\n");
        printf("Jeżeli zawrócisz do domu bez potrzebnego jedzenia nie będziesz miał już więcej czasu żeby je zdobyć.\n");
        printf("Czy napewno chcesz zawrócić do domu?\n");
        printf("(t)tak\n(n)nie\n");

        if (scanf("%2s", last_choice) != 1) {
            printf("Wystąpił błąd przy odczycie danych. Spróbuj ponownie.\n");
            while (getchar() != '\n');
            continue;
        }

        if (strlen(last_choice) == 1 && (last_choice[0] == 't' || last_choice[0] == 'n')) {
            if (last_choice[0] == 't') {
                printf("Decyzja: Zawracasz do domu.\n");
                break;
            }
            else if (last_choice[0] == 'n') {
                printf("Decyzja: Wracasz do miasta.\n");
                go_back_to_the_city();
                break;
            }
        }
        else {
            printf("Nieprawidłowy wybór. Wprowadź tylko 't' lub 'n'.\n");
            while (getchar() != '\n');
        }
    }


    if (alfred.goose_food >= 20) {
        printf("\033[33mWygrałeś. Przyniosłeś rodzinie jedzenie, którego potrzebowali żeby przetrwać\n");
        printf("\n");
        printf("      ______\n");
        printf("     /%c     |\n", 92);
        printf("    /  |  @ >\n");
        printf("   /___|__   )\n");
        printf("         |  |\n");
        printf("         |  |\n");
        printf("         |  |\n");
        printf("         |-- %c _________ _\n", 92);
        printf("        /     /         %c  %c__   \n", 92, 92);
        printf("       |               _/   _/\n", 92);
        printf("       %c_      _____/     _/\n", 92, 92);
        printf("         %c_           ___/\n", 92, 92);
        printf("           %c___    __/\n", 92, 92);
        printf("               %c_|/\n", 92, 92);
        printf("                ||\n");
        printf("               _||\n");
        printf("              >__/ \n", 92);
        printf("Gratulacje Alfredzie\033[0m\n");
        Sleep(10000);
        exit(0);

        return 0;
    }
    else {
        printf("\033[31mPrzegrałeś. Nie przyniosłeś swojej rodzinie dostatecznej ilości Gęsiego jedzenia żeby przetrwali zimę\n");
        printf("       ______      _____ _________ _                   \n");
        printf("      /%c     %c____/     /         %c  %c__               \n", 92, 92, 92, 92);
        printf("     /  |   X  ___                _/   _/              \n");
        printf("    /___|_____)  %c_      _____/     _/                 \n", 92);
        printf("|^^________________%c_           ___/________________^^|\n", 92);
        printf("|____________________%c_________/______________________|\n\n\n", 92);
        printf("Przegrana\033[0m\n");
        while (1) {
            printf("Czy chcesz zagrać ponownie czy zakończyć rozgrywkę:\n");
            printf("(1) Zakończ rozgrywkę\n");
            printf("(2) Zagraj ponownie\n");

            int ending_choice;
            int result = scanf(" %d", &ending_choice);

            if (result != 1) {

                printf("Wprowadziłeś niepoprawną wartość. Spróbuj ponownie.\n");
                while (getchar() != '\n');
                continue;
            }

            if (ending_choice == 1) {
                system("cls");
                printf("END\n");
                Sleep(5000);
                exit(0);
                return 0;
            }
            else if (ending_choice == 2) {
                system("cls");
                reset_players_stats();
                casino_enters_counter = 0;
                start();
                break;
            }
            else {
                printf("Wprowadziłeś niepoprawną wartość. Spróbuj ponownie.\n");
            }
        }
    }

}

//-------------------------------------------------------------------Prolog i początek Gry-------------------------------------------------------------------------------------------------------------------/
void prologue() {
    printf("\n");
    printf("      ______\n");
    printf("     /%c     |\n", 92);
    printf("    /  |  @ >\n");
    printf("   /___|__   )\n");
    printf("         |  |\n");
    printf("         |  |\n");
    printf("         |  |\n");
    printf("         |-- %c _________ _\n", 92);
    printf("        /     /         %c  %c__   \n", 92, 92);
    printf("       |               _/   _/\n", 92);
    printf("       %c_      _____/     _/\n", 92, 92);
    printf("         %c_           ___/\n", 92, 92);
    printf("           %c___    __/\n", 92, 92);
    printf("               %c_|/\n", 92, 92);
    printf("                ||\n");
    printf("               _||\n");
    printf("              >__/ \n", 92);

    printf("   _____  .____   ________________________________________\n");
    printf("  /  _  %c |    |  %c_   _____/%c______   %c_   _____/%c______ %c\n", 92, 92, 92, 92, 92, 92);
    printf(" /  /_%c  %c|    |   |    __)   |       _/|    __)_  |    |  %c\n", 92, 92, 92);
    printf("/    |    %c    |___|     %c    |    |   %c|        %c |    `   %c\n", 92, 92, 92, 92, 92);
    printf("%c____|__  /_______ %c___  /    |____|_  /_______  //_______  /\n", 92, 92);
    printf("        %c/        %c/   %c/            %c/        %c/         %c/\n", 92, 92, 92, 92, 92, 92);
    printf("______________ ______________\n");
    printf("%c__    ___/   |   %c_   _____/\n", 92, 92, 92);
    printf("  |    | /    ~    %c    __)_\n", 92);
    printf("  |    | %c    Y    /        %c\n", 92, 92);
    printf("  |____|  %c___|_  /_______  /\n", 92);
    printf("                %c/        %c/\n", 92, 92);
    printf("  ________ ________   ________    ____________________\n");
    printf(" /  _____/ %c_____  %c  %c_____  %c  /   _____/%c_   _____/\n", 92, 92, 92, 92, 92, 92);
    printf("/   %c  ___  /   |   %c  /   |   %c %c_____  %c  |    __)_\n", 92, 92, 92, 92, 92);
    printf("%c    %c_%c  %c/    |    %c/    |    %c/        %c |        %c\n", 92, 92, 92, 92, 92, 92, 92, 92);
    printf(" %c______  /%c_______  /%c_______  /_______  //_______  /\n", 92, 92, 92);
    printf("        %c/         %c/         %c/        %c/         %c/\n", 92, 92, 92, 92, 92);

    printf("\n\n\nAby rozpocząć rozgrywkę wciśnij Enter...");
    getchar();

    system("cls");
    printf("Nazywasz się Albert. Jesteś gęsią, która żyje w swoim domu (gnieździe) na polanie wraz ze swoim młodszym rodzeństwem.\nZbliża się zima i musisz zadbać o to żebyś ty i twoje młodsze rodzeństwo mieli co jeść.\nW tym celu masz zamiar wyruszyć do miasta bo słyszałeś, że tam najłatwiej zdobyć pokarm\n");
    printf("Żeby twoja rodzina przetrwała zimę musisz uzbierać 20 worków karmy dla gęsi.\n");

    printf("\nAby kontynuować wciśnij Enter...\n");
    getchar();

}




void start() {
    char select_location[3];
    system("cls");
    printf("HONK!\n");
    do {
    printf("Wziąłeś ze sobą gęsi plecak i jesteś gotowy do drogi\n");
    printf("(m)Żeby wyruszyć do Miasta ludzką drogą\n");

        if (scanf("%2s", select_location) != 1) {
            system("cls");
            printf("Wystąpił błąd przy odczycie danych. Spróbuj jeszcze raz\n");
            while (getchar() != '\n');
            continue;
        }

        if (strlen(select_location) == 1 && select_location[0] == 'm') {
            way_to_the_city();
            break;
        }
        else {
            system("cls");
            printf("Wprowadzono niepoprawną wartość. Spróbuj ponownie.\n");
            while (getchar() != '\n');
        }
    } while (1);
}


void way_to_the_city() {
    system("cls");
    printf("Idąc drogą do miasta zauważasz na jej środku błyszczący przedmiot przypominający monetę\n");
    printf("Czy chcesz podejść i podnieść przedmiot, czy wolisz od razu iść dalej\n");
    printf("Wpisz:\n(tak) jeśli chcesz podnieść przedmiot\n(nie) jeśli chcesz go pominąć\n");

    while (1) {
        char risky_money_choice[10];

        if (scanf("%9s", risky_money_choice) != 1) {
            while (getchar() != '\n');
            system("cls");
            printf("Wprowadziłeś niepoprawną wartość, spróbuj jeszcze raz.\n");
            printf("Wpisz:\n(tak) jeśli chcesz podnieść przedmiot\n(nie) jeśli chcesz go pominąć\n");
            continue;
        }

        if (strcmp(risky_money_choice, "tak") == 0) {
            system("cls");
            int random_number = rand() % 100;

            if (random_number < 80) {
                add_money(5);
                printf("\033[33mPodniosłeś 5$ i ruszasz dalej do miasta\033[0m\n");
                printf("Kliknij Enter aby kontynuować...\n");
                while (getchar() != '\n');
                getchar();
                city_menu();
            }
            else {
                printf("\033[31mMiałeś pecha i potrącił cię tir\n");
                printf("       ______      _____ _________ _                   \n");
                printf("      /%c     %c____/     /         %c  %c__               \n", 92, 92, 92, 92);
                printf("     /  |   X  ___                _/   _/              \n");
                printf("    /___|_____)  %c_      _____/     _/                 \n", 92);
                printf("|^^________________%c_           ___/________________^^|\n", 92);
                printf("|____________________%c_________/______________________|\n\n\n", 92);
                printf("Przegrana\033[0m\n");

                while (1) {
                    printf("Czy chcesz zagrać ponownie czy zakończyć rozgrywkę:\n");
                    printf("(1) Zakończ rozgrywkę\n");
                    printf("(2) Zagraj ponownie\n");

                    int ending_choice;

                    if (scanf("%d", &ending_choice) != 1) {
                        printf("Wprowadziłeś niepoprawną wartość. Spróbuj ponownie.\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    if (ending_choice == 1) {
                        system("cls");
                        printf("END\n");
                        Sleep(5000);
                        exit(0);
                        return 0;
                    }
                    else if (ending_choice == 2) {
                        system("cls");
                        reset_players_stats();
                        casino_enters_counter = 0;
                        start();
                        break;
                    }
                    else {
                        printf("Wprowadziłeś niepoprawną wartość. Spróbuj ponownie.\n");
                    }
                }
            }
            break;
        }
        else if (strcmp(risky_money_choice, "nie") == 0) {
            system("cls");
            printf("Ruszyłeś w dalszą drogę do miasta\n");
            printf("Kliknij Enter aby kontynuować...\n");
            while (getchar() != '\n');
            getchar();
            city_menu();
            break;
        }
        else {
            system("cls");
            printf("Wprowadziłeś niepoprawną wartość spróbuj jeszcze raz\n");
            printf("Wpisz:\n(tak) jeśli chcesz podnieść przedmiot\n(nie) jeśli chcesz go pominąć\n");
        }
    }
}


//-------------------------------------------------------------------Prolog i początek Gry-------------------------------------------------------------------------------------------------------------------/

void show_credits() {
    printf("Gra stworzone przez: Jacek Puchałko\n");
    printf("ASCII art gęś, maszyna losująca: Jacek Puchałko\n");
    printf("ASCII arty zaporzyczone z na potrzeby projektu z www.asciiart.eu: \n");
    printf("  - ASCII art Szop: Joan Stark - art from https://www.asciiart.eu/animals/cats \n");
    printf("  - ASCII art Miasta: (Autor nie był podany na stronie) https://www.asciiart.eu/buildings-and-places/cities \n");
    printf("Wszelkie ASCII arty napisów zostały stworzone za pomocą generatora: https://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%%20Something%%20 \n\n");
    go_back_to_the_city();
}







//------------------------------------------------------------------------Main Menu--------------------------------------------------------------------------------------------------------------------------/

void city_menu() {
    system("cls");
    printf("Witaj w mieście\n");
    printf("                                    +					\n");
    printf("                                   / %c					\n", 92);
    printf(" _____        _____     __________/ o %c/%c_________      _________	\n", 92, 92);
    printf("|o o o|_______|    |___|               | | # # #  |____|o o o o  | /%c	\n", 92);
    printf("|o o o|  * * *|: ::|. .|               |o| # # #  |. . |o o o o  |//%c%c	\n", 92, 92);
    printf("|o o o|* * *  |::  |. .| []  []  []  []|o| # # #  |. . |o o o o  |((|))	\n");
    printf("|o o o|**  ** |:  :|. .| []  []  []    |o| # # #  |. . |o o o o  |((|))	\n");
    printf("|_[]__|__[]___|_||_|__<|____________;;_|_|___/%c___|_.|_|____[]___|  |	\n\n\n", 92);
    printf("W mieście jest wiele miejsc i budynków. Wybierz, który z nich chciałbyś odwiedzić:\n");
    printf("(b) Bank\n(s) Sklep\n(a) Kasyno\n(w) Wysypisko\n(m) Małe Zoo\n");
    printf("\nW tym miejscu możesz również wybrać:\n(i)Zajrzyj do ekwipunku\n(z)Zawróć do domu\n(c)Credits\n\n");



    printf("Wybierz miejsce: ");
    scanf(" %c", &city_building_choice);


    switch (city_building_choice) {
    case 'b':
        system("cls");
        bank_menu();
        break;
    case 's':
        system("cls");
        shop_menu();
        break;
    case 'a':
        system("cls");
        casino_menu();
        break;
    case 'w':
        system("cls");
        rubbish_dump_menu();
        break;
    case 'm':
        system("cls");
        mini_Zoo_menu();
        break;
    case 'i':
        system("cls");
        printf("Oto twój ekwipunek:\n");
        print_goose_info();
        break;
    case 'z':
        system("cls");
        go_back_to_home_ending();
        break;
    case 'c':
        system("cls");
        show_credits();
        break;
    default:
        printf("Nieprawidłowy wybór.\n");
        printf("\nNaciśnij Enter...");
        getchar();
        getchar();
        city_menu();
    }
}
//------------------------------------------------------------------------Main Menu--------------------------------------------------------------------------------------------------------------------------/

//------------------------------------------------------------------------Bank-------------------------------------------------------------------------------------------------------------------------------/
void bank_worker() {
    int conversation_choice;
    printf("\033[36mPracownica banku:  Dzień dobry w czym mogę pomóc?! Czy pan jest Gęsią?\033[0m\n(1) Tak\n(dowolna inna liczba) Nie\n");
    scanf("%d", &conversation_choice);

    if (conversation_choice == 1) {
        printf("\033[36mPracownica banku:  W takim razie w czym mogę pomóc?\033[0m\n(1) Zdobądź informacje o tym jak używać pieniędzy\n(dowolna inna liczba) Odejdź\n");
    }
    else {
        printf("\033[36mPracownica banku:  Przepraszam pana słabo widzę bez okularów. W takim razie w czym mogę pomóc?\033[0m\n(1) Zdobądź informacje o tym jak używać pieniędzy\n(dowolna inna liczba) Odejdź\n");
    }

    scanf("%d", &conversation_choice);
    if (conversation_choice == 1) {
        printf("\033[36mPracownica banku:  Pieniądz to powszechnie akceptowany środek wymiany i przechowywania wartości.\nPełni rolę uniwersalnego środka płatniczego w transakcjach handlowych.\nPieniądz ułatwia wymianę dóbr i usług oraz umożliwia dokonywanie pomiaru wartości.\033[0m\n");
        update_ability(0, true);
        printf("\033[33m\nBrawo Alfred dowiedział się czym są pieniądze i jak ich używać!\n\033[0m");
        printf("Wciśnij Enter żeby wrócić na hol główny banku\n");
        getchar();
        getchar();
        bank_menu();
    }
    else {
        bank_menu();
    }
}



void bank_menu() {
    system("cls");
    printf("Bank\n");
    printf("W banku widzisz pracowniczkę banku i szefa banku, który rozmawia z jednym ze swoich pracowników\n");
    printf("Wybierz co chcesz zrobić w banku:\n(1)Porozmawiaj z pracowniczką banku\n(2)Porozmawiaj z szefem banku\n(3)Wyjdź z banku\n");

    int bank_worker_choice;
    scanf("%d", &bank_worker_choice);

    if (bank_worker_choice == 1) {
        bank_worker();
    }
    else if (bank_worker_choice == 2) {
        printf("Szef banku jest w tej chwili zajęty i nie może z tobą porozmawiać.\n(dowolny znak, litera lub liczba a następnie Enter)żeby wrócić\n");
        getchar();
        getchar();
        bank_menu();
    }
    else if (bank_worker_choice == 3) {
        go_back_to_the_city();
    }
    else {
        printf("Wprowadzono niepoprawne dane.\nWciśnij dowolny przycisk żeby spróbować jeszcze raz\n");
        getchar();
        getchar();
        bank_menu();
    }
}


//------------------------------------------------------------------------Bank-------------------------------------------------------------------------------------------------------------------------------/


//------------------------------------------------------------------------Sklep------------------------------------------------------------------------------------------------------------------------------/


//------------------------------------------------------------------------Opcjonalna_Walka-----------------------------------------------------------/
int goose_hp = 30;
int sellers_hp = 40;

void npc_attack() {
    // Sprzedawca ma 50% szansy na trafienie za 10 HP
    if (rand() % 2 == 0) {
        printf("\033[31mSprzedawca atakuje miotłą! Straciłeś 10 HP!\033[0m\n");
        goose_hp -= 10;
    }
    else {
        printf("Sprzedawca nie trafił cię miotłą!\n");
    }
}

void player_peck() {
    // Gracz ma 100% szans na trafienie za 5hp
    printf("\033[32mDziobiesz Sprzedawcę za 5 HP!\033[0m\n");
    sellers_hp -= 5;
}

void player_scare_HONK() {
    if (rand() % 100 < 30) {  // 30% szansy na zastraszenie oponenta
        printf("\033[32mSprzedawca uciekł w strachu! Walka zakończona!\033[0m\n");
        sellers_hp = 0;  // Zmiana hp sprzedawcy na 0, żeby pętla przestała działać
    }
    else {
        printf("Próba zastraszenia nie powiodła się!\n");
    }
}

void display_hp() {
    printf("HP Alfred: %d | HP Sprzedawca: %d\n", goose_hp, sellers_hp);
}

void shopseller_fight() {
    system("cls");
    char fight_or_no_fight;
    printf("Czy na pewno chcesz zabrać karmę dla gęsi ze sklepu bez pozwolenia właściciela?\n(t)tak\n(dowolny znak, litera lub liczba a następnie Enter)nie\n");
    scanf(" %c", &fight_or_no_fight);

    if (fight_or_no_fight == 't') {
        printf("\033[31mKiedy próbowałeś wymknąć się z 20 workami karmy dla gęsi ze sklepu, twoje poczynania zauważył Sprzedawca.\nWziął miotłę i postanowił zapobiec kradzieży.\nStanął z tobą do pojedynku na śmierć i życie.\033[0m\n");

        char attack_move_choice;
        int round = 1;

        while (goose_hp > 0 && sellers_hp > 0) {
            printf("\nRunda %d:\n", round);
            display_hp();

            // Tura gracza, wybór akcji
            printf("Wybierz akcję:\n");
            printf("(a) Dziobanie (5 obrażeń)\n");
            printf("(b) HONK! (30%c szans na zastraszenie oponenta)\n", 37);
            scanf(" %c", &attack_move_choice);

            if (attack_move_choice == 'a') {
                player_peck();
            }
            else if (attack_move_choice == 'b') {
                player_scare_HONK();
            }
            else {
                printf("Niepoprawny wybór. Spróbuj ponownie.\n");
                continue;
            }

            // Sprawdzenie, czy walka zakończyła się po akcji gracza
            if (sellers_hp <= 0) {
                printf("Pokonałeś Sprzedawcę!\n");
                printf("\033[33mUciekasz ze sklepu z łupem\033[0m\n");
                add_goose_food(20);
                printf("Naciśnij Enter, aby wyjść ze sklepu...\n");
                getchar();
                getchar();
                city_menu();


                break;
            }
            else if (goose_hp <= 0) {
                while (1) {
                    printf("\033[31m       ______      _____ _________ _                   \n");
                    printf("      /%c     %c____/     /         %c  %c__               \n", 92, 92, 92, 92);
                    printf("     /  |   X  ___                _/   _/              \n");
                    printf("    /___|_____)  %c_      _____/     _/                 \n", 92);
                    printf("|^^________________%c_           ___/________________^^|\n", 92);
                    printf("|____________________%c_________/______________________|\n\n\n", 92);
                    printf("Zostałeś pokonany przez Sprzedawcę!\n");
                    printf("Przez to nie wróciłeś do swojej gęsiej rodziny i twoje dzieci umarły z powodu zimna i głodu.\033[0m\n");
                    printf("Czy chcesz zagrać ponownie czy zakończyć rozgrywkę:\n");
                    printf("(1) Zakończ rozgrywkę\n");
                    printf("(2) Zagraj ponownie\n");

                    int ending_choice;
                    int result = scanf(" %d", &ending_choice);

                    if (result != 1) {

                        printf("Wprowadziłeś niepoprawną wartość. Spróbuj ponownie.\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    if (ending_choice == 1) {
                        system("cls");
                        printf("END\n");
                        Sleep(5000);
                        exit(0);
                        return 0;
                    }
                    else if (ending_choice == 2) {
                        system("cls");
                        reset_players_stats();
                        casino_enters_counter = 0;
                        start();
                        break;
                    }
                    else {
                        printf("Wprowadziłeś niepoprawną wartość. Spróbuj ponownie.\n");
                    }
                }
            }

            // Tura Sprzedawcy, atakuje gracza
            npc_attack();  // Sprzedawca atakuje gracza

            // Sprawdzenie, czy walka zakończyła się po ataku Sprzedawcy
            if (sellers_hp <= 0) {
                printf("Pokonałeś Sprzedawcę!\n");
                printf("\033[33mUciekasz ze sklepu z łupem\033[0m\n");
                add_goose_food(20);
                printf("Naciśnij Enter, aby wyjść ze sklepu...\n");
                getchar();
                getchar();
                city_menu();


                break;
            }
            else if (goose_hp <= 0) {
                while (1) {
                    printf("\033[31m       ______      _____ _________ _                   \n");
                    printf("      /%c     %c____/     /         %c  %c__               \n", 92, 92, 92, 92);
                    printf("     /  |   X  ___                _/   _/              \n");
                    printf("    /___|_____)  %c_      _____/     _/                 \n", 92);
                    printf("|^^________________%c_           ___/________________^^|\n", 92);
                    printf("|____________________%c_________/______________________|\n\n\n", 92);
                    printf("Zostałeś pokonany przez Sprzedawcę!\n");
                    printf("Przez to nie wróciłeś do swojej gęsiej rodziny i twoje dzieci umarły z powodu zimna i głodu.\033[0m\n");
                    printf("Czy chcesz zagrać ponownie czy zakończyć rozgrywkę:\n");
                    printf("(1) Zakończ rozgrywkę\n");
                    printf("(2) Zagraj ponownie\n");

                    int ending_choice;
                    int result = scanf(" %d", &ending_choice);

                    if (result != 1) {

                        printf("Wprowadziłeś niepoprawną wartość. Spróbuj ponownie.\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    if (ending_choice == 1) {
                        system("cls");
                        printf("END\n");
                        Sleep(5000);
                        exit(0);
                        return 0;
                    }
                    else if (ending_choice == 2) {
                        system("cls");
                        reset_players_stats();
                        casino_enters_counter = 0;
                        start();
                        break;
                    }
                    else {
                        printf("Wprowadziłeś niepoprawną wartość. Spróbuj ponownie.\n");
                    }
                }
            }

            round++;
        }
    }
    else {
        printf("Naciśnij Enter, aby wyjść ze sklepu...\n");
        getchar();
        getchar();
        city_menu();
    }
}
//------------------------------------------------------------------------Opcjonalna_Walka-----------------------------------------------------------/



//------------------------------------------------------------------------Zakupy---------------------------------------------------------------------/
void shop_menu() {
    char shop_choice;
    char shop_choice_2;
    int quantity_of_goose_food_bags;
    system("cls");
    printf("Wszedłeś do Sklepu. W powietrzu udało ci się wyczuć woń karmy dla gęsi. Widzisz Sprzedawcę co robisz?\n");
    printf("(a)Podejdz do sprzedawcy\n(b)spróbuj okraść sklep\n(dowolny znak, litera lub liczba a następnie Enter) Wyjdź ze sklepu\n");
    scanf(" %c", &shop_choice);

    if ((shop_choice == 'a') && (alfred.using_money_ability == true)) {
        printf("\n\033[34mSprzedawca: Dzień dobry w czym mogę pomóc\033[0m\n");
        printf("Alfred: Potrzebuje Gęsiej karmy HONK!\n");
        printf("\033[34mSprzedawca: Jedna torba gęsiej karmy kosztuje 10$\033[0m\n");
        printf("Alfred: ILE? HONK?!\n");
        printf("(1)Jeśli chcesz kontynuować konwersację wciśnij\n(2)jeżeli chcesz wyjść ze sklepu)\n");
        scanf(" %c", &shop_choice_2);

        if ((shop_choice_2 == '1') && (alfred.money >= 10) && (alfred.using_money_ability == true)) {
            do {
                printf("\033[34mSprzedawca: Ile chce pan kupić worków?\033[0m\n");
                printf("Ile obecnie masz pieniędzy = %d\n", alfred.money);

                if ((scanf("%d", &quantity_of_goose_food_bags) == 1)) {
                    if (quantity_of_goose_food_bags <= 0) {
                        printf("Nie możesz kupić '%d' worków. Wprowadź liczbę większą od zera.\n", quantity_of_goose_food_bags);
                        continue; // Powrót do początku pętli
                    }

                    if ((quantity_of_goose_food_bags * 10) <= alfred.money) {
                        printf("\033[34mSprzedawca: Oto pana zakupy: \033[33m'%d'\033[34m worków z gęsią karmą.\033[0m\n", quantity_of_goose_food_bags);

                        add_goose_food(quantity_of_goose_food_bags);
                        add_money(-(quantity_of_goose_food_bags * 10));

                        printf("Naciśnij Enter, aby kontynuować...\n");
                        getchar();
                        getchar();
                        shop_menu();
                        break;
                    }
                    else {
                        printf("Nie masz wystarczająco dużo pieniędzy na zakup '%d' worków z gęsią karmą.\n", quantity_of_goose_food_bags);
                    }
                }
                else {
                    printf("Podałeś wartość, która nie jest numerem. Ponów próbę wprowadzenia wartości.\n");
                    while (getchar() != '\n');
                }
            } while (1);
        }
        else if ((shop_choice_2 == '1') && (alfred.money < 10) && (alfred.using_money_ability == true)) {
            printf("Nie masz wystarczająco dużo pieniędzy żeby kupić gęsią karmę\n");
            printf("Naciśnij Enter, aby kontynuować...\n");
            getchar();
            getchar();
            shop_menu();
        }
        else if ((shop_choice_2 == '1') && (alfred.using_money_ability == false)) {
            printf("Nie wiesz jak działają pieniądze więc nie możesz nic kupić.\nDowiedz się jak działają pieniądze\n");
            printf("Naciśnij Enter, aby kontynuować...\n");
            getchar();
            getchar();
            shop_menu();
        }
        else if (shop_choice_2 == '2') {
            go_back_to_the_city();
        }
        else {
            printf("Podałeś niewłaściwą Daną");
            printf("Naciśnij Enter, aby kontynuować...\n");
            getchar();
            getchar();
            shop_menu();
        }
    }
    else if ((shop_choice == 'a') && (alfred.using_money_ability == false)) {
        printf("Nie wiesz jak działają pieniądze więc nie możesz nic kupić.\nDowiedz się jak działają pieniądze\n");
        printf("Naciśnij Enter, aby kontynuować...\n");
        getchar();
        getchar();
        shop_menu();
    }
    else if (shop_choice == 'b') {
        shopseller_fight();
    }
    else {
        go_back_to_the_city();
    }
}
//------------------------------------------------------------------------Zakupy---------------------------------------------------------------------/



//------------------------------------------------------------------------Sklep------------------------------------------------------------------------------------------------------------------------------/


//------------------------------------------------------------------------Kasyno-----------------------------------------------------------------------------------------------------------------------------/



void slot_machine() {
    while (1) {
        system("cls");
        printf("Żeby zagrać musisz wrzucić 2$ do maszyny\n");
        printf("czy chcesz zagrać?\n(t)tak\n(n)nie\n");

        char slot_machine_choice_1;

        scanf(" %c", &slot_machine_choice_1);

        if ((slot_machine_choice_1 == 't') && (alfred.money >= 2)) {

            int random_number_1;
            int random_number_2;
            int random_number_3;

            system("cls");
            add_money(-2);

            random_number_1 = rand() % 7 + 1;
            random_number_2 = rand() % 7 + 1;
            random_number_3 = rand() % 7 + 1;

            if ((random_number_1 == random_number_2) && (random_number_2 == random_number_3)) {
                char try_spinning_again_or_no;
                printf("\033[33mMaszyna do gry (jednoręki bandyta)\n\n");
                printf("      ___________      \n");
                printf("     /___________%c     \n", 92);
                printf("     |  _______  | ({})\n");
                printf("     |  |%d|%d|%d|  |  || \n", random_number_1, random_number_2, random_number_3);
                printf("     |  ```````  |__|| \n");
                printf("     |:::::::::::|---' \n");
                printf("     |  BIG WIN  |     \n");
                printf("     |:::::::::::|     \n");
                printf("     |___________|     \n\n");
                printf(" _______   ______   ______         __       __  ______  __    __ \n");
                printf("/       %c /      | /      %c       /  |  _  /  |/      |/  %c  /  |\n", 92, 92, 92);
                printf("$$$$$$$  |$$$$$$/ /$$$$$$  |      $$ | / %c $$ |$$$$$$/ $$  %c $$ |\n", 92, 92);
                printf("$$ |__$$ |  $$ |  $$ | _$$/       $$ |/$  %c$$ |  $$ |  $$$  %c$$ |\n", 92, 92);
                printf("$$    $$<   $$ |  $$ |/    |      $$ /$$$  $$ |  $$ |  $$$$  $$ |\n");
                printf("$$$$$$$  |  $$ |  $$ |$$$$ |      $$ $$/$$ $$ |  $$ |  $$ $$ $$ |\n");
                printf("$$ |__$$ | _$$ |_ $$ %c__$$ |      $$$$/  $$$$ | _$$ |_ $$ |$$$$ |\n", 92);
                printf("$$    $$/ / $$   |$$    $$/       $$$/    $$$ |/ $$   |$$ | $$$ |\n");
                printf("$$$$$$$/  $$$$$$/  $$$$$$/        $$/      $$/ $$$$$$/ $$/   $$/ \n\033[0m");
                printf("\nczy chcesz zagrać jeszcze raz?\n(t)tak\n(n)nie\n");

                scanf(" %c", &try_spinning_again_or_no);

                if (try_spinning_again_or_no == 't') {
                    printf("\033[31m _______   ______   ______         __         ______    ______   ________ \n");
                    printf("/       %c /      | /      %c       /  |       /      %c  /      %c /        |\n", 92, 92, 92, 92);
                    printf("0000000  |000000/ /000000  |      00 |      /000000  |/000000  |00000000/ \n");
                    printf("00 |__00 |  00 |  00 | _00/       00 |      00 |  00 |00 %c__00/ 00 |__    \n", 92);
                    printf("00    00<   00 |  00 |/    |      00 |      00 |  00 |00      %c 00    |   \n", 92);
                    printf("0000000  |  00 |  00 |0000 |      00 |      00 |  00 | 000000  |00000/    \n");
                    printf("00 |__00 | _00 |_ 00 %c__00 |      00 |_____ 00 %c__00 |/  %c__00 |00 |_____ \n", 92, 92, 92);
                    printf("00    00/ / 00   |00    00/       00       |00    00/ 00    00/ 00       |\n");
                    printf("0000000/  000000/  000000/        00000000/  000000/   000000/  00000000/ \n");
                    printf("\nUzależniłeś się od hazardu i straciłeś wszyckie pieniądze.\nPrzez swoje uzależnienie nie wróciłeś do swojej rodziny i wszyscy umarli przez zagłodzenie\033[0m\n");

                    while (1) {
                        printf("Czy chcesz zagrać ponownie czy zakończyć rozgrywkę:\n");
                        printf("(1) Zakończ rozgrywkę\n");
                        printf("(2) Zagraj ponownie\n");

                        int ending_choice;
                        printf("Twój wybór: ");
                        int result = scanf(" %d", &ending_choice);

                        if (result != 1) {

                            printf("Wprowadziłeś niepoprawną wartość. Spróbuj ponownie.\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        if (ending_choice == 1) {
                            system("cls");
                            printf("END\n");
                            Sleep(5000);
                            exit(0);
                            return 0;
                        }
                        else if (ending_choice == 2) {
                            system("cls");
                            reset_players_stats();
                            casino_enters_counter = 0;
                            start();
                            break;
                        }
                        else {
                            printf("Wprowadziłeś niepoprawną wartość. Spróbuj ponownie.\n");
                        }
                    }

                }
                else if (try_spinning_again_or_no == 'n') {
                    system("cls");
                    printf("\033[33m _______   ______   ______         __       __  ______  __    __ \n");
                    printf("/       %c /      | /      %c       /  |  _  /  |/      |/  %c  /  |\n", 92, 92, 92);
                    printf("$$$$$$$  |$$$$$$/ /$$$$$$  |      $$ | / %c $$ |$$$$$$/ $$  %c $$ |\n", 92, 92);
                    printf("$$ |__$$ |  $$ |  $$ | _$$/       $$ |/$  %c$$ |  $$ |  $$$  %c$$ |\n", 92, 92);
                    printf("$$    $$<   $$ |  $$ |/    |      $$ /$$$  $$ |  $$ |  $$$$  $$ |\n");
                    printf("$$$$$$$  |  $$ |  $$ |$$$$ |      $$ $$/$$ $$ |  $$ |  $$ $$ $$ |\n");
                    printf("$$ |__$$ | _$$ |_ $$ %c__$$ |      $$$$/  $$$$ | _$$ |_ $$ |$$$$ |\n", 92);
                    printf("$$    $$/ / $$   |$$    $$/       $$$/    $$$ |/ $$   |$$ | $$$ |\n");
                    printf("$$$$$$$/  $$$$$$/  $$$$$$/        $$/      $$/ $$$$$$/ $$/   $$/ \n");

                    printf("\nGratulacje wygrałeś.\nDzięki temu, że zdobyłeś tyle pieniędzy, twoja rodzina nie będzie głodna przez najbliższe kilka lat.\nTa zima będzie dla was łagodna i będziecie cieszyć się dostatnim życiem\n\n\n");
                    printf("\n");
                    printf("      ______\n");
                    printf("     /%c     |\n", 92);
                    printf("    /  |  @ >\n");
                    printf("   /___|__   )\n");
                    printf("         |  |\n");
                    printf("         |  |\n");
                    printf("         |  |\n");
                    printf("         |-- %c _________ _\n", 92);
                    printf("        /     /         %c  %c__   \n", 92, 92);
                    printf("       |               _/   _/\n", 92);
                    printf("       %c_      _____/     _/\n", 92, 92);
                    printf("         %c_           ___/\n", 92, 92);
                    printf("           %c___    __/\n", 92, 92);
                    printf("               %c_|/\n", 92, 92);
                    printf("                ||\n");
                    printf("               _||\n");
                    printf("              >__/ \n", 92);
                    printf("Gratulacje Alfredzie\033[0m\n");
                    Sleep(10000);
                    exit(0);

                    return 0;
                }

            }
            else {
                char try_spinning_again_or_no;
                printf("Maszyna do gry (jednoręki bandyta)\n\n");
                printf("      ___________      \n");
                printf("     /___________%c     \n", 92);
                printf("     |  _______  | ({})\n");
                printf("     |  |%d|%d|%d|  |  || \n", random_number_1, random_number_2, random_number_3);
                printf("     |  ```````  |__|| \n");
                printf("     |:::::::::::|---' \n");
                printf("     |           |     \n");
                printf("     |:::::::::::|     \n");
                printf("     |___________|     \n\n");
                printf("Niczego nie wygrałeś\n");
                printf("\nczy chcesz zagrać jeszcze raz?\n(t)tak\n(n)nie\n");
                scanf(" %c", &try_spinning_again_or_no);
                if (try_spinning_again_or_no == 't') {
                    slot_machine();
                }
                else if (try_spinning_again_or_no == 'n') {
                    go_back_to_the_city();
                }

            }
            break;
        }
        else if ((slot_machine_choice_1 == 't') && (alfred.money < 2)) {
            printf("nie masz wystarczająco dużo pieniędzy żeby zagrać\n");
            go_back_to_the_city();
            break;
        }
        else if (slot_machine_choice_1 == 'n') {
            go_back_to_the_city();
            break;
        }
        else {
            system("cls");
            printf("wprowadziłeś niepoprawną daną\n");
            printf("Naciśnij Enter, aby kontynuować...\n");
            getchar();
            getchar();
        }
    }
}








void casino_menu() {
    char casino_choice_1;
    system("cls");
    printf("Wszedłeś do Kasyna. Masz wrażenie, że to miejsce jest wypełniane negatywnymi emocjami i rozgoryczeniem.\nWidzisz ludzi, którzy siedzą przed maszynami i wykonują w kółko jedną czynność.\nRaz wydają się podekscytowani, a zaraz potem smutni.\n\n\n");

    if (casino_enters_counter == 0) {
        while (1) {
            char casino_choice_first_time;
            printf("\033[35mPracownik kasyna: Dzień dobry. Witaj w kasynie 'El Goose de la gazpacho'. W czym mogę pomóc? Jakaś maszyna nie działa?\033[0m\n\n");
            printf("Alfred: Szukam sposobu, żeby pozyskać gęsią karmę. Dokładniej 20 worków gęsiej karmy.\n\n");
            printf("\033[35mPracownik kasyna: Jeżeli zagra pan u nas w jednorękiego bandytę, ma pan szanse na wygranie ogromnej puli pieniędzy, dzięki której będzie pan mógł kupić tyle gęsiej karmy, ile pan zechce.\033[0m\n");
            printf("\033[35mŻeby wygrać w tej grze wysztkie 3 wylosowane przez maszynę liczby muszą być jednakowe, każdy inny wynik będzie uznawany za przegraną.\033[0m\n\n");
            printf("\n\033[35mPracownik kasyna: Czy chce pan spróbować zagrać?\033[0m\n(t)tak\n(n)nie\n");
            scanf(" %c", &casino_choice_first_time);

            if (casino_choice_first_time == 't') {
                printf("Pracownik kasyna: Wspaniale!\n");
                break;
            }
            else if (casino_choice_first_time == 'n') {
                casino_enters_counter += 1;
                go_back_to_the_city();
                return;
            }
            else {
                system("cls");
                printf("Wprowadziłeś niepoprawną wartość.\n");
                continue;
            }
        }
        casino_enters_counter += 1;
    }

    while (1) {
        printf("czy chcesz podejść do stanowiska do gry w jednorękiego bandytę?\n(t)tak\n(n)nie\n");
        scanf(" %c", &casino_choice_1);
        if ((casino_choice_1 == 't') && (alfred.using_money_ability == true)) {
            casino_enters_counter += 1;
            slot_machine();

            break;
        }
        else if ((casino_choice_1 == 't') && (alfred.using_money_ability == false)) {
            printf("Nie wiesz jak działają pieniądze więc nie możesz zagrać w kasynie.\nDowiedz się jak działają pieniądze\n");
            go_back_to_the_city();
        }
        else if (casino_choice_1 == 'n') {
            casino_enters_counter += 1;
            go_back_to_the_city();
            return;
        }
        else {
            system("cls");
            printf("Wprowadziłeś niepoprawną wartość.\n");
            continue;
        }
    }
}
//------------------------------------------------------------------------Kasyno-----------------------------------------------------------------------------------------------------------------------------/

//------------------------------------------------------------------------Mini Zoo---------------------------------------------------------------------------------------------------------------------------/
void work_in_the_mini_zoo() {
    system("cls");
    int paycheck = 0;
    char zoo_work_choice_1;
    char zoo_work_choice_2;
    char zoo_work_choice_3;
    char zoo_work_choice_4;

    while (1) {
        system("cls");
        printf("Rozpoczęcie godziny pracy\n");
        printf("Problem 1\nDziecko próbuje złapać cię za skrzydło. Co robisz?\n");
        printf("(1)Uciekasz\n(2)Uderzasz je lekko skrzydłem\n");
        scanf(" %c", &zoo_work_choice_1);

        if (zoo_work_choice_1 == '1') {
            printf("Udało ci się uciec.\n");
            paycheck += 5;
            break;
        }
        else if (zoo_work_choice_1 == '2') {
            printf("Dziecko zaczęło płakać, szef potrąci ci z wypłaty.\n");
            break;
        }
        else {
            printf("Wprowadziłeś niepoprawną wartość, spróbuj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
            continue;
        }
    }

    while (1) {
        system("cls");
        printf("Problem 2\nDziecko chce cię dokarmić\n");
        printf("(1)Zjedz jedzenie, które dało ci dziecko\n(2)Odejdź\n");
        scanf(" %c", &zoo_work_choice_2);

        if (zoo_work_choice_2 == '1') {
            printf("Jedzenie nie było gęsią karmą, ale o dziwo ci nie zaszkodziło\n");
            paycheck += 20;
            break;
        }
        else if (zoo_work_choice_2 == '2') {
            printf("Dziecko przyszło na skargę do szefa, a ten potrącił ci z wypłaty.\n");
            break;
        }
        else {
            printf("Wprowadziłeś niepoprawną wartość, spróbuj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
            continue;
        }
    }

    while (1) {
        system("cls");
        printf("Problem 3\nDziecko zmierza w twoją stronę i chce cię pogłaskać\n");
        printf("(1)Ucieknij\n(2)Ukryj się\n");
        scanf(" %c", &zoo_work_choice_3);

        if (zoo_work_choice_3 == '1') {
            printf("Uciekłeś w popłochu, niestety zauważył to twój szef.\n");
            break;
        }
        else if (zoo_work_choice_3 == '2') {
            printf("Dziecko cię nie znalazło i poszło pogłaskać osła obok twojej kryjówki.\n");
            paycheck += 10;
            break;
        }
        else {
            printf("Wprowadziłeś niepoprawną wartość, spróbuj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
            continue;
        }
    }

    while (1) {
        system("cls");
        printf("Problem 4\nDziecko rzuciło w ciebie kamieniem. Na szczęście nie trafiło\n");
        printf("(1)HONK!\n(2)Podziób\n");
        scanf(" %c", &zoo_work_choice_4);

        if (zoo_work_choice_4 == '1') {
            printf("Wystraszyłeś dziecko, ale pracodawca zrozumiał, że to była samoobrona, więc nie potrącił ci z wypłaty.\n");
            paycheck += 5;
            break;
        }
        else if (zoo_work_choice_4 == '2') {
            printf("Zadrapałeś dziobem dziecko, ale pracodawca mimo wszystko potrącił ci z wypłaty.\n");
            break;
        }
        else {
            printf("Wprowadziłeś niepoprawną wartość, spróbuj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
        }
    }

    printf("\033[33mZa przepracowaną godzinę dostałeś zapłatę w wysokości %d$\033[0m\n", paycheck);
    add_money(paycheck);
    go_back_to_the_city();
}

bool game_running = true;

void mini_Zoo_menu() {
    bool exit_flag = false; 

    while (!exit_flag && game_running) {  
        char mini_zoo_choice_1;
        char mini_zoo_choice_2;

        system("cls"); 
        printf("Małe Zoo\n");
        printf("\033[92mSzef małego Zoo: Witaj w małym zoo. Czemu tu się zjawiłeś? Nie przypominam sobie, żebyśmy hodowali gęsi.\033[0m\n");
        printf("Alfred: Widzi pan, potrzebuję...\n");
        printf("(k)karmy\n(n)nie potrzebuje niczego\n");
        scanf(" %c", &mini_zoo_choice_1);
        getchar();

        if (mini_zoo_choice_1 == 'k') {
            printf("\033[92mSzef małego Zoo: Skoro potrzebuje pan karmy, mogę zaoferować panu pracę na najbliższą godzinę. Będzie pan zabawiał u nas dzieci, a w zamian otrzyma pan pieniądze za, które może pan kupić karmę.\033[0m\n");
            printf("Alfred: Czyli dostanę karmę? Czy tylko pieniądze?\n");
            printf("\033[92mSzef małego Zoo: Dostanie pan walutę, za którą będzie pan mógł kupić karmę.\033[0m\n");

            while (1) {
                printf("\033[92mSzef małego Zoo: To jak. Chce pan u nas pracować?\033[0m\n");
                printf("(t)tak\n(n)nie\n");
                scanf(" %c", &mini_zoo_choice_2);
                getchar();

                if (mini_zoo_choice_2 == 't') {
                    work_in_the_mini_zoo();
                    break; 
                }
                else if (mini_zoo_choice_2 == 'n') {
                    go_back_to_the_city();
                    exit_flag = true;  
                    break;
                }
                else {
                    system("cls");
                    printf("Wprowadziłeś niepoprawną wartość. Spróbuj jeszcze raz.\n");
                    printf("Kliknij Enter...\n");
                    getchar();  
                }
            }
        }
        else if (mini_zoo_choice_1 == 'n') {
            go_back_to_the_city();
            exit_flag = true;  
        }
        else {
            system("cls");
            printf("Wprowadziłeś niepoprawną wartość. Spróbuj jeszcze raz.\n");
            printf("Kliknij Enter...\n");
            getchar();  
        }
    }
}


//------------------------------------------------------------------------Mini Zoo---------------------------------------------------------------------------------------------------------------------------/

//------------------------------------------------------------------------Wysypisko--------------------------------------------------------------------------------------------------------------------------/
void search_in_trash() {
    char go_again_or_stop[10];
    int keep_searching = 1;

    while (keep_searching) {
        int random = rand() % 100;

        if (random < 40) {
            add_junk_part(0, 1);
            printf("\033[33mZnalazłeś Kule śmieci\033[0m\n");
        }
        else if (random < 80) {
            add_junk_part(1, 1);
            printf("\033[33mZnalazłeś Pokrywe od kubła na śmieci\033[0m\n");
        }
        else if (random < 90) {
            add_junk_part(2, 1);
            printf("\033[33mZnalazłeś zgniłą marchewkę \033[0m\n");
        }
        else if (random < 95) {
            add_junk_part(3, 1);
            printf("\033[33mZnalazłeś nie działającą żarówkę \033[0m\n");
        }
        else {
            add_money(5);
            printf("\033[33mZnalazłeś drobne w śmieciach (5$)\033[0m\n");
        }

        while (1) {
            printf("Czy chcesz dalej przeszukiwać stertę śmieci?\nWpisz (tak), (nie):\n");
            scanf("%9s", go_again_or_stop);
            getchar();

            if (strcmp(go_again_or_stop, "tak") == 0) {
                break;
            }
            else if (strcmp(go_again_or_stop, "nie") == 0) {
                rubbish_dump_menu();
                keep_searching = 0;
                break;
            }
            else {
                system("cls");
                printf("Wprowadziłeś niepoprawną wartość spróbuj jeszcze raz\n");
                printf("Kliknij Enter...\n");
                getchar();
            }
        }
    }
}


void racoon_ending() {
    system("cls");
    printf("\033[33mDzięki jedzeniu, które zdobył dla ciebie Benedykt twoja rodzina przetrwała zimę.\n\n");
    printf("Wygrałeś\n");
    printf("\n");
    printf("      ______\n");
    printf("     /%c     |\n", 92);
    printf("    /  |  @ >\n");
    printf("   /___|__   )\n");
    printf("         |  |\n");
    printf("         |  |\n");
    printf("         |  |\n");
    printf("         |-- %c _________ _\n", 92);
    printf("        /     /         %c  %c__   \n", 92, 92);
    printf("       |               _/   _/\n", 92);
    printf("       %c_      _____/     _/\n", 92, 92);
    printf("         %c_           ___/\n", 92, 92);
    printf("           %c___    __/\n", 92, 92);
    printf("               %c_|/\n", 92, 92);
    printf("                ||\n");
    printf("               _||\n");
    printf("              >__/ \n", 92);
    printf("Gratulacje Alfredzie\033[0m\n");
    Sleep(10000);
    exit(0);
    getchar();
    return 0;
}
//95
void meet_the_racoon() {
    system("cls");
    char backslash = 92;
    char answer[10];
    printf("Szop\n");
    printf("                 __        .-. \n");
    printf("             .-'/ . %c    / %c%c|   \n", backslash, backslash, backslash);
    printf("     _(%c-/)_' ,  .   ,%c  /%c%c%c/ \n", backslash, backslash, backslash, backslash, backslash);
    printf("    {(#b^d#)} .   ./,  |/%c%c%c/  \n", backslash, backslash, backslash);
    printf("    `-.(Y).-`  ,  |  , |%c .-`   \n", backslash);
    printf("         /~/,_/~~~%c,__.-`      \n", backslash);
    printf("        ////~    // ~%c%c        \n", backslash, backslash);
    printf("      ==`==`   ==`   ==`       \n");

    printf("\033[95mBenedykt: Witaj przybyszu, nazywam się szop Benedykt. Czego tu szukasz?\033[0m\n");
    printf("Alfred: Witaj Benedykcie! Jestem Alfred. Poszukuję karmy dla gęsi.\n");
    printf("        Potrzebuję jej, żeby moja rodzina nie głodowała przez zimę.\n");
    printf("        Masz może trochę karmy?\n");

    printf("\033[95mBenedykt: Niestety nie, Alfredzie. Ale mogę ją ukraść dla ciebie, jeśli mi pomożesz.\033[0m\n");
    printf("Alfred: W takim razie, jak mogę ci pomóc?\n");

    printf("\033[95mBenedykt: Moje dzieci zawsze chciały zobaczyć bałwana ze śniegu w zimę,\n");
    printf("          ale na wysypisku i w ogóle w mieście rzadko pada śnieg.\n");
    printf("          W związku z tym chcę im wybudować bałwana z części znalezionych tutaj,\n");
    printf("          żeby były szczęśliwe.\033[0m\n");

    printf("\033[95mBenedykt: Jeżeli przyniesiesz mi:\n");
    printf("          (3) kule śmieciowe,\n");
    printf("          (1) pokrywę od śmietnika,\n");
    printf("          (1) zgniłą marchewkę,\n");
    printf("          (2) zepsute żarówki,\n");
    printf("          to znajdę dla ciebie tyle karmy, ile tylko chcesz.\033[0m\n\n");

    //int junk_sphere;
    //int garbage_can_lid;
    //int rotten_carrot;
    //int broken_light_bulb;

    while (1) {
        printf("Benedykt: Czy masz już te części? (tak/nie)\n");
        scanf("%9s", answer);

        if ((strcmp(answer, "tak") == 0) && alfred.junk_sphere >= 2 && alfred.garbage_can_lid >= 1 && alfred.rotten_carrot >= 1 && alfred.broken_light_bulb >= 2) {
            printf("\033[95mBenedykt: Wspaniale! Moje dzieci będą zachwycone!\n");
            printf("          W zamian za twoją pomoc, oto karma dla twojej rodziny.\033[0m\n");
            printf("Alfred: Dziękuję, Benedykcie! Uratowałeś moją rodzinę!\n");
            printf("\033[95mBenedykt: Do zobaczenia, Alfredzie! Powodzenia!\033[0m\n");
            printf("Kliknij Enter...\n");
            getchar();
            getchar();
            racoon_ending();
            break;
        }
        else if ((strcmp(answer, "tak") == 0) && (alfred.junk_sphere < 2 || alfred.garbage_can_lid < 1 || alfred.rotten_carrot < 1 || alfred.broken_light_bulb < 2)) {
            printf("Nie masz wystarczająco dużo wszystkich elementów śmieciowego bałwana");
            getchar();
            getchar();
        }
        else if (strcmp(answer, "nie") == 0) {
            printf("\033[95mBenedykt: Hmm, w takim razie wróć, gdy zdobędziesz wszystkie części.\033[0m\n");
            printf("          Moje dzieci bardzo na to czekają...\n");
            printf("Alfred: W porządku, Benedykcie. Wrócę, gdy wszystko znajdę.\n");
            printf("Kliknij Enter...\n");
            getchar();
            getchar();
            rubbish_dump_menu();
            break;
        }
        else {
            system("cls");
            printf("Wprowadziłeś niepoprawną wartość spróbuj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
            getchar();
        }
    }

}


void rubbish_dump_menu() {
    system("cls");
    printf("Wszedłeś na teren wysypiska\n");
    printf("Wokół na pierwszy rzut oka widać było tylko góry różnego rodzaju śmieci.\n W oddali dostrzegłeś jednak zwierzęcą sylwetkę\n");
    while (1) {
        char dump_menu_choice_1;
        printf("Co robisz?\n");
        printf("(1)Poszukuj przedmiotów w górze śmieci\n(2)Podejdź do tajemniczej figury\n(3)żeby opuścić to miejsce\n");
        scanf(" %c", &dump_menu_choice_1);
        if (dump_menu_choice_1 == '1') {
            search_in_trash();
            break;
        }
        else if (dump_menu_choice_1 == '2') {
            meet_the_racoon();
            break;
        }
        else if (dump_menu_choice_1 == '3') {
            go_back_to_the_city();
            break;
        }
        else {
            system("cls");
            printf("Wprowadziłeś niepoprawną wartość spróbuj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
            getchar();
        }
    }
}

//------------------------------------------------------------------------Wysypisko--------------------------------------------------------------------------------------------------------------------------/



int main() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_MAXIMIZE);
    setlocale(LC_ALL, "Polish");
    srand(time(NULL));
    //bank_menu();
    //shop_menu();
    //casino_menu();
    //mini_Zoo_menu();
    //rubbish_dump_menu();
    prologue();
    start();
    return 0;
}
