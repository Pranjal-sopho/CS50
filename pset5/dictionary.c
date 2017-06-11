/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include<string.h>
#include "dictionary.h"
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>

int hashfunction(char*);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    char str[46];
    strcpy(str,word);
    int i=0;
    while (str[i]!='\0')
    {    
        str[i] = tolower(str[i]);
        i++;
    }    
        
    node* cursor = hashtable[hashfunction(str)];
 
    while(cursor != NULL)
    {
        if ( ( strcmp(str,cursor->word) )==0 )
            return true;
        else
            cursor = cursor->pointer;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    int k;
    FILE* fp = fopen(dictionary,"r");
    if(fp == NULL)
        return false;
        
    for(int i=0; i<26; i++)
    {
        hashtable[i] = NULL;
    }
 
    while(true)
    {
        if(feof(fp))
            return true;
            
        node* n = malloc(sizeof(node));
        
        n->pointer = NULL;
        
        fscanf(fp,"%s",n->word);
        
        if(isalpha(n->word[0]))
        {
            k = hashfunction(n->word);
        }
        
        else return true;
        
        if(hashtable[k] == NULL)
        {
            hashtable[k] = n;
            total_words++;
        }
        
        else
        {
            node* traverse = hashtable[k];
            while(true)
            {
                if(traverse->pointer == NULL)
                {
                    traverse->pointer = n;
                    total_words++;
                    break;
                }
                traverse = traverse->pointer;
            }
        }
        
    }
   return false; 
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return total_words;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    int i;
    for( i=0; i<26; i++)
    {
        node* liberator = hashtable[i];
        while(liberator != NULL)
        {
            node* temporary = liberator;
            liberator = liberator->pointer;
            free(temporary);
        }
    }
    
    if(i==26)
        return true;
     
    return false;
}

// hashfunction definition
int hashfunction(char* word )
{
    return (*word- 'a');
}