//
//  main.c
//  MD5
//
//  Created by 小浩克 on 2018/5/23.
//  Copyright © 2018年 小浩克. All rights reserved.
//

#include <stdio.h>
#define F( X, Y, Z ) ( ( (X) & (Y) ) | ( (~(X)) & (Z) ) )
#define G( X, Y, Z ) ( ( (X) & (Z) ) | ( (Y) & (~(Z)) ) )
#define H( X, Y, Z ) ( (X) ^ (Y) ^ (Z) )
#define I( X, Y, Z ) ( (Y) ^ ( (X) | (~(Z)) ) )

#define ROTATE_LEFT(x,n)  ( (x<<n)|(x>>(32-n)))
#define FF(a ,b ,c ,d ,Mj ,s ,ti )  a = b + ROTATE_LEFT((a + F(b,c,d) + Mj + ti),s)
#define GG(a ,b ,c ,d ,Mj ,s ,ti )  a = b + ROTATE_LEFT( (a + G(b,c,d) + Mj + ti),s)
#define HH(a ,b ,c ,d ,Mj ,s ,ti)   a = b + ROTATE_LEFT( (a + H(b,c,d) + Mj + ti),s)
#define II(a ,b ,c ,d ,Mj ,s ,ti)   a = b + ROTATE_LEFT( (a + I(b,c,d) + Mj + ti),s)


  void MD5intchar(unsigned char*output,unsigned int *input,unsigned int len)
{
    unsigned int i,j;i=0;j=0;
    
    while(j<len)
    {
        output[j]=(input[i])&0xff;
        output[j+1]=(input[i]>>8)&0xff;
        output[j+2]=(input[i]>>16)&0xff;
        output[j+3]=(input[i]>>24)&0xff;
        j+=4;
        i++;
    }
}
void MD5intchar2(unsigned int*output,unsigned int *input,unsigned int len)
{
    unsigned int i,j;i=0;j=0;
    int z=0;
    
    while(i<len)
    {
        output[z]=(
                   input[i]<<0)+
        (input[i+1]<<8)+
        (input[i+2]<<16)+
        (input[i+3]<<24);
        i+=4;
        z++;
    }
}
void MD5charint(unsigned int* output,unsigned char *input,unsigned int len)
{
    unsigned int i,j;
    i=0;j=0;
    int z=0;
    
    while(i<len+8)
    {
        
        output[z]=
        (input[i+0]<<(7))|
        (input[i+1]<<(6))|
        (input[i+2]<<(5))|
        (input[i+3]<<(4))|
        (input[i+4]<<(3))|
        (input[i+5]<<(2))|
        (input[i+6]<<(1))|
        (input[i+7]<<(0));
            i+=8;
            z++;
    }
}




