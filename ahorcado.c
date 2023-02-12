#include<stdio.h>
#include<time.h>

void juego1 (char c[][1]);
void juego2 (char c[][1]);

void cambio (char t[]);
void copy (char cad1[], char cad2[]);
int conta (char t[]);

int main()
{
    char (c[6][1])= {'O', '|', '\\', '/', '\\', '/'};
    char modo, key;
    
    printf ("\n\n\tBIENVENIDO AL AHORCADO\n\n");
do {
   
    printf ("\t ____\n");
    printf ("\t|    |\n");
    printf ("\t|    %c \n", c[0][0]);
    printf ("\t|   %c%c%c\n", c[3][0], c[1][0], c[2][0]);
    printf ("\t|   %c %c\n", c[5][0], c[4][0]);
    printf ("\t|\n");
    
 do {   
    printf ("\nElige el modo de juego:\n");
    printf ("(1) Adivinar una palabra del juego.\n");
    printf ("(2) Adivinar una palabra introducida.\n\n");
    scanf (" %c", &modo);
  } while (modo < '1' || modo > '2');
  
    switch (modo){
        case '1': {
            juego1 (c);
            break;
        }
        case '2': {
            juego2 (c);
            break;
        }
    }
    printf ("\nDeseas jugar de nuevo?\n(S/N)\n");
    scanf (" %c", &key);
    printf ("\n\n\n\n");
 } while (key == 'S' || key == 's');
    return 0;
}

void juego1 (char c[][1]){
    char palabras [][20] = {"dinosaurio", "paz", "kiwi", "noche", "luna de miel", "complicacion", "escudero", "reestructuracion", "audifonos", "espadachin", "eucariota", "profesionales", "anochecer", "minerales", "pulverizador", "impar", "inhalar", "toallon", "economizado"};
    int ran, i, letras, win, stop, auxstop, lim, err;
    int vida, perder;
    char palabra[20], subpalabra[20];
    char x;
    
    for (i = 0; i < 6; i++){
        c[i][0] = ' ';
    }
    
    srand (time(NULL));
    ran = rand () % 20;
    copy (palabra, palabras[ran]);
    lim = conta (palabras[ran]);
    letras = lim;
    copy (subpalabra, palabra);
    for (i = 0; i < lim; i++){
        if (subpalabra[i] != ' '){
            subpalabra[i] = '-';
        }
        else {
        letras--;
        }
        if (i+1 == lim){
            subpalabra[i+1] = '\0';
            palabra[i+1] = '\0';
        }
        
    }
    vida = perder = auxstop = 0;
 do {
	system ("cls"); 
	if (err == 0 && perder > 0){
		printf ("\n\n\nLa '%c' NO SE HALLA en la palabra.\n\n", x - 32);
	}
	
    printf ("\n\t ____\n");
    printf ("\t|    |\n");
    printf ("\t|    %c \n", c[0][0]);
    printf ("\t|   %c%c%c\n", c[3][0], c[1][0], c[2][0]);
    printf ("\t|   %c %c\n", c[5][0], c[4][0]);
    printf ("\t|\n");
    
    printf ("\nLa palabra tiene '%i' letras.\n\n", letras);
    printf ("\t%s\n\n", subpalabra);
    printf ("Coloca una letra: ");
    scanf (" %c", &x);
    
    err = 0;
    
    for (i = 0; palabra[i] != '\0'; i++){
        if (palabra[i] == x){
            subpalabra[i] = x;
            err = 1;
        }
    }
    if (err == 0){
        vida++;
        perder++;
        switch (vida){
            case 1: {
                c[0][0]= 'O';
            break;
            }
            case 2: {
               c[1][0] = '|';
            break;
            }
            case 3: {
            	c[2][0] = '\\';
            break;
            }
            case 4: {
                c[3][0] = '/';
            break;
            }
            case 5: {
                c[4][0] = '\\';
            break;
            }
            case 6: {
                c[5][0] = '/';
            break;
            }
        }
    }
    
    if (perder == 6){
    	auxstop = 1;
	}
    
    win = 0;
    
    for (i = 0; palabra[i] != '\0'; i++){
        if (palabra[i] == subpalabra[i]){
            win++;
        }
    }
    
    stop = lim;
  } while (win != stop && auxstop == 0);

	  if (win == stop){
	        printf ("\nHAS GANADO! La palabra es:");
	        printf ("\n\n\t%s\n\n", subpalabra);
	        
	        printf ("\n\t ____\n");
		    printf ("\t|    |\n");
		    printf ("\t|\n");
		    printf ("\t|\n");
		    printf ("\t|    O/\n");
		    printf ("\t|   /|\n");
		    printf ("\t    / \\");
	  }
	  else {
	  		printf ("\nHAS PERDIDO!\n");
	  		
	  		printf ("\n\t ____\n");
		    printf ("\t|    |\n");
		    printf ("\t|     %c \n", c[0][0]);
		    printf ("\t|   %c%c%c\n", c[3][0], c[1][0], c[2][0]);
		    printf ("\t|   %c %c\n", c[5][0], c[4][0]);
		    printf ("\t|\n");
	  }
} 

