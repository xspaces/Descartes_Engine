#include<stdio.h> 
#include<stdlib.h>
#include <conio.h>
#include<time.h>
#include <string.h>
#include <io.h>
#define key_num_set 10
#define vX.X.X v1.8.7

int first(void);
int about(void);
int talk(void);
int win(int,int);
int m_key(int m_key_n);
int load();
int shape_l[25][25];
int x_l,y_l;
int object_l[key_num_set][2];
int key_l[key_num_set][2];
int key_num_l=3;
char maker[50];

int main()
{
	first();
	while(1)
	{					
    	/*标题画面初始化*/
    	char first_a='0',start_n=0;
    	int first_n=1,first_n_b=1,first_f=0;
		int first_s=0;
	
    	/*标题画面主程式*/ 
    	while(1)
    	{
    		while(first_f<=0)
	    	{
        		system("cls");
	    		switch(first_a)
        		{
    	    		case 'W':
					case 'w':
	        		{
    	    			first_n--;break;
	        		}
            		case 'S':
					case 's':
    	    		{
	        			first_n++;break;
	        		}
	        		case 'J':
					case 'j':
	        		{
	        			printf("\a");
						switch(first_n)
	        			{
	        				case 1:start_n=load();break;
	        				case 2:about();break;
	        				case 3:talk();break;
	        				case 4:return 0;
	        				default:break;
	    				}
	    				break;
	    			}
	        		default:break;
	            }
	        	
	        	/*游戏开始模块1*/
    	    	if(start_n==1)
    	    	{
					break;
				}
	        	
				/*光标移动边缘判定*/
				first_a='0';
	        	if(first_n<1)
	        	{
	        		first_n=1;
	    		}
	    		if(first_n>4)
	    		{
	    			first_n=4;
	    		}
	    		
	    		/*主菜单显示模块*/ 
	    		m_key(first_n);
	    		
	    		
	        	if(kbhit())
    	    	{
    		    	first_a=getch();
    	    		first_f=0;
    	    	}
    			first_f++;
    		}
	        /*游戏开始模块2*/
    	    if(start_n==1)
    	    {
				start_n=0;
				break;
			}
			
			if(kbhit())
    	    {
    		   	first_a=getch();
    	    	first_f=0;
    	    }
			if(first_s)
			{
				first_s=0;
				break;
			}	
    	} 

    	/*游戏程式初始化*/
    	register char a='0';
		int dbug=0,dbug_code=0;
		int break_n=0;
    	int o_n=0,s_n=0;
    	register int i,j,u,x=0,xb=0,y=0,yb=0,pd=12; 
    	int io=0,jo=0;
    	register int shape[25][25]={
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}} ;//图形数组 
    	register int shape_b[25][25];
        register int object_b[key_num_set][2]={0};
    	register int object[key_num_set][2]={0};
    	register int key[key_num_set][2]={0},key_n[key_num_set]={0},key_num=0,key_num_b=0,path_num=0;
    	int ik=0;
    	int t,t_l,t_b;
		t_l=time(0);
    	path_num=0;
    	for(i=0;i<=24;i++)
    	{
    		for(j=0;j<=24;j++)
    		{
    			shape[j][i]=shape_l[i][j];
			}
		}
		x=x_l;
		y=y_l;
		for(i=0;i<=key_num_l-1;i++)
    	{
    		for(j=0;j<=1;j++)
    		{
    			object[i][j]=object_l[i][j];
			}
		}
		for(i=0;i<=key_num_l-1;i++)
    	{
    		for(j=0;j<=1;j++)
    		{
    			key[i][j]=key_l[i][j];
			}
		}

    	/*游戏主循环*/ 
    	while(1)
    	{
        	while(s_n<=0)//刷新循环 
        	{		
        		system("cls");
        		/*初状态储存*/ 
        		xb=x;
        		yb=y;
	        	for(io=0;io<=key_num_l-1;io++)
	        	{
    	    		object_b[io][0]=object[io][0];
    	    		object_b[io][1]=object[io][1];
        		}
        		
        		/*主动运动计算模块*/ 
        		switch(a)
        		{
        			case 'W':
					case 'w':
	        		{
        				y--;pd=12;break;
	        		}
            		case 'S':
					case 's':
        			{
	        			y++;pd=13;break;
	        		}
	    	    	case 'A':
					case 'a':
	        		{
	        			x--;pd=14;break;
	        		}
	        		case 'D':
					case 'd':
	        		{
	        			x++;pd=15;break;
	        		}
	        		case 'K':
					case 'k':
	        		{
	        			break_n=1;break;
					}
					case '1':
	        		{
	        			dbug=dbug==1?0:1;break;
	        		}
	        		case '2':
	        		{
	        			dbug=dbug==2?0:2;break;
					}
					case '3':
					{
						dbug_code=dbug_code==1?0:1;break;
					}
	        		default:break;
	            }
    	    	
				/*游戏退出模块1*/
    	    	if(break_n==1)
    	    	{
					break;
				}
		
	        	/*被动运动计算模块*/ 
	        	x<=24?:x=24;
	            x>=0?:x=0;
	            y<=24?:y=24;
	            y>=0?:y=0;
	            if(shape[y][x]!=0&&shape[y][x]!=-1&&shape[y][x]!=-2&&shape[y][x]!=-3)
    	        {
    	        	x=xb;
	            	y=yb;
    	    	}
	    
        		for(io=0;io<=key_num_l-1;io++)
    	        {
	        		if(x==object[io][0]&&y==object[io][1])
	        		{
	        			object[io][0]+=x-xb;
        				object[io][1]+=y-yb;
	        			o_n=io;
	        		}
	            }
	            if (o_n!=-1&&shape[object[o_n][1]][object[o_n][0]]!=0&&shape[object[o_n][1]][object[o_n][0]]!=-3)
        	    {
	            	x=xb;
	            	y=yb;
	            	object[o_n][0]=object_b[o_n][0];
	            	object[o_n][1]=object_b[o_n][1];
	        		o_n=-1;	    	
	        	}
	        	o_n=-1;
	        	
	        	/*步数计算*/
	        	if(x!=xb||y!=yb)
	        	{
	        		path_num++;
				}
	    	   
	            /*坐标装载至图形数组*/ 
        		for(io=0;io<=key_num_l-1;io++)
        		{
	        		shape[object_b[io][1]][object_b[io][0]]=0;
	        		shape[object[io][1]][object[io][0]]=-1;
	        	} 
	        	shape[yb][xb]=0;
				for(ik=0;ik<=key_num_l-1;ik++)//被占据判定点判定 
	        	{
	        		switch(shape[key[ik][1]][key[ik][0]])
	        		{
	        			case 0:shape[key[ik][1]][key[ik][0]]=-3;key_n[ik]=0;break;
	    				case -1:shape[key[ik][1]][key[ik][0]]=-2;key_n[ik]=1;break;
	    				case -2:shape[key[ik][1]][key[ik][0]]=-2;key_n[ik]=1;break;
	    				case -3:shape[key[ik][1]][key[ik][0]]=-3;key_n[ik]=0;break;
	        			default:break;
		    		}
	    		}
	        	shape[y][x]=pd;
	    	
	    		/*被占据判定点记录*/ 
	    		key_num=0;
	    		for(ik=0;ik<=key_num_l-1;ik++)
	    		{
	    			if(key_n[ik]==1)
	    			{
	    				key_num++;
	    			}
	    		}
	    		if(key_num_b!=key_num)
	    		{
	    			printf("\a");
				}
	    		key_num_b=key_num;
			 


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
	    	    		if(dbug==2)
	    	    		{
	    	    			printf("%-2d",shape[j][i]);
						}
						if(dbug!=2)
						switch(shape[j][i])
		        		{
		    	    		case -3:printf("×",0);break;
		    				case -2:printf("◎",0);break;
		    				case -1:printf("○",0);break;
		    	    		case 0:printf("  ",0);break;
		    	    		case 1:printf("┌",0);break;
		    	    		case 2:printf("┐",0);break;
		    	    		case 3:printf("┘",0);break;
		    	    		case 4:printf("└",0);break;
			        		case 5:printf("┬",0);break;
		    	    		case 6:printf("┤",0);break;
			        		case 7:printf("┴",0);break;
		        			case 8:printf("├",0);break;    
	        				case 9:printf("┼",0);break;
		        			case 10:printf("─",0);break;
		        			case 11:printf("│",0);break;
		        			case 12:printf("↑",0);break;
	        				case 13:printf("↓",0);break;
	        				case 14:printf("←",0);break;
	        				case 15:printf("→",0);break;
	        				case 16:printf("█",0);break;
	        				default:printf("？",0);break;
	        			}	
	        		};
	        		printf("│\n",0);
	        	}
	        	printf("└",0);
	        	for(u=0;u<=24;u++)
	        	{
	        		printf("─");
	        	}
	        	printf("┘\n",0);
	        	for(i=0;i<=49;i++)
				{
					if(maker[i]!=0)
					{
						printf("%c",maker[i]);
					}
					else
					{
						break;
					}
				}
		    	printf("path_num:%d\n",path_num);
				printf("key _num:%d/%d\n",key_num,key_num_l);	
				printf("按K返回主菜单\n",0)	;
				
    			/*控制台信息输出函数*/ 
				if(dbug==1||dbug==2)
   				{
					printf("char_a=%c\n",a);
					printf("x_n=%-4d y_n=%-4d\n",x+1,y+1);
					printf("x_b=%-4d y_b=%-4d\n",xb+1,yb+1);
				    for(io=0;io<=key_num_l-1;io++)
				    {
    			    	printf("object_n_%2d_x=%3d object_n_%2d_y=%3d\nobject_b_%2d_x=%3d object_b_%2d_y=%3d\n",io+1,object[io][0]+1,io+1,object[io][1]+1,io+1,object_b[io][0]+1,io+1,object_b[io][1]+1);
				   	}
				   	printf("key_num:%d/%d\n",key_num,key_num_l);
				   	printf("key_n[]={");
				   	for(io=0;io<=key_num_l-1;io++)
				   	{
				   		printf("%d,",key_n[io]);
					}
				   	printf("\b}\n");
				   	printf("time=%d\n",t-t_l);
				}
	
    	    	/*过关判定*/
    	    	if(key_num==key_num_l)
    	    	{
					win(t-t_l,path_num);
					break_n=1;
					break;
				} 
				
				/*输入模块*/
    	    	if(dbug_code)
    	    	{
    	    		scanf("%c",&a);
				}
				//a=getche();
				if(dbug!=1&&kbhit())
	        	{
		        	a=getch();
	        		s_n=0;
	        	}
	        	if(dbug_code==0)
				{
					s_n++;
				}
            }
           	
			/*游戏退出模块2*/
    	    if(break_n==1)
    	    {
    	   		break_n=0;
				break;
			}
			
			/*计时器模块*/
			t_b=t;
			t=time(0);
            
            
			if(kbhit())
	        {
		       	a=getch();
	        	s_n=0;
	        }
        }        
    }
}


