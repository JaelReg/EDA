#include <stdio.h>
#include <string.h>

#define TAM 2       
#define NUM_DIR 2   
#define STR  20

struct pelicula {
    char nombre[STR];
    char genero[STR];
    int  anio;
    int  numDirectores;
    char directores[NUM_DIR][STR];
};


static void imprimirPelicula(const struct pelicula *p) {
    printf("Pelicula: %s\n", p->nombre);
    printf("Genero  : %s\n", p->genero);
    printf("Anio    : %d\n", p->anio);
    printf("Directores (%d):\n", p->numDirectores);
    for (int j = 0; j < p->numDirectores; j++) {
        printf("  - %s\n", p->directores[j]);
    }
}


static int validarVideoteca(const struct pelicula v[], int n) {
    if (n <= 0) {  
        printf("[ERROR] La videoteca no puede tener %d peliculas.\n", n);
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (v[i].numDirectores <= 0) {
            printf("[ERROR] '%s' tiene numDirectores = %d (invalido). Debe ser > 0.\n",
                   v[i].nombre, v[i].numDirectores);
            return 0;
        }
    }
    return 1;
}


static int buscarPorNombre(const struct pelicula v[], int n, const char *nombre) {
    int encontrados = 0;
    for (int i = 0; i < n; ++i) {
        if (strcmp(v[i].nombre, nombre) == 0) {
            imprimirPelicula(&v[i]);
            puts("");
            ++encontrados;
        }
    }
    return encontrados;
}

static int buscarPorAnio(const struct pelicula v[], int n, int anio) {
    int encontrados = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i].anio == anio) {
            imprimirPelicula(&v[i]);
            puts("");
            ++encontrados;
        }
    }
    return encontrados;
}

static int buscarPorDirector(const struct pelicula v[], int n, const char *director) {
    int encontrados = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < v[i].numDirectores; ++j) {
            if (strcmp(v[i].directores[j], director) == 0) {
                imprimirPelicula(&v[i]);
                puts("");
                ++encontrados;
                break; 
            }
        }
    }
    return encontrados;
}


static int contarGenero(const struct pelicula v[], int n, const char *genero) {
    int c = 0;
    for (int i = 0; i < n; ++i)
        if (strcmp(v[i].genero, genero) == 0) ++c;
    return c;
}


static void resumenGeneros(const struct pelicula v[], int n) {
    char vistos[TAM][STR];
    int  usados = 0;

    puts("=== Conteo por genero ===");
    for (int i = 0; i < n; ++i) {
        
        int ya = 0;
        for (int k = 0; k < usados; ++k) {
            if (strcmp(v[i].genero, vistos[k]) == 0) { ya = 1; break; }
        }
        if (!ya) {
            strcpy(vistos[usados++], v[i].genero);
            printf("%s : %d\n", v[i].genero, contarGenero(v, n, v[i].genero));
        }
    }
    puts("=========================");
}

int main(void) {
    struct pelicula videoteca[TAM];
    int n = TAM; 
   
    strcpy(videoteca[0].nombre, "Matrix");
    strcpy(videoteca[0].genero, "CienciaFiccion");
    videoteca[0].anio = 1999;
    videoteca[0].numDirectores = 2;
    strcpy(videoteca[0].directores[0], "Lana");
    strcpy(videoteca[0].directores[1], "Lilly");

    
    strcpy(videoteca[1].nombre, "Inception");
    strcpy(videoteca[1].genero, "Accion");
    videoteca[1].anio = 2010;
    videoteca[1].numDirectores = 1;
    strcpy(videoteca[1].directores[0], "Nolan");

    
    if (!validarVideoteca(videoteca, n)) {
        puts("Corrige los datos y vuelve a ejecutar.");
        return 1;
    }

    
    printf("####### Contenido de la videoteca #######\n");
    for (int i = n - 1; i >= 0; i--) {
        imprimirPelicula(&videoteca[i]);
        puts("");
    }

    
    int opc = -1;
    do {
        puts("========= MENU =========");
        puts("1) Buscar por nombre");
        puts("2) Buscar por anio");
        puts("3) Buscar por director");
        puts("4) Contar por genero (especifico)");
        puts("5) Resumen de todos los generos");
        puts("0) Salir");
        printf("Opcion: ");
        if (scanf("%d", &opc) != 1) { while (getchar()!='\n'); opc = -1; }

        if (opc == 1) {
            char nombre[STR];
            printf("Nombre exacto: ");
            scanf("%19s", nombre);
            int e = buscarPorNombre(videoteca, n, nombre);
            if (!e) puts("No se encontraron peliculas con ese nombre.\n");
        } else if (opc == 2) {
            int anio;
            printf("Anio: ");
            if (scanf("%d", &anio) == 1) {
                int e = buscarPorAnio(videoteca, n, anio);
                if (!e) puts("No se encontraron peliculas para ese anio.\n");
            }
        } else if (opc == 3) {
            char dir[STR];
            printf("Director: ");
            scanf("%19s", dir);
            int e = buscarPorDirector(videoteca, n, dir);
            if (!e) puts("No se encontraron peliculas de ese director.\n");
        } else if (opc == 4) {
            char gen[STR];
            printf("Genero: ");
            scanf("%19s", gen);
            printf("Hay %d peliculas del genero '%s'.\n\n",
                   contarGenero(videoteca, n, gen), gen);
        } else if (opc == 5) {
            resumenGeneros(videoteca, n);
        } else if (opc != 0) {
            puts("Opcion invalida.\n");
        }
    } while (opc != 0);

    return 0;
}
