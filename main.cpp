#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>


using namespace std;


class Palabra{

    public:
        string palabra;
        int tamaño;
		Palabra(string, int);
		void muestraPalabra();
		bool buscarLetra(char letra);
};

Palabra::Palabra(string word, int size){
		palabra = word;
		tamaño = size;
}




int main(int argc, char **argv)
{
    string p = ""
    
    
    char character = 0;
    while (!feof(input_file)) {
       character = getc(input_file);
       cout << character << "-";
    } cout << endl; fclose(input_file);
    
    
    
    return 0;
}

void creaPalabras(){
	
}
