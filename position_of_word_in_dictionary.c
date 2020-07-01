/*
Problem 2:
------------
Given N(<=26) followed by N distinct characters, we can find all possible 2N words(sequence of characters) which preserve the ordering in the input (assuming that all words are valid words in the language). For example, if N is 3 and chatacters are A, B and C, the words in the alphabet order are A, AB, ABC, AC, B, BC and C. Your task now, is to find the index of the word in the dictionary i.e., if input is AC, output is 4. You may avoid generating all the words and comparing the word with every word in the dictionary.


Input Specification
--------------------

Input contains a number N representing the number of alphabets(<=26) followed by a space and N characters in the dictionary listed in lexicographic order and then a valid word present in dictionary.


Output Specification
---------------------

Output must be the index of the word in the dictionary.


Sample Input and Output
------------------------

Input: 3 A B C AC
Output: 4
Input: 3 A B C BC
Output: 6

*/


#include<stdio.h>


int main(){
int N;
	scanf("%d",&N);
	char input_chars[N];
	int i;
	for(i=0;i<N ;i++)
	{
		scanf(" %c",&input_chars[i]);
	}
	char input[100];
	scanf("%s",input);
	
	
	int position=0,j=0; 
	int addValue[N];
	for(i=0,j=N-1;i<N ;i++,j--)
	   addValue[i] = (1<<j);
	
	for(int a = 0; a < N; ++a)
	    printf("%2d : %3d\n", a, addValue[a]);
	
	
	
	for(i=0,j=0;input[i];i++){
       		while(input_chars[j]!=input[i]){ 
			position+=addValue[j];
			j++;
		}
		j++;
		position++;	
	}
	printf("%d\n",position);

	return 0;
}
