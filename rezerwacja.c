#include<stdio.h>


struct rezerwacja {
    char imie[100];
    char nazwisko[100];
    int w;
    int m;
};

int main() {

    struct rezerwacja miejsce[15];
    int j;
    for (j = 0; j < 15; j++) {
        miejsce[j].w = 0;
    }
    while(1){
        char odp;
        int suma = 0, i, mi;
        printf("wybierz sposrod:\n");
        printf("a) Pokaz, ile jest wolnych miejsc\n");
        printf("b) Pokaz, ktore miejsca sa wolne\n");
        printf("c) Zarezerwuj miejsce\n");
        printf("d) Pokaz wszystkie zarezerwowane miejsca, wraz z danymi klienta dokonujacego rezerwacje\n");
        printf("e) Koniec\n");
        scanf("%c", &odp);
        getchar(); // Usuń znak nowej linii z bufora wejściowego

        switch (odp) {
            case 'a':
                for (i = 0; i < 15; i++) {
                    if (miejsce[i].w == 0)
                        suma += 1;
                }
                printf("suma wolnych miejsc: %d\n", suma);
                break;
            case 'b':
                for (i = 0; i < 15; i++) {
                    if (miejsce[i].w == 0)
                        printf("Miejsce %d jest wolne\n", i);
                    else
                        printf("Miejsce %d jest zajete\n", i);
                }
                break;
            case 'c':
                printf("ktore miejsce chcesz zarezerowoac?: ");
                scanf("%d", &mi);
                if (miejsce[mi].w == 0) {
                    int M = 1;
                    miejsce[mi].w = M;
                    miejsce[mi].m = mi;
                    puts("Podaj imie: ");
                    getchar();
                    fgets(miejsce[mi].imie, 100, stdin);
                    puts("Podaj nazwisko: ");
                    fgets(miejsce[mi].nazwisko, 100, stdin);
                } else
                    printf("mniejsce zajete wybierz ponownie \n");
                break;
            case 'd':
                for (i = 0; i < 15; i++) {
                    if (miejsce[i].w == 1)
                        printf("Miejsce %d jest zajete przez %s %s", i, miejsce[i].imie, miejsce[i].nazwisko);
                }
                break;
            case 'e':
                printf("koncze program\ndo widzenia\n ");
                return 0;
            default:
                printf("zla odpowiedz\n");
                break;
        }
    }
}
