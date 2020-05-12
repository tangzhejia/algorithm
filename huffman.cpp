#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//haffman ���Ľṹ
typedef struct
{
    //Ҷ�ӽ��Ȩֵ
    unsigned int weight;
    //ָ��˫�ף��ͺ��ӽ���ָ��
    unsigned int parent;
    unsigned int lChild;
    unsigned int rChild;
} Node, *HuffmanTree;

//��̬�������飬�洢����������
typedef char *HuffmanCode;

//ѡ������parentΪ0����weight��С�Ľ��s1��s2�ķ���ʵ��
//n ΪҶ�ӽ���������s1�� s2����ָ�����ָ��Ҫѡȡ����������Ȩֵ��С�Ľ��
void select(HuffmanTree *huffmanTree, int n, int *s1, int *s2)
{
    //��� i
    int i = 0;
    //��¼��СȨֵ
    int min;
    //����ȫ����㣬�ҳ����ڵ�
    for(i = 1; i <= n; i++)
    {
        //����˽��ĸ���û�У���ô�ѽ��Ÿ�ֵ�� min������ѭ��
        if((*huffmanTree)[i].parent == 0)
        {
            min = i;
            break;
        }
    }
    //��������ȫ����㣬�ҳ�Ȩֵ��С�ĵ��ڵ�
    for(i = 1; i <= n; i++)
    {
        //����˽��ĸ���Ϊ�գ������ if
        if((*huffmanTree)[i].parent == 0)
        {
            //����˽���Ȩֵ�� min ����ȨֵС����ô���� min ��㣬��������ʼ�� min
            if((*huffmanTree)[i].weight < (*huffmanTree)[min].weight)
            {
               min = i;
            }
        }
    }
    //�ҵ�����СȨֵ�Ľ�㣬s1ָ��
    *s1 = min;
    //����ȫ�����
    for(i = 1; i <= n; i++)
    {
        //�ҳ���һ�����ڵ㣬��û�б� s1ָ����ôi ��ֵ�� min������ѭ��
        if((*huffmanTree)[i].parent == 0 && i != (*s1))
        {
            min = i;
            break;
        }
    }
    //��������ȫ����㣬�ҵ�Ȩֵ��С����һ��
    for(i = 1; i <= n; i++)
    {
        if((*huffmanTree)[i].parent == 0 && i != (*s1))
        {
            //����˽���Ȩֵ�� min ����ȨֵС����ô���� min ��㣬��������ʼ�� min
            if((*huffmanTree)[i].weight < (*huffmanTree)[min].weight)
            {
               min = i;
            }
        }
    }
    //s2ָ��ָ��ڶ���Ȩֵ��С��Ҷ�ӽ��
    *s2 = min;
}

