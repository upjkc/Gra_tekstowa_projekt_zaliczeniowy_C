
/*

Jednorêki Bandyta - by Jacek Pucha³ko

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

 Gêœ - by Jacek Pucha³ko
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


 Martwa Gêœ robi szpagat - by Jacek Pucha³ko

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
#include <locale.h>//Gra korzysta z polskich znaków st¹d zastosowanie tej biblioteki
#include <ctype.h>
#include <stdbool.h>//Program korzysta ze zmiennej bool w strukturze (która przetrzymuje dane gracza: umiejêtnoœci które posiada gracz, zasoby pozyskane przez gracza) bool jest u¿yty jako true/false dla umiejêtnoœci które posiada gracz
#include <stdlib.h>
#include <time.h>
#include <windows.h>//Program zosta³ napisany na widowsie jako gra na windowsa st¹d u¿ycie biblioteki windows.h + program u¿ywa system("cls"); ¿eby zwiêkszyæ czytelnoœæ tekstu w konsoli

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
    "Alfred",               // Imiê gêsi
    false,                  // Umiejêtnoœæ korzystania z pieniêdzy
    //false,                  // Umiejêtnoœæ korzystania z drukarki
    //false,                  // Zainspirowanie gêsi
    0,                      // Iloœæ pieniêdzy
    0,                      // Iloœæ worków karmy
    0,                      // Kula œmieci
    0,                      // Pokrywa od kub³a na œmieci
    0,                      // przegni³a marchewka
    0                       // Nie dzia³aj¹ca ¿arówka
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





char select_location;
char city_building_choice;
int casino_enters_counter = 0;

void print_goose_info() {
    printf("Gêœ o imieniu %s:\n", alfred.name);
    printf("Umiejêtnoœci:\n");
    printf("  - Korzystanie z pieniêdzy: %s\n", alfred.using_money_ability ? "Tak" : "Nie");
    printf("Pieni¹dze i Karma:\n");
    printf("  - Iloœæ pieniêdzy: %d\n", alfred.money);
    printf("  - Iloœæ worków karmy: %d\n", alfred.goose_food);
    printf("Czêœci œmieciowego ba³wana:\n");
    printf("  - Kule œmieciowe: %d\n", alfred.junk_sphere);
    printf("  - Pokrywy od kub³a na œmieci: %d\n", alfred.garbage_can_lid);
    printf("  - przegni³e marchewki: %d\n", alfred.rotten_carrot);
    printf("  - Nie dzia³aj¹ce ¿arówki: %d\n", alfred.broken_light_bulb);

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

void reset_players_stats(){
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
        char back_to_the_city;
        printf("¯eby powróciæ do mapy miasta wpisz (m)\n");
        scanf(" %c", &back_to_the_city);
        if (back_to_the_city == 'm') {
            city_menu();
            break;
        }
        else {
            printf("Poda³eœ nie poprawn¹ wartoœæ. Spróbuj jeszcze raz\n");
        }
    } while (1);
}

void go_back_to_home_ending() {
    while (1) {
        char last_choice;
        printf("Czy napewno chcesz u¿yæ tej opcji?\n");
        printf("Je¿eli zawrócisz do domu bez potrzebnego jedzenia nie bêdziesz mia³ ju¿ wiêcej czasu ¿eby je zdobyæ.\n");
        printf("Czy napewno chcesz zawróciæ do domu?\n");
        printf("(t)tak\n(n)nie\n");
        scanf(" %c", &last_choice);
        if (last_choice == 't') {
            break;
        }
        else if (last_choice == 'n') {
            go_back_to_the_city();
            break;
        }
        else {
            printf("Nieprawid³owy wybór.\n");
            printf("\nNaciœnij Enter...");
            getchar();
            getchar();
        }
    }


    if (alfred.goose_food >= 20) {
        printf("\033[33mWygra³eœ. Przynios³eœ rodzinie jedzenie, którego potrzebowali ¿eby przetrwaæ\n");
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
        return 0;
    }
    else {
        printf("\033[31mPrzegra³eœ. Nie przynios³eœ swojej rodzinie dostatecznej iloœci Gêsiego jedzenia ¿eby przetrwali zimê\n");
        printf("       ______      _____ _________ _                   \n");
        printf("      /%c     %c____/     /         %c  %c__               \n", 92, 92, 92, 92);
        printf("     /  |   X  ___                _/   _/              \n");
        printf("    /___|_____)  %c_      _____/     _/                 \n", 92);
        printf("|^^________________%c_           ___/________________^^|\n", 92);
        printf("|____________________%c_________/______________________|\n\n\n", 92);
        printf("Przegrana\033[0m\n");
        while (1) {
            printf("Czy chcesz zagraæ ponownie czy zakoñczyæ rozgrywkê:\n");
            printf("(1) Zakoñcz rozgrywkê\n");
            printf("(2) Zagraj ponownie\n");

            int ending_choice;
            int result = scanf(" %d", &ending_choice);

            if (result != 1) {

                printf("Wprowadzi³eœ niepoprawn¹ wartoœæ. Spróbuj ponownie.\n");
                while (getchar() != '\n');
                continue;
            }

            if (ending_choice == 1) {
                system("cls");
                printf("END\n");
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
                printf("Wprowadzi³eœ niepoprawn¹ wartoœæ. Spróbuj ponownie.\n");
            }
        }
    }

}

//-------------------------------------------------------------------Prolog i pocz¹tek Gry-------------------------------------------------------------------------------------------------------------------/
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

        printf("\n\n\nAby rozpocz¹æ rozgrywkê wciœnij Enter...");
        getchar();

        system("cls");
        printf("Nazywasz siê Albert. Jesteœ gêsi¹, która ¿yje w swoim domu (gniezdzie) na polanie wraz ze swoim m³odszym rodzeñstwem.\nZbli¿a siê zima i musisz zadbaæ o to ¿ebyœ ty i twoje m³odsze rodzeñstwo mieli co jeœæ.\nW tym celu masz zamiar wyruszyæ do miasta bo s³ysza³eœ, ¿e tam naj³atwiej zdobyæ pokarm\n");
        printf("¯eby twoja rodzina przetrwa³a zimê musisz uzbieraæ 20 worków karmy dla gêsi.\n");

        printf("\nAby kontynuowaæ wciœnij Enter...\n");
        getchar();

}




void start() {
    system("cls");
    printf("HONK!\n");
    printf("Wzi¹³eœ ze sob¹ gêsi plecak i jesteœ gotowy do drogi\n");
    printf("(m)¯eby wyruszyæ do Miasta ludzk¹ drog¹\n");

    do {
        scanf(" %c", &select_location);
        select_location = tolower(select_location);

        if (select_location == 'm') {
            way_to_the_city();
            break;
        }
        else {
            printf("Wprowadzono niepoprawn¹ wartoœæ. Spróbuj ponownie.\n");
        }
    } while (1);
}


void way_to_the_city() {
    system("cls");
    char risky_money_choice[10];
    printf("Idaæ drog¹ do miasta zauwa¿asz na jej œrodku b³yszcz¹cy przedmiot przypominaj¹cy monetê\n");
    printf("Czy chcesz podjeœæ i podnieœæ przedmiot, czy wolisz odrazu iœæ dalej\n");
    printf("Wpisz:\n(tak)jeœli chcesz podnieœæ przedmiot\n(nie)jeœli chcesz go pomin¹æ\n");
    while (1) {
        scanf("%9s", risky_money_choice);

        if (strcmp(risky_money_choice, "tak") == 0) {
            system("cls");
            int random_number = rand() % 100;

            if (random_number < 80) {
                add_money(5);
                printf("\033[33mPodnios³eœ 5$ i ruszasz dalej do miasta\033[0m\n");
                printf("Kliknij Enter aby kontynuowaæ...\n");
                getchar();
                getchar();
                city_menu();
            }
            else {
                printf("\033[31mMia³eœ pecha i potr¹ci³ ciê tir\n");
                printf("       ______      _____ _________ _                   \n");
                printf("      /%c     %c____/     /         %c  %c__               \n", 92, 92, 92, 92);
                printf("     /  |   X  ___                _/   _/              \n");
                printf("    /___|_____)  %c_      _____/     _/                 \n", 92);
                printf("|^^________________%c_           ___/________________^^|\n", 92);
                printf("|____________________%c_________/______________________|\n\n\n", 92);
                printf("Przegrana\033[0m\n");
                while (1) {
                    printf("Czy chcesz zagraæ ponownie czy zakoñczyæ rozgrywkê:\n");
                    printf("(1) Zakoñcz rozgrywkê\n");
                    printf("(2) Zagraj ponownie\n");

                    int ending_choice;
                    int result = scanf(" %d", &ending_choice);

                    if (result != 1) {

                        printf("Wprowadzi³eœ niepoprawn¹ wartoœæ. Spróbuj ponownie.\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    if (ending_choice == 1) {
                        system("cls");
                        printf("END\n");
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
                        printf("Wprowadzi³eœ niepoprawn¹ wartoœæ. Spróbuj ponownie.\n");
                    }
                }
            }
            break;
        }
        else if (strcmp(risky_money_choice, "nie") == 0) {
            system("cls");
            printf("Ruszy³eœ w dalsz¹ drogê do miasta\n");
            printf("Kliknij Enter aby kontynuowaæ...\n");
            getchar();
            getchar();
            city_menu();
            break;
        }
        else {
            system("cls");
            printf("Wprowadzi³eœ niepoprawn¹ wartoœæ spróbuj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
            getchar();
        }
    }
}

//-------------------------------------------------------------------Prolog i pocz¹tek Gry-------------------------------------------------------------------------------------------------------------------/

void show_credits() {
    printf("Gra stworzone przez: Jacek Pucha³ko\n");
    printf("ASCII art gêœ, maszyna losuj¹ca: Jacek Pucha³ko\n");
    printf("ASCII arty zaporzyczone z na potrzeby projektu z www.asciiart.eu: \n");
    printf("  - ASCII art Szop: Joan Stark - art from https://www.asciiart.eu/animals/cats \n");
    printf("  - ASCII art Miasta: (Autor nie by³ podany na stronie) https://www.asciiart.eu/buildings-and-places/cities \n");
    printf("Wszelkie ASCII arty napisów zosta³y stworzone za pomoc¹ generatora: https://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%%20Something%%20 \n\n");
    go_back_to_the_city();
}







//------------------------------------------------------------------------Main Menu--------------------------------------------------------------------------------------------------------------------------/

void city_menu() {
    system("cls");
    printf("Witaj w mieœcie\n");
    printf("                                    +					\n");
    printf("                                   / %c					\n",92);
    printf(" _____        _____     __________/ o %c/%c_________      _________	\n",92,92);
    printf("|o o o|_______|    |___|               | | # # #  |____|o o o o  | /%c	\n",92);
    printf("|o o o|  * * *|: ::|. .|               |o| # # #  |. . |o o o o  |//%c%c	\n",92,92);
    printf("|o o o|* * *  |::  |. .| []  []  []  []|o| # # #  |. . |o o o o  |((|))	\n");
    printf("|o o o|**  ** |:  :|. .| []  []  []    |o| # # #  |. . |o o o o  |((|))	\n");
    printf("|_[]__|__[]___|_||_|__<|____________;;_|_|___/%c___|_.|_|____[]___|  |	\n\n\n",92);
    printf("W mieœcie jest wiele miejsc i budynków. Wybierz, który z nich chcia³byœ odwiedziæ:\n");
    printf("(b) Bank\n(s) Sklep\n(a) Kasyno\n(w) Wysypisko\n(m) Ma³e Zoo\n");
    printf("\nW tym miejscu mo¿esz równie¿ wybraæ:\n(i)Zajrzyj do ekwipunku\n(z)Zawróæ do domu\n(c)Credits\n\n");



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
            printf("Nieprawid³owy wybór.\n");
            printf("\nNaciœnij Enter...");
            getchar();
            getchar();
            city_menu();
        }
}
//------------------------------------------------------------------------Main Menu--------------------------------------------------------------------------------------------------------------------------/

//------------------------------------------------------------------------Bank-------------------------------------------------------------------------------------------------------------------------------/
void bank_worker() {
    char conversation_choice;
    printf("\033[36mPracowniczka banku:  Dzieñ dobry w czym mogê pomóc?! Czy pan jest Gêsi¹?\033[0m\n(t)tak\n(n)nie\n");
    scanf(" %c", &conversation_choice);

    if (conversation_choice == 't') {
        printf("\033[36mPracowniczka banku:  W takim razie w czym mogê pomóc?\033[0m\n(1)Zdob¹dŸ informacje o tym jak u¿ywaæ pieniêdzy\n(2)OdejdŸ\n");
    }
    else{
        printf("\033[36mPracowniczka banku:  Przepraszam pana s³abo widzê bez okularów. W takim razie w czym mogê pomóc?\033[0m\n(1)Zdob¹dŸ informacje o tym jak u¿ywaæ pieniêdzy\n(wciœnij jaki kolwiek inny przycisk)OdejdŸ\n");
    }
    scanf(" %c", &conversation_choice);
    if (conversation_choice == '1') {
        printf("\033[36mPracowniczka banku:  Pieni¹dz to powszechnie akceptowany œrodek wymiany i przechowywania wartoœci.\nPe³ni rolê uniwersalnego œrodka p³atniczego w transakcjach handlowych.\nPieni¹dz u³atwia wymianê dóbr i us³ug oraz umo¿liwia dokonywanie pomiaru wartoœci.\033[0m\n");
        update_ability(0, true);
        printf("\033[33m\nBrawo Alfred dowiedzia³ siê czym s¹ pieni¹dze i jak ich u¿ywaæ!\n\033[0m");
        printf("Wciœnij dowolny przycisk ¿eby wróciæ na hol g³ówny banku\n");
        getchar();
        getchar();
        bank_menu();
    }
    else{
        bank_menu();
    }
}



void bank_menu() {
    system("cls");
    printf("Bank\n");
    printf("W banku widzisz pracowniczkê banku i szefa banku, który rozmawia z jednym ze swoich pracowników\n");
    printf("Wybierz co chcesz zrobiæ w banku:\n(1)Porozmawiaj z pracowniczk¹ banku\n(2)Porozmawiaj z szefem banku\n(3)WyjdŸ z banku\n");
        char bank_worker_choice;
        scanf(" %c", &bank_worker_choice);
        
        if (bank_worker_choice == '1') {
            bank_worker();
        }
        else if (bank_worker_choice == '2') {
            printf("Szef banku jest w tej chwili zajêty i nie mo¿e z tob¹ porozmawiaæ.\nWciœnij dowolny przycisk ¿eby wróciæ\n");
            getchar();
            getchar();
            bank_menu();
        }
        else if (bank_worker_choice == '3') {
            go_back_to_the_city();
        }
        else {
            printf("Wprowadzono niepoprawne dane.\nWciœnij dowolny przycisk ¿eby spróbowaæ jeszcze raz\n");
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
        printf("\033[31mSprzedawca atakuje miot³¹! Straci³eœ 10 HP!\033[0m\n");
        goose_hp -= 10;
    }
    else {
        printf("Sprzedawca nie trafi³ ciê miot³¹!\n");
    }
}

void player_peck() {
    // Gracz ma 100% szans na trafienie za 5hp
    printf("\033[32mDziobiesz Sprzedawcê za 5 HP!\033[0m\n");
    sellers_hp -= 5;
}

void player_scare_HONK() {
    if (rand() % 100 < 30) {  // 30% szansy na zastraszenie oponenta
        printf("\033[32mSprzedawca uciek³ w strachu! Walka zakoñczona!\033[0m\n");
        sellers_hp = 0;  // Zmiana hp sprzedawcy na 0, ¿eby pêtla przesta³a dzia³aæ
    }
    else {
        printf("Próba zastraszenia nie powiod³a siê!\n");
    }
}

void display_hp() {
    printf("HP Alfred: %d | HP Sprzedawca: %d\n", goose_hp, sellers_hp);
}

void shopseller_fight() {
    system("cls");
    char fight_or_no_fight;
    printf("Czy na pewno chcesz zabraæ karmê dla gêsi ze sklepu bez pozwolenia w³aœciciela?\n(t)tak\n(dowolny znak, litera lub liczba)nie\n");
    scanf(" %c", &fight_or_no_fight);

    if (fight_or_no_fight == 't') {
        printf("\033[31mKiedy próbowa³eœ wymkn¹æ siê z 20 workami karmy dla gêsi ze sklepu, twoje poczynania zauwa¿y³ Sprzedawca.\nWzi¹³ miot³ê i postanowi³ zapobiec kradzie¿y.\nStan¹³ z tob¹ do pojedynku na œmieræ i ¿ycie.\033[0m\n");

        char attack_move_choice;
        int round = 1;

        while (goose_hp > 0 && sellers_hp > 0) {
            printf("\nRunda %d:\n", round);
            display_hp();  

            // Tura gracza, wybór akcji
            printf("Wybierz akcjê:\n");
            printf("(a) Dziobanie (5 obra¿eñ)\n");
            printf("(b) HONK! (30%c szans na zastraszenie oponenta)\n",37);
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

            // Sprawdzenie, czy walka zakoñczy³a siê po akcji gracza
            if (sellers_hp <= 0) {
                printf("Pokona³eœ Sprzedawcê!\n");
                printf("\033[33mUciekasz ze sklepu z ³upem\033[0m\n");
                add_goose_food(20);
                printf("Naciœnij Enter, aby wyjœæ ze sklepu...\n");
                getchar();
                getchar();
                city_menu();


                break;
            }
            else if (goose_hp <= 0) {
                while (1) {
                    printf("\033[31m       ______      _____ _________ _                   \n");
                    printf("      /%c     %c____/     /         %c  %c__               \n",92,92,92,92);
                    printf("     /  |   X  ___                _/   _/              \n");
                    printf("    /___|_____)  %c_      _____/     _/                 \n",92);
                    printf("|^^________________%c_           ___/________________^^|\n",92);
                    printf("|____________________%c_________/______________________|\n\n\n",92);
                    printf("Zosta³eœ pokonany przez Sprzedawcê!\n");
                    printf("Przez to nie wróci³eœ do swojej gêsiej rodziny i twoje dzieci umar³y z powodu zimna i g³odu.\033[0m\n");
                    printf("Czy chcesz zagraæ ponownie czy zakoñczyæ rozgrywkê:\n");
                    printf("(1) Zakoñcz rozgrywkê\n");
                    printf("(2) Zagraj ponownie\n");

                    int ending_choice;
                    int result = scanf(" %d", &ending_choice);

                    if (result != 1) {

                        printf("Wprowadzi³eœ niepoprawn¹ wartoœæ. Spróbuj ponownie.\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    if (ending_choice == 1) {
                        system("cls");
                        printf("END\n");
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
                        printf("Wprowadzi³eœ niepoprawn¹ wartoœæ. Spróbuj ponownie.\n");
                    }
                }
            }

            // Tura Sprzedawcy, atakuje gracza
            npc_attack();  // Sprzedawca atakuje gracza

            // Sprawdzenie, czy walka zakoñczy³a siê po ataku Sprzedawcy
            if (sellers_hp <= 0) {
                printf("Pokona³eœ Sprzedawcê!\n");
                printf("\033[33mUciekasz ze sklepu z ³upem\033[0m\n");
                add_goose_food(20);
                printf("Naciœnij Enter, aby wyjœæ ze sklepu...\n");
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
                    printf("Zosta³eœ pokonany przez Sprzedawcê!\n");
                    printf("Przez to nie wróci³eœ do swojej gêsiej rodziny i twoje dzieci umar³y z powodu zimna i g³odu.\033[0m\n");
                    printf("Czy chcesz zagraæ ponownie czy zakoñczyæ rozgrywkê:\n");
                    printf("(1) Zakoñcz rozgrywkê\n");
                    printf("(2) Zagraj ponownie\n");

                    int ending_choice;
                    int result = scanf(" %d", &ending_choice);

                    if (result != 1) {
                        
                        printf("Wprowadzi³eœ niepoprawn¹ wartoœæ. Spróbuj ponownie.\n");
                        while (getchar() != '\n'); 
                        continue;
                    }

                    if (ending_choice == 1) {
                        system("cls");
                        printf("END\n");
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
                        printf("Wprowadzi³eœ niepoprawn¹ wartoœæ. Spróbuj ponownie.\n");
                    }
                }
            }

            round++;
        }
    }
    else {
        printf("Naciœnij Enter, aby wyjœæ ze sklepu...\n");
        getchar();
        getchar();
        city_menu();
    }
}
// Walka do dokoñczenia koniecznie (zakoñczenia walki do zrobienia)
//------------------------------------------------------------------------Opcjonalna_Walka-----------------------------------------------------------/



//------------------------------------------------------------------------Zakupy---------------------------------------------------------------------/
void shop_menu() {
    char shop_choice;
    char shop_choice_2;
    int quantity_of_goose_food_bags;
    system("cls");
    printf("Wszed³eœ do Sklepu. W powietrzu uda³o ci siê wyczuæ woñ karmy dla gêsi. Widzisz Sprzedawcê co robisz?\n");
    printf("(a)Podejdz do sprzedawcy\n(b)spróbuj okraœæ sklep\n(dowolna znak, litera lub liczba) WyjdŸ ze sklepu\n");
    scanf(" %c", &shop_choice);

    if ((shop_choice == 'a') && (alfred.using_money_ability == true)) {
        printf("\n\033[34mSprzedawca: Dzieñ dobry w czym mogê pomóc\033[0m\n");
        printf("Alfred: Potrzebuje Gêsiej karmy HONK!\n");
        printf("\033[34mSprzedawca: Jedna torba gêsiej karmy kosztuje 10$\033[0m\n");
        printf("Alfred: ILE? HONK?!\n");
        printf("(1)Jeœli chcesz kontynuowaæ konwersacjê wciœnij\n(2)je¿eli chcesz wyjœæ ze sklepu)\n");
        scanf(" %c", &shop_choice_2);

        if ((shop_choice_2 == '1') && (alfred.money >= 10) && (alfred.using_money_ability == true)) {
            do {
                printf("\033[34mSprzedawca: Ile chce pan kupiæ worków?\033[0m\n");
                printf("Ile obecnie masz pieniêdzy = %d\n", alfred.money);

                if ((scanf("%d", &quantity_of_goose_food_bags) == 1)) {
                    if (quantity_of_goose_food_bags <= 0) {
                        printf("Nie mo¿esz kupiæ '%d' worków. WprowadŸ liczbê wiêksz¹ od zera.\n", quantity_of_goose_food_bags);
                        continue; // Powrót do pocz¹tku pêtli
                    }

                    if ((quantity_of_goose_food_bags * 10) <= alfred.money) {
                        printf("\033[34mSprzedawca: Oto pana zakupy: \033[33m'%d'\033[34m worków z gêsi¹ karm¹.\033[0m\n", quantity_of_goose_food_bags);

                        add_goose_food(quantity_of_goose_food_bags);
                        add_money(-(quantity_of_goose_food_bags * 10));

                        printf("Naciœnij Enter, aby kontynuowaæ...\n");
                        getchar();
                        getchar();
                        shop_menu();
                        break;
                    }
                    else {
                        printf("Nie masz wystarczaj¹co du¿o pieniêdzy na zakup '%d' worków z gêsi¹ karm¹.\n", quantity_of_goose_food_bags);
                    }
                }
                else {
                    printf("Poda³eœ wartoœæ, która nie jest numerem. Ponów próbê wprowadzenia wartoœci.\n");
                    while (getchar() != '\n'); 
                }
            } while (1);
        }
        else if ((shop_choice_2 == '1') && (alfred.money < 10) && (alfred.using_money_ability == true)) {
            printf("Nie masz wystarczaj¹co du¿o pieniêdzy ¿eby kupiæ gêsi¹ karmê\n");
            printf("Naciœnij Enter, aby kontynuowaæ...\n");
            getchar();
            getchar();
            shop_menu();
        }
        else if ((shop_choice_2 == '1') && (alfred.using_money_ability == false)) {
            printf("Nie wiesz jak dzia³aj¹ pieni¹dze wiêc nie mo¿esz nic kupiæ.\nDowiedz siê jak dzia³aj¹ pieni¹dze\n");
            printf("Naciœnij Enter, aby kontynuowaæ...\n");
            getchar();
            getchar();
            shop_menu();
        }
        else if(shop_choice_2 == '2') {
            go_back_to_the_city();
        }
        else {
            printf("Poda³eœ niew³aœciw¹ Dan¹");
            printf("Naciœnij Enter, aby kontynuowaæ...\n");
            getchar();
            getchar();
            shop_menu();
        }
    }
    else if ((shop_choice == 'a') && (alfred.using_money_ability == false)) {
        printf("Nie wiesz jak dzia³aj¹ pieni¹dze wiêc nie mo¿esz nic kupiæ.\nDowiedz siê jak dzia³aj¹ pieni¹dze\n");
        printf("Naciœnij Enter, aby kontynuowaæ...\n");
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
/*




*/

