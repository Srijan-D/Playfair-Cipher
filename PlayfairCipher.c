
#include <stdio.h>
#include <string.h>
int main()
{

    // input character array
    char key[200];
    printf("Enter the key\n");
    scanf("%s", key);
    // delete repeated characters in the key
    // STEP2:
    int i, j, k;
    for (i = 0; i < strlen(key); i++)
    {
        for (j = i + 1; j < strlen(key); j++)
        {
            if (key[i] == key[j])
            {
                for (k = j; k < strlen(key); k++)
                {
                    key[k] = key[k + 1];
                }
                j--;
            }
        }
    }
    //  STEP3:
    // adding rest of the alphabets in the array
    // add rest of the alphabets in the array

    char newKey[300];
    // copy key in newkey
    for (i = 0; i < strlen(key); i++)
    {
        newKey[i] = key[i];
    }
    // add rest of the alphabets in the array
    int count = 0;
    for (i = 0; i < 26; i++)
    {
        int flag = 0;
        for (j = 0; j < strlen(key); j++)
        {
            if (key[j] == 'a' + i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            newKey[strlen(key) + count] = 'a' + i;
            count++;
        }
    }
    // remove alphabet j from newKey string
    for (i = 0; i < strlen(newKey); i++)
    {
        if (newKey[i] == 'j')
        {
            for (j = i; j < strlen(newKey); j++)
            {
                newKey[j] = newKey[j + 1];
            }
            i--;
        }
    }

    int len = strlen(newKey);
    for (i = 0; i < len; i++)
    {
        if (newKey[i] == 'j')
        {
            for (j = i; j < len; j++)
            {
                newKey[j] = newKey[j + 1];
            }
            len--;
            i--;
        }
    }
    // storing newkey in matrix
    char matrix[5][5];
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            matrix[i][j] = newKey[i * 5 + j];
        }
    }
    // print matrix
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    // input a string
    char plainText[2];
    printf("Enter a plainText string :");
    scanf("%s", plainText);
    // check if length of plaintext is even or odd
    int len1 = strlen(plainText);
    if (len1 % 2 != 0)
    {
        strcpy(plainText, strcat(plainText, "x"));
        len1++;
    }
    // if both elements are same replace one with 'x'
    if (plainText[0] == plainText[1])
    {
        plainText[1] = 'x';
    }

    // replace j with i if present in plaintext
    for (i = 0; i < len1; i++)
    {
        if (plainText[i] == 'j')
        {
            plainText[i] = 'i';
        }
    }
    printf("Plaintext: %s", plainText);

    // Encryption
    char cipherText[20];
    // finding position of first element of plaintext in matrix
    int row1 = 0;
    int col1 = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (matrix[i][j] == plainText[0])
            {
                row1 = i;
                col1 = j;
                break;
            }
        }
    }
    // finding position of second element of plaintext in matrix
    int row2 = 0;
    int col2 = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (matrix[i][j] == plainText[1])
            {
                row2 = i;
                col2 = j;
                break;
            }
        }
    }

    // three cases:
    int checkCase = 0;
    // case 1:
    // same column:
    if (col1 == col2)
    {
        checkCase = 1;
        if (row1 != 4)
        {
            row1 = row1 + 1;
        }
        else
        {
            row1 = 0;
        }
        if (row2 != 4)
        {
            row2 = row2 + 1;
        }
        else
        {
            row2 = 0;
        }
    }

    // case 2:
    // same row:
    if (row1 == row2)
    {
        checkCase = 2;
        if (col1 != 4)
        {
            col1 = col1 + 1;
        }
        else
        {
            col1 = 0;
        }
        if (col2 != 4)
        {
            col2 = col2 + 1;
        }
        else
        {
            col2 = 0;
        }
    }

    // case 3:
    //  different row and column:
    if (row1 != row2 && col1 != col2)
    {
        checkCase = 3;
        int temp = col1;
        col1 = col2;
        col2 = temp;
    }

    // printf("\n row1: %d\n col1: %d\n row2: %d\n col2: %d\n", row1, col1, row2, col2);
    printf("\ncipherText: %c%c", matrix[row1][col1], matrix[row2][col2]);

    // Decryption:
    // similar approach for encryption
    switch (checkCase)
    {

    case 1:
        // same column
        if (row1 != 0)
        {
            row1 = row1 - 1;
        }
        else
        {
            row1 = 4;
        }
        if (row2 != 0)
        {
            row2 = row2 - 1;
        }
        else
        {
            row2 = 4;
        }

        break;

    case 2:
        // same row

        if (col1 != 0)
        {
            col1 = col1 - 1;
        }
        else
        {
            col1 = 4;
        }
        if (col2 != 0)
        {
            col2 = col2 - 1;
        }
        else
        {
            col2 = 4;
        }
        break;
        int temp;
    case 3:
        // default statements
        // interchanging col1 and col2
        temp = col2;
        col2 = col1;
        col1 = temp;
        break;

    default:
        printf("Some error occurred");
    }
    // decrypted text is:
    printf("\ndecrypted text: %c%c", matrix[row1][col1], matrix[row2][col2]);
    return 0;
}
