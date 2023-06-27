#include<stdio.h>


void addsub(int c[2][2],int d[2][2])
{
    int f[2][2],f1[2][2];
    printf("the sum of matrix is :\n");
 for(int i=0;i<2;i++)
 {
     for(int j=0;j<2;j++)
     {
         f[i][j]=c[i][j]+d[i][j];
         printf("%d ",f[i][j]);

     }
     printf("\n");
 }

   printf("the subtraction of matrix is :\n");

    for(int i=0;i<2;i++)
 {
     for(int j=0;j<2;j++)
     {
         f1[i][j]=c[i][j]-d[i][j];
         printf("%d ",f1[i][j]);
     }
     printf("\n");
 }

}

void multiply(int c[2][2],int d[2][2])
{
    int i,j,k,mul[2][2];
   printf("multiply of the matrix=\n");
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
mul[i][j]=0;
for(k=0;k<2;k++)
{
mul[i][j]+=c[i][k]*d[k][j];
}
}
}
//for printing result
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
printf("%d\t",mul[i][j]);
}
printf("\n");
}

}

void sumprincidiag(int c[2][2])
{
    int sum=0;
     for(int i=0;i<2;i++)
 {
     for(int j=0;j<2;j++)
     {
          if(i==j)
       {
         sum+=c[i][j];
       }
    }

}
printf("sum of principal diagonal element is %d\n",sum);

}

// Function to calculate the sum of rows and columns
void rowColumnSum(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        printf("Sum of elements in Row %d: %d\n", i + 1, rowSum);
    }

    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += matrix[i][j];
        }
        printf("Sum of elements in Column %d: %d\n", j + 1, colSum);
    }
}
// Function to print the transpose of a matrix
void printTranspose(int matrix[][100], int rows, int cols) {
    printf("Transpose of the matrix:\n");
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a matrix is symmetric
int isSymmetric(int matrix[][100], int rows, int cols) {
    if (rows != cols) {
        printf("not symmetric\n");
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                 printf("not symmetric\n");
            }
        }
    }

    printf("matrix is symmetric\n");
}

main()
{
 int a[2][2],b[2][2];
 int i,j;
 int ch;
 printf("enter the elements of 1st matrix");
 for(i=0;i<2;i++)
 {
     for(j=0;j<2;j++)
     {
           scanf("%d",&a[i][j]);
     }

}
 printf("enter the elements of 2nd matrix");
  for(i=0;i<2;i++)
 {
     for(j=0;j<2;j++)
     {
           scanf("%d",&b[i][j]);
     }

}
while(1)
{
 printf("1.add&sub 2.multiply 3.Sum of principal diagonal 4.row column sum 5.Transpose 6.Symmetric check 7.exit\n");
 scanf("%d",&ch);
 switch(ch)
 {

 case 1:
    addsub(a,b);
    break;

 case 2:
    multiply(a,b);
    break;

 case 3:
    sumprincidiag(a);
    break;

 case 4:
     rowColumnSum(a,2,2);
     break;

 case 5:
     printTranspose(a,2,2);
     break;

 case 6:
     isSymmetric(a,2,2);
     break;

case 7:
    return 0;
 }
}
}

