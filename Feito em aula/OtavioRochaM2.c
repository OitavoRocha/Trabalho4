#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_PALAVRA 10

char ** removeAnagrams( char ** words, int wordsSize, int * returnSize );

int main() {
    int n, newN = 0;
    char ** words;

    printf("Informe a quantidade de palavras: ");
    scanf("%d", &n);
    words = (char **)malloc( sizeof(char *) * n );

    printf("Informe uma sequencia de %d palavras: ", n);
    for( int i = 0 ; i<n ; i++ ) {
        words[i] = (char *)malloc( sizeof(char) * TAMANHO_PALAVRA );
        getchar();
        scanf("%[^\n]s", words[i]);
    }

    words = removeAnagrams( words, n, &newN );

    printf("Saida: ");
    for( int i = 0 ; i<newN ; i++ ) {
        printf("%s ", words[i]);
    }

    printf("\n");
    free( words );

    return 0;
}

char ** removeAnagrams( char ** words, int wordsSize, int * returnSize ) {
    char ** ret;
    char * key;
    int ai, bi;
    int f;
    int flag = 0;

    *returnSize = wordsSize;


    for( int i = 0 ; i<*returnSize ; i++ ) {
        key = words[i];

        for( int j = 0 ; j<*returnSize ; j++ ) {
            if( (strlen(key) == strlen(words[j])) && i!=j ) {
                ai = bi = 0;
                for( int  k = 0 ; k<((int)strlen(key)) ; k++ ) {
                    ai += (int) key[k];
                    bi += (int) words[j][k];
                }
                
                if( ai == bi ) {
                    flag++;
                    f = 0;
                    for( int k = j+1 ; k<*(returnSize); k++, f++ )
                        strcpy(words[j + f], words[k]);
                    (*returnSize)--;
                    j--; // to repeat the same position
                }
            }
        }
    }

    if( flag == 0 ) // if there were no changes in the first array, then returns it
        return words;


    ret = (char **)malloc( sizeof(char) * (*returnSize) );
    for( int i = 0 ; i<*returnSize ; i++ ){
        ret[i] = (char *)malloc( sizeof(char) * TAMANHO_PALAVRA );
        strcpy(ret[i], words[i]);
    }

    return ret;
}   