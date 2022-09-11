// Complete the function to replace any period by an exclamation point. Ex:
// "Hello. I'm Miley. Nice to meet you." becomes: "Hello! I'm Miley! Nice to
// meet you!"

#include <stdio.h>
#include <string.h>

void MakeSentenceExcited(char* sentenceText) {
    /* Your solution goes here  */
    for (int i = 0; i < strlen(sentenceText); i++) {
        if (sentenceText[i] == '.') sentenceText[i] = '!';
    }
}

int main(void) {
    const int TEST_STR_SIZE = 50;
    char testStr[TEST_STR_SIZE];

    fgets(testStr, TEST_STR_SIZE, stdin);
    MakeSentenceExcited(testStr);
    printf("%s", testStr);

    return 0;
}
