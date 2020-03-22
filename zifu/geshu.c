#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int char_NUM(char *file) {//统计字符数
    FILE *fp=NULL;
    int char_num=0;
	char file_char='\0';
    if (NULL==(fp=fopen(file, "r"))) {//打开文件
        printf("寻找文件失败！\n");
        exit(0);
    }
    while ((file_char=fgetc(fp))!=EOF) {//逐个读取文件字符
        char_num++;//计算字符数
    }
    fclose(fp);
    return char_num;
}
int word_NUM(char *file) {//统计单词数
    FILE *fp=NULL;
    int word_num=0;
	char file_word='\0';
	int i=0;//判断单词数是否加1标志
    if (NULL==(fp=fopen(file, "r"))) {
        printf("文件寻找失败！\n");
        exit(0);
    }
    while ((file_word=fgetc(fp))!=EOF) {
        if (file_word<'A'||(file_word>'Z'&&file_word<'a')||file_word>'z'){
            i=0;
        }
        else if(i==0){
           i=1;
           word_num++;
        }
    }
    return word_num;
}
int line_NUM(char *file) {//统计行数
    FILE *fp=NULL;
    int line_num=0;
	char file_line='\0';
    if (NULL==(fp=fopen(file, "r"))) {
        printf("文件寻找失败！\n");
        exit(0);
    }
    while ((file_line=fgetc(fp))!=EOF) {
        if (file_line=='\n') {//换行计算行数
            line_num++;
        }
	}
        fclose(fp);
        return line_num;
}
int main() {
    char file[150], in='\0';
	int a=1;
	printf("输入c -> wc.exe -c file.c    //返回文件 file.c 的字符数\n");
	printf("输入w -> wc.exe -w file.c    //返回文件 file.c 的词的数目\n");
	printf("输入l -> wc.exe -l file.c    //返回文件 file.c 的行数\n");
	printf("输入E则退出程序\n");
	while(a){
		printf("请输入用户命令:wc.exe -");
		scanf(" %c",&in);
    switch(in)
    {
    case 'c':{
        printf("\n请输入文件名：");
        scanf("%s", &file);
        printf("文件字符数为：%d \n\n",char_NUM(file));
		break;}
    case 'w':{
        printf("\n请输入文件名：");
        scanf("%s", &file);
        printf("文件单词数为：%d \n\n",word_NUM(file));
		break;}
    case 'l':{
        printf("\n请输入文件名：");
        scanf("%s", &file);
        printf("文件行数为：%d \n\n",line_NUM(file));
		break;}
	case 'E':{
		printf("感谢使用此程序!\n");
		a=0;
		break;}
    default:
        printf("错误操作！请重新输入\n");
    }
 }
    return 0;
}