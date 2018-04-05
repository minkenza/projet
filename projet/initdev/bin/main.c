#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

/* pour la création des répertoire et des fichiers */

void creationFichBase(char *nom[])
{
char lic[1024],mkf[1024],main[1024];
char cwd[1024];
 
  if(getcwd(cwd,sizeof(cwd)) != NULL )
		{
		strcat(cwd, "/");
		strcat(cwd, nom);
		}
    strcpy(main ,cwd);
		strcat(main, "/main");
    int fd=creat(main ,0777);		
		
	  strcpy(lic ,cwd);
		strcat(lic, "/LINCENCE");
     fd=creat(lic ,0777);

		strcpy(mkf ,cwd);
		strcat(mkf, "/Mikefile");
     fd=creat(mkf ,0777);
}
void creationRepBase(char *nom[])
{
	char cwd[1024];
 
  if(getcwd(cwd,sizeof(cwd)) != NULL )
		{
		strcat(cwd, "/");
		strcat(cwd, nom);
		mkdir(cwd , 0775);
		//printf(cwd);
		}
}		

void creationFich(char *main[],char *param[])
{
	char lic[1024],mkf[1024],main1[1024];
	char cwd[1024] , buf;
  int fd1, fd2;
	
	 if(getcwd(cwd,sizeof(cwd)) != NULL )
		{
		strcat(cwd, "/");
		strcat(cwd, main);
		}
if(strcmp(param, "-GPL") != 0 && strcmp(param, "-MIT") !=0){
 strcpy(lic ,cwd);
 strcat(lic, "/LINCENCE");
 fd=creat(lic ,0777);

 strcpy(mkf ,cwd);
 strcat(mkf, "/Mikefile");
 fd=creat(mkf ,0777);

	 if (strcmp(param, "-C") == 0) {strcat(main, "/main.c");fd1=creat(main ,0777);
                         fd2 = open("../sources/main.c",O_RDONLY);
            while (read (fd2,&buf,1) != 0)
		        write(1,&buf,1);}
    else if (strcmp(param, "-Py") == 0) {strcat(main, "/main.py");fd1=creat(main ,0777); fd2 = open("../sources/main.py",O_RDONLY);}
     else if (strcmp(param, "-Latex") == 0) {strcat(main, "/main.tex");fd1=creat(main ,0777); fd2 = open("../sources/main.tex",O_RDONLY);}
      else if (strcmp(param, "-CPP") == 0) {strcat(main, "/main.cpp");fd1=creat(main ,0777); fd2 = open("../sources/main.cpp",O_RDONLY);}
       else if (strcmp(param, "-C++") == 0) {strcat(main, "/main.cpp");fd1=creat(main ,0777); fd2 = open("../sources/main.cpp",O_RDONLY);}
        else if (strcmp(param, "-BEAMER") == 0) {strcat(main, "/main.tex");fd1=creat(main ,0777); fd2 = open("../sources/beamer.tex",O_RDONLY);}
	
	
   }else{
			strcat(main, "/main");
			fd=creat(main ,0777);
      if (strcmp(param, "-GPL") == 0) {strcat(main, "/LICENCE");fd=creat(main ,0777); }
       else if (strcmp(param, "-MIT") == 0) {strcat(main, "/LICENCE");fd=creat(main ,0777);}
			
		}	
}
 
int main(int argc, char *argv[])
{
char cwd[1024];

  if (argc < 2)        /*s'il y a pas d'argument*/
	{
   	printf("argument attendu, veuillez vérifier l'aide: initdev -help \n");
  }
	else{           /* s'il y a d'argument*/
   if (argc == 2)
		{
     if (strcmp(argv[1], "-help") == 0)   /* si l'utilisateur fait entrer des valeurs fausses */
     {
      	printf("Initdev: un outil de développement qui gagne du temps en configurant le repertoire dev\n");
        printf("use: initdev <dev_source_name> [args]\n");
        printf("args:\t\t  -C: projet C\n");
        printf("\t\t  -CPP or -C++: projet C++\n");
        printf("\t\t  -Py: projet Python\n");
        printf("\t\t  -Latex: projet Latex\n");
        printf("\t\t  -BEAMER: projet BEAMER\n");
     }else
			{
			  creationRepBase(argv[1]);
				creationFichBase(argv[1]);
			}
		 }	
			 if(argc >= 3){
				if(argc == 3 )
				{
        	if(strcmp(argv[2],"-Py") &&
						strcmp(argv[2],"-C") && 
            strcmp(argv[2],"-CPP") &&
            strcmp(argv[2],"-C++") &&
            strcmp(argv[2],"-Latex") &&
            strcmp(argv[2],"-BEAMER") &&
            strcmp(argv[2],"-GPL") &&
            strcmp(argv[2],"-MIT"))
      
        	 printf("argument inconnu, veuillez vérifier l'aide: initdev -help \n");      
       	  else
					{
						creationRepBase(argv[1]);
						creationFich(argv[1],argv[2]);

					}
				}
       }
   }	
   
    return 0;
}
