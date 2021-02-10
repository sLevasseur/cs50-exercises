#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

int readabilityScore(int length, string str);

int main (void)
{
    string str = get_string("Sentence(s) to process : ");
    int length = strlen(str);
    
    if (readabilityScore(length, str) >= 16)
    {
        printf("Grade 16+\n");
    } else if (readabilityScore(length, str) < 1) 
    {
        printf ("Before Grade 1\n");
    } else {
        printf("Grade %i\n",readabilityScore(length, str));
    }
    
    
}

int readabilityScore(int length, string str)
{
    int countLetters = 0;
    int countWords = 1;
    int countSentences = 0;
    
    for (int i = 0; i < length; i++)
    {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
        {
            countLetters++;
        }

        if (str[i]==32)
        {
            countWords++;
        }
        
        if (str[i]==33 || str[i]==46 || str[i]==63)
        {
            countSentences++;
        }
    }
    
    float L = ((float)countLetters / (float)countWords) * 100;
    float S = ((float)countSentences / (float)countWords) * 100;
    
    return round((0.0588*L) - (0.296*S) - 15.8);

    
    
}