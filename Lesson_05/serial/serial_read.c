//#include <stdlib.h>
//#include <stdio.h>
//#include <unistd.h>
//#include <fcntl.h>
//#include <string.h>

//int main()
//{
//    int i = 0;
//    char ch;
//    char buf[1024] ;  //Random data we want to send
//    FILE *file;
//    file = fopen("/dev/ttyUSB0","rt");  //Opening device file

//    if(file == NULL)
//    {
//        perror("fopen failed for ttyUSB0");
//        exit(-1);
//    }

//    for(i = 0 ; 1;)
//    {
//        ch = fgetc(file);
//        if(ch != -1)
//        {
//            buf[i++] = ch;
//            if(ch == '\n')
//            {
//                buf[i] = 0;
//                printf("%s" , buf);
//                i = 0;
//            }

//        }
//    }
//    fclose(file);
//}



