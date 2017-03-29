#pragma once
class StringBuffer
{

private:

	char *ptr;		//puntatore a caratteri
	size_t used;		//caratteri utilizzati
	size_t dim = 32;	//dimensione buffer

public:
	/*
	costruisce un oggetto con un buffer di dimensione iniziale ragionevole e 0 caratteri utilizzati
	*/
	StringBuffer();

	/*
	costruisce un oggetto allocando un buffer di dimensione sufficiente a contenere l'array di caratteri str
	(compreso il terminatore finale) e segnando correttamente il numero di caratteri effettivamente utilizzati
	*/
	StringBuffer(const char *str);

	/*
	costruisce un oggetto con un buffer iniziale di
	dimensione adeguata a contenere i caratteri contenuti nell’oggetto sb e inizializzato con
	una copia di tali caratteri
	*/
	StringBuffer(const StringBuffer& sb);

	/*
	rilascia le risorse contenute nell'oggetto
	*/
	~StringBuffer();

	/*
	restituisce il numero di caratteri utilizzati dalla stringa memorizzata nel buffer
	*/
	size_t size();

	/*
	restituisce la dimensione totale del buffer di caratteri
	*/
	size_t bufsize();

	/*
	porta a 0 il numero di caratteri utilizzati
	*/
	void clear();

	/*
	inserisce il contenuto s nella posizione pos del buffer
	o se pos è maggiore di size(), inserisce spazi tra size() e pos
	*/
	void insert(const char *str, size_t pos);

	/*
	inserisce il contenuto di sb nella posizione pos del buffer
	o se pos è maggiore di size(), inserisci spazi tra size() e pos
	*/
	void insert(const StringBuffer& sb, size_t pos);

	/*
	aggiunge i caratteri contenuti in str in coda a quelli
	memorizzati nel buffer, riallocando il buffer se necessario
	*/
	void append(const char *str);

	/*
	aggiunge i caratteri contenuti nell'oggetto sb in coda
	a quelli memorizzati nel buffer, riallocando il buffer se necessario
	*/
	void append(const StringBuffer& sb);

	/*
	restituisce un puntatore in sola lettura al buffer interno
	*/
	const char *c_str();

	/*
	sostituisce la stringa memorizzata nel buffer con il contenuto
	dell'array s, riallocando il buffer se necessario
	*/
	void set(const char *str);

	/*
	sostituisce la stringa memorizzata nel buffer con il contenuto
	dell'oggetto s, riallocando il buffer se necessario
	*/
	void set(const StringBuffer& s);
};