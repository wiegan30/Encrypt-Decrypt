

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int args, char *argc[]){

int i=0;
int j=0;
int len=0;
char str[501]="";
char str2[3];
char c;
FILE *finp;
FILE *keyFile;
FILE *fout;

//if ( strcmp(argc[1], "e") == 0 )

   if ( (finp = fopen(argc[2],"r")) == NULL )
   {
      printf("Could Not Open file %s\n", argc[2]);
       exit(1);
   }

   if ( (keyFile = fopen(argc[3],"r")) == NULL )
   {
      printf("Could Not Open file %s\n", argc[3]);
        exit(1);
   }

   while((c = fgetc(finp))!=EOF){
     str[j++] = c;
   }
   str[j]='\0';
//   printf("I've got %s",str);

  
   while((c = fgetc(keyFile)) != EOF){
    
     str2[i++] = c;    
    
   }

   
   /*Print Statement to test the keys*/
   //  printf("%c%c", str2[0], str2[2]);
   /*Print Statement to test the input*/
   //  printf("%s\n", str);
      

  /* *** START CODE THAT USES INPUT.TXT FILE and KEYS.TXT *** */
  
  len = strlen(str);
  for(i=0;i<len-1;i+=2){
    //swap
    //    printf("xoring %x with %x\n",str[i],str2[2]);
    str[i]^=str2[2];
    //    printf("xoring %x with %x\n",str[i+1],str2[0]);
    //swap
    str[i+1]^=str2[0];
  }
  //printf("finished, i=%d, len=%d\n",i,len);

    
  if(i == len-1)
    str[i] ^= (str2[2] ^ str2[0]);

  fout=fopen("out.txt","w");
  if(fout==NULL){
    printf("ERROR");
    exit(1);
  }


  //loop to print to out.txt
  for(j=0;j<len;j++){
    fprintf(fout, "%c", str[j]);
}}
