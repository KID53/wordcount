#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int char_NUM(char *file) {//ͳ���ַ���
    FILE *fp=NULL;
    int char_num=0;
	char file_char='\0';
    if (NULL==(fp=fopen(file, "r"))) {//���ļ�
        printf("Ѱ���ļ�ʧ�ܣ�\n");
        exit(0);
    }
    while ((file_char=fgetc(fp))!=EOF) {//�����ȡ�ļ��ַ�
        char_num++;//�����ַ���
    }
    fclose(fp);
    return char_num;
}
int word_NUM(char *file) {//ͳ�Ƶ�����
    FILE *fp=NULL;
    int word_num=0;
	char file_word='\0';
	int i=0;//�жϵ������Ƿ��1��־
    if (NULL==(fp=fopen(file, "r"))) {
        printf("�ļ�Ѱ��ʧ�ܣ�\n");
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
int line_NUM(char *file) {//ͳ������
    FILE *fp=NULL;
    int line_num=0;
	char file_line='\0';
    if (NULL==(fp=fopen(file, "r"))) {
        printf("�ļ�Ѱ��ʧ�ܣ�\n");
        exit(0);
    }
    while ((file_line=fgetc(fp))!=EOF) {
        if (file_line=='\n') {//���м�������
            line_num++;
        }
	}
        fclose(fp);
        return line_num;
}
int main() {
    char file[150], in='\0';
	int a=1;
	printf("����c -> wc.exe -c file.c    //�����ļ� file.c ���ַ���\n");
	printf("����w -> wc.exe -w file.c    //�����ļ� file.c �Ĵʵ���Ŀ\n");
	printf("����l -> wc.exe -l file.c    //�����ļ� file.c ������\n");
	printf("����E���˳�����\n");
	while(a){
		printf("�������û�����:wc.exe -");
		scanf(" %c",&in);
    switch(in)
    {
    case 'c':{
        printf("\n�������ļ�����");
        scanf("%s", &file);
        printf("�ļ��ַ���Ϊ��%d \n\n",char_NUM(file));
		break;}
    case 'w':{
        printf("\n�������ļ�����");
        scanf("%s", &file);
        printf("�ļ�������Ϊ��%d \n\n",word_NUM(file));
		break;}
    case 'l':{
        printf("\n�������ļ�����");
        scanf("%s", &file);
        printf("�ļ�����Ϊ��%d \n\n",line_NUM(file));
		break;}
	case 'E':{
		printf("��лʹ�ô˳���!\n");
		a=0;
		break;}
    default:
        printf("�������������������\n");
    }
 }
    return 0;
}