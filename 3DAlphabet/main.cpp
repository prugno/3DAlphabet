#include <math.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  /* UNIX standard function definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <sys/types.h>
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */

#define WINDOW 40
#define N_VAR 10
#define CHARSIZE 20

int system(const char *command);

FILE *din;
FILE *dout, *oout,*mo;

char stg[260],stg2[250],stg3[250],stgr[200];
char tipo=(char)(97);
int i=0,x=0,y=0,z=0,ind=0,xmax=0,cx=0,j;
int gl,p=0;
char tt;
int char_max=0,char_min=0,chsize;

int main() {
   
    din=fopen("/Users/uea/Documents/xcode/3DAlphabet/3DAlphabet/alphabet.txt","r");
    
        while (fscanf(din,"%d%c",&gl,&tt) !=EOF) {
            x++;
            if(tt=='\n'){
              if(i==0)  printf("W,H = %d ",x);
                if(xmax<x) xmax=x;
                y++;
                x=0;
                i++;
            }
        }
    rewind(din);
    printf("%d\n",y);
    chsize=xmax/36;
    printf("Xmax= %d ; width=%d\n",xmax,chsize);
    y=0;

    p=0;
    
    for(i=97;i<123;i++){
    sprintf(stg,"/Users/uea/Documents/xcode/3DAlphabet/3DAlphabet/tifs/%c.obj",(char)(i));
    dout=fopen(stg,"w");
        char_min=p;
        char_max=p+chsize;
        p+=chsize;
        while (fscanf(din,"%d ",&gl) !=EOF) {
           if(x<=char_max && x>=char_min){
                cx++;
               if(gl>100){
                   for(j=0;j<5;j++) fprintf(dout,"v %f %f %f\n",(float)(cx),(float)(y),(float)(j));
            }
           }
            if(cx==chsize)   y++,cx=0;
            if(x==xmax)  x=0,cx=0;
            x++;
        }
          
        y=0; cx=0;
        fclose(dout);
        rewind(din);
    }
    
    for(i=48;i<58;i++){
        sprintf(stg,"/Users/uea/Documents/xcode/3DAlphabet/3DAlphabet/tifs/%c.obj",(char)(i));
        dout=fopen(stg,"w");
        char_min=p;
        char_max=p+chsize;
        p+=chsize;
        while (fscanf(din,"%d ",&gl) !=EOF) {
            if(x<=char_max && x>=char_min){
                cx++;
                if(gl>100){
                    for(j=0;j<5;j++) fprintf(dout,"v %f %f %f\n",(float)(cx),(float)(y),(float)(j));
                }
            }
            if(cx==chsize)   y++,cx=0;
            if(x==xmax)  x=0, cx=0;
            x++;
        }
        
        y=0; cx=0;
        fclose(dout);
        rewind(din);
    }

    fclose(din);
    char st[100];
    sprintf(st,"x%.2f_y%.2f",1.23,4.56);
    for(i=0;i<strlen(st);i++){
        printf("STRING %c\n",(char)(st[i]));
    }
}