void spin_the_numbers_in_machine() {
    system("cls");
    int random_number_1;
    int random_number_2;
    int random_number_3;
    add_money(-2);
    random_number_1 = rand() % 7 + 1;
    random_number_2 = rand() % 7 + 1;
    random_number_3 = rand() % 7 + 1;
    printf("%d, %d, %d", random_number_1, random_number_2, random_number_3);
    if ((random_number_1 == random_number_2) && (random_number_2 == random_number_3)) {
        printf("\033[33mMaszyna do gry (jednorêki bandyta)\n\n");
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

    }
    else {
        printf("Maszyna do gry (jednorêki bandyta)\n\n");
        printf("      ___________      \n");
        printf("     /___________%c     \n", 92);
        printf("     |  _______  | ({})\n");
        printf("     |  |%d|%d|%d|  |  || \n", random_number_1, random_number_2, random_number_3);
        printf("     |  ```````  |__|| \n");
        printf("     |:::::::::::|---' \n");
        printf("     |           |     \n");
        printf("     |:::::::::::|     \n");
        printf("     |___________|     \n\n");
        printf("Niczego nie wygra³eœ\n");

    }
}


void slot_machine() {
    while (1) {
        system("cls");
        printf("¯eby zagraæ musisz wrzuciæ 2$ do maszyny\n");
        printf("czy chcesz zagraæ?\n(t)tak\n(n)nie\n");

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
                printf("\033[33mMaszyna do gry (jednorêki bandyta)\n\n");
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
                printf("\nczy chcesz zagraæ jeszcze raz?\n(t)tak\n(n)nie\n");

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
                    printf("\nUzale¿ni³eœ siê od hazardu i straci³eœ wszyckie pieni¹dze.\nPrzez swoje uzale¿nienie nie wróci³eœ do swojej rodziny i wszyscy umarli przez zag³odzenie\033[0m\n");

                    while (1) {
                        printf("Czy chcesz zagraæ ponownie czy zakoñczyæ rozgrywkê:\n");
                        printf("(1) Zakoñcz rozgrywkê\n");
                        printf("(2) Zagraj ponownie\n");

                        int ending_choice;
                        printf("Twój wybór: ");
                        int result = scanf(" %d", &ending_choice);

                        if (result != 1) {

                            printf("Wprowadzi³eœ niepoprawn¹ wartoœæ. Spróbuj ponownie.\n");
                            while (getchar() != '\n');
                            continue;
                        }

                        if (ending_choice == 1) {
                            system("cls");
                            printf("END\n");
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
                            printf("Wprowadzi³eœ niepoprawn¹ wartoœæ. Spróbuj ponownie.\n");
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

                    printf("\nGratulacje wygra³eœ.\nDziêki temu, ¿e zdoby³eœ tyle pieniêdzy, twoja rodzina nie bêdzie g³odna przez najbli¿sze kilka lat.\nTa zima bêdzie dla was ³agodna i bêdziecie cieszyæ siê dostatnim ¿yciem\n\n\n");
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

                    return 0;
                }

            }
            else {
                char try_spinning_again_or_no;
                printf("Maszyna do gry (jednorêki bandyta)\n\n");
                printf("      ___________      \n");
                printf("     /___________%c     \n", 92);
                printf("     |  _______  | ({})\n");
                printf("     |  |%d|%d|%d|  |  || \n",random_number_1, random_number_2, random_number_3);
                printf("     |  ```````  |__|| \n");
                printf("     |:::::::::::|---' \n");
                printf("     |           |     \n");
                printf("     |:::::::::::|     \n");
                printf("     |___________|     \n\n");
                printf("Niczego nie wygra³eœ\n");
                printf("\nczy chcesz zagraæ jeszcze raz?\n(t)tak\n(n)nie\n");
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
            printf("nie masz wystarczaj¹co du¿o pieniêdzy ¿eby zagraæ\n");
            go_back_to_the_city();
            break;
        }
        else if (slot_machine_choice_1 == 'n') {
            go_back_to_the_city();
            break;
        }
        else {
            system("cls");
            printf("wprowadzi³eœ niepoprawn¹ dan¹\n");
            printf("Naciœnij Enter, aby kontynuowaæ...\n");
            getchar();
            getchar();
        }
    }
}