//���������������������������㷨���£�w��������֪��n��Ȩֵ
void createHuffmanTree(HuffmanTree *huffmanTree, int w[], int n)
{
    //m Ϊ���������ܹ��Ľ������n ΪҶ�ӽ����
    int m = 2 * n - 1;
    //s1 �� s2 Ϊ������ǰ����Ҫѡȡ����СȨֵ�Ľ��
    int s1;
    int s2;
    //���
    int i;
    // �������������Ľ������Ŀռ䣬m+1���������а���һ��ͷ���
    *huffmanTree = (HuffmanTree)malloc((m + 1) * sizeof(Node));
    //1--n�Ŵ��Ҷ�ӽ�㣬��ʼ��Ҷ�ӽ�㣬�ṹ��������ʼ��ÿ��Ҷ�ӽ�㣬��ʼ��ʱ����һ�����������Ķ�����
    for(i = 1; i <= n; i++)
    {
       
        //����Ҷ�ӽ���Ȩֵ�� w��n������������
        (*huffmanTree)[i].weight = w[i];
        //��ʼ��Ҷ�ӽ�㣨���������������ĺ��Ӻ�˫�ף�������㣬Ҳ����û�к��Ӻ�˫�ף�==0
        (*huffmanTree)[i].lChild = 0;
        (*huffmanTree)[i].parent = 0;
        (*huffmanTree)[i].rChild = 0;
    }// end of for
    //��Ҷ�ӽ��ĳ�ʼ��
    for(i = n + 1; i <= m; i++)
    {
        (*huffmanTree)[i].weight = 0;
        (*huffmanTree)[i].lChild = 0;
        (*huffmanTree)[i].parent = 0;
        (*huffmanTree)[i].rChild = 0;
    }
    
    printf("\n HuffmanTree: \n");
    //������Ҷ�ӽ�㣬����������
    for(i = n + 1; i <= m; i++)
    {
        //��(*huffmanTree)[1]~(*huffmanTree)[i-1]�ķ�Χ��ѡ������parentΪ0
        //��weight��С�Ľ�㣬����ŷֱ�ֵ��s1��s2
        select(huffmanTree, i-1, &s1, &s2);
        //ѡ��������Ȩֵ��С��Ҷ�ӽ�㣬���һ���µĶ���������Ϊ i ���
        (*huffmanTree)[s1].parent = i;
        (*huffmanTree)[s2].parent = i;
        (*huffmanTree)[i].lChild = s1;
        (*huffmanTree)[i].rChild = s2;
        //�µĽ�� i ��Ȩֵ
        (*huffmanTree)[i].weight = (*huffmanTree)[s1].weight + (*huffmanTree)[s2].weight;
        
        printf("%d (%d, %d)\n", (*huffmanTree)[i].weight, (*huffmanTree)[s1].weight, (*huffmanTree)[s2].weight);
    }
    
    printf("\n");
}

//��������������ϣ��� n ��Ҷ�ӽ�㵽����������ÿ��Ҷ�ӽ���Ӧ�Ĺ���������
void creatHuffmanCode(HuffmanTree *huffmanTree, HuffmanCode *huffmanCode, int n)
{
    //ָʾbiaoji
    int i;
    //�������ʼָ��
    int start;
    //ָ��ǰ���ĸ��ڵ�
    int p;
    //���� n ��Ҷ�ӽ���ָʾ��� c
    unsigned int c;
    //����n�������ͷָ��
    huffmanCode=(HuffmanCode *)malloc((n+1) * sizeof(char *));
    //������ǰ����Ĺ����ռ�
    char *cd = (char *)malloc(n * sizeof(char));
    //����������λ��ű��룬���ȴ�ű��������
    cd[n-1] = '\0';
    //��n��Ҷ�ӽ���Ӧ�Ĺ���������
    for(i = 1; i <= n; i++)
    {
        //��ʼ��������ʼָ��
        start = n - 1;
        //��Ҷ�ӵ�����������
        for(c = i, p = (*huffmanTree)[i].parent; p != 0; c = p, p = (*huffmanTree)[p].parent)
        {
            if( (*huffmanTree)[p].lChild == c)
            {
                //���ҵ����˳�������������
                 cd[--start] = '0';  //���֧��0
            }
            else
            {
                cd[--start] = '1';  //�ҷ�֧��1
            }
        }// end of for
        //Ϊ��i���������ռ�
        huffmanCode[i] = (char *)malloc((n - start) * sizeof(char));
        
        strcpy(huffmanCode[i], &cd[start]);
    }
    
    free(cd);
    //��ӡ��������
    for(i = 1; i <= n; i++)
    {
         printf("HuffmanCode of %3d is %s\n", (*huffmanTree)[i].weight, huffmanCode[i]);
    }
    
    printf("\n");
}

int main(void)
{
    HuffmanTree HT;
    HuffmanCode HC;
    int *w,i,n,wei,m;
    
    printf("\nn = " );
    
    scanf("%d",&n);
    
    w=(int *)malloc((n+1)*sizeof(int));
    
    printf("\ninput the %d element's weight:\n",n);
    
    for(i=1; i<=n; i++)
    {
        printf("%d: ",i);
        fflush(stdin);
        scanf("%d",&wei);
        w[i]=wei;
    }
    
    createHuffmanTree(&HT, w, n);
    creatHuffmanCode(&HT,&HC,n);
    
    return 0;
}