int first(void)
{
    printf("By Penxil\n操作说明：\n按 W/w 向上\n按 S/s 向下\n按 A/a 向左\n按 D/d 向右\n按 J/j 确定\n按 K/k 返回\n按 1 调用控制台\n按 2 调用完全测试模式\n按 3 调用安全模式\n",0); 
	system("pause");
	system("cls");
}


 /*关于界面*/ 
int about(void)
{
        printf("┌─────────────────────────┐\n",0);
		printf("│               仑质Penxil荣誉巨献                 │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│           Powered by Descartes Engine            │\n",0);
	  	printf("│            由笛卡尔引擎提供技术支持              │\n",0);
		printf("│                 Penx.com 2017                    │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                            v1.9.3│\n",0);
		printf("└─────────────────────────┘\n",0);
		getch();
		system("cls");
		return 0;
}


/*说明界面*/
int talk()
{
        	printf("┌─────────────────────────┐\n",0);
		    printf("│                                                  │\n",0);
		    printf("│          操作说明：                              │\n",0);
			printf("│               按W向上                            │\n",0);
			printf("│               按S向下                            │\n",0);
			printf("│               按A向左                            │\n",0);
			printf("│               按D向右                            │\n",0);
			printf("│               按J确定                            │\n",0);
			printf("│               按K返回                            │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│          地图说明：                              │\n",0);
			printf("│               地图文件以.dat格式储存在主目录下   │\n",0);
		   	printf("│               的map文件夹中，编写格式由作者确    │\n",0);
		   	printf("│               定。                               │\n",0);
		   	printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
		   	printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
	  		printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("│                                                  │\n",0);
			printf("└─────────────────────────┘\n",0);
			getch();
			system("cls");
			return 0;
}

