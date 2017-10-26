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
//    file = fopen("/dev/ttyUSB0","wt");  //Opening device file

//    if(file == NULL)
//    {
//        perror("fopen failed for ttyUSB0");
//        exit(-1);
//    }

//    while(1)
//    {
//        gets(buf);
//        fputs(buf , stdout);
//        fputs("\n",stdout);
//        fputs(buf, file);
//        fputs("\n",file);
//    }
//    fclose(file);
//}



