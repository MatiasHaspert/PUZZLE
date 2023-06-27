#include "puzzle.h"

int main()
{
    srand(time(NULL));
    int caso;                     // VARIABLE PARA GUARDAR UN NRO ALEATORIO QUE CARGARA UNA MATRIZ VALIDA
    int matriz[N][N];             // VARIABLE PARA GUARDAR VALORES EN UNA MATRIZ
    int i = 0;
    int numAleatorios[MAXP] = {0};// VARIABLE DE BANDERAS PARA CONTROLAR QUE LOS NUMEROS ALEATORIOS NO SE REPITAN
    int mov;                      // VARIABLE PARA GUARDAR LA APUESTA DEL USUARIO
    int ch;                       // VARIABLE PARA GUARDAR LA LETRA QUE REPRESENTA EL DESPLAZAMIENTO QUE DESEA EL USUARIO
    int cont_mov = 0;             // VARIABLE PARA GUARDAR LA CANTIDAD DE MOVIMIENTOS DEL USUARIO
    int apuestas[MAXP] = {0};     // VARIABLE PARA GUARDAR LA APUESTA DE CADA PARTIDA
    int puntajes[MAXP] = {0};     // VARIABLE PARA GUARDAR LOS PUNTAJES DE CADA PARTIDA
    int puntos;

    printf("\n**BIENVENIDO A PUZZLE 15**\n");
    printf("JUGAR CON MAYÚS DESACTIVADA.\n");
    printf("**********************************\n");

    /* BUCLE DEL JUEGO */
    while(i < MAXP)
    {
        caso = noRepetidos(numAleatorios);
        matrizValida(matriz,caso);
        
        do
        {
            printf("\nEn su partida %d#:\n",i+1);
            printf("Apueste la cantidad de movimientos en que lo logrará [40..200]: ");
            scanf("%d",&mov);
        }while(mov < AMIN || mov > AMAX);

        cont_mov = 0;
        puntos = 0;
        apuestas[i] = mov;
        ch = 'x';

        while(ch!='q') 
        {

            initscr();		
            raw();			
            noecho();		
            move(1,1);
	        system("clear");
            printw("\nMovimientos realizados %d",cont_mov);
            printw("\nAposto que lo logrará en %d movimientos",mov);
            printw("\n**PUZZLE 15**\n");
            printw("**********************************\n");
            printw("PARTIDA %d#:\n\n",i+1);

            imprimirM(matriz);

	        printw("\nIngrese una letra (q: para abandonar la partida):\n");
            printw("\nARRIBA      -> W");
            printw("\nABAJO       -> S");
            printw("\nIZQUIERDA   -> A");
            printw("\nDERECHA     -> D\n");
	        printw("> ");

	        do
            {
                ch = getch();		
            }while(ch != 'w' && ch != 's' && ch != 'a' && ch != 'd' && ch != 'q');

            desplazamientos(matriz,ch,&cont_mov);
	        
            if((solucion(matriz)) == TRUE)
            {
                endwin();
                puntajes[i] = puntajesObtenidos(cont_mov,mov,puntos);
                printf("\nFELICITACIONES! LO LOGRASTE!"); 
                printf("\nOBTUVISTE %d PUNTOS\n",puntajes[i]);
                break;      
            }
            else
            {
                refresh();
                endwin();
            } 
            
            if (ch=='q')
            {
                endwin();
                puntajes[i] = 0;
                printf("\nABANDONASTE LA PARTIDA.");
                printf("\nOBTUVISTE %d PUNTOS\n",puntajes[i]); 
                break;
            }
        }
        
        historiales(puntajes,apuestas,i);
        
        if(i < MAXP)
        {
            if(finalizarPartida() == TRUE)
            {
                i++;
            }
            else
            {
                return EXIT_SUCCESS;
            }
        }
    }

    return EXIT_SUCCESS;
  
}

