#include <stdio.h>


int *ptr=NULL;
int choice=1;
//module_param(choice,int, S_IRUGO);

void do_write(void) {
    int i,dummy=0;
    for(i=1;i<=10;i++)              //dummy code
      dummy+=i;
    *ptr = 100;                     //suspected code
    printf("end of do_write\n");
}
void do_read(void) {
    int val,i,dummy;
    for(i=1;i<=10;i++)              //dummy code
      dummy+=i;
    val = *ptr;                     //suspected code
    printf("val is %d\n",*ptr);
}

int main(int argc, char* argv[])
{
  printf("Hello World..welcome\n");
  if(choice==1)
     do_write();   
  else
     do_read();
  return 0;
}
/*static void __exit hello_exit(void) {       //cleanup_module
  printf("Bye,Leaving the world\n");
}
static void test(void) {
  printf("test function\n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your name");
MODULE_DESCRIPTION("A Hello, World Module");*/
