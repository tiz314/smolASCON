#include <stdio.h>
#include "headers/ascon128.h"

int main()
{

    char plaintext[500];
    char associated[500] = {0};

    char key[17] = "antaniantani1234";
    char nonce[16] = "mntaniantani1234";

    while (1)
    {

        scanf("%s", plaintext);
        scanf("%s", associated);

        ascon_t *ascon = encrypt(plaintext, associated, key, nonce);

        printf("Plaintext> %s\n", plaintext);
        printf("Associated> %s\n", associated);
        //printf("Ciphertext> %s\n", ciphertext);

        char *ciphertext = "";

        char *m = decrypt(ciphertext, associated, key, nonce);

        printf("Decrypted plaintext> %s\n\n", m);
        printf("Nonce used> %32x\n\n", *nonce);
        *nonce += 1;
    }

    return 0;
}