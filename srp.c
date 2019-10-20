#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

//Global Variables 
int z = 0, i = 0, j = 0, c = 0; 

// Modify array size to increase 

char str[16], ac[20], stk[15], act[10]; 


void check() 
{ strcpy(ac,"REDUCE TO E -> ");   
    for(z = 0; z < c - 2; z++) 
    { 
        //checking for another production 
        if(stk[z] == 'E' && stk[z + 1] == '+' &&  
                                stk[z + 2] == 'T')  
        { 
            printf("%s", ac); 
            stk[z] = 'E'; 
            stk[z + 1] = '\0'; 
            stk[z + 2] = '\0'; 
            printf("\n$%s\t%s$\t", stk, str); 
            i = i - 2; 
        } 
        
          
    }
     
	  for(z = 0; z < c; z++)  
    { 
        //checking for producing rule E->4 
        if(stk[z] == 'T')  
        { 
            printf("%sT", ac); 
            stk[z] = 'E'; 
            stk[z + 1] = '\0'; 
              
            //pinting action 
            printf("\n$%s\t%s$\t", stk, str); 
        
        } 
    } 
     
    strcpy(ac,"REDUCE TO T -> "); 
      for(z=0; z<c-2; z++) 
    { 
         
        if(stk[z] == 'T' && stk[z + 1] == '*' &&  
                                stk[z + 2] == 'F')  
        { 
            printf("%sT*F", ac); 
            stk[z]='T'; 
            stk[z + 1]='\0'; 
            stk[z + 2]='\0'; 
            printf("\n$%s\t%s$\t", stk, str); 
            i = i - 2; 
        } 
        
    } 
	
      for(z = 0; z < c; z++)  
    { 
       
        if(stk[z] == 'F')  
        { 
            printf("%sF", ac); 
            stk[z] = 'T'; 
            stk[z + 1] = '\0'; 
              
            
            printf("\n$%s\t%s$\t", stk, str);  
        } 
        
    }   
    
    
	 strcpy(ac,"REDUCE TO F -> ");
      for(z = 0; z < c; z++)  
    { 
       
        if((stk[z] != 'F')&&(stk[z] != 'E')&&(stk[z] != 'T')&&(stk[z] != '+')&&(stk[z] != '*')&&(stk[z] != '(')&&(stk[z] != ')')&&(stk[z]!='\0'))  
        { 
            printf("%sid", ac); 
            stk[z] = 'F'; 
            stk[z + 1] = '\0'; 
              
            
            printf("\n$%s\t%s$\t", stk, str); 
            
        } 
       
    }

     for(z=0; z<c-2; z++) 
    { 
         
        if(stk[z] == '(' && stk[z + 1] == 'E' &&  
                                stk[z + 2] == ')')  
        { 
            printf("%s(E)", ac); 
            stk[z]='F'; 
            stk[z + 1]='\0'; 
            stk[z + 2]='\0'; 
            printf("\n$%s\t%s$\t", stk, str); 
            i = i - 2; 
        } 
        
    }   
     for(z=0;stk[z]!='\0'; z++)
     if(stk[z]=='F'||stk[z]=='T')
     check();
     
    
   
     return;
}
	
int main() 
{ 
	printf("GRAMMAR is E+T/T \n T*F/F \n (E)/id \n");	 
	
	
	printf("Enter the input");
	scanf("%s",str);
	
	
	c=strlen(str); 
	
	
	strcpy(act,"SHIFT"); 
	
	
	printf("\nstack \t input \t action"); 
	
	printf("\n$\t%s$\t", str); 
	
	
	for(i = 0; j < c; i++, j++) 
	{ 
		
		printf("%s", act); 
		
		
		stk[i] = str[j];	 
		stk[i + 1] = '\0'; 
		
		
		str[j]=' '; 
		
		
		printf("\n$%s\t%s$\t", stk, str); 
		
		// Call check function ..which will 
		// check the stack whether its contain 
		// any production or not 
		check(); 
	} 
	
	// Rechecking last time if contain 
	// any valid production then it will 
	// replace otherwise invalid 
	check(); 
	
	// if top of the stack is E(starting symbol) 
	// then it will accept the input 
	if(stk[0] == 'E' && stk[1] == '\0') 
		printf("Accept\n"); 
	else //else reject 
		printf("Reject\n"); 
} 