void matrizValida(int matriz[][N], int x)
{
    
    switch (x)
    {
    case 1:
        matriz[0][0] = 8, matriz[0][1] = 6, matriz[0][2] = 15, matriz[0][3] = 13;
        matriz[1][0] = 14, matriz[1][1] = 3, matriz[1][2] = 7, matriz[1][3] = 1;
        matriz[2][0] = 0,matriz[2][1] = 11, matriz[2][2] = 9, matriz[2][3] = 4;
        matriz[3][0] = 2, matriz[3][1] = 10, matriz[3][2] = 12, matriz[3][3] = 5;
        break;
    case 2:
        matriz[0][0] = 13; matriz[0][1] =  9; matriz[0][2] =  8; matriz[0][3] =  4;
        matriz[1][0] =  6; matriz[1][1] =  2; matriz[1][2] = 12; matriz[1][3] = 10;
        matriz[2][0] =  1; matriz[2][1] = 15; matriz[2][2] = 0; matriz[2][3] =  7;
        matriz[3][0] = 11; matriz[3][1] =  5; matriz[3][2] =  3; matriz[3][3] = 14;
        break;
    case 3:
        matriz[0][0] = 8; matriz[0][1] = 0; matriz[0][2] =  9; matriz[0][3] =  11;
        matriz[1][0] =  6; matriz[1][1] =  1; matriz[1][2] = 12; matriz[1][3] = 7;
        matriz[2][0] =  4; matriz[2][1] = 10; matriz[2][2] =  5; matriz[2][3] =  13;
        matriz[3][0] = 15; matriz[3][1] =  2; matriz[3][2] =  3; matriz[3][3] = 14;
        break;
    case 4:
        matriz[0][0] = 8; matriz[0][1] =  11; matriz[0][2] =  9; matriz[0][3] =  14;
        matriz[1][0] =  6; matriz[1][1] =  12; matriz[1][2] = 7; matriz[1][3] = 1;
        matriz[2][0] =  4; matriz[2][1] = 10; matriz[2][2] =  15; matriz[2][3] =  13;
        matriz[3][0] = 2; matriz[3][1] =  3; matriz[3][2] =  0; matriz[3][3] = 5;
        break;
    case 5:
        matriz[0][0] = 7; matriz[0][1] =  0; matriz[0][2] =  2; matriz[0][3] =  9;
        matriz[1][0] =  5; matriz[1][1] =  14; matriz[1][2] = 10; matriz[1][3] = 6;
        matriz[2][0] =  8; matriz[2][1] = 12; matriz[2][2] =  15; matriz[2][3] =  4;
        matriz[3][0] = 3; matriz[3][1] =  13; matriz[3][2] =  11; matriz[3][3] = 1;
        break;
    case 6:
        matriz[0][0] = 0; matriz[0][1] =  15; matriz[0][2] =  10; matriz[0][3] =  14;
        matriz[1][0] =  9; matriz[1][1] =  4; matriz[1][2] = 3; matriz[1][3] = 8;
        matriz[2][0] =  12; matriz[2][1] = 13; matriz[2][2] =  7; matriz[2][3] =  11;
        matriz[3][0] = 5; matriz[3][1] =  6; matriz[3][2] =  1; matriz[3][3] = 2;
        break;
    case 7:
        matriz[0][0] = 8; matriz[0][1] =  1; matriz[0][2] =  2; matriz[0][3] =  3;
        matriz[1][0] =  11; matriz[1][1] =  7; matriz[1][2] = 0; matriz[1][3] = 12;
        matriz[2][0] =  10; matriz[2][1] = 14; matriz[2][2] =  5; matriz[2][3] =  15;
        matriz[3][0] = 13; matriz[3][1] =  6; matriz[3][2] =  9; matriz[3][3] = 4;
        break;
    case 8:
        matriz[0][0] = 1; matriz[0][1] =  5; matriz[0][2] =  14; matriz[0][3] =  10;
        matriz[1][0] =  2; matriz[1][1] =  12; matriz[1][2] = 9; matriz[1][3] = 8;
        matriz[2][0] =  3; matriz[2][1] = 6; matriz[2][2] =  0; matriz[2][3] =  15;
        matriz[3][0] = 4; matriz[3][1] =  13; matriz[3][2] =  11; matriz[3][3] = 7;
        break;
    case 9:
        matriz[0][0] = 15; matriz[0][1] =  10; matriz[0][2] =  13; matriz[0][3] =  3;
        matriz[1][0] =  5; matriz[1][1] = 11; matriz[1][2] = 6; matriz[1][3] = 4;
        matriz[2][0] =  7; matriz[2][1] = 9; matriz[2][2] =  14; matriz[2][3] =  1;
        matriz[3][0] = 2; matriz[3][1] =  8; matriz[3][2] =  0; matriz[3][3] = 12;
        break;        
    case 10:
        matriz[0][0] = 8; matriz[0][1] =  2; matriz[0][2] =  13; matriz[0][3] =  3;
        matriz[1][0] =  14; matriz[1][1] =  9; matriz[1][2] = 6; matriz[1][3] = 5;
        matriz[2][0] =  4; matriz[2][1] = 15; matriz[2][2] =  7; matriz[2][3] =  11;
        matriz[3][0] = 0; matriz[3][1] =  1; matriz[3][2] =  12; matriz[3][3] = 10;
        break;
    default:
        printf("Error\n");
        break;
    }
}

