#include<stdio.h>
 int b,f;
void firstfit(int sb[b],int sf[f],int b,int f)
{
    int occ[b],m[f];
    int tb[f],fg[f],g[f];
    for(int i=0;i<b;i++)
    {
        occ[i]=0;
    }
    for(int i=0;i<f;i++)
    {
        m[i]=0;
        for(int j=0;j<b;j++)
        {
            if(occ[j]==0)
            {
                if(sf[i]<=sb[j])
                {
                    g[i]=j+1;
                    tb[i]=sb[j];
                    occ[j]=1;
                    m[i]=1;
                    fg[i]=sb[j]-sf[i];
                    break;
                }
            }
        }
    }
    printf("FILENO\tFILESIZE\tBLOCKNO\tBLOCKSIZE\tFRAGSIZE\n");
    for(int i=0;i<f;i++)
    {
        if(m[i]==1)
        {
          printf("%d\t\t%d\t\t\t%d\t\t%d\t\t\t%d\n",i+1,sf[i],g[i],tb[i],fg[i]);
        }

    }
}
void bestfit(int sb[b],int sf[f],int b,int f)
{
    int occ[b],m[f],min,diff;

    int tb[f],fg[f],g[f];
    for(int i=0;i<b;i++)
    {
        occ[i]=0;
    }
    for(int i=0;i<f;i++)
    {
        g[i]=-1;
        m[i]=0;
        min=1000;
        for(int j=0;j<b;j++)
        {
            if(occ[j]==0)
            {
                diff=sb[j]-sf[i];
                if(diff>=0&&diff<min)
                {
                    min=diff;
                    g[i]=j+1;
                    tb[i]=sb[j];
                }
            }
        }
        if(g[i]!=-1)
        {
            occ[(g[i]-1)]=1;
            m[i]=1;
            fg[i]=min;
        }
    }
    printf("FILENO\tFILESIZE\tBLOCKNO\tBLOCKSIZE\tFRAGSIZE\n");
    for(int i=0;i<f;i++)
    {
        if(m[i]==1)
        {
          printf("%d\t\t%d\t\t\t%d\t\t%d\t\t\t%d\n",i+1,sf[i],g[i],tb[i],fg[i]);
        }

    }
}
void worstfit(int sb[b],int sf[f],int b,int f)
{
    int occ[b],m[f],max;

    int tb[f],fg[f],g[f];
    for(int i=0;i<b;i++)
    {
        occ[i]=0;
    }
    for(int i=0;i<f;i++)
    {
        g[i]=-1;
        m[i]=0;
        max=0;
        for(int j=0;j<b;j++)
        {
            
            if(sf[i]<sb[j]&&occ[j]==0)
            {
                if(max<=sb[j])
                {
                    max=sb[j];
                    g[i]=j+1;
                    tb[i]=sb[j];
                }
            }
        }
        if(g[i]!=-1)
        {
            occ[(g[i]-1)]=1;
            m[i]=1;
            fg[i]=tb[i]-sf[i];
        }
    }
    printf("FILENO\tFILESIZE\tBLOCKNO\tBLOCKSIZE\tFRAGSIZE\n");
    for(int i=0;i<f;i++)
    {
        if(m[i]==1)
        {
          printf("%d\t\t%d\t\t\t%d\t\t%d\t\t\t%d\n",i+1,sf[i],g[i],tb[i],fg[i]);
        }

    }
}
void main()
{

   printf("Enter the number of blocks:");
   scanf("%d",&b);
   printf("Enter the number of files:");
   scanf("%d",&f);
   int sb[b],sf[f];
   printf("Enter the size of each block:\n");
   for(int i=0;i<b;i++)
   {
       printf("BLOCK %d:",i+1);
       scanf("%d",&sb[i]);
   }
   printf("Enter the size of each file:\n ");
   for(int i=0;i<f;i++)
   {
       printf("FILE %d:",i+1);
       scanf("%d",&sf[i]);
   }
   printf("Memory management(First-fit)\n");
   firstfit(sb,sf,b,f);
   printf("Memory management(Best-fit)\n");
   bestfit(sb,sf,b,f);
   printf("Memory management(Worst-fit)\n");
   worstfit(sb,sf,b,f);
}
