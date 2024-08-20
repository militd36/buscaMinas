#include <iostream>

const int filas_max = 30;
const int columas_max = 30;
using namespace std;
//test
//test2
//1.- Iniciar y setear tablero
// Colocar Minas random (ColocaMinas)
// Imprimir tablero una vez con 0 (ImprimeTablero)
// Actualizar tabla segun lo escogido por el jugador (ColocaNumeros)
// Verificar si se ha chocado una mina
// Volver a imprimir hasta que gane o pierda

void InicializaTablero(int tablero[filas_max][columas_max], int filas, int columas);
void ColocaMinas(int tablero[filas_max][columas_max], int filas, int columas, int Cantminas);
void ImprimeTablero(int tablero, int  playerFila, int playerColum);
char ColocarNumeros(int tablero[filas_max][columas_max], int filas, int columas);
bool VerificarGanador(int tablero[filas_max][columas_max], int  playerFila, int playerColum);
int main() {
	int nivel, CantMinas, filas, columnas, Cantminas;
	int tablero[filas_max][columas_max];
	int playerFila, playerColum;

	cout << "Bienvenido al juego de Buscaminasaaaa" << endl;
	cout << "Los niveles son: \n";
	cout << "Ingrese opcion: ";
	cin >> nivel;
	//Se escoge el nivel de dificultad del juego
	switch (nivel)
	{
	case 1:
		filas = 8;
		columnas = 8;
		Cantminas = 10;
	case 2:
		filas = 16;
		columnas = 16;
		Cantminas = 40;
	case 3:
		filas = 16;
		columnas = 30;
		Cantminas = 99;
	case 4:
		cout << "Ingrese cantidad de minas: ";
		cin >> CantMinas;
		cout << "\nIngrese dimensiones del table [NxM]: ";
		cin >> filas >> columnas;

	}

	InicializaTablero(tablero, filas, columnas);
	ColocaMinas(tablero, filas, columnas, CantMinas);
	//Imprime al menos una vez la tabla
	do {

		cout << "Ingrese la fila y la columna de la casilla a voltear: ";
		cin >> playerFila >> playerColum;
		ImprimeTablero(tablero, playerFila, playerColum); // Se escoge la tabla y la fila y columa seleccionada por el jugador

	}(VerificarGanador(tablero, playerFila, playerColum))
		return 0;
}

void InicializaTablero(int tablero[filas_max][columas_max], int filas, int columas) {



	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columas; j++) {
			tablero[i][j] = 0; //Llenar el tablero con 0  con numeros del 1 al 
		}
	}

	cout << "El tablero ha sido creado, puede empezar a jugar." << endl;
	cout << "El tablero actual es: \n"; // Solo por por unica vez imprime
	//Se imprime un tablero lleno de 0's	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << tablero[i][j] << " ";
		}
		cout << endl;
	}
}
void ColocaMinas(int tablero[filas_max][columas_max], int filas, int columas, int Cantminas) {
	int flag = 0;
	while (flag == Cantminas) {
		int filarRam;
		int columRam;
		filarRam = rand() % (filas); // Resto de filas para obtener un numero random 
		columRam = rand() % (columas); // Resto de columnas para obtener un numero random
		tablero[filarRam][columRam] = 'M';
		flag++; //Cuando la flag llegue al numero de minas sale del bucle
	}
}
char ColocarNumeros(int tablero[filas_max][columas_max], int filas, int columas) {


	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columas; j++) {
			if (tablero[i][j] != 'M') {//Se aplican las estructuras selecctivas necesarias para filtrar los valores de alrededor
				if ((tablero[i][j + 1] == 'M') || (tablero[i][j - 1] == 'M'));

			}
		}
	}

}

void ImprimeTablero(int tablero[filas_max][columas_max], int  playerFila, int playerColum) {
	int Impresion[filas_max][columas_max];
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columas; j++) {
			Impresion[i][j] = 0; //Se ponen los valores a 0 para que el jugador observe (Mascara para jugador)
		}
	}
	Impresion[playerFila][playerColum] = tablero[playerFila][playerColum]; // Se cambia los valores escogidos por el jugador al original del tablero 
	//Se imprime un tablero actualizado	
	for (int i = 0; i < ; i++) {
		for (int j = 0; j < ; j++) {
			cout << Impresion[i][j] << " ";
		}
		cout << endl;
	}

}
bool VerificarGanador(int tablero[filas_max][columas_max], int  playerFila, int playerColum) {
	//Verifica que la casilla escogida por el jugador es M o no 
	if (tablero[playerFila][playerColum] == 'M') {
		cout << "Ud. Descubrio una mina, por lo tanto pierde el juego" << endl;
		return false;
	}
	return true;
}