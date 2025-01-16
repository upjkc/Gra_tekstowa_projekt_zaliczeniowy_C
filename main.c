
/*

Jednor�ki Bandyta - by Jacek Pucha�ko

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

 G� - by Jacek Pucha�ko
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


 Martwa G� robi szpagat - by Jacek Pucha�ko

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
#include <locale.h>//Gra korzysta z polskich znak�w st�d zastosowanie tej biblioteki
#include <ctype.h>
#include <stdbool.h>//Program korzysta ze zmiennej bool w strukturze (kt�ra przetrzymuje dane gracza: umiej�tno�ci kt�re posiada gracz, zasoby pozyskane przez gracza) bool jest u�yty jako true/false dla umiej�tno�ci kt�re posiada gracz
#include <stdlib.h>
#include <time.h>
#include <windows.h>//Program zosta� napisany na widowsie jako gra na windowsa st�d u�ycie biblioteki windows.h + program u�ywa system("cls"); �eby zwi�kszy� czytelno�� tekstu w konsoli

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
    "Alfred",               // Imi� g�si
    false,                  // Umiej�tno�� korzystania z pieni�dzy
    //false,                  // Umiej�tno�� korzystania z drukarki
    //false,                  // Zainspirowanie g�si
    0,                      // Ilo�� pieni�dzy
    0,                      // Ilo�� work�w karmy
    0,                      // Kula �mieci
    0,                      // Pokrywa od kub�a na �mieci
    0,                      // przegni�a marchewka
    0                       // Nie dzia�aj�ca �ar�wka
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
    printf("G� o imieniu %s:\n", alfred.name);
    printf("Umiej�tno�ci:\n");
    printf("  - Korzystanie z pieni�dzy: %s\n", alfred.using_money_ability ? "Tak" : "Nie");
    printf("Pieni�dze i Karma:\n");
    printf("  - Ilo�� pieni�dzy: %d\n", alfred.money);
    printf("  - Ilo�� work�w karmy: %d\n", alfred.goose_food);
    printf("Cz�ci �mieciowego ba�wana:\n");
    printf("  - Kule �mieciowe: %d\n", alfred.junk_sphere);
    printf("  - Pokrywy od kub�a na �mieci: %d\n", alfred.garbage_can_lid);
    printf("  - przegni�e marchewki: %d\n", alfred.rotten_carrot);
    printf("  - Nie dzia�aj�ce �ar�wki: %d\n", alfred.broken_light_bulb);

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
        printf("�eby powr�ci� do mapy miasta wpisz (m)\n");
        scanf(" %c", &back_to_the_city);
        if (back_to_the_city == 'm') {
            city_menu();
            break;
        }
        else {
            printf("Poda�e� nie poprawn� warto��. Spr�buj jeszcze raz\n");
        }
    } while (1);
}

void go_back_to_home_ending() {
    while (1) {
        char last_choice;
        printf("Czy napewno chcesz u�y� tej opcji?\n");
        printf("Je�eli zawr�cisz do domu bez potrzebnego jedzenia nie b�dziesz mia� ju� wi�cej czasu �eby je zdoby�.\n");
        printf("Czy napewno chcesz zawr�ci� do domu?\n");
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
            printf("Nieprawid�owy wyb�r.\n");
            printf("\nNaci�nij Enter...");
            getchar();
            getchar();
        }
    }


    if (alfred.goose_food >= 20) {
        printf("\033[33mWygra�e�. Przynios�e� rodzinie jedzenie, kt�rego potrzebowali �eby przetrwa�\n");
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
        printf("\033[31mPrzegra�e�. Nie przynios�e� swojej rodzinie dostatecznej ilo�ci G�siego jedzenia �eby przetrwali zim�\n");
        printf("       ______      _____ _________ _                   \n");
        printf("      /%c     %c____/     /         %c  %c__               \n", 92, 92, 92, 92);
        printf("     /  |   X  ___                _/   _/              \n");
        printf("    /___|_____)  %c_      _____/     _/                 \n", 92);
        printf("|^^________________%c_           ___/________________^^|\n", 92);
        printf("|____________________%c_________/______________________|\n\n\n", 92);
        printf("Przegrana\033[0m\n");
        while (1) {
            printf("Czy chcesz zagra� ponownie czy zako�czy� rozgrywk�:\n");
            printf("(1) Zako�cz rozgrywk�\n");
            printf("(2) Zagraj ponownie\n");

            int ending_choice;
            int result = scanf(" %d", &ending_choice);

            if (result != 1) {

                printf("Wprowadzi�e� niepoprawn� warto��. Spr�buj ponownie.\n");
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
                printf("Wprowadzi�e� niepoprawn� warto��. Spr�buj ponownie.\n");
            }
        }
    }

}

//-------------------------------------------------------------------Prolog i pocz�tek Gry-------------------------------------------------------------------------------------------------------------------/
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

        printf("\n\n\nAby rozpocz�� rozgrywk� wci�nij Enter...");
        getchar();

        system("cls");
        printf("Nazywasz si� Albert. Jeste� g�si�, kt�ra �yje w swoim domu (gniezdzie) na polanie wraz ze swoim m�odszym rodze�stwem.\nZbli�a si� zima i musisz zadba� o to �eby� ty i twoje m�odsze rodze�stwo mieli co je��.\nW tym celu masz zamiar wyruszy� do miasta bo s�ysza�e�, �e tam naj�atwiej zdoby� pokarm\n");
        printf("�eby twoja rodzina przetrwa�a zim� musisz uzbiera� 20 work�w karmy dla g�si.\n");

        printf("\nAby kontynuowa� wci�nij Enter...\n");
        getchar();

}




void start() {
    system("cls");
    printf("HONK!\n");
    printf("Wzi��e� ze sob� g�si plecak i jeste� gotowy do drogi\n");
    printf("(m)�eby wyruszy� do Miasta ludzk� drog�\n");

    do {
        scanf(" %c", &select_location);
        select_location = tolower(select_location);

        if (select_location == 'm') {
            way_to_the_city();
            break;
        }
        else {
            printf("Wprowadzono niepoprawn� warto��. Spr�buj ponownie.\n");
        }
    } while (1);
}


void way_to_the_city() {
    system("cls");
    char risky_money_choice[10];
    printf("Ida� drog� do miasta zauwa�asz na jej �rodku b�yszcz�cy przedmiot przypominaj�cy monet�\n");
    printf("Czy chcesz podje�� i podnie�� przedmiot, czy wolisz odrazu i�� dalej\n");
    printf("Wpisz:\n(tak)je�li chcesz podnie�� przedmiot\n(nie)je�li chcesz go pomin��\n");
    while (1) {
        scanf("%9s", risky_money_choice);

        if (strcmp(risky_money_choice, "tak") == 0) {
            system("cls");
            int random_number = rand() % 100;

            if (random_number < 80) {
                add_money(5);
                printf("\033[33mPodnios�e� 5$ i ruszasz dalej do miasta\033[0m\n");
                printf("Kliknij Enter aby kontynuowa�...\n");
                getchar();
                getchar();
                city_menu();
            }
            else {
                printf("\033[31mMia�e� pecha i potr�ci� ci� tir\n");
                printf("       ______      _____ _________ _                   \n");
                printf("      /%c     %c____/     /         %c  %c__               \n", 92, 92, 92, 92);
                printf("     /  |   X  ___                _/   _/              \n");
                printf("    /___|_____)  %c_      _____/     _/                 \n", 92);
                printf("|^^________________%c_           ___/________________^^|\n", 92);
                printf("|____________________%c_________/______________________|\n\n\n", 92);
                printf("Przegrana\033[0m\n");
                while (1) {
                    printf("Czy chcesz zagra� ponownie czy zako�czy� rozgrywk�:\n");
                    printf("(1) Zako�cz rozgrywk�\n");
                    printf("(2) Zagraj ponownie\n");

                    int ending_choice;
                    int result = scanf(" %d", &ending_choice);

                    if (result != 1) {

                        printf("Wprowadzi�e� niepoprawn� warto��. Spr�buj ponownie.\n");
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
                        printf("Wprowadzi�e� niepoprawn� warto��. Spr�buj ponownie.\n");
                    }
                }
            }
            break;
        }
        else if (strcmp(risky_money_choice, "nie") == 0) {
            system("cls");
            printf("Ruszy�e� w dalsz� drog� do miasta\n");
            printf("Kliknij Enter aby kontynuowa�...\n");
            getchar();
            getchar();
            city_menu();
            break;
        }
        else {
            system("cls");
            printf("Wprowadzi�e� niepoprawn� warto�� spr�buj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
            getchar();
        }
    }
}

//-------------------------------------------------------------------Prolog i pocz�tek Gry-------------------------------------------------------------------------------------------------------------------/

void show_credits() {
    printf("Gra stworzone przez: Jacek Pucha�ko\n");
    printf("ASCII art g�, maszyna losuj�ca: Jacek Pucha�ko\n");
    printf("ASCII arty zaporzyczone z na potrzeby projektu z www.asciiart.eu: \n");
    printf("  - ASCII art Szop: Joan Stark - art from https://www.asciiart.eu/animals/cats \n");
    printf("  - ASCII art Miasta: (Autor nie by� podany na stronie) https://www.asciiart.eu/buildings-and-places/cities \n");
    printf("Wszelkie ASCII arty napis�w zosta�y stworzone za pomoc� generatora: https://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%%20Something%%20 \n\n");
    go_back_to_the_city();
}







//------------------------------------------------------------------------Main Menu--------------------------------------------------------------------------------------------------------------------------/

void city_menu() {
    system("cls");
    printf("Witaj w mie�cie\n");
    printf("                                    +					\n");
    printf("                                   / %c					\n",92);
    printf(" _____        _____     __________/ o %c/%c_________      _________	\n",92,92);
    printf("|o o o|_______|    |___|               | | # # #  |____|o o o o  | /%c	\n",92);
    printf("|o o o|  * * *|: ::|. .|               |o| # # #  |. . |o o o o  |//%c%c	\n",92,92);
    printf("|o o o|* * *  |::  |. .| []  []  []  []|o| # # #  |. . |o o o o  |((|))	\n");
    printf("|o o o|**  ** |:  :|. .| []  []  []    |o| # # #  |. . |o o o o  |((|))	\n");
    printf("|_[]__|__[]___|_||_|__<|____________;;_|_|___/%c___|_.|_|____[]___|  |	\n\n\n",92);
    printf("W mie�cie jest wiele miejsc i budynk�w. Wybierz, kt�ry z nich chcia�by� odwiedzi�:\n");
    printf("(b) Bank\n(s) Sklep\n(a) Kasyno\n(w) Wysypisko\n(m) Ma�e Zoo\n");
    printf("\nW tym miejscu mo�esz r�wnie� wybra�:\n(i)Zajrzyj do ekwipunku\n(z)Zawr�� do domu\n(c)Credits\n\n");



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
            printf("Oto tw�j ekwipunek:\n");
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
            printf("Nieprawid�owy wyb�r.\n");
            printf("\nNaci�nij Enter...");
            getchar();
            getchar();
            city_menu();
        }
}
//------------------------------------------------------------------------Main Menu--------------------------------------------------------------------------------------------------------------------------/

//------------------------------------------------------------------------Bank-------------------------------------------------------------------------------------------------------------------------------/
void bank_worker() {
    char conversation_choice;
    printf("\033[36mPracowniczka banku:  Dzie� dobry w czym mog� pom�c?! Czy pan jest G�si�?\033[0m\n(t)tak\n(n)nie\n");
    scanf(" %c", &conversation_choice);

    if (conversation_choice == 't') {
        printf("\033[36mPracowniczka banku:  W takim razie w czym mog� pom�c?\033[0m\n(1)Zdob�d� informacje o tym jak u�ywa� pieni�dzy\n(2)Odejd�\n");
    }
    else{
        printf("\033[36mPracowniczka banku:  Przepraszam pana s�abo widz� bez okular�w. W takim razie w czym mog� pom�c?\033[0m\n(1)Zdob�d� informacje o tym jak u�ywa� pieni�dzy\n(wci�nij jaki kolwiek inny przycisk)Odejd�\n");
    }
    scanf(" %c", &conversation_choice);
    if (conversation_choice == '1') {
        printf("\033[36mPracowniczka banku:  Pieni�dz to powszechnie akceptowany �rodek wymiany i przechowywania warto�ci.\nPe�ni rol� uniwersalnego �rodka p�atniczego w transakcjach handlowych.\nPieni�dz u�atwia wymian� d�br i us�ug oraz umo�liwia dokonywanie pomiaru warto�ci.\033[0m\n");
        update_ability(0, true);
        printf("\033[33m\nBrawo Alfred dowiedzia� si� czym s� pieni�dze i jak ich u�ywa�!\n\033[0m");
        printf("Wci�nij dowolny przycisk �eby wr�ci� na hol g��wny banku\n");
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
    printf("W banku widzisz pracowniczk� banku i szefa banku, kt�ry rozmawia z jednym ze swoich pracownik�w\n");
    printf("Wybierz co chcesz zrobi� w banku:\n(1)Porozmawiaj z pracowniczk� banku\n(2)Porozmawiaj z szefem banku\n(3)Wyjd� z banku\n");
        char bank_worker_choice;
        scanf(" %c", &bank_worker_choice);
        
        if (bank_worker_choice == '1') {
            bank_worker();
        }
        else if (bank_worker_choice == '2') {
            printf("Szef banku jest w tej chwili zaj�ty i nie mo�e z tob� porozmawia�.\nWci�nij dowolny przycisk �eby wr�ci�\n");
            getchar();
            getchar();
            bank_menu();
        }
        else if (bank_worker_choice == '3') {
            go_back_to_the_city();
        }
        else {
            printf("Wprowadzono niepoprawne dane.\nWci�nij dowolny przycisk �eby spr�bowa� jeszcze raz\n");
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
        printf("\033[31mSprzedawca atakuje miot��! Straci�e� 10 HP!\033[0m\n");
        goose_hp -= 10;
    }
    else {
        printf("Sprzedawca nie trafi� ci� miot��!\n");
    }
}

void player_peck() {
    // Gracz ma 100% szans na trafienie za 5hp
    printf("\033[32mDziobiesz Sprzedawc� za 5 HP!\033[0m\n");
    sellers_hp -= 5;
}

void player_scare_HONK() {
    if (rand() % 100 < 30) {  // 30% szansy na zastraszenie oponenta
        printf("\033[32mSprzedawca uciek� w strachu! Walka zako�czona!\033[0m\n");
        sellers_hp = 0;  // Zmiana hp sprzedawcy na 0, �eby p�tla przesta�a dzia�a�
    }
    else {
        printf("Pr�ba zastraszenia nie powiod�a si�!\n");
    }
}

void display_hp() {
    printf("HP Alfred: %d | HP Sprzedawca: %d\n", goose_hp, sellers_hp);
}

void shopseller_fight() {
    system("cls");
    char fight_or_no_fight;
    printf("Czy na pewno chcesz zabra� karm� dla g�si ze sklepu bez pozwolenia w�a�ciciela?\n(t)tak\n(dowolny znak, litera lub liczba)nie\n");
    scanf(" %c", &fight_or_no_fight);

    if (fight_or_no_fight == 't') {
        printf("\033[31mKiedy pr�bowa�e� wymkn�� si� z 20 workami karmy dla g�si ze sklepu, twoje poczynania zauwa�y� Sprzedawca.\nWzi�� miot�� i postanowi� zapobiec kradzie�y.\nStan�� z tob� do pojedynku na �mier� i �ycie.\033[0m\n");

        char attack_move_choice;
        int round = 1;

        while (goose_hp > 0 && sellers_hp > 0) {
            printf("\nRunda %d:\n", round);
            display_hp();  

            // Tura gracza, wyb�r akcji
            printf("Wybierz akcj�:\n");
            printf("(a) Dziobanie (5 obra�e�)\n");
            printf("(b) HONK! (30%c szans na zastraszenie oponenta)\n",37);
            scanf(" %c", &attack_move_choice);

            if (attack_move_choice == 'a') {
                player_peck();  
            }
            else if (attack_move_choice == 'b') {
                player_scare_HONK();  
            }
            else {
                printf("Niepoprawny wyb�r. Spr�buj ponownie.\n");
                continue;
            }

            // Sprawdzenie, czy walka zako�czy�a si� po akcji gracza
            if (sellers_hp <= 0) {
                printf("Pokona�e� Sprzedawc�!\n");
                printf("\033[33mUciekasz ze sklepu z �upem\033[0m\n");
                add_goose_food(20);
                printf("Naci�nij Enter, aby wyj�� ze sklepu...\n");
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
                    printf("Zosta�e� pokonany przez Sprzedawc�!\n");
                    printf("Przez to nie wr�ci�e� do swojej g�siej rodziny i twoje dzieci umar�y z powodu zimna i g�odu.\033[0m\n");
                    printf("Czy chcesz zagra� ponownie czy zako�czy� rozgrywk�:\n");
                    printf("(1) Zako�cz rozgrywk�\n");
                    printf("(2) Zagraj ponownie\n");

                    int ending_choice;
                    int result = scanf(" %d", &ending_choice);

                    if (result != 1) {

                        printf("Wprowadzi�e� niepoprawn� warto��. Spr�buj ponownie.\n");
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
                        printf("Wprowadzi�e� niepoprawn� warto��. Spr�buj ponownie.\n");
                    }
                }
            }

            // Tura Sprzedawcy, atakuje gracza
            npc_attack();  // Sprzedawca atakuje gracza

            // Sprawdzenie, czy walka zako�czy�a si� po ataku Sprzedawcy
            if (sellers_hp <= 0) {
                printf("Pokona�e� Sprzedawc�!\n");
                printf("\033[33mUciekasz ze sklepu z �upem\033[0m\n");
                add_goose_food(20);
                printf("Naci�nij Enter, aby wyj�� ze sklepu...\n");
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
                    printf("Zosta�e� pokonany przez Sprzedawc�!\n");
                    printf("Przez to nie wr�ci�e� do swojej g�siej rodziny i twoje dzieci umar�y z powodu zimna i g�odu.\033[0m\n");
                    printf("Czy chcesz zagra� ponownie czy zako�czy� rozgrywk�:\n");
                    printf("(1) Zako�cz rozgrywk�\n");
                    printf("(2) Zagraj ponownie\n");

                    int ending_choice;
                    int result = scanf(" %d", &ending_choice);

                    if (result != 1) {
                        
                        printf("Wprowadzi�e� niepoprawn� warto��. Spr�buj ponownie.\n");
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
                        printf("Wprowadzi�e� niepoprawn� warto��. Spr�buj ponownie.\n");
                    }
                }
            }

            round++;
        }
    }
    else {
        printf("Naci�nij Enter, aby wyj�� ze sklepu...\n");
        getchar();
        getchar();
        city_menu();
    }
}
// Walka do doko�czenia koniecznie (zako�czenia walki do zrobienia)
//------------------------------------------------------------------------Opcjonalna_Walka-----------------------------------------------------------/



//------------------------------------------------------------------------Zakupy---------------------------------------------------------------------/
void shop_menu() {
    char shop_choice;
    char shop_choice_2;
    int quantity_of_goose_food_bags;
    system("cls");
    printf("Wszed�e� do Sklepu. W powietrzu uda�o ci si� wyczu� wo� karmy dla g�si. Widzisz Sprzedawc� co robisz?\n");
    printf("(a)Podejdz do sprzedawcy\n(b)spr�buj okra�� sklep\n(dowolna znak, litera lub liczba) Wyjd� ze sklepu\n");
    scanf(" %c", &shop_choice);

    if ((shop_choice == 'a') && (alfred.using_money_ability == true)) {
        printf("\n\033[34mSprzedawca: Dzie� dobry w czym mog� pom�c\033[0m\n");
        printf("Alfred: Potrzebuje G�siej karmy HONK!\n");
        printf("\033[34mSprzedawca: Jedna torba g�siej karmy kosztuje 10$\033[0m\n");
        printf("Alfred: ILE? HONK?!\n");
        printf("(1)Je�li chcesz kontynuowa� konwersacj� wci�nij\n(2)je�eli chcesz wyj�� ze sklepu)\n");
        scanf(" %c", &shop_choice_2);

        if ((shop_choice_2 == '1') && (alfred.money >= 10) && (alfred.using_money_ability == true)) {
            do {
                printf("\033[34mSprzedawca: Ile chce pan kupi� work�w?\033[0m\n");
                printf("Ile obecnie masz pieni�dzy = %d\n", alfred.money);

                if ((scanf("%d", &quantity_of_goose_food_bags) == 1)) {
                    if (quantity_of_goose_food_bags <= 0) {
                        printf("Nie mo�esz kupi� '%d' work�w. Wprowad� liczb� wi�ksz� od zera.\n", quantity_of_goose_food_bags);
                        continue; // Powr�t do pocz�tku p�tli
                    }

                    if ((quantity_of_goose_food_bags * 10) <= alfred.money) {
                        printf("\033[34mSprzedawca: Oto pana zakupy: \033[33m'%d'\033[34m work�w z g�si� karm�.\033[0m\n", quantity_of_goose_food_bags);

                        add_goose_food(quantity_of_goose_food_bags);
                        add_money(-(quantity_of_goose_food_bags * 10));

                        printf("Naci�nij Enter, aby kontynuowa�...\n");
                        getchar();
                        getchar();
                        shop_menu();
                        break;
                    }
                    else {
                        printf("Nie masz wystarczaj�co du�o pieni�dzy na zakup '%d' work�w z g�si� karm�.\n", quantity_of_goose_food_bags);
                    }
                }
                else {
                    printf("Poda�e� warto��, kt�ra nie jest numerem. Pon�w pr�b� wprowadzenia warto�ci.\n");
                    while (getchar() != '\n'); 
                }
            } while (1);
        }
        else if ((shop_choice_2 == '1') && (alfred.money < 10) && (alfred.using_money_ability == true)) {
            printf("Nie masz wystarczaj�co du�o pieni�dzy �eby kupi� g�si� karm�\n");
            printf("Naci�nij Enter, aby kontynuowa�...\n");
            getchar();
            getchar();
            shop_menu();
        }
        else if ((shop_choice_2 == '1') && (alfred.using_money_ability == false)) {
            printf("Nie wiesz jak dzia�aj� pieni�dze wi�c nie mo�esz nic kupi�.\nDowiedz si� jak dzia�aj� pieni�dze\n");
            printf("Naci�nij Enter, aby kontynuowa�...\n");
            getchar();
            getchar();
            shop_menu();
        }
        else if(shop_choice_2 == '2') {
            go_back_to_the_city();
        }
        else {
            printf("Poda�e� niew�a�ciw� Dan�");
            printf("Naci�nij Enter, aby kontynuowa�...\n");
            getchar();
            getchar();
            shop_menu();
        }
    }
    else if ((shop_choice == 'a') && (alfred.using_money_ability == false)) {
        printf("Nie wiesz jak dzia�aj� pieni�dze wi�c nie mo�esz nic kupi�.\nDowiedz si� jak dzia�aj� pieni�dze\n");
        printf("Naci�nij Enter, aby kontynuowa�...\n");
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
        printf("\033[33mMaszyna do gry (jednor�ki bandyta)\n\n");
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
        printf("Maszyna do gry (jednor�ki bandyta)\n\n");
        printf("      ___________      \n");
        printf("     /___________%c     \n", 92);
        printf("     |  _______  | ({})\n");
        printf("     |  |%d|%d|%d|  |  || \n", random_number_1, random_number_2, random_number_3);
        printf("     |  ```````  |__|| \n");
        printf("     |:::::::::::|---' \n");
        printf("     |           |     \n");
        printf("     |:::::::::::|     \n");
        printf("     |___________|     \n\n");
        printf("Niczego nie wygra�e�\n");

    }
}


void slot_machine() {
    while (1) {
        system("cls");
        printf("�eby zagra� musisz wrzuci� 2$ do maszyny\n");
        printf("czy chcesz zagra�?\n(t)tak\n(n)nie\n");

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
                printf("\033[33mMaszyna do gry (jednor�ki bandyta)\n\n");
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
                printf("\nczy chcesz zagra� jeszcze raz?\n(t)tak\n(n)nie\n");

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
                    printf("\nUzale�ni�e� si� od hazardu i straci�e� wszyckie pieni�dze.\nPrzez swoje uzale�nienie nie wr�ci�e� do swojej rodziny i wszyscy umarli przez zag�odzenie\033[0m\n");

                    while (1) {
                        printf("Czy chcesz zagra� ponownie czy zako�czy� rozgrywk�:\n");
                        printf("(1) Zako�cz rozgrywk�\n");
                        printf("(2) Zagraj ponownie\n");

                        int ending_choice;
                        printf("Tw�j wyb�r: ");
                        int result = scanf(" %d", &ending_choice);

                        if (result != 1) {

                            printf("Wprowadzi�e� niepoprawn� warto��. Spr�buj ponownie.\n");
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
                            printf("Wprowadzi�e� niepoprawn� warto��. Spr�buj ponownie.\n");
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

                    printf("\nGratulacje wygra�e�.\nDzi�ki temu, �e zdoby�e� tyle pieni�dzy, twoja rodzina nie b�dzie g�odna przez najbli�sze kilka lat.\nTa zima b�dzie dla was �agodna i b�dziecie cieszy� si� dostatnim �yciem\n\n\n");
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
                printf("Maszyna do gry (jednor�ki bandyta)\n\n");
                printf("      ___________      \n");
                printf("     /___________%c     \n", 92);
                printf("     |  _______  | ({})\n");
                printf("     |  |%d|%d|%d|  |  || \n",random_number_1, random_number_2, random_number_3);
                printf("     |  ```````  |__|| \n");
                printf("     |:::::::::::|---' \n");
                printf("     |           |     \n");
                printf("     |:::::::::::|     \n");
                printf("     |___________|     \n\n");
                printf("Niczego nie wygra�e�\n");
                printf("\nczy chcesz zagra� jeszcze raz?\n(t)tak\n(n)nie\n");
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
            printf("nie masz wystarczaj�co du�o pieni�dzy �eby zagra�\n");
            go_back_to_the_city();
            break;
        }
        else if (slot_machine_choice_1 == 'n') {
            go_back_to_the_city();
            break;
        }
        else {
            system("cls");
            printf("wprowadzi�e� niepoprawn� dan�\n");
            printf("Naci�nij Enter, aby kontynuowa�...\n");
            getchar();
            getchar();
        }
    }
}








void casino_menu() {
    char casino_choice_1;
    system("cls");
    printf("Wszed�e� do Kasyna. Masz wra�enie, �e to miejsce jest wype�niane negatywnymi emocjami i rozgoryczeniem.\nWidzisz ludzi, kt�rzy siedz� przed maszynami i wykonuj� w k�ko jedn� czynno��.\nRaz wydaj� si� podekscytowani, a zaraz potem smutni.\n\n\n");

    if (casino_enters_counter == 0) {
        while (1) {
            char casino_choice_first_time;
            printf("\033[35mPracownik kasyna: Dzie� dobry. Witaj w kasynie 'El Goose de la gazpacho'. W czym mog� pom�c? Jaka� maszyna nie dzia�a?\033[0m\n\n");
            printf("Alfred: Szukam sposobu, �eby pozyska� g�si� karm�. Dok�adniej 20 work�w g�siej karmy.\n\n");
            printf("\033[35mPracownik kasyna: Je�eli zagra pan u nas w jednor�kiego bandyt�, ma pan szanse na wygranie ogromnej puli pieni�dzy, dzi�ki kt�rej b�dzie pan m�g� kupi� tyle g�siej karmy, ile pan zechce.\033[0m\n");
            printf("\033[35m�eby wygra� w tej grze wysztkie 3 wylosowane przez maszyn� liczby musz� by� jednakowe, ka�dy inny wynik b�dzie uznawany za przegran�.\033[0m\n\n");
            printf("\n\033[35mPracownik kasyna: Czy chce pan spr�bowa� zagra�?\033[0m\n(t)tak\n(n)nie\n");
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
                printf("Wprowadzi�e� niepoprawn� warto��.\n");
                continue;
            }
        }
        casino_enters_counter += 1;
    }

    while (1) {
        printf("czy chcesz podej�� do stanowiska do gry w jednor�kiego bandyt�?\n(t)tak\n(n)nie\n");
        scanf(" %c", &casino_choice_1);
        if ((casino_choice_1 == 't') && (alfred.using_money_ability == true)) {
            casino_enters_counter += 1;
            slot_machine();
            
            break;
        }
        else if((casino_choice_1 == 't') && (alfred.using_money_ability == false)){
            printf("Nie wiesz jak dzia�aj� pieni�dze wi�c nie mo�esz zagra� w kasynie.\nDowiedz si� jak dzia�aj� pieni�dze\n");
            go_back_to_the_city();
        }
        else if (casino_choice_1 == 'n') {
            casino_enters_counter += 1;
            go_back_to_the_city();
            return;
        }
        else {
            system("cls");
            printf("Wprowadzi�e� niepoprawn� warto��.\n");
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
    printf("Rozpocz�cie godziny pracy\n");
    printf("Problem 1\nDziecko pr�buje z�apa� ci� za skrzyd�o. Co robisz?\n");
    printf("(1)Uciekasz\n(2)Uderzasz je lekko skrzyd�em\n");
    scanf(" %c", &zoo_work_choice_1);

        if (zoo_work_choice_1 == '1') {
            printf("Uda�o ci si� uciec.\n");
            paycheck += 5;
            break;
        }
        else if (zoo_work_choice_1 == '2') {
            printf("Dziecko zacz�o p�aka�, szef potr�ci ci z wyp�aty.\n");
            break;
        }
        else {
            printf("Wprowadzi�e� niepoprawn� warto��, spr�buj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
            continue;
        }
    }

    while (1) {
        system("cls");
    printf("Problem 2\nDziecko chce ci� dokarmi�\n");
    printf("(1)Zjedz jedzenie, kt�re da�o ci dziecko\n(2)Odejd�\n");
    scanf(" %c", &zoo_work_choice_2);

        if (zoo_work_choice_2 == '1') {
            printf("Jedzenie nie by�o g�si� karm�, ale o dziwo ci nie zaszkodzi�o\n");
            paycheck += 20;
            break;
        }
        else if (zoo_work_choice_2 == '2') {
            printf("Dziecko przysz�o na skarg� do szefa, a ten potr�ci� ci z wyp�aty.\n");
            break;
        }
        else {
            printf("Wprowadzi�e� niepoprawn� warto��, spr�buj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
            continue;
        }
    }

    while (1) {
        system("cls");
    printf("Problem 3\nDziecko zmierza w twoj� stron� i chce ci� pog�aska�\n");
    printf("(1)Ucieknij\n(2)Ukryj si�\n");
    scanf(" %c", &zoo_work_choice_3);

        if (zoo_work_choice_3 == '1') {
            printf("Uciek�e� w pop�ochu, niestety zauwa�y� to tw�j szef.\n");
            break;
        }
        else if (zoo_work_choice_3 == '2') {
            printf("Dziecko ci� nie znalaz�o i posz�o pog�aska� os�a obok twojej kryj�wki.\n");
            paycheck += 10;
            break;
        }
        else {
            printf("Wprowadzi�e� niepoprawn� warto��, spr�buj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
            continue;
        }
    }

    while (1) {
        system("cls");
    printf("Problem 4\nDziecko rzuci�o w ciebie kamieniem. Na szcz�cie nie trafi�o\n");
    printf("(1)HONK!\n(2)Podzi�b\n");
    scanf(" %c", &zoo_work_choice_4);

        if (zoo_work_choice_4 == '1') {
            printf("Wystraszy�e� dziecko, ale pracodawca zrozumia�, �e to by�a samoobrona, wi�c nie potr�ci� ci z wyp�aty.\n");
            paycheck += 5;
            break;
        }
        else if (zoo_work_choice_4 == '2') {
            printf("Zadrapa�e� dziobem dziecko, ale pracodawca mimo wszystko potr�ci� ci z wyp�aty.\n");
            break;
        }
        else {
            printf("Wprowadzi�e� niepoprawn� warto��, spr�buj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
        }
    }

    printf("\033[33mZa przepracowan� godzin� dosta�e� zap�at� w wysoko�ci %d$\033[0m\n", paycheck);
    add_money(paycheck);
    go_back_to_the_city();
}




void mini_Zoo_menu() {
    while (1) {
        char mini_zoo_choice_1;
        char mini_zoo_choice_2;
        printf("Ma�e Zoo\n");
        printf("\033[92mSzef ma�ego Zoo: Witaj w ma�ym zoo. Czemu tu si� zjawi�e� nie przypominam sobie �eby�my hodowali g�si?\033[0m\n");
        printf("Alfred: Widzi pan, potrzebuj�...\n");
        printf("(k)karmy\n(n)nie potrzebuje niczego\n");
        scanf(" %c", &mini_zoo_choice_1);
        if (mini_zoo_choice_1 == 'k') {
            printf("\033[92mSzef ma�ego Zoo: Skoro potrzebuje pan karmy, mog� zaoferowa� panu prac� na najbli�sz� godzin�. B�dzie pan zabawia� u nas dzieci a w zamian otrzyma pan pieni�dze za, kt�re mo�e pan kupi� karm�\033[0m\n");
            printf("Alfred: Czyli dostan� karm�? czy tylko pieni�dze?\n");
            printf("\033[92mSzef ma�ego Zoo: Dostanie pan walut� za, kt�r� b�dzie pan m�g� kupi� karm�.\nJe�eli pan nie wie jak dzia�a waluta powinien si� pan potem zg�osi� do banku, tam panu wszystko wyt�umacz�.\033[0m\n");
            while (1) {
                printf("\033[92mSzef ma�ego Zoo: To jak chce pan u nas pracowa�?\033[0m\n");
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
                    printf("Wprowadzi�e� niepoprawn� warto�� spr�buj jeszcze raz\n");
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
            printf("Wprowadzi�e� niepoprawn� warto�� spr�buj jeszcze raz\n");
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
            printf("\033[33mZnalaz�e� Kule �mieci\033[0m\n");
        }
        else if (random < 80) {
            add_junk_part(1, 1);
            printf("\033[33mZnalaz�e� Pokrywe od kub�a na �mieci\033[0m\n");
        }
        else if (random < 90) {
            add_junk_part(2, 1);
            printf("\033[33mZnalaz�e� zgni�� marchewk� \033[0m\n");
        }
        else if (random < 95) {
            add_junk_part(3, 1);
            printf("\033[33mZnalaz�e� nie dzia�aj�c� �ar�wk� \033[0m\n");
        }
        else {
            add_money(5);
            printf("\033[33mZnalaz�e� drobne w �mieciach (5$)\033[0m\n");
        }

        while (1) {
            printf("Czy chcesz dalej przeszukiwa� stert� �mieci?\nWpisz (tak), (nie):\n");
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
                printf("Wprowadzi�e� niepoprawn� warto�� spr�buj jeszcze raz\n");
                printf("Kliknij Enter...\n");
                getchar();
            }
        }
    }
}


void racoon_ending() {
    system("cls");
    printf("\033[33mDzi�ki jedzeniu, kt�re zdoby� dla ciebie Benedykt twoja rodzina przetrwa�a zim�.\n\n");
        printf("Wygra�e�\n");
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

    printf("\033[95mBenedykt: Witaj przybyszu, nazywam si� szop Benedykt. Czego tu szukasz?\033[0m\n");
    printf("Alfred: Witaj Benedykcie! Jestem Alfred. Poszukuj� karmy dla g�si.\n");
    printf("        Potrzebuj� jej, �eby moja rodzina nie g�odowa�a przez zim�.\n");
    printf("        Masz mo�e troch� karmy?\n");

    printf("\033[95mBenedykt: Niestety nie, Alfredzie. Ale mog� j� ukra�� dla ciebie, je�li mi pomo�esz.\033[0m\n");
    printf("Alfred: W takim razie, jak mog� ci pom�c?\n");

    printf("\033[95mBenedykt: Moje dzieci zawsze chcia�y zobaczy� ba�wana ze �niegu w zim�,\n");
    printf("          ale na wysypisku i w og�le w mie�cie rzadko pada �nieg.\n");
    printf("          W zwi�zku z tym chc� im wybudowa� ba�wana z cz�ci znalezionych tutaj,\n");
    printf("          �eby by�y szcz�liwe.\033[0m\n");

    printf("\033[95mBenedykt: Je�eli przyniesiesz mi:\n");
    printf("          (3) kule �mieciowe,\n");
    printf("          (1) pokryw� od �mietnika,\n");
    printf("          (1) zgni�� marchewk�,\n");
    printf("          (2) zepsute �ar�wki,\n");
    printf("          to znajd� dla ciebie tyle karmy, ile tylko chcesz.\033[0m\n\n");

    //int junk_sphere;
    //int garbage_can_lid;
    //int rotten_carrot;
    //int broken_light_bulb;

    while (1) {
        printf("Benedykt: Czy masz ju� te cz�ci? (tak/nie)\n");
        scanf("%9s", answer);

        if ((strcmp(answer, "tak") == 0) && alfred.junk_sphere >= 2 && alfred.garbage_can_lid >= 1 && alfred.rotten_carrot >= 1 && alfred.broken_light_bulb >= 2) {
            printf("\033[95mBenedykt: Wspaniale! Moje dzieci b�d� zachwycone!\n");
            printf("          W zamian za twoj� pomoc, oto karma dla twojej rodziny.\033[0m\n");
            printf("Alfred: Dzi�kuj�, Benedykcie! Uratowa�e� moj� rodzin�!\n");
            printf("\033[95mBenedykt: Do zobaczenia, Alfredzie! Powodzenia!\033[0m\n");
            printf("Kliknij Enter...\n");
            getchar();
            getchar();
            racoon_ending();
            break;
        }
        else if ((strcmp(answer, "tak") == 0) && (alfred.junk_sphere < 2 || alfred.garbage_can_lid < 1 || alfred.rotten_carrot < 1 || alfred.broken_light_bulb < 2)) {
            printf("Nie masz wystarczaj�co du�o wszystkich element�w �mieciowego ba�wana");
            getchar();
            getchar();
        }
        else if (strcmp(answer, "nie") == 0) {
            printf("\033[95mBenedykt: Hmm, w takim razie wr��, gdy zdob�dziesz wszystkie cz�ci.\033[0m\n");
            printf("          Moje dzieci bardzo na to czekaj�...\n");
            printf("Alfred: W porz�dku, Benedykcie. Wr�c�, gdy wszystko znajd�.\n");
            printf("Kliknij Enter...\n");
            getchar();
            getchar();
            rubbish_dump_menu();
            break;
        }
        else {
            system("cls");
            printf("Wprowadzi�e� niepoprawn� warto�� spr�buj jeszcze raz\n");
            printf("Kliknij Enter...\n");
            getchar();
            getchar();
        }
    }

}


void rubbish_dump_menu(){
    system("cls");
    printf("Wszed�e� na teren wysypiska\n");
    printf("Wok� na pierwszy rzut oka wida� by�o tylko g�ry r�nego rodzaju �mieci.\n W oddali dostrzeg�e� jednak zwierz�c� sylwetk�\n");
    while (1) {
        char dump_menu_choice_1;
        printf("Co robisz?\n");
        printf("(1)Poszukuj przedmiot�w w g�rze �mieci\n(2)Podejd� do tajemniczej figury\n(3)�eby opu�ci� to miejsce\n");
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
            printf("Wprowadzi�e� niepoprawn� warto�� spr�buj jeszcze raz\n");
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
