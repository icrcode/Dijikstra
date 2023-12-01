#include<stdio.h>
#define QTD 9999
#define MAX 10

void dijkstra(int G[MAX][MAX],int n,int inicial);

int main()
{
    int i,j,u,l,p;
    int G[MAX][MAX];

    for(l=0 ;l < MAX; l++)
    {
        for( p=0; p< MAX; p++)
        {
            G[l][p] = -1;
        }
    }

    G[0][1]=15;
    G[0][2]=4;
    G[1][3]=2;
    G[2][3]=3;
    G[2][4]=7;
    G[3][5]=4;
    G[3][6]=500;
    G[4][8]=25;
    G[5][7]=7;
    G[6][7]=25;
    G[7][9]=45;
    G[8][9]=80;
    G[6][7]=16;

    for(l=0 ;l < MAX; l++)
    {
        for( p=0; p< MAX; p++)
        {
            printf("%d,",G[l][p]);
        }
        printf("\n");
    }

    printf("\nInforme o node inicial:");
    scanf("%d",&u);
    dijkstra(G,MAX,u);

    return 0;
}

void dijkstra(int G[MAX][MAX],int n,int inicial)
{

    int custo[n][n],distancia[n],pred[n];
    int visitado[n],cont,distanciamin,proxno,i,j;


    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==-1)
                custo[i][j]=QTD;
            else
                custo[i][j]=G[i][j];

    for(i=0;i<n;i++)
    {
        distancia[i]=custo[inicial][i];
        pred[i]=inicial;
        visitado[i]=0;
    }

    distancia[inicial]=0;
    visitado[inicial]=1;
    cont=1;

    while(cont<n-1)
    {
        distanciamin=QTD;


        for(i=0;i<n;i++)
            if(distancia[i]<distanciamin&&!visitado[i])
            {
                distanciamin=distancia[i];
                proxno=i;
            }

        //verifica se existe melhor caminho atraves do proximo node
        visitado[proxno]=1;
        for(i=0;i<n;i++){
            if(!visitado[i])
                if(distanciamin+custo[proxno][i]<distancia[i])
                {
                    distancia[i]=distanciamin+custo[proxno][i];
                    pred[i]=proxno;
                }
        }
        cont++;
    }
    //imprime o caminho e a distancia de cada node
    for(i=0;i<n;i++)
        if(i!=inicial)
        {
            printf("\nDistancia do no %d = %d",i,distancia[i]);
            printf("\nCaminho = %d",i);

            j=i;
            do
            {
                j=pred[j];
                printf("<-%d",j);
            }while(j!=inicial);
    }
}