int noRepetidos(int numAleatorios[])
{
    int caso;
    
    do
    {
        caso = 1 + rand() % MAXP;  //Genera un numero aleatorio entre 1 y 10
    } while (numAleatorios[caso - 1] == 1); // Verifica si el número ya ha sido seleccionado
        
    numAleatorios[caso - 1] = 1; // Marca el número como seleccionado

    return caso;
}

void imprimirM (int m[][N])
{
    int i,j;

    for ( i = 0; i < N; i++)
    {
        for(j = 0; j < N;j++)
        {
            if(m[i][j] == 0) printw("[    ]");
            else printw("[ %2d ]",m[i][j]);
        }
        printw("\n");
    }  
}

void desplazamientos (int m[][N],int letra,int *cont)
{
    int i,j;
    int pivot; // pivot para intercambiar valores de la matriz
    
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(m[i][j] == 0) //Nos posicionamos en el lugar vacío
            {
                if(letra == 'w')
                {
                    if(i < N-1) //Comprobamos si no estamos en el borde de la matriz
                    {
                        /*Intercambiamos los valores*/
                        pivot = m[i][j];
                        m[i][j] = m[i+1][j];
                        m[i+1][j] = pivot;
                        *cont = *cont + 1; //Incremento los movimientos
                        return; //Salimos de la funcion 
                    }
                }
                else if(letra == 's')
                {
                    if(i != 0) //Comprobamos si no estamos en el borde de la matriz
                    {
                        pivot = m[i][j];
                        m[i][j] = m[i-1][j];
                        m[i-1][j] = pivot;
                        *cont = *cont + 1;
                        return;
                    }
                }
                else if(letra == 'a')
                {
                    if(j < N-1) //Comprobamos si no estamos en el borde de la matriz
                    {
                        pivot = m[i][j];
                        m[i][j] = m[i][j+1];
                        m[i][j+1] = pivot;
                        *cont = *cont + 1;
                        return;
                    } 
                }
                else if(letra == 'd')
                {
                    if(j != 0) //Comprobamos si no estamos en el borde de la matriz
                    {
                        pivot = m[i][j];
                        m[i][j] = m[i][j-1];
                        m[i][j-1] = pivot;
                        *cont = *cont + 1;
                        return;
                    } 
                }   
            }
        }
    }    
}

int solucion (int m[][N])
{
    int i,j;
    
    for(i = 0; i < N; i++)
    {
        for (j = 0; j < N-1; j++)
        {
            if (j == N-2 && i == N-1)
            {
                break;// Evitar la comparación si estamos en la posición m[3][2]
            }
            if(m[i][j] > m[i][j+1]) //Si la matriz no esta en forma ascendente 
            {
                return FALSE; // Retornamos falso
            }
        }    
    }
    //Si sale del for quiere decir que la matriz está en forma ascendente

    if(m[N-1][N-1] == 0) //Si en la esquina inferior derecha se encuentra vacío
    {
        return TRUE; //El puzzle está solucionado
    }
    else
    {
        return FALSE;
    }
}

int puntajesObtenidos (int cont_mov, int mov,int puntos)
{
    if(cont_mov < (mov-RPUN)) // 1500 puntos si lo hace en menos de M-10 movimientos
    {                               
        puntos = MINP + MP;
        return puntos;
    }
    else if(cont_mov >= (mov-RPUN) && cont_mov < mov) //1200 puntos si lo hace en una cantidad de movimientos dentro del rango [M-10, M)
    {
        puntos = MAXPU;
        return puntos;
    }
    else if(cont_mov == mov) //1000 puntos si lo hace en exactamente M movimientos
    {
        puntos = MP;
        return puntos;
    }
    else if(cont_mov > mov && cont_mov <= (mov+RPUN)) // 500 puntos si lo logra en (M, M+10] movimientos
    {
        puntos = MINP;
        return puntos;
    }
    else //0 puntos en otro caso
    {
        puntos = 0;
        return puntos;
    }    
}

void historiales (int puntajes[],int apuestas[],int i)
{
    int j;

    printf("\n<<HISTORIALES>>");
    for(j = 0; j <= i; j++)
    {
        printf("\nPartida %d#:",j+1);
        printf("\nSu apuesta: %d.",apuestas[j]);
        printf("\nPuntos: %d.\n",puntajes[j]);
    }
}

int finalizarPartida ()
{
    char respuesta;
    do
    {
        printf("\n¿Quieres realizar una nueva partida?(s)i/(n)o: ");
        scanf(" %c",&respuesta);
    }while(respuesta != 's' && respuesta != 'n');

    if(respuesta == 's') return TRUE;
    else return FALSE;
}