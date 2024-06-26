#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "headers/ascon128.h"
#include <stdlib.h>

int main()
{

    char plaintext[500];
    char associated[500] = {0};

    char key[17] = "antaniantani1234";
    char nonce[17] = "antaniantani1234";


    while (1)
    {

        fgets(plaintext, 500, stdin);
        plaintext[strlen(plaintext)-1] = 0;
        ascon_t *ascon = encrypt(plaintext, associated, key, nonce);

        printf("Plaintext> %s\n", plaintext);
        printf("Associated> %s\n", associated);
        printf("Ciphertext> %s\n", getPrintableText(ascon->ciphertext, ascon->originalLength));
        printf("Tag: %s\n", getPrintableText(ascon->tag, 16));

        char *m = decrypt(ascon, associated, key, nonce);

        printf("Decrypted plaintext> %s\n", m);
        printf("decrypted length: %ld\n", strlen(m));
        printf("Nonce used> %lx%lx\n\n", *((uint64_t *)nonce), *((uint64_t *)nonce + 1));

        incrementNonce(nonce);
    }

    /*int check = 1, counter = 0;
    while(check){
        ascon_t *ascon = encrypt(plaintext, associated, key, nonce);
        //printf("Ciphertext> %s\n", ascon->ciphertext);
        char *m = decrypt(ascon, associated, key, nonce);
        //printf("Decrypted plaintext> %s\n\n", m);
        printf("Plaintext> %s\n", plaintext);
        //printf("Ciphertext> %s\n", ascon->ciphertext);
        printf("Nonce used> %lx%lx\n\n", *((uint64_t *)nonce), *((uint64_t *)nonce + 1));
        incrementNonce(nonce);
        printf("Counter: %d\n", counter++);
        printf("decrypted length: %d\n", strlen(m));
        if(strcmp(plaintext, m)){
            check = 0;
            printf("Ciphertext> %s\n", ascon->ciphertext);
            printf("Decrypted plaintext> %s\n\n", m);
        }
        incrementNonce(key);
        //free(ascon->ciphertext);
        //free(ascon->tag);
        //free(ascon);
        //free(m);
        //strcat(plaintext, "a");
    }*/

    return 0;
}