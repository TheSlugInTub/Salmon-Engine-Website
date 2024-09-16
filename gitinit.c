#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void PrintUsage()
{
    printf("The Gitinator 3000\n");
    printf("USAGE:\n");
    printf("new - Makes new git repository\n");
    printf("commit - Adds all files in the directory, commits and pushes them\n");
    printf("remove - Removes git from project (deletes .git folder)\n");
}

int main(int argc, char const* argv[])
{
    if (argc < 2)
    {
        PrintUsage();
        exit(0);
    }

    if (strcmp(argv[1], "new") == 0)
    {
        char remoteName[100]; 
        char newCommand[200]; 

        printf("Enter remote name (link to .git file on github repository): ");
        scanf("%99s", remoteName);

        strcpy(newCommand, "git remote add origin ");
        strcat(newCommand, remoteName);

        system("git init");
        system(newCommand);
        printf("Succesfully created git repository!\n");
    }
    else if (strcmp(argv[1], "commit") == 0)
    {
        char commitMsg[100]; 
        char newCommand[200]; 

        printf("Enter commit message (please put quotation marks): ");
        scanf("%99s", commitMsg);

        strcpy(newCommand, "git commit -m ");
        strcat(newCommand, commitMsg);

        system("git add .");
        system(newCommand);
        system("git push origin main");
        printf("Succesfully committed and pushed new files!\n");
    }
    else if (strcmp(argv[1], "remove") == 0)
    {
        #ifdef _WIN32
            // Windows command to remove the .git folder
            int result = system("rmdir /S /Q .git");
        #else
            // Linux/Unix command to remove the .git folder
            int result = system("rm -rf .git");
        #endif

        if (result == 0) {
            printf(".git folder removed successfully.\n");
        } else {
            printf("Failed to remove .git folder.\n");
        }
    }
    else
    {
        printf("Command not found\n");
    }

    return 0;
}