int win(int t,int path_num)
{
	    system("cls");
		printf("┌─────────────────────────┐\n",0);
	    printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│  ┌─────────────────────┐  │\n",0);
	   	printf("│  │  无穷的远方，无数的名字，都与笛卡尔有关  │  │\n",0);
	   	printf("│  └─────────────────────┘  │\n",0);
	   	printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
	   	printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                                你的步数：%-5d步 │\n",path_num);
	  	printf("│                                你的用时：%-5d秒 │\n",t);
		printf("│                                                  │\n",0);
		printf("│                                                  │\n",0);
		printf("│                            请按任意键返回主菜单  │\n",0);
		printf("└─────────────────────────┘\n",0);
		getch();
}

int m_key(int m_key_n)
{
	switch(m_key_n)
    {
	   	case 1:
			{
				printf("┌─────────────────────────┐\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                  ┌─────┐                  │\n",0);
		    	printf("│                  │  开  始  │                  │\n",0);
		    	printf("│                  └─────┘                  │\n",0);
		    	printf("│                      关  于                      │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                      说  明                      │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                      退  出                      │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
			   	printf("│                                                  │\n",0);
			    printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		   		printf("│                                                  │\n",0);
		   		printf("│                                                  │\n",0);
		   		printf("└─────────────────────────┘\n",0);
		   		break;
		   	}
		case 2:
		   	{
				printf("┌─────────────────────────┐\n",0);
				printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
			    printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
			    printf("│                                                  │\n",0);
			    printf("│                                                  │\n",0);
		    	printf("│                      开  始                      │\n",0);
		    	printf("│                  ┌─────┐                  │\n",0);
		    	printf("│                  │  关  于  │                  │\n",0);
		    	printf("│                  └─────┘                  │\n",0);
		    	printf("│                      说  明                      │\n",0);
	    		printf("│                                                  │\n",0);
    			printf("│                      退  出                      │\n",0);
			  	printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
			    printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
	    		printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
			    printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
	    		printf("└─────────────────────────┘\n",0);
		    	break;
		    }
		case 3:
	    	{
		    	printf("┌─────────────────────────┐\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
	    		printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
				printf("│                      开  始                      │\n",0);
			    printf("│                                                  │\n",0);
		    	printf("│                      关  于                      │\n",0);
	    		printf("│                  ┌─────┐                  │\n",0);
    			printf("│                  │  说  明  │                  │\n",0);
				printf("│                  └─────┘                  │\n",0);
				printf("│                      退  出                      │\n",0);
			    printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
	    		printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
				printf("│                                                  │\n",0);
			    printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
	    		printf("│                                                  │\n",0);
	    		printf("└─────────────────────────┘\n",0);
		    	break;
		    }
	    case 4:
	    	{
		    	printf("┌─────────────────────────┐\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                      开  始                      │\n",0);
		    	printf("│                                                  │\n",0);
		    	printf("│                      关  于                      │\n",0);
		    	printf("│                                                  │\n",0);
			    printf("│                      说  明                      │\n",0);
	    		printf("│                  ┌─────┐                  │\n",0);
	    		printf("│                  │  退  出  │                  │\n",0);
	    		printf("│                  └─────┘                  │\n",0);
	    		printf("│                                                  │\n",0);
	    		printf("│                                                  │\n",0);
	    		printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
		    	printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
    			printf("│                                                  │\n",0);
	    		printf("└─────────────────────────┘\n",0);
	    		break;
	    	}
	}
	return 0;
}


int load()
{
	char fproot[20]="./map/*.dat";
	char froot[20]="./map/";
	char *f_root=froot;
	FILE *fp;
	int a,i,j;
	int load_n=1,load_n_i=1,load_f=0,load_set=0;
	char load_a='a';
	char a_c;
	system("cls");
	
	/*地图文件计数*/ 
	int load_num_l=0;
	char *path_l=fproot;
	struct _finddata_t data_l;
	long hnd_l = _findfirst( path_l, &data_l );
	if ( hnd_l < 0 )
    {
       	perror( path_l );
    }
    int  nRet = (hnd_l <0 ) ? -1 : 1;
	while ( nRet >= 0 )
    {
        nRet = _findnext( hnd_l, &data_l );
        load_num_l++;
    }
    _findclose( hnd_l ); 
	
	/*地图文件选择模块*/	
	while(1)
	{
		while(load_f<=0)
	    {
			system("cls");
			printf("请选择地图文件：\n\n");
			switch(load_a)
    		{
    		    case 'W':
				case 'w':
	 	    	{
    		    	load_n--;break;
		        }
   	        	case 'S':
				case 's':
   		 		{
	 	  			load_n++;break;
	 	  		}
		   		case 'J':
				case 'j':
		   		{
					load_set=1;
					printf("\a");
	 		   		break;
	    		}
	    		case 'K':
	    		case 'k':
	    		{
	    			system("cls");
					return 0;
				}
	   			default:break;
	    	}
	    	load_a='0';
	        if(load_n<1)
	        {
	        	load_n=1;
	    	}
	    	if(load_n>load_num_l)
	    	{
	    		load_n=load_num_l;
	    	}
	    	char *path=fproot;
			struct _finddata_t data;
			long hnd = _findfirst( path, &data );
			if ( hnd < 0 )
    		{
        		perror( path );
    		}
    		int  nRet = (hnd <0 ) ? -1 : 1;
    		load_n_i=1;
			while ( nRet >= 0 )
    		{
				if(load_n_i==load_n)
				{
					printf("-->");
					if(load_set==1)
					{
						break;
					}
				}
				else
				{
					printf("   ");
				}
				printf(" [%s]\n", data.name );
        		nRet = _findnext( hnd, &data );
        		load_n_i++;
    		}
	    	char *dname=data.name;
	    	strcat(f_root,dname);
			
			if(load_set==1)
			{
				break;
			}
			_findclose( hnd ); 
	    	load_f++;
		}
		
		if(load_set==1)
		{
			break;
		}
		while(kbhit())
		{
			load_a=getch();
			load_f=0;
		}
	}
	
	/*地图文件读取*/ 
	if ( (fp = fopen(f_root,"r"))==NULL)
	{
		printf("can not open data file……\n");
		getch();
		exit(0);
	}
	else
	{
		printf("已找到文件\n");
	}
	printf("正在写入地图\n");
	for(i=0;i<=24;i++)
	{
		for(j=0;j<=24;j++)
		{
			fscanf(fp,"%d",&a);
			shape_l[j][i]=a;
		}
		printf("*");
	}
	printf("\n正在初始化操作模块\n");
	fscanf(fp,"%d",&a);
	x_l=a;
	fscanf(fp,"%d",&a);
	y_l=a;
	printf("\n正在初始化物体模块\n");
	fscanf(fp,"%d",&key_num_l);
	for(i=0;i<=key_num_l-1;i++)
	{
		for(j=0;j<=1;j++)
		{
			fscanf(fp,"%d",&a);
			object_l[i][j]=a;
			printf("*");
		}
	}
	printf("\n正在初始化检测点模块\n");
	for(i=0;i<=key_num_l-1;i++)
	{
		for(j=0;j<=1;j++)
		{
			fscanf(fp,"%d",&a);
			key_l[i][j]=a;
			printf("*");
		}
	}
	printf("\n\n");
	for(i=0;i<=49;i++)
	{
		maker[i]=0;
	}
	for(i=0;i<=49;i++)
	{
		if((a=fscanf(fp,"%c",&a_c))!=-1)
		{
			maker[i]=a_c;
		}
		else
		{
			break;
		}
	}
	system("cls");
	return 1;
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
