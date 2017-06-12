#include<stdio.h> 
#include<stdlib.h>

int first(void);
int before(void);

int main()
{
	first();
	char a;
	int o_n;
	int i,j,u,x=12,xb=12,y=12,yb=12; 
	int io,jo;
	int shape[25][25]={
	{1,10,10,10,10,2,1,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,2},
	{11,0,0,0,0,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,4,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
	{4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,3}} ;//图形数组 
	int shape_b[25][25];
    int object_b[3][2]={{13,13},{13,13},{13,13}};
	int object[3][2]={{13,9},{2,20},{17,17}};
	
	/*	
		for(j=0;j<=24;j++)
		{		
			for(i=0;i<=24;i++)
			{
				printf("%d",shape[j][i]);	
			};
			printf("\n",0);	
		}
	*/
	
	while(1)
	{		
		/*主动运动计算模块*/ 
		switch(a)
		{
			case 'w':
			{
				y--;break;
			}
			case 's':
			{
				y++;break;
			}
			case 'a':
			{
				x--;break;
			}
			case 'd':
			{
				x++;break;
			}
			default:break;
	    }
		
		/*被动运动计算模块*/ 
		x<=24?:x=24;
	    x>=0?:x=0;
	    y<=24?:y=24;
	    y>=0?:y=0;
	    for(io=0;io<=2;io++)
	    {
			if(x==object[io][0]&&y==object[io][1])
			{
				object[io][0]+=x-xb;
				object[io][1]+=y-yb;
				o_n=io;
				
			}
	    }
	    if (o_n!=-1&&shape[object[o_n][1]][object[o_n][0]]!=0)
	    {
	    	x=xb;
	    	y=yb;
	    	object[o_n][0]=object_b[o_n][0];
	    	object[o_n][1]=object_b[o_n][1];
			o_n=-1;	    	
		}
	    
	    /*坐标装载至图形数组*/ 
		shape[yb][xb]=0;
		shape[y][x]=12;
		for(io=0;io<=2;io++)
		{
			shape[object_b[io][1]][object_b[io][0]]=0;
			shape[object[io][1]][object[io][0]]=-1;
		} 
	    
	    /*调试信息输出*/ 
		printf("x=%d y=%d\n",x+1,y+1);
		for(io=0;io<=2;io++)
		{
			printf("object_%d_x=%d object_%d_y=%d\n",io+1,object[io][0]+1,io+1,object[io][1]+1);
		}

		/*屏幕扫描*/ 
		printf("┌",0);
		for(u=0;u<=24;u++)
		{
			printf("─");
		}
		printf("┐\n",0);		
		for(j=0;j<=24;j++)
		{
			printf("│",0);			
			for(i=0;i<=24;i++)
			{
				switch(shape[j][i])
				{
					case -1:{printf("猪",0);break;}
					case 0:{printf("  ",0);break;}
					case 1:{printf("┌",0);break;}
					case 2:{printf("┐",0);break;}
					case 3:{printf("┘",0);break;}
					case 4:{printf("└",0);break;}
					case 5:{printf("┬",0);break;}
					case 6:{printf("┤",0);break;}
					case 7:{printf("┴",0);break;}
					case 8:{printf("├",0);break;}
					case 9:{printf("┼",0);break;}
					case 10:{printf("─",0);break;}
					case 11:{printf("│",0);break;}
					case 12:{printf("你",0);break;}
					default:{printf("？",0);break;}
				}	
			};
			printf("│\n",0);
		}
		printf("└",0);
		for(u=0;u<=24;u++)
		{
			printf("─");
		}
		printf("┘\ncode=",0);
		scanf("%c",&a);
		system("cls");
		
		/*初状态储存*/ 
		xb=x;
		yb=y;
		for(io=0;io<=2;io++)
		{
			object_b[io][0]=object[io][0];
			object_b[io][1]=object[io][1];
		}
    }
}


int first(void)
{
    printf("By Penxil\n操作说明：\n输入一个字母代表移动一下\n可以连续输入\n输入w向上\n输入s向下\n输入a向左\n输入d向右\n输入完毕后请回车\n",0); 
	system("pause");
	system("cls");
}

/*
┌─┬─┬─┬─┐
│  │  │  │  │ 
├─┼─┼─┼─┤
│  │  │  │  │
├─┼─┼─┼─┤
│  │  │  │  │
└─┴─┴─┴─┘
*/ 
