#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define MAXREGION 30
#define REGIONMAXCARACTER 15
#define MAXCONTACT MAXREGION - 1

typedef struct s_Region{
    char* name;
    struct s_Region** regionTouch;
    int GDP;
    char** temp;

} t_Region;




char ***ItsToYouToPlay(t_Region **result, int numberRegion){
    
    //You begin here//
    //result is an array of t_region with the name, the region touching, and the GDP (which is translated into french by 'PIB'), numberRegion is the number of regions we want
    
    


    
    





    //Joyeux Noel !!!!!////////
    return NULL;
}








char** MySplitIsBiggerThanYours(char *str, char delim){
  
	if (str == NULL)
		return (NULL);

	int sizeMalloc = 0;
	int count = 0;
	int _bool = 0;
	while (str[sizeMalloc])
	{
		if (str[sizeMalloc] != delim && !_bool)
		{
			count++;
			_bool = 1;
		}
		else if (str[sizeMalloc] == delim && _bool)
			_bool = 0;
		sizeMalloc++;
	}

	char	**bigarray = (char **)malloc(sizeof(char *) * (count + 1));
	if (!bigarray)
		return (NULL);

    int	countStr = 0;
    int i = 0;

	while (str[i]){
		if (str[i] == delim)
			i++;
		else{
    	    int		j = 0;
            while (str[i + j] && str[i + j] != delim){
                j++;
            }
            bigarray[countStr] = (char *)malloc(sizeof(char) * (j + 1));
            if (!bigarray[countStr]){
				while (countStr > 0){
		            free(bigarray[countStr - 1]);
		            countStr--;
	            }
				return (NULL);
			}
            j = 0;
            while (str[i + j] && str[i + j] != delim){
                bigarray[countStr][j] = str[i + j];
                j++;
            }
            bigarray[countStr][j] = '\0';
            i = i + j;
			
			countStr++;
		}
	}
	bigarray[count] = 0;
	return (bigarray);
}

int Error(FILE * errorFile){
    return fprintf(errorFile, "Error\n");
}

t_Region** FreeRegion(t_Region** myRegion, int i){
    if (i >= 0){

        if (myRegion[i]->temp){
            for (int j = 0; myRegion[i]->temp[j]; j++)
                free(myRegion[i]->temp[j]);
            free(myRegion[i]->temp);
        }
        if (myRegion[i]-> name)
            free(myRegion[i]->name);
        free(myRegion[i]);
        myRegion[i] = NULL;
    }
    for (int i = 0; myRegion[i]; i++){
        if (myRegion[i]->temp){
            for (int j = 0; myRegion[i]->temp[j]; j++)
                free(myRegion[i]->temp[j]);
            free(myRegion[i]->temp);
        }
        free(myRegion[i]->name);
        if (myRegion[i]->regionTouch)
            free(myRegion[i]->regionTouch);
        free(myRegion[i]);
    }
    free(myRegion);
    return NULL;
}



t_Region** ReadTheFile(FILE* fd){
    char bufferName[REGIONMAXCARACTER];
    char bufferList[REGIONMAXCARACTER * MAXCONTACT + MAXCONTACT - 1];
    int bufferGDP[1];
    t_Region **myRegion;
    myRegion = malloc(sizeof (t_Region*) * MAXREGION);
    if (!myRegion)
        return myRegion;
    int i = 0;
    int result = 3;
    while (result == 3 && i < MAXREGION){
        result = fscanf(fd, "%s : %d : %s\n", bufferName, bufferGDP, bufferList);
        if (result == 3){
            //printf("Read Name |%s| GDP = |%d| ListofName = |%s| Result = |%d| \n", bufferName, *bufferGDP, bufferList,result); 
            myRegion[i] = malloc(sizeof(t_Region));
            if (myRegion[i] == NULL)
                return FreeRegion(myRegion, -1);
            myRegion[i]->temp = MySplitIsBiggerThanYours(bufferList, '-');
            myRegion[i]->GDP = *bufferGDP;
            myRegion[i]->name = strdup(bufferName);
            if (!myRegion[i]->temp || !myRegion[i]-> name)
                return FreeRegion(myRegion, i);
        }
        i++;
    }
    myRegion[--i] = NULL;
    if (result != -1){
        printf("Error in parsing\n");
        return FreeRegion(myRegion, -1);
    }
    return myRegion;
}

int PointerStrlen(char **str){
    int i = 0;
    while (str[i]){
        i++;
    }
    return i;
}

t_Region* SearchByName(t_Region** myRegion, char * _name){
    for (int i = 0; myRegion[i]; i++){
        if (strcmp(myRegion[i]->name, _name) == 0)
            return (myRegion[i]);
    }
    dprintf(1, "Error, Region %s not find\n", _name);
    return NULL;
}

t_Region** PutThePointer(t_Region** myRegion){
    for (int i = 0; myRegion[i] != NULL; i++){
        int size = PointerStrlen(myRegion[i]->temp);
        myRegion[i]->regionTouch = malloc(sizeof (t_Region) * size);
        if (myRegion[i]->regionTouch == NULL)
            return FreeRegion(myRegion, -1);
        myRegion[i]->regionTouch[--size] = NULL;
        for (; size >= 0; size--){
            myRegion[i]->regionTouch[size] = SearchByName(myRegion, myRegion[i]->temp[size]);
            if (myRegion[i]->regionTouch[size] == NULL){
                return FreeRegion(myRegion, -1);
            }
        }
    }
    return myRegion;
}

void Freepointerpointerstr(char ***str){
    for (int i = 0; str[i]; i++){
        free(str[i]);
    }
    free(str);
}

void PrintRet(char ***ret, FILE * fdRet){
    for (int i = 0; ret[i]; i++){
		for(int j = 0; ret[i][j]; j++){
			fprintf(fdRet, "%s", ret[i][j]);
			if (ret[i][j + 1])
				fprintf(fdRet, "-");
		}
		fprintf(fdRet, "\n");
	}
}


int main(int argc, char **argv){
    if (argc != 4)
        return printf("Error : not the good number of argument\n");
    
    FILE * fdRet = fopen(argv[2], "w");
    if (fdRet == NULL)
        return printf("Error : could not create or open the first file\n");
    
    FILE* fd = fopen(argv[1], "r");
    if (fd == NULL)
        return Error(fdRet) + printf("Error : could not find or open the first file\n");

	int numberRegion = atoi(argv[3]);
	if (numberRegion < 1 || numberRegion > MAXREGION)
		return Error(fdRet) + printf("Error : invalid number of region\n");

    t_Region** result = ReadTheFile(fd);
    if (result == NULL)
        return Error(fdRet);
    result = PutThePointer(result);
    if (result == NULL)
        return Error(fdRet);
    
    char ***ret = ItsToYouToPlay(result, numberRegion);

    if (ret == NULL)
		return Error(fdRet);
	PrintRet(ret,  fdRet);
	FreeRegion(result, -1);
    Freepointerpointerstr(ret);
    return 0;
}