void juego2 (char c[][1]){
    int ran, i, letras, win, stop, auxstop, lim, err;
    int vida, perder;
    char palabra[30], subpalabra[30];
    char x, y;
    
    for (i = 0; i < 6; i++){
        c[i][0] = ' ';
    }
    
    printf ("Escribe una palabra o frase.\nNo más de 30 carac. sin tildes ni mayúsculas:\n");
    fflush (stdin);
    fgets (palabra, 30, stdin);
    printf ("\n\n\n");
    cambio (palabra);
    lim = conta (palabra);
    letras = lim;
    copy (subpalabra, palabra);
    for (i = 0; i < lim; i++){
        if (subpalabra[i] != ' '){
            subpalabra[i] = '-';
        }
        else {
        letras--;
        }
        if (i+1 == lim){
            subpalabra[i+1] = '\0';
            palabra[i+1] = '\0';
        }
        
    }
    vida = perder = auxstop = 0;
 do { 
 	system ("cls");
	if (err == 0 && perder > 0){
		printf ("\n\n\nLa '%c' NO SE HALLA en la palabra.\n\n", x - 32);
	}

    printf ("\n\t ____\n");
    printf ("\t|    |\n");
    printf ("\t|    %c \n", c[0][0]);
    printf ("\t|   %c%c%c\n", c[3][0], c[1][0], c[2][0]);
    printf ("\t|   %c %c\n", c[5][0], c[4][0]);
    printf ("\t|\n");
    
    printf ("\nLa palabra tiene '%i' letras.\n\n", letras);
    printf ("\t%s\n\n", subpalabra);
    printf ("Coloca una letra: ");
    fflush (stdin);
    scanf (" %c", &x);
    
    err = 0;
    
    for (i = 0; palabra[i] != '\0'; i++){
        if (palabra[i] == x){
            subpalabra[i] = x;
            err = 1;
        }
    }
    if (err == 0){
        vida++;
        perder++;
        switch (vida){
            case 1: {
                c[0][0]= 'O';
            break;
            }
            case 2: {
               c[1][0] = '|';
            break;
            }
            case 3: {
            	c[2][0] = '\\';
            break;
            }
            case 4: {
                c[3][0] = '/';
            break;
            }
            case 5: {
                c[4][0] = '\\';
            break;
            }
            case 6: {
                c[5][0] = '/';
            break;
            }
        }
    }
    
    if (perder == 6){
    	auxstop = 1;
	}
    
    win = 0;
    
    for (i = 0; palabra[i] != '\0'; i++){
        if (palabra[i] == subpalabra[i]){
            win++;
        }
    }
    
    stop = lim;
  } while (win != stop && auxstop == 0);

	  if (win == stop){
	        printf ("\nHAS GANADO! La palabra es:");
	        printf ("\n\n\t%s\n\n", subpalabra);
	        
	        printf ("\n\t ____\n");
		    printf ("\t|    |\n");
		    printf ("\t|\n");
 		   printf ("\t|\n");
		    printf ("\t|    O/\n");
		    printf ("\t|   /|\n");
		    printf ("\t    / \\");
	  }
	  else {
	  		printf ("\nHAS PERDIDO!\n");
	  		
	  		printf ("\n\t ____\n");
		    printf ("\t|    |\n");
		    printf ("\t|     %c \n", c[0][0]);
		    printf ("\t|   %c%c%c\n", c[3][0], c[1][0], c[2][0]);
		    printf ("\t|   %c %c\n", c[5][0], c[4][0]);
		    printf ("\t|\n");
	  }
} 

void cambio (char t[]){
    int i, lim = conta (t);
    
    for (i = 0; i < lim; i++){
        if (t[i] == '\n'){
            t[i] = '\0';
        }
    }
}

void copy (char cad1[], char cad2[]){
    int lim2, i;
    lim2 = conta(cad2);
    for (i = 0; i < lim2; i++){
        cad1[i] = cad2[i];
    }
}

int conta (char t[]){
    int i;
    
    for (i = 0; t[i] != '\0'; i++);
    return i;
}
