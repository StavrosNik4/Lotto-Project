#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char s[20], error;
    int numbers, metric, *filenum, counter, num, lines,i,j,nu[49],f[49],d[49],z,t2;
    float h2[49],t1;
    scanf("%d %d ", &numbers, &metric);
    fgets(s,20,stdin);
    s[strcspn(s,"\n")]='\0';
    if(metric<=-1 || metric>=4 || numbers<=0 || numbers>=50)
    {
        printf("Wrong Input!");
        return 0;
    }
    filenum = NULL;
    fp = fopen(s,"r");
    if(fp!=NULL)
    {
        while(!feof(fp) && !error)
        {
            if(fscanf(fp,"%d",&num)==1)
            {
                counter++;
                filenum = realloc(filenum,sizeof(int[counter]));
                filenum[counter-1]=num;
            }
            else
                error=1;
        }
        fclose(fp);
    }
    else
    {
        printf("File Error!");
        return 0;
    }
    lines = counter/7;
    float flines = lines;
    for(i=0;i<49;i++)
    {
        f[i]=0;
        d[i]=0;
        h2[i]=0;
        nu[i]=i+1;
    }
    if(metric==0)
    {
        for(i=0;i<counter;i++)
        {
            num=1;
            while(num!=filenum[i])
                num++;
            h2[num-1]=h2[num-1]+1;
        }
    }
    if(metric==1)
    {
        for(j=1;j<=49;j++)
        {
            z=counter;
            for(i=counter;i>0;i--)
            {
                if(j==filenum[i])
                    h2[j-1]=i/7;
                else
                    z--;
            }
            if(z==0)
                h2[j-1]=lines;
            if(j==filenum[0])
                h2[j-1]=0;
        }
    }
    if(metric==2)
    {
        for(i=0;i<counter;i++)
            {
                num=1;
                while(num!=filenum[i])
                    num++;
                f[num-1]=f[num-1]+1;
            }
            for(j=1;j<=49;j++)
            {
                z=counter;
                for(i=counter;i>0;i--)
                {
                    if(j==filenum[i])
                        d[j-1]=i/7;
                    else
                        z--;
                }
                if(z==0)
                    d[j-1]=lines;
                if(j==filenum[0])
                    d[j-1]=0;
            }
            for(i=0;i<49;i++)
                h2[i]=f[i]+d[i];
    }
    if(metric==3)
    {
        for(i=0;i<counter;i++)
        {
            num=1;
            while(num!=filenum[i])
                num++;
            f[num-1]=f[num-1]+1;
        }
        for(j=1;j<=49;j++)
        {
            z=counter;
            for(i=counter;i>0;i--)
            {
                if(j==filenum[i])
                    d[j-1]=i/7;
                else
                    z--;
            }
            if(z==0)
                d[j-1]=lines;
            if(j==filenum[0])
                d[j-1]=0;
        }
        for(i=0;i<49;i++){
            if(f[i]==0)
                h2[i]=0;
            else
                h2[i]=d[i]-(flines/f[i]);
        }
    }
    for(i=0;i<49;i++)
    {
        for(j=0;j<48-i;j++)
        {
            if(h2[j]<h2[j+1])
            {
                t1=h2[j];
                h2[j]=h2[j+1];
                h2[j+1]=t1;
                t2=nu[j];
                nu[j]=nu[j+1];
                nu[j+1]=t2;
            }
            if(nu[j]>nu[j+1] && h2[j]==h2[j+1])
            {
                t2=nu[j];
                nu[j]=nu[j+1];
                nu[j+1]=t2;
            }
        }
    }
    for(i=0;i<numbers;i++)
        printf("%d ", nu[i]);
    return 0;
}

