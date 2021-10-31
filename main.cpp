#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <iterator>
#include <list>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Jugador{
	public:
		int aciertos;
		int errores;
		list<int> jugados;
};

class Palabra
{

public:
	string palabra;
	int tamaño;
	Palabra(string, int);
	Palabra();
	void muestraPalabra();
	list<int> buscarLetra(char letra);
};

Palabra::Palabra(string word, int size)
{
	palabra = word;
	tamaño = size;
}

Palabra::Palabra()
{
	palabra = "";
	tamaño = 0;
}

list <int> Palabra :: buscarLetra(char letra){
	list <int> pos;
	for (int i = 0; i < tamaño; i++)
	{
		if(palabra.at(i) == letra){
			pos.push_back(i);
		}
	}
	return pos;	
}

//Variable Global
list<Palabra> listaPalabras;

void creaPalabras(string word, int size)
{
	Palabra p = Palabra(word, size);
	cout << p.palabra << " " << p.tamaño << endl;
	listaPalabras.push_back(p);
}


void imprimeMono(int errores){
	switch (errores)
	{
	case 1 : 
			cout << "\t o" << endl;
		break;
	case 2 : 
			cout << "\t o" << endl;
			cout << "\t l" << endl;
		break;
	case 3 : 
			cout << "\t o" << endl;
			cout << "\t-l" << endl;
		break;
	case 4 : 
			cout << "\t o" << endl;
			cout << "\t-l-" << endl;
		break;
	case 5 : 
			cout << "\t o" << endl;
			cout << "\t-l-" << endl;
			cout << "\t/" << endl;
		break;
	case 6 : 
			cout << "\t o" << endl;
			cout << "\t-l-" << endl;
			cout << "\t/ \\" << endl;
		break;
	default:
		break;
	}
}



int main(int argc, char **argv)
{
	srand(time(NULL));
	string p = "";
	string namefile = "words.txt";
	char letra;
	Jugador p1;
	list <int> resposci;
	int j;
	
	int cpos, num, cletra = 0;
	ifstream file;

	char *copy;

	list<Palabra>::iterator pos;
	

	file.open(namefile.c_str());
	if (file.fail())
	{
		cout << "Error al leer el archivo de palabras" << endl;
		return 1;
	}
	else
	{
		file.get(letra);
		while (!file.eof())
		{
			if (letra != '\n')
			{
				cletra++;
				p += toupper(letra);
			}
			else
			{
				creaPalabras(p, cletra);
				cletra = 0;srand(time(NULL));
				p = "";
			}
			file.get(letra);
		}
	}
	file.close();

	num = rand() % listaPalabras.size();

	pos = listaPalabras.begin();
	cpos = 0;
	Palabra temp;

	cout << "Palabra seleccionada: " << num << endl;

	while (pos != listaPalabras.end())
	{
		if (cpos == num)
		{
			temp.palabra = pos->palabra;
			temp.tamaño = pos->tamaño;
			break;
		}
		pos++;
		cpos++;
	}

	copy = (char *) malloc(temp.tamaño*sizeof(char));

	for (int i = 0; i < temp.tamaño; i++)
	{
		if(temp.palabra.at(i) == ' '){
			copy[i]=' ';
		}else{
			copy[i]='_';
		}
	}


	for (int i = 0; i < temp.tamaño; i++)
	{
		cout << copy[i];
	}

	cout << endl;

	int posci;
	char luser;
	int vidas =6;
	p1.aciertos = 0;
	p1.errores = 0;
	do{

	cout << "Ingresa una letra" << endl;

	cin >> luser;

	luser = toupper(luser);

	resposci = temp.buscarLetra(luser);
	if(! resposci.empty()){
		while(! resposci.empty()){
			copy[resposci.front()] = luser;
			p1.aciertos++;
			resposci.pop_front();
		}
		
	}else{
		cout << "La letra no esta en la palabra :" << endl;
		p1.errores++;
		imprimeMono(p1.errores);
	}

	for (int i = 0; i < temp.tamaño; i++)
	{
		cout << copy[i];
	}

	cout << endl;
	
	}while((p1.errores != vidas) && ( p1.aciertos != temp.tamaño));

	if(p1.errores == vidas){
		cout << "PERDISTE" << endl;
	}else{
		cout << "GANASTE" << endl;
	}
	

	return 0;
}
