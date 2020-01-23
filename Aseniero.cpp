#include <iostream>
#include <string.h>
#include <dirent.h>

using namespace std;

int main(){
	
	struct dirent *dc;
	string file[100] = "";
	int count = 0;
	
	DIR *de = opendir(".");

    while ((dc = readdir(de)) != NULL){
    	file[count] += dc->d_name; 
    	count++;
	}
    closedir(de); 
	
	char ch, file1[50], file2[50];
	FILE *fp;
	
	for (int i = 2; i < 38; i++){
		if (i == 16){
			continue;
		}
		for (int j = 2; j < 38; j++){
			if (j == 16){
				continue;
			}
			string content1[1000] = "", content2[1000] = "";
			
			strcpy(file1, file[i].c_str());
			
			fp = fopen(file1, "r");
			
			int c = 0;
			while ((ch = fgetc(fp)) != EOF){
				if (ch == '\n' || ch == '  '){
					c++;
					continue;
				}
				else{
					content1[c] += ch;
				}
			}
			
			fclose(fp);
			
			strcpy(file2, file[j].c_str());
			fp = fopen(file2,"r");
			c = 0;
			while ((ch = fgetc(fp)) != EOF){
				if (ch == '\n' || ch == '  '){
					c++;
					continue;
				}
				else{
					content2[c] += ch;
				}
			}
	
			fclose(fp);
			
			double equalcounter = 0;
			double notequalcounter = 0;
	
			for (int i = 0; i < 1000; i++){
				int g = equalcounter;
				if (content1[i] == ""){
					continue;
				}
				for (int j = 0; j < 100; j++){
					if (content1[i] == content2[j]){
						equalcounter++;
						break;
					}
				}
				if (g == equalcounter){
					notequalcounter++;
				}
			}
	
			double total = equalcounter + notequalcounter;
	
			double comparison = equalcounter / total * 100;
			
			printf("%4.0f ",comparison);
		}
		cout << endl;
	}
}