int main() {
    char a[640]={0};
    unsigned char bit[640]={0};
    int ii=0;
    int num=0;
    int c[64]={0};
    int p=0;
    int i=0;
    int z=0;
    int z1=0;
    int z2=0;
    unsigned int A=0x67452301;
    unsigned int B=0x0efcdab89;
    unsigned int C=0x98BADCFE;
    unsigned int D=0x10325476;
    int AA;
    int BB;
    int CC;
    int DD;
    static int Sfirst[16]={0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,0xf57c0faf,0x4787c62a,0xa8304613,0xfd469501,0x698098d8,0x8b44f7af,0xffff5bb1,0x895cd7be,0x6b901122,0xfd987193,0xa679438e,0x49b40821};
    static int Ssecond[16]={0xf61e2562,0xc040b340,0x265e5a51,0xe9b6c7aa,0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,0x21e1cde6,0xc33707d6,0xf4d50d87,0x455a14ed,0xa9e3e905,0xfcefa3f8,0x676f02d9,0x8d2a4c8a};
    static int Sthird[16]={0xfffa3942,0x8771f681,0x6d9d6122,0xfde5380c,0xa4beea44,0x4bdecfa9,0xf6bb4b60,0xbebfbc70,0x289b7ec6,0xeaa127fa,0xd4ef3085,0x04881d05,0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665};
    static int Sforth[16]={0xf4292244,0x432aff97,0xab9423a7,0xfc93a039,0x655b59c3,0x8f0ccc92,0xffeff47d,0x85845dd1,0x6fa87e4f,0xfe2ce6e0,0xa3014314,0x4e0811a1,0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391};
    //int M[16][32]={0};
    unsigned int M1[16];
    unsigned int M2[16];
    unsigned int o[16]={2150838833,00000000,00000000,00000000,0000000,0000000,0000000,0000000,0000000,0000000,00000000,00000000,00000000,
        00000000,24,00000000};
    unsigned int sFF[16]={7,12,17,22,7,12,17,22,7,12,17,22,7,12,17,22};
    unsigned int sGG[16]={5,9,14,20,5,9,14,20,5,9,14,20,5,9,14,20};
    unsigned int sHH[16]={4,11,16,23,4,11,16,23,4,11,16,23,4,11,16,23};
    unsigned int sII[16]={6,10,15,21,6,10,15,21,6,10,15,21,6,10,15,21};
    
    
    static int Mfirst[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    static int Msecond[16]={1,6,11,0,5,10,15,4,9,14,3,8,13,2,7,12};
    static int Mthrid[16]={5,8,11,14,1,4,7,10,13,0,3,6,9,12,15,2};
    static int Mfourth[16]={0,7,14,5,12,3,10,1,8,15,6,13,4,11,2,9};
    unsigned int final[4]={0};
    unsigned char S[16]={0};
    unsigned int d=0;
    AA=A;
    BB=B;
    CC=C;
    DD=D;
     printf("请输入密文");
    
        
    gets(a);

    
    for(int i=0;i<640;i++)
    {
        bit[i]=(a[i/8]>>(7-i%8))&0x01;
        //明文转化为二进制
    }
    while(a[ii]!='\0')        // 计算密钥长度
    {
        ii++;
    }
    
    for(int i=0;i<3;i++)
    {
        printf("%d",a[i]);
    }

    for(int i=ii-1;i<=ii;i++)
    {
        
    }
    printf("\n");
    printf("明文的长度%d\n",ii);
    printf("明文转化为的二进制");
    printf("\n");
    for(int i=0;i<8*ii;i++)
    {
       
      printf("%0x",bit[i]);

    }
    printf("\n");
    p=8*ii;
    
    while (p>0)
    {
        c[i]=(p)%2;
        i=i+1;
        (p)=(p)/2;
        d=i-1;
    }
    z=i;
    z1=i;
    z2=i;
    printf("i的值是%d\n",i);
    printf("十进制整数转换为二进制数是:\n");
    printf("%d\n",d);
    
    for(;(i-1)>=0;i--)
      printf("%d",c[i-1]);
    printf("\n");
    
    
    
    
    printf("64位填充\n");
    printf("\n");
    num=8*ii/512;
    printf("%d\n",num);
    
    if((8*ii)%512!=418)
    {
        
        for(int i=8*ii;i<8*ii+1;i++)
        {
            bit[i]=1;
        
        }

        if((8*ii+2)<((num)*512+448))
       {
        for(int i=8*ii+2;i<(num)*512+448;i++)
            {
            bit[i]=0;
            }
        }
    }
    
    printf("填充后的二进制");
    for(int i=0;i<(num)*512+448;i++)
    {
        printf("%d",bit[i]);
    }
    printf("\n");
    
    printf("二进制总的位数%d",(num)*512+448);
    printf("\n");
    
    //printf("你今年可能看见你看见%d",z1%8);
    printf("%d",z1%8);
    
    for(int j=(num+1)*512+448;j<(num)*512+448+8-(z1%8);j++)
    {
        bit[j]=0;
    }
    
    //printf("%d",z);
    printf("\n");
    printf("%d\n",(num)*512+448+8-(z1%8));
    printf("%d\n",(num)*512+456-(z1%8));
    
    for(int f=5;f>0;f--)
    printf("%d",c[f-1]);
    
     for(int j=(num)*512+456-(z1%8);j<(num)*512+456-z1%8+z1;j++,z--)
    {
        if(z!=0)
        {
            bit[j]=c[z-1];
        }
    }
    
    printf("\n");
    
    
    printf("dfsfsd");
    for(int j=(num)*512+456-z1%8;j<(num)*512+456-z1%8+z1;j++)
    {
    printf("%d",bit[j]);
    }
    
   
    for(int j=(num)*512+496-z1%8+z1;j<(num+1)*512;j++)
    {
        bit[j]=0;
    }
    printf("\n");
    
    printf("添加64位之后的数值\n");
    
    for(int j=0;j<(num+1)*512;j++)
    {
        
        printf("%d",bit[j]);
    }
    printf("\n");
    printf("%d\n",(num+1)*512);
    
    
    MD5charint(M1,bit,1000);
    MD5intchar2(M2, M1, 64);
    
    
    for(int i=0;i<16;i++)
    {
        printf("%08x ",o[i]);
        
    }
    printf("\n");
    for(int i=0;i<16;i++)
    {
       // printf("%08x ",M1[i]);
    }
    
    for(int i=0;i<16;i++)
    {
        printf("%08x ",M2[i]);
    }

    

    for(int q=0;q<(num+1);q++)
   {
        for(int i=0;i<16;i++)
      {
          for(int z=0;z<32;z++)
          {
              
              //M[i][z]=bit[i*32+z];

        }
  }
       
       
       printf("\n");
       
           for(int i=0;i<16;i++)
           {
               for(int z=0;z<32;z++)
               {
                   
                 //  M1[i]=M[i][z];
                   //gets(M1);
                   //printf("%d",M1[i]);
                   
               }
               //printf(" ");
           }
     
       
       
       
       printf("\n");
       printf("\n");
       //printf("%08x",A);
       //printf("%08x",B);
      // printf("%08x",C);
       //printf("%08x",D);
       
       
       
       
       
        for(int q=0;q<16;q++)
           {
               printf("%08x %08x %08x %08x %08x,%d,%08x",A,B,C,D,o[Mfirst[q]],sFF[q],Sfirst[q]);
               printf("\n");
            FF(A,B,C,D,M2[Mfirst[q]],sFF[q],Sfirst[q]);
            int temp1,temp2;
            temp1=B;
            B=A;
            temp2=C;
            C=temp1;
            A=D;
            D=temp2;
               
             
           }
      
       printf("%08x ",A);
       printf("%08x ",B);
       printf("%08x ",C);
       printf("%08x ",D);
       printf("\n");
       printf("\n");
       printf("第一轮循环");
       
       
       printf("\n");
       
       for(int q=0;q<16;q++)
       {
           
           printf("%08x %08x %08x %08x %08x,%d,%08x",A,B,C,D,o[Msecond[q]],sGG[q],Ssecond[q]);
           printf("\n");
             //  printf("%d ",M1[Mfirst[q]]);
               GG(A,B,C,D,M2[Msecond[q]],sGG[q], Ssecond[q]);
               int temp1,temp2;
               temp1=B;
               B=A;
               temp2=C;
               C=temp1;
               A=D;
               D=temp2;
           
       }
      
       printf("%08x ",A);
       printf("%08x ",B);
       printf("%08x ",C);
       printf("%08x ",D);
       printf("\n");
  
       printf("第二轮循环");
        printf("\n");
       
       
       
       for(int q=0;q<16;q++)
       {
           
               printf("%08x %08x %08x %08x %08x,%d,%08x",A,B,C,D,
                      o[Mthrid[q]],sHH[q],Sthird[q]);
               printf("\n");
               HH(A,B,C,D,M2[Mthrid[q]],sHH[q], Sthird[q]);
               int temp1,temp2;
               temp1=B;
               B=A;
               temp2=C;
               C=temp1;
               A=D;
               D=temp2;
           
       }
       
       printf("%08x ",A);
       printf("%08x ",B);
       printf("%08x ",C);
       printf("%08x ",D);
       printf("\n");
         printf("第三轮循环");
       printf("\n");
       
    
       for(int q=0;q<16;q++)
       {
           printf("%08x %08x %08x %08x %08x,%d,%08x",A,B,C,D,o[Mfourth[q]],sII[q],Sforth[q]);
           printf("\n");
           II(A,B,C,D,M2[Mfourth[q]],sII[q], Sforth[q]);
               int temp1,temp2;
               temp1=B;
               B=A;
               temp2=C;
               C=temp1;
               A=D;
               D=temp2;
       }
      
     
       printf("%08x ",A);
       printf("%08x ",B);
       printf("%08x ",C);
       printf("%08x ",D);
       printf("\n");
  
        printf("\n");
         printf("第四轮循环");
       printf("%08x ",A);
       printf("%08x ",B);
       printf("%08x ",C);
       printf("%08x ",D);
       printf("\n");
       
       
       A=A+AA;
       B=B+BB;
       C=C+CC;
       D=D+DD;
       printf("%08x ",A);
       printf("%08x ",B);
       printf("%08x ",C);
       printf("%08x ",D);
       printf("\n");
       printf("%08x ",AA);
       printf("%08x ",BB);
       printf("%08x ",CC);
       printf("%08x ",DD);
       printf("\n");
       
 }
    printf("\n");
    final[0]=A;
    final[1]=B;
    final[2]=C;
    final[3]=D;
    MD5intchar(S,final,16);
    for(i=0;i<16;i++)
        printf("%02x",S[i]);
    printf("\n");
    
     
    return 0;
}
