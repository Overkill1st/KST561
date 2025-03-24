#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 1000




int read_data(char*filename, char* data)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening file");
        return EXIT_FAILURE;
    }
    if(fgets(data, MAXN, fp) == NULL)
    {
        printf("Error reading from file");
        return EXIT_FAILURE;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}
void write_text(char*filename, char*text)
{
    FILE *fp = fopen(filename,"wb");
    fprintf(fp, "%s",text);
    fclose(fp);
}
char* vigenere_encrypt(char *plaintext, char *key)
{
    int text_length = strlen(plaintext);
    int key_length = strlen(key);

    char* cipher = (char*)malloc(sizeof(char)*(text_length + 1));
    memset(cipher, '\0', sizeof(char) * (text_length + 1));

    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            int shift = tolower(key[i % key_length]) - 'a';
            if (islower(plaintext[i]))
            {
                cipher[i] = 'a' + (plaintext[i] - 'a' + shift) % 26;
            }
            else
            {
                cipher[i] = 'A' + (plaintext[i] - 'A' + shift) % 26 ;
            }
            
        }
        else if (isdigit(plaintext[i])){
            int shift = tolower(key[i % key_length]) - 'a';
            cipher[i] = '0' + (plaintext[i] - '0' + shift) % 10;
        }
        else
        {
            cipher[i] = plaintext[i];
        }
    }
    cipher[text_length] = '\0';
    return cipher;
}
char* vigenere_decrypt(char *cipher, char *key)
{
    int text_length = strlen(cipher);
    int key_length = strlen(key);

    char* decrypted = (char*)malloc(sizeof(char)*(text_length + 1));
    memset(decrypted, '\0', sizeof(char) * (text_length + 1));

    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(cipher[i]))
        {
            int shift = tolower(key[i % key_length]) - 'a';
            if (islower(cipher[i]))
            {
                decrypted[i] = (cipher[i] - 'a' - shift + 26) % 26 + 'a';
            }
            else
            {
                decrypted[i] = (cipher[i] - 'A' - shift + 26) % 26 + 'A';
            }
        }
        else if (isdigit(cipher[i])){
            int shift = tolower(key[i % key_length]) - 'a';
            decrypted[i] = (cipher[i] - '0' - shift + 10) % 10 + '0';
        }
        else
        {
            decrypted[i] = cipher[i];
        }
    }
    decrypted[text_length] = '\0';
    return decrypted;
}
int main()
{
    printf("Enter filename for text. \n");
    char filename[MAXN];
    scanf("%s", filename);

    char cipher[MAXN];
    read_data(filename, cipher);

    printf("Enter filename for key. \n");
    scanf("%s", filename);

    char key[MAXN];
    read_data(filename, key);
  
    char* decrypted = vigenere_decrypt(cipher, key);

    printf("Enter filename for decryption. \n");
    char output_filename[MAXN];
    scanf("%s", output_filename);

    write_text(output_filename,decrypted);

    free(decrypted);
    return EXIT_SUCCESS;
}
