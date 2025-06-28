#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentence(string text);

int main(void)
{
    // prompt the user for text
    string text = get_string("text:");

    // count the number of letters ,words and setneces in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentence = count_sentence(text);

    // compute the coleman-liau index
    float L = (float) letters / words * 100;
    float S = (float) sentence / words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    // print the grade level
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }

    return 0;
}

int count_letters(string text)
{ // return the number of letters in the text
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    // return the number of words in the text
    int words = 0;
    for (int j = 0; j < strlen(text); j++)
    {
        if (isblank(text[j]))
        {
            words++;
        }
    }
    return words + 1;
}

int count_sentence(string text)
{
    // return the number of sentences in the text
    int sentence = 0;
    for (int k = 0; k < strlen(text); k++)
    {
        if (text[k] == '.' || text[k] == '?' || text[k] == '!')
        {
            sentence++;
        }
    }
    return sentence;
}
