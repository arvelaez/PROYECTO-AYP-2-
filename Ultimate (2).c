#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define p printf


typedef struct _nodo {
   float valor;
   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Pila;

float Push(Pila *l, float v);
float Pop(Pila *l);
float a_rads(float x);
float a_grados(float x);
float factorial(float n);
void Display(Pila *pila);
float Clear(Pila *pila);
int fTOi(float v);
int Binary(int v);
int Octal(int v);
void Hexadecimal(int v);



int main() {
  Pila pila = NULL;
  Pila pila_aux = NULL;

  char n[40];
  float t, x, v1,v2;
  int k;

  p("Ingrese elementos en RPN...\n\n");
  p("Para ver los comandos disponibles escriba 'HELP'\n\n \n");
  do {
    printf("CALC> ");
    scanf("%s",n );

    if (strcmp(n, "+") == 0) {
      v1 = Pop(&pila);
      v2 = Pop(&pila);                           /*SUMA*/
      Push(&pila, (v2+v1));
      p("%.2f\n", v2+v1);
    }else
    if (strcmp(n, "-") == 0 ) {
      v1 = Pop(&pila);
      v2 = Pop(&pila);                           /*RESTA*/
      Push(&pila, (v2-v1));
      p("%.2f\n", v2-v1);
    }else
    if (strcmp(n, "*") == 0 ) {
      v1 = Pop(&pila);
      v2 = Pop(&pila);                           /*MULTIPLICACION*/
      Push(&pila, (v2*v1));
      p("%.2f\n", v2*v1);
    }else
    if (strcmp(n, "/") == 0 ) {
      v1 = Pop(&pila);                          /*DIVISION*/
      v2 = Pop(&pila);
      if (v1 != 0) {
        Push(&pila, (v2/v1));
        p("%.2f\n", v2/v1);
      }else
        p("Dividio por cero, ERROR\n");
    }else
    /*seno*/
    if (strcmp(n,"sen") == 0) {
      v1 = Pop(&pila);
      t = sin(a_rads(v1));
      Push(&pila, t);
      p("%.2f\n", t);
    }else
    /*coseno*/
    if (strcmp(n,"cos") == 0) {
      v1 = Pop(&pila);
      t  = cos(a_rads(v1));
      Push(&pila, t);
      p("%.2f\n", t);
    }else
    /*tangente*/
    if (strcmp(n,"tan") == 0) {
      v1 = Pop(&pila);
      t  = tan(a_rads(v1));
      Push(&pila, t);
      p("%.2f\n", t);
    }else
    /*cotangente*/
    if (strcmp(n,"cot") == 0) {
      v1 = Pop(&pila);
      t = 1.0f / (tan(a_rads(v1)));
      Push(&pila, t);
      p("%.2f\n", t);
    }
    else
    /*secante*/
    if (strcmp(n,"sec") == 0) {
      v1 = Pop(&pila);
      t = 1.0f / (cos(a_rads(v1)));
      Push(&pila, t);
      p("%.2f\n", t);
    }else
    /*cosecante*/
    if (strcmp(n,"csc") == 0) {
      v1 = Pop(&pila);
      t = 1.0f / (sin(a_rads(v1)));
      Push(&pila, t);
      p("%.2f\n", t);
    }else
    /*arcsen*/
    if (strcmp(n,"arcsen") == 0) {
      v1 = Pop(&pila);
      if ( (v1>=-1) && (v1<=1) ) {
        t  = asin(a_rads(v1));
        Push(&pila, t);
        p("%.2f\n", t);
      }else
        p("Error en el dominio, debe estar entre [-1,1]\n");
    }else
    /*arccos*/
    if (strcmp(n,"arccos") == 0) {
      v1 = Pop(&pila);
      if ( (v1 >= -1) && (v1<=1) ) {
        t  = acos(a_rads(v1));
        Push(&pila, t);
        p("%.2f\n", t);
      }else
        p("Error en el dominio, debe estar entre [-1,1]\n ");
    }else
    /*arctan*/
    if (strcmp(n, "arctan") == 0) {
      v1 = Pop(&pila);
      t  = atan(a_grados(v1));
      Push(&pila, t);
      p("%.2f\n", t);
    }else
    /*Raíz cuadrada de un numero*/
    if (strcmp(n, "raiz2") == 0) {
      v1 = Pop(&pila);
      t  = sqrt(v1);
      Push(&pila, t);
      p("%.2f\n", t);
    }else
    /*Raíz cubica de un numero*/
    if (strcmp(n, "raiz3") == 0) {
      v1 = Pop(&pila);
      t  = pow(v1,1.0/3.0);
      Push(&pila, t);
      p("%.2f\n", t);
    }else
    /*ELEVAR AL CUADRADA*/
    if (strcmp(n, "elev2") == 0) {
      v1 = Pop(&pila);
      t  = pow(v1,2);
      p("%.2f\n", t);
      Push(&pila, t);
    }else
    /*ELEVAR AL CUBO*/
    if (strcmp(n, "elev3") == 0) {
      //p("Ingrese el exponente: ");
      //scanf("%i\n", &a);
      v1 = Pop(&pila);
      t  = pow(v1,3);
      p("%.2f\n", t);
      Push(&pila, t);
    }else
    /*Logaritmo Natural LN*/
    if (strcmp(n,"ln") == 0) {
      v1 = Pop(&pila);
      t  = log(v1);
      p("%.2f\n", t);
      Push(&pila, t);
    }else
    /*Logaritmo base 10 Log10*/
    if (strcmp(n,"log10") == 0) {
      v1 = Pop(&pila);
      t  = log10(v1);
      p("%.2f\n", t);
      Push(&pila, t);
    }else
    /*Factorial de n*/
    if (strcmp(n,"!") == 0) {
      //Dara error si el resultado es mayor al maximo permitido por float
      v1 = Pop(&pila);
      t  = factorial(v1);
      p("%.2f\n", t);
      Push(&pila, t);
    }else
    //BINARY
    if (strcmp(n, "BINARY") == 0) {
      v1 = Pop(&pila);
      k = fTOi(v1);
      Binary(k);
      Push(&pila, v1);
    }else
    //OCTAL
    if (strcmp(n, "OCTAL") == 0) {
      v1 = Pop(&pila);
      k  = fTOi(v1);
      Octal(k);
      Push(&pila, v1);
    }else
    //HEXADECIMAL
    if (strcmp(n, "HEXADECIMAL") == 0) {
      v1 = Pop(&pila);
      k  = fTOi(v1);
      Hexadecimal(k);
      Push(&pila, v1);
    }else
    //STORE
    if (strcmp(n, "STO") == 0) {
      t = Pop(&pila);
      Push(&pila_aux, t);
      Push(&pila, t);
      p("Almacenado: %.2f\n",t);
    }else
    //SUMAR A MEMORIA
    if (strcmp(n, "S+") == 0) {
      v1 = Pop(&pila);
      t  = Pop(&pila_aux);
      x  = v1+t;
      Push(&pila_aux, x);
      p("Almacenado: %.2f\n", x);
    }else
    //RESTAR A MEMORIA
    if (strcmp(n, "S-") == 0) {
      t  = Pop(&pila_aux);
      v1 = Pop(&pila);
      x  = t-v1;
      Push(&pila_aux, x);
      p("Almacenado: %.2f\n",x);
    }else
    //MEMORY RECALL
    if (strcmp(n, "MRCL") == 0) {
      if (!pila_aux) {
        p("No hay dato Almacenado\n");
      }else{
        v1 = Pop(&pila_aux);
        t  = Push(&pila, v1);
        p("Memory Recall: %.2f\n",t);
      }
    }else
    //RECALL
    if (strcmp(n, "RCL") == 0) {
      t = Pop(&pila);
      p("Valor actual: %.2f\n",t);
      Push(&pila, t);
    }else
    //DISPLAY
    if (strcmp(n, "DSP") == 0) {
      Display(&pila);
    }else
    //DISPLAY DE LA PILA AUX
    if (strcmp(n, "DSPA") == 0) {
      Display(&pila_aux);
    }else
    //SWAP
    if (strcmp(n, "SWP") == 0) {
      v1 = Pop(&pila);
      v2 = Pop(&pila);
      Push(&pila,v1);
      Push(&pila,v2);
    }else
    //CLEAR
    if (strcmp(n, "CLR") == 0) {
      do {
        Clear(&pila);
      }while(pila!=NULL);
    }else
    //IMPRIME POR PANTALLA LAS OPCIONES DISPONIBLES EN EL PROGRAMA
    if (strcmp(n, "HELP") == 0) {
      p("--------------------------------------------------------------------------------");
      p("                             Operaciones Basicas: \n\n");
      p("|+|--> SUMA  |-|-->RESTA |*|-->MULTIPLICACION |/|-->DIVISION \n\n\n");
      p("--------------------------------------------------------------------------------");
      p("                               Trigonometria:\n\n");
      p("\n|sen|--> SENO  |cos|-->COS |tan|-->TANGENTE |cot|-->COTANGENTE \n");
      p("\n|sec|--> SECANTE  |csc|-->COSECANTE |arcsen|-->ARCOSENO |arccos|-->ARCOCOSENO\n");
      p("--------------------------------------------------------------------------------");
      p("                               Matematicas Avanzadas:\n\n");
      p("\n|raiz2|-->RAIZ CUADRADA |raiz3|-->RAIZ CUBICA |elev2|-->CUADRADO |elev3|-->CUBO \n");
      p("\n|ln|-->LOGARITMO NEPERIANO  |log10|-->LOGARITMO BASE 10 |!|-->FACTORIAL\n");
      p("--------------------------------------------------------------------------------");
      p("                               Funciones Miscaleneas:\n\n");
      p("\n|DSP|-->MUESTRA LA PILA \n");
      p("\n|SWP|-->INTERCAMBIA LA POSICION DEL TOPE DE LA PILA CON EL QUE LE SIGUE\n");
      p("\n|CLR|-->VACIA LA PILA |RCL|-->IMPRIME EL TOPE DE LA PILA\n");
      p("--------------------------------------------------------------------------------");
      p("                               Funciones de Memoria:\n\n");
      p("\n|STO|-->ALMACENA UN DATO DE LA PILA |S+|-->SUMA AL DATO ALMACENADO EN STO  \n");
      p("\n|S-|-->RESTA AL DATO ALMACENADO EN LA PILA\n");
      p("\n|MRCL|-->INTRODUCE EL VALOR ALMACENADO EN LA PILA\n");
      p("\n|DSPA|-->MUESTRA PILA DONDE SE ESTA ALMACENANDO EL DATO DE LA PILA ORIGINAL \n");
      p("--------------------------------------------------------------------------------");
      p("                             Conversion a multiples bases: \n\n");
      p("\n|BINARY|--> MUESTRA EL TOPE DE LA PILA EN BINARIO\n");
      p("\n|OCTAL|--> MUESTRA EL TOPE DE LA PILA EN OCTAL\n");
      p("\n|HEXADECIMAL|--> MUESTRA EL TOPE DE LA PILA EN HEXADECIMAL\n");
      p("--------------------------------------------------------------------------------\n");
      p("|QUIT|-->TERMINA LA EJECUCION DEL PROGRAMA ");
      p("\n\n");
    }else
    //PARA QUE NO LEA EL ENTER "\0"
    if (n[0] != '\0') {
      Push(&pila, atoi(n));
    }

  } while(strcmp(n,"QUIT") != 0);


  return 0;
}//FIN MAIN

float Push(Pila *pila, float v) {
   pNodo nuevo;

   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->valor = v;

   nuevo->siguiente = *pila;

   *pila = nuevo;

   return v;
 } //AÑADE A LA PILA

float Pop(Pila *pila) {
   pNodo nodo;

   float v;

   nodo = *pila;
   if(!nodo) return 0;

   *pila = nodo->siguiente;

   v = nodo->valor;

   free(nodo);
   return v;
 } //SACA DE LA PILA

void Display(Pila *pila) {
  pNodo nodo;

  nodo = *pila;
  if(!nodo) p("Pila vacia\n");
  else{
    p("TOPE----------------------------------------------BASE\n\n");
    do {
      p("|  %.2f  |",nodo->valor);
      nodo = nodo->siguiente;
    }while(nodo != NULL);
    p("\n\nTOPE----------------------------------------------BASE\n\n");
    p("\n");
  }
} //MUESTRA LA PILA

float Clear(Pila *pila){
  pNodo nodo;
  float v;

  nodo = *pila;
  if(!nodo) return 0;
  else{
    *pila = nodo->siguiente;
    v = nodo->valor;
    free(nodo);
  }
  return 0;
} //LIMPIA TODA LA PILA

float a_grados(float num){
const float PI=3.141592653589;
    float grad;
    grad=num*180/PI;
 return grad;
} // CONVIERTE EN GRADOS

float a_rads(float num){
const float PI=3.141592653589;
    float grad;
    grad=num*PI/180;
 return grad;
} //CONVIERTE A RADIANES

float factorial(float n){
  if (n == 0)
    return 1;
  else
    return(n * factorial(n-1));
  } //FACTORIAL DE UN NUMERO

int fTOi(float v){
  int a;
  a = (int)v;
  return a;
} //CONVIERTE FLOAT A ENTERO

int Binary(int v) {
  int i = 0, j, arr[100];
  while (v > 0) {
    arr[i] = v % 2;
    v /= 2;
    i++;
  }
  for (j = i - 1; j >= 0; j--)
    p("%d",arr[j]);
  p("\n");

  return 0;
} // CONVIERTE ENTERO A BIANRIO, SOLO LO MUESTRA.

int Octal(int v){

  int octal[8];
  int i=0;

  while (v >= 8) {
    octal[i]= v % 8;
    v = v / 8;
    i++;
  }

  octal[i]=v;
  int j=0;

  for (j = i; j >= 0; j--)
    p("%d",octal[j]);

  p("\n");return 0;
} //CONVIERTE UN ENTERO A OCTAL, SOLO LO MUESTRA

void Hexadecimal(int v){
  char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  char hexa[8];
  int i = 0, j = 0;

  while (v >= 16) {
      hexa[i] = hex[v % 16];
      v = v/ 16;
      i++;
  }
  hexa[i]=hex[v];
  for (j = i; j >= 0; j--)
    p("%c", hexa[j]);
  p("\n");
} //CONVIERTE UN ENTERO A HEXADECIMAL, SOLO LO MUESTRA
