#include "stdafx.h"
#include "StringBuffer.h"


/*
costruisce un oggetto con un buffer di dimensione iniziale ragionevole e 0 caratteri utilizzati
*/
StringBuffer::StringBuffer() {
	ptr = new char[dim]; //dim-1 caratteri + terminatore
	used = 0;			//0 caratteri utilizzati
}

/*
costruisce un oggetto allocando un buffer di dimensione sufficiente a contenere l'array di caratteri str
(compreso il terminatore finale) e segnando correttamente il numero di caratteri effettivamente utilizzati
*/
StringBuffer::StringBuffer(const char *str) {
	size_t i = strlen(str); //caratteri contenuti dalla stringa
	if (i > dim) {
		// allocare più memoria
		dim = i + 1;
	}
	ptr = new char[dim];		//alloco un buffer di dimensione uguale alla stringa passata al costruttore
	memcpy(ptr, str, dim);
	used = i; //caratteri effettivamente utilizzati
	//std::cout << "stringa: " << ptr << std::endl;
	//std::cout << "caratteri utilizzati: " << i << std::endl;
}

/*
costruisce un oggetto con un buffer iniziale di dimensione adeguata a contenere i caratteri contenuti nell’oggetto sb 
e inizializzato con una copia di tali caratteri
*/
StringBuffer::StringBuffer(const StringBuffer& sb) {
	this->used = sb.used;
	this->dim = sb.dim;
	this->ptr = new char[used];
	memcpy(this->ptr, sb.ptr, dim);
	//std::cout << ptr << std::endl;
}

/*
rilascia le risorse contenute nell'oggetto
*/
StringBuffer::~StringBuffer() {
	delete[] ptr;
}

/*
restituisce il numero di caratteri utilizzati dalla stringa memorizzata nel buffer
*/
size_t size() {

}