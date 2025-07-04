
#include "engine.h"

char** list_asset_files(const char* folder){

    DIR *dir = opendir(folder); 

    if(!dir){
        printf("Unable to oepn assets directory!\n"); 
        exit(EXIT_FAILURE);
         
    }

    printf("Avaliable object files: \n"); 

    struct dirent *entry;
    char** filename = NULL;
    int count = 0;
    
    while((entry = readdir(dir)) != NULL){
        if(strstr(entry->d_name, ".obj")){
            printf("- %s\n", entry->d_name);
            filename = realloc(filename, (count + 1) * sizeof(char*));
            filename[count] = strdup(entry->d_name); // allocate and copy
            count++;
        }
    }

    char **tmp = realloc(filename, (count + 1) * sizeof *tmp);
    if (!tmp && count > 0) {
        perror("realloc");
        exit(EXIT_FAILURE);
    }
    
    filename = tmp;
    closedir(dir); 

    return filename;
}





const char *select_file(const char** filename){

    int count = 0; 
    while(filename[count] != NULL){
        count++;
    }

    for(int i = 0; i < count; i++){
        printf("filename[%i]: %s\n", i , filename[i]);
    }

    char input[255];
    while(1){
        printf("please enter which file you'd like to render: ");
        scanf("%255s", input);

        for(int i = 0; i < count; i++){
            if(strcmp(input, filename[i]) == 0){
                //printf("HERE IS THE SELECTED INTPUT: %s\n", filename[i]);
                return filename[i];
            }
        }
        printf("No match was found, please try again!\n\n");

    }

    return 0;
}