void casino_menu() {
    char casino_choice_1;
    system("cls");
    printf("Wszed³eœ do Kasyna. Masz wra¿enie, ¿e to miejsce jest wype³niane negatywnymi emocjami i rozgoryczeniem.\nWidzisz ludzi, którzy siedz¹ przed maszynami i wykonuj¹ w kó³ko jedn¹ czynnoœæ.\nRaz wydaj¹ siê podekscytowani, a zaraz potem smutni.\n\n\n");

    if (casino_enters_counter == 0) {
        while (1) {
            char casino_choice_first_time;
            printf("\033[35mPracownik kasyna: Dzieñ dobry. Witaj w kasynie 'El Goose de la gazpacho'. W czym mogê pomóc? Jakaœ maszyna nie dzia³a?\033[0m\n\n");
            printf("Alfred: Szukam sposobu, ¿eby pozyskaæ gêsi¹ karmê. Dok³adniej 20 worków gêsiej karmy.\n\n");
            printf("\033[35mPracownik kasyna: Je¿eli zagra pan u nas w jednorêkiego bandytê, ma pan szanse na wygranie ogromnej puli pieniêdzy, dziêki której bêdzie pan móg³ kupiæ tyle gêsiej karmy, ile pan zechce.\033[0m\n");
            printf("\033[35m¯eby wygraæ w tej grze wysztkie 3 wylosowane przez maszynê liczby musz¹ byæ jednakowe, ka¿dy inny wynik bêdzie uznawany za przegran¹.\033[0m\n\n");
            printf("\n\033[35mPracownik kasyna: Czy chce pan spróbowaæ zagraæ?\033[0m\n(t)tak\n(n)nie\n");
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
                printf("Wprowadzi³eœ niepoprawn¹ wartoœæ.\n");
                continue;
            }
        }
        casino_enters_counter += 1;
    }

    while (1) {
        printf("czy chcesz podejœæ do stanowiska do gry w jednorêkiego bandytê?\n(t)tak\n(n)nie\n");
        scanf(" %c", &casino_choice_1);
        if ((casino_choice_1 == 't') && (alfred.using_money_ability == true)) {
            casino_enters_counter += 1;
            slot_machine();
            
            break;
        }
        else if((casino_choice_1 == 't') && (alfred.using_money_ability == false)){
            printf("Nie wiesz jak dzia³aj¹ pieni¹dze wiêc nie mo¿esz zagraæ w kasynie.\nDowiedz siê jak dzia³aj¹ pieni¹dze\n");
            go_back_to_the_city();
        }
        else if (casino_choice_1 == 'n') {
            casino_enters_counter += 1;
            go_back_to_the_city();
            return;
        }
        else {
            system("cls");
            printf("Wprowadzi³eœ niepoprawn¹ wartoœæ.\n");
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
    printf("Rozpoczêcie godziny pracy\n");
    printf("Problem 1\nDziecko próbuje z³apaæ ciê za skrzyd³o. Co robisz?\n");
    printf("(1)Uciekasz\n(2)Uderzasz je lekko skrzyd³em\n");
    scanf(" %c", &zoo_work_choice_1);

        if (zoo_work_choice_1 == '1') {
            printf("Uda³o ci siê uciec.\n");
            paycheck += 5;
            break;
        }
        else if (zoo_work_choice_1 == '2') {
            printf("Dziecko zaczê³o p³akaæ, szef potr¹ci ci z wyp³aty.\n");
            break;
        }
        else {
            printf("Wprowadzi³eœ niepoprawn¹ wartoœæ, spróbuj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
            continue;
        }
    }

    while (1) {
        system("cls");
    printf("Problem 2\nDziecko chce ciê dokarmiæ\n");
    printf("(1)Zjedz jedzenie, które da³o ci dziecko\n(2)OdejdŸ\n");
    scanf(" %c", &zoo_work_choice_2);

        if (zoo_work_choice_2 == '1') {
            printf("Jedzenie nie by³o gêsi¹ karm¹, ale o dziwo ci nie zaszkodzi³o\n");
            paycheck += 20;
            break;
        }
        else if (zoo_work_choice_2 == '2') {
            printf("Dziecko przysz³o na skargê do szefa, a ten potr¹ci³ ci z wyp³aty.\n");
            break;
        }
        else {
            printf("Wprowadzi³eœ niepoprawn¹ wartoœæ, spróbuj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
            continue;
        }
    }

    while (1) {
        system("cls");
    printf("Problem 3\nDziecko zmierza w twoj¹ stronê i chce ciê pog³askaæ\n");
    printf("(1)Ucieknij\n(2)Ukryj siê\n");
    scanf(" %c", &zoo_work_choice_3);

        if (zoo_work_choice_3 == '1') {
            printf("Uciek³eœ w pop³ochu, niestety zauwa¿y³ to twój szef.\n");
            break;
        }
        else if (zoo_work_choice_3 == '2') {
            printf("Dziecko ciê nie znalaz³o i posz³o pog³askaæ os³a obok twojej kryjówki.\n");
            paycheck += 10;
            break;
        }
        else {
            printf("Wprowadzi³eœ niepoprawn¹ wartoœæ, spróbuj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
            continue;
        }
    }

    while (1) {
        system("cls");
    printf("Problem 4\nDziecko rzuci³o w ciebie kamieniem. Na szczêœcie nie trafi³o\n");
    printf("(1)HONK!\n(2)Podziób\n");
    scanf(" %c", &zoo_work_choice_4);

        if (zoo_work_choice_4 == '1') {
            printf("Wystraszy³eœ dziecko, ale pracodawca zrozumia³, ¿e to by³a samoobrona, wiêc nie potr¹ci³ ci z wyp³aty.\n");
            paycheck += 5;
            break;
        }
        else if (zoo_work_choice_4 == '2') {
            printf("Zadrapa³eœ dziobem dziecko, ale pracodawca mimo wszystko potr¹ci³ ci z wyp³aty.\n");
            break;
        }
        else {
            printf("Wprowadzi³eœ niepoprawn¹ wartoœæ, spróbuj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
        }
    }

    printf("\033[33mZa przepracowan¹ godzinê dosta³eœ zap³atê w wysokoœci %d$\033[0m\n", paycheck);
    add_money(paycheck);
    go_back_to_the_city();
}




void mini_Zoo_menu() {
    while (1) {
        char mini_zoo_choice_1;
        char mini_zoo_choice_2;
        printf("Ma³e Zoo\n");
        printf("\033[92mSzef ma³ego Zoo: Witaj w ma³ym zoo. Czemu tu siê zjawi³eœ nie przypominam sobie ¿ebyœmy hodowali gêsi?\033[0m\n");
        printf("Alfred: Widzi pan, potrzebujê...\n");
        printf("(k)karmy\n(n)nie potrzebuje niczego\n");
        scanf(" %c", &mini_zoo_choice_1);
        if (mini_zoo_choice_1 == 'k') {
            printf("\033[92mSzef ma³ego Zoo: Skoro potrzebuje pan karmy, mogê zaoferowaæ panu pracê na najbli¿sz¹ godzinê. Bêdzie pan zabawia³ u nas dzieci a w zamian otrzyma pan pieni¹dze za, które mo¿e pan kupiæ karmê\033[0m\n");
            printf("Alfred: Czyli dostanê karmê? czy tylko pieni¹dze?\n");
            printf("\033[92mSzef ma³ego Zoo: Dostanie pan walutê za, któr¹ bêdzie pan móg³ kupiæ karmê.\nJe¿eli pan nie wie jak dzia³a waluta powinien siê pan potem zg³osiæ do banku, tam panu wszystko wyt³umacz¹.\033[0m\n");
            while (1) {
                printf("\033[92mSzef ma³ego Zoo: To jak chce pan u nas pracowaæ?\033[0m\n");
                printf("(t)tak\n(n)nie\n");
                scanf(" %c", &mini_zoo_choice_2);
                if (mini_zoo_choice_2 == 't') {
                    work_in_the_mini_zoo();

                }
                else if (mini_zoo_choice_2 == 'n') {
                    go_back_to_the_city();
                }
                else {
                    system("cls");
                    printf("Wprowadzi³eœ niepoprawn¹ wartoœæ spróbuj jeszcze raz\n");
                    printf("Kliknij Enter...\n");
                    getchar();
                    getchar();

                }
            }
            break;
        }
        else if (mini_zoo_choice_1 == 'n') {
            go_back_to_the_city();
            break;
        }
        else {
            system("cls");
            printf("Wprowadzi³eœ niepoprawn¹ wartoœæ spróbuj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
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
            printf("\033[33mZnalaz³eœ Kule œmieci\033[0m\n");
        }
        else if (random < 80) {
            add_junk_part(1, 1);
            printf("\033[33mZnalaz³eœ Pokrywe od kub³a na œmieci\033[0m\n");
        }
        else if (random < 90) {
            add_junk_part(2, 1);
            printf("\033[33mZnalaz³eœ zgni³¹ marchewkê \033[0m\n");
        }
        else if (random < 95) {
            add_junk_part(3, 1);
            printf("\033[33mZnalaz³eœ nie dzia³aj¹c¹ ¿arówkê \033[0m\n");
        }
        else {
            add_money(5);
            printf("\033[33mZnalaz³eœ drobne w œmieciach (5$)\033[0m\n");
        }

        while (1) {
            printf("Czy chcesz dalej przeszukiwaæ stertê œmieci?\nWpisz (tak), (nie):\n");
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
                printf("Wprowadzi³eœ niepoprawn¹ wartoœæ spróbuj jeszcze raz\n");
                printf("Kliknij Enter...\n");
                getchar();
            }
        }
    }
}


void racoon_ending() {
    system("cls");
    printf("\033[33mDziêki jedzeniu, które zdoby³ dla ciebie Benedykt twoja rodzina przetrwa³a zimê.\n\n");
        printf("Wygra³eœ\n");
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

    printf("\033[95mBenedykt: Witaj przybyszu, nazywam siê szop Benedykt. Czego tu szukasz?\033[0m\n");
    printf("Alfred: Witaj Benedykcie! Jestem Alfred. Poszukujê karmy dla gêsi.\n");
    printf("        Potrzebujê jej, ¿eby moja rodzina nie g³odowa³a przez zimê.\n");
    printf("        Masz mo¿e trochê karmy?\n");

    printf("\033[95mBenedykt: Niestety nie, Alfredzie. Ale mogê j¹ ukraœæ dla ciebie, jeœli mi pomo¿esz.\033[0m\n");
    printf("Alfred: W takim razie, jak mogê ci pomóc?\n");

    printf("\033[95mBenedykt: Moje dzieci zawsze chcia³y zobaczyæ ba³wana ze œniegu w zimê,\n");
    printf("          ale na wysypisku i w ogóle w mieœcie rzadko pada œnieg.\n");
    printf("          W zwi¹zku z tym chcê im wybudowaæ ba³wana z czêœci znalezionych tutaj,\n");
    printf("          ¿eby by³y szczêœliwe.\033[0m\n");

    printf("\033[95mBenedykt: Je¿eli przyniesiesz mi:\n");
    printf("          (3) kule œmieciowe,\n");
    printf("          (1) pokrywê od œmietnika,\n");
    printf("          (1) zgni³¹ marchewkê,\n");
    printf("          (2) zepsute ¿arówki,\n");
    printf("          to znajdê dla ciebie tyle karmy, ile tylko chcesz.\033[0m\n\n");

    //int junk_sphere;
    //int garbage_can_lid;
    //int rotten_carrot;
    //int broken_light_bulb;

    while (1) {
        printf("Benedykt: Czy masz ju¿ te czêœci? (tak/nie)\n");
        scanf("%9s", answer);

        if ((strcmp(answer, "tak") == 0) && alfred.junk_sphere >= 2 && alfred.garbage_can_lid >= 1 && alfred.rotten_carrot >= 1 && alfred.broken_light_bulb >= 2) {
            printf("\033[95mBenedykt: Wspaniale! Moje dzieci bêd¹ zachwycone!\n");
            printf("          W zamian za twoj¹ pomoc, oto karma dla twojej rodziny.\033[0m\n");
            printf("Alfred: Dziêkujê, Benedykcie! Uratowa³eœ moj¹ rodzinê!\n");
            printf("\033[95mBenedykt: Do zobaczenia, Alfredzie! Powodzenia!\033[0m\n");
            printf("Kliknij Enter...\n");
            getchar();
            getchar();
            racoon_ending();
            break;
        }
        else if ((strcmp(answer, "tak") == 0) && (alfred.junk_sphere < 2 || alfred.garbage_can_lid < 1 || alfred.rotten_carrot < 1 || alfred.broken_light_bulb < 2)) {
            printf("Nie masz wystarczaj¹co du¿o wszystkich elementów œmieciowego ba³wana");
            getchar();
            getchar();
        }
        else if (strcmp(answer, "nie") == 0) {
            printf("\033[95mBenedykt: Hmm, w takim razie wróæ, gdy zdobêdziesz wszystkie czêœci.\033[0m\n");
            printf("          Moje dzieci bardzo na to czekaj¹...\n");
            printf("Alfred: W porz¹dku, Benedykcie. Wrócê, gdy wszystko znajdê.\n");
            printf("Kliknij Enter...\n");
            getchar();
            getchar();
            rubbish_dump_menu();
            break;
        }
        else {
            system("cls");
            printf("Wprowadzi³eœ niepoprawn¹ wartoœæ spróbuj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
            getchar();
        }
    }

}


void rubbish_dump_menu(){
    system("cls");
    printf("Wszed³eœ na teren wysypiska\n");
    printf("Wokó³ na pierwszy rzut oka widaæ by³o tylko góry ró¿nego rodzaju œmieci.\n W oddali dostrzeg³eœ jednak zwierzêc¹ sylwetkê\n");
    while (1) {
        char dump_menu_choice_1;
        printf("Co robisz?\n");
        printf("(1)Poszukuj przedmiotów w górze œmieci\n(2)PodejdŸ do tajemniczej figury\n(3)¿eby opuœciæ to miejsce\n");
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
            printf("Wprowadzi³eœ niepoprawn¹ wartoœæ spróbuj jeszcze raz\n");
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
