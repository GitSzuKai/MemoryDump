#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void memdump(char * p , int len) {
    // Add your code here.
      int address_at_p;
      int count = 0;
  
    while (count < len) {

        printf("0x%x: ",&p[count]);
	int i =count;
      for (i; i < len && i < count +16; i++){
        address_at_p = p[i]&0xFF;
         
        printf("%02X ",address_at_p);
      }

      int temporary_total_Length = len;
      
        while (len < count +16){
        printf("%s", " ");
        //temporary_total_Length++;
      }
	int k = count;
          for(k; k < len && k < count +16; k++){
            address_at_p = p[k]&0xFF;
            if(address_at_p >= 32 && address_at_p <= 127){
              printf("%c", address_at_p);
            }else{
              printf(".");
            }
          }
        count +=16;
        printf("\n");
    }
    
}

struct X{
    char a;
    int i;
    char b;
    int *p;
};

//Each block stores str and pointer to next block
struct List {
  char * str;
  struct List * next;
};

int main() {
  char str[20];
  int a = 5;
  int b = -5;
  double y = 12;
  struct X x;
  struct List * head;

  x.a = 'A';
  x.i = 9;
  x.b = '0';
  x.p = &x.i;
  strcpy(str, "Hello world\n");
  
  printf("&str=0x%x\n",&str);
  printf("&a=0x%x\n",&a);
  printf("&b=0x%x\n",&b);
  printf("&x.i=0x%x\n",&x.i);
  printf("&x.b=0x%x\n",&x.b);
  printf("&x.p=0x%x\n",&x.p);  
  printf("&x=0x%x\n", &x.a); //Prints out the address of x.a
  printf("&y=0x%x\n", &y);  //Prints out the address of y or the double 12
  memdump((char *) &x.a, 64);

  head = (struct List *) malloc(sizeof(struct List)); //Initialize the Link list space
  head->str=strdup("Welcome ");
  head->next = (struct List *) malloc(sizeof(struct List));
  head->next->str = strdup("to ");
  head->next->next = (struct List *) malloc(sizeof(struct List));
  head->next->next->str = strdup("cs250");
  head->next->next->next = NULL;
  printf("head=0x%x\n", head); // Print pointers of the header
  printf("head>str=%p\n",head->str);
  printf("head->next=%p\n",head->next);
  printf("head->next->str=%p\n",head->next->str);
  printf("head->next->next=%p\n",head->next->next);
  printf("head->next->next->str=%p\n",head->next->next->str);
  printf("head->next->next->next=%p\n",head->next->next->next);
 memdump((char*) head, 128);
}

