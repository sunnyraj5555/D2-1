/*
 *  EncodeDecode.cpp
 *
 *  Created on: 17-Oct-2021
 *     Authors: Tanishka Vaswani
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Person.h"

#define ACCURACY 5
#define SINGLE_MAX 10000
#define EXPONENT_MAX 1000
#define BUF_SIZE 1024

/*
 * Computes a^b mod c
 */
int modpow2(long long a, long long b, int c) 
{
	int res = 1;
	while(b > 0) 
	{
		/* Need long multiplication else this will overflow... */
		if(b & 1) 
		{
			res = (res * a) % c;
		}
		
		b = b >> 1;
		a = (a * a) % c; /* Same deal here */
	}
	
	return res;
}

/*
 * Read the file fd into an array of bytes ready for encryption.
 * The array will be padded with zeros until it divides the number of
 * bytes encrypted per block. Returns the number of bytes read.
 */
int readFile(FILE* fd, char** buffer, int bytes) 
{
	int len = 0, cap = BUF_SIZE, r;
	char buf[BUF_SIZE];
	
	*buffer = (char*)malloc(BUF_SIZE * sizeof(char));
	
	while((r = fread(buf, sizeof(char), BUF_SIZE, fd)) > 0) 
	{
		if(len + r >= cap) 
		{
			cap *= 2;
			*buffer = (char*)realloc(*buffer, cap);
		}
		
		memcpy(&(*buffer)[len], buf, r);
		len += r;
	}
	
	/* Pad the last block with zeros to signal end of cryptogram. An additional block is added if there is no room */
	if(len + bytes - len % bytes > cap) *buffer = (char*)realloc(*buffer, len + bytes - len % bytes);
	
	do 
	{
		(*buffer)[len] = '\0';
		len++;
	}
	
	while(len % bytes != 0);
	
	return len;
}

/*
 * Encode the message m using public exponent and modulus, c = m^e mod n
 */
int encode(int m, int e, int n) 
{
	return modpow2(m, e, n);
}

/*
 * Decode cryptogram c using private exponent and public modulus, m = c^d mod n
 */
int decode(int c, int d, int n) 
{
	return modpow2(c, d, n);
}

/*
 * Encode the message of given length, using the public key (exponent, modulus)
 * The resulting array will be of size len/bytes, each index being the encryption
 * of "bytes" consecutive characters, given by m = (m1 + m2*128 + m3*128^2 + ..),
 * encoded = m^exponent mod modulus
 */
int* encodeMessage(int len, int bytes, char* message, int exponent, int modulus) 
{
	int *encoded = (int*)malloc((len/bytes) * sizeof(int));
	int x, i, j;
	
	for(i = 0; i < len; i += bytes) 
	{
		x = 0;
		for(j = 0; j < bytes; j++) x += message[i + j] * (1 << (7 * j));
		
		encoded[i/bytes] = encode(x, exponent, modulus);
		
        #ifndef MEASURE
		    printf("%d ", encoded[i/bytes]);
        #endif
	}
	
	return encoded;
}

/*
 * Decode the cryptogram of given length, using the private key (exponent, modulus)
 * Each encrypted packet should represent "bytes" characters as per encodeMessage.
 * The returned message will be of size len * bytes.
 */
int* decodeMessage(int len, int bytes, int* cryptogram, int exponent, int modulus) 
{
	int *decoded = (int*)malloc(len * bytes * sizeof(int));
	int x, i, j;
	
	for(i = 0; i < len; i++) 
	{
		x = decode(cryptogram[i], exponent, modulus);
		
		for(j = 0; j < bytes; j++) 
		{
			decoded[i*bytes + j] = (x >> (7 * j)) % 128;
			
            #ifndef MEASURE
			    if(decoded[i*bytes + j] != '\0') printf("%c", decoded[i*bytes + j]);
            #endif
		}
	}
	
	return decoded;
}

int EncodeDecode(User &user) 
{
	int p, q, n, phi, e, d, bytes, len;
	int *encoded, *decoded;
	char *buffer;
	FILE *f;
	srand(time(NULL));

	e = user.get_User_Public_Key();
	d = user.get_User_Private_Key();
	n = user.get_User_EDFactor();
	
	if(n >> 21) bytes = 3;
	else if(n >> 14) bytes = 2;
	else bytes = 1;	
	
	f = fopen("text.txt", "r");
	
	if(f == NULL) 
	{
		return EXIT_FAILURE;
	}
	
	len = readFile(f, &buffer, bytes); /* len will be a multiple of bytes, to send whole chunks */
	fclose(f);
	
	encoded = encodeMessage(len, bytes, buffer, e, n);
	
	decoded = decodeMessage(len/bytes, bytes, encoded, d, n);
	
	free(encoded);
	free(decoded);
	free(buffer);
	
	return EXIT_SUCCESS;